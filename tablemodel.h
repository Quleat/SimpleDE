#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QString>
#include <QVector>

class TableModel
{
public:
    TableModel(QVector<QString>, int count);
    TableModel();
    int rowCount = 0;
    QVector<QString> data;
};

#endif // TABLEMODEL_H
