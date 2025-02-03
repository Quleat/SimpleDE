#include "dbhelper.h"
#include "QVector"

DBHelper::DBHelper(QStringList c) {
    columns = c;
}

bool DBHelper::setupConnnection(QString path){
    db = QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
    db.setDatabaseName(path);
    if(!db.open())
        return false;
    return true;
}

TableModel DBHelper::getTable(){
    auto query = QSqlQuery(db);
    query.exec("SELECT * FROM Workers");
    QVector<QString> values;
    int counter = 0;

    while(query.next()) {
        counter++;

        for(int i = 0; i < columns.count(); i++){
            values.append(query.value(i).toString());
        }
    }

    TableModel model(values, counter);
    lastModel = TableModel(values, counter);
    return model;
}

bool DBHelper::updateTable(TableModel model){
    int minIndex = lastModel.data.count() > model.data.count() ? model.data.count() : lastModel.data.count();
    int colCount = columns.count();

    auto query = QSqlQuery(db);

    //Updating existing values
    for(int i = 0; i < minIndex; i++){

        if(lastModel.data.at(i) == model.data.at(i))
            continue;

        int index = (i / colCount) * colCount;
        QString command = "UPDATE Workers SET";
        for(int i = 0; i < colCount; i++){
            command.append(columns.at(i) + " = \'" + model.data.at(index + 1) + "\'");
        }

        command.append("\' WHERE id = ");
        command.append(QString::number(i / colCount + 1));

        query.exec(command);
        i = (index + 1) * 5;
    }

    //Inserting new records
    if(lastModel.data.count() < model.data.count()){
        for(int i = lastModel.data.count(); i < model.data.count(); i += 5){
            QString command = "INSERT INTO Workers ";
            QString columnTitles = "(", columnValues = "(";
            for(int j = 0; j < colCount; j++){
                if (j != colCount-1){
                    columnTitles.append(columns.at(j) + ", ");
                    columnValues.append("\'" + model.data.at(i + j) + "\'" + ", ");
                }
                else{
                    columnTitles.append(columns.at(j));
                    columnValues.append("\'" + model.data.at(i + j) + + "\'");
                }
            }
            command.append(columnTitles);
            command.append(") VALUES ");
            command.append(columnValues);
            command.append(")");

            query.exec(command);
        }
    }

    //Deleting records
    if(lastModel.data.count() > model.data.count()){
        for(int i = lastModel.data.count()-5; i >= model.data.count(); i-=5){
            QString command = "DELETE FROM Workers WHERE ";
            command.append("id = ");
            command.append(lastModel.data.at(i));
            query.exec(command);
        }
    }

    lastModel = model;
    return true;
}


