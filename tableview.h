#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QObject>
#include <QTableWidget>
#include <tablemodel.h>

class TableView : public QTableWidget
{
    int colCount;
    QStringList columnTypes;
public:
    TableView(QWidget* parent, QStringList columnTitles, QStringList columnTypes);
    void sendModel(TableModel model);
    TableModel getModel();
    void addNew();
    void deleteById(int id);
};

#endif // TABLEVIEW_H
