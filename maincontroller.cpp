#include "maincontroller.h"
#include "ui_maincontroller.h"
#include "tableview.h"
#include "dbhelper.h"
#include "jsonutilities.h"

MainController::MainController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainController)
{
    ui->setupUi(this);
    setup();
}

void saveDefaultJson(){
    JsonUtilities utilities;
    QStringList strings = {
        "O:/Projects/Work/WorkAssgnment/Database/WorkersDB.db",
        "id",
        "FullName",
        "Salary",
        "password",
        "nickname",
        "int",
        "text",
        "int",
        "text",
        "text"
    };
    utilities.saveJson("data.json", strings);
}

void MainController::setup(){
    JsonUtilities utilities;
    if(!utilities.read("data.json"))
        saveDefaultJson();

    QString dbPath = utilities.getDBPath();
    QStringList columns = utilities.getColumns();
    QStringList columnTypes = utilities.getTypes();

    db = new DBHelper(columns);
    if(!db->setupConnnection(dbPath))
        ui->connectionStatus->setText("Couldn't connect to the DB :(");
    else
        ui->connectionStatus->setText("Connected to the DB.");

    TableModel model = db->getTable();

    view = new TableView(this, columns, columnTypes);
    view->sendModel(model);
    ui->verticalLayout->addWidget(view);
}

MainController::~MainController()
{
    delete ui;
}

void MainController::on_saveButton_clicked()
{
    db->updateTable(view->getModel());
}


void MainController::on_addButton_clicked()
{
    view->addNew();
}


void MainController::on_deleteButton_clicked()
{
    view->deleteById(ui->deleteIdBox->value());
}

