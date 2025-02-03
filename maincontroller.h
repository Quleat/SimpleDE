#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QMainWindow>
#include "tablemodel.h"
#include "tableview.h"
#include "dbhelper.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainController;
}
QT_END_NAMESPACE

class MainController : public QMainWindow
{
    Q_OBJECT

public:
    MainController(QWidget *parent = nullptr);
    ~MainController();

private slots:
    void on_saveButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    TableView *view;
    DBHelper *db;

    Ui::MainController *ui;
    void setup();
};
#endif //MAINCONTROLLER_H
