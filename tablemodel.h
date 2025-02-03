#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QString>
#include <QVector>

class TableModel
{
public:
    static const int columns = 5;

    TableModel(QVector<QString>, int count);
    TableModel();
    int rowCount = 0;
    QVector<QString> data;
};

#endif // TABLEMODEL_H
