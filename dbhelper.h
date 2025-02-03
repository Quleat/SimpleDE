#ifndef DBHELPER_H
#define DBHELPER_H
#include "tablemodel.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

class DBHelper
{
    TableModel lastModel;
    QSqlDatabase db;
    QStringList columns;
public:
    DBHelper(QStringList c);
    bool setupConnnection(QString path);
    bool updateTable(TableModel model);
    TableModel getTable();
};

#endif // DBHELPER_H
