#include "tableview.h"
#include <QHeaderView>
#include "tabledelegate.h"

TableView::TableView(QWidget* parent, QStringList columnTitles, QStringList columnTypes) : QTableWidget(parent), columnTypes(columnTypes){
    colCount = columnTitles.count();
    this->setColumnCount(colCount);
    this->setHorizontalHeaderLabels(columnTitles);
    this->verticalHeader()->setVisible(false);

    for(int i = 0; i < columnTypes.size(); i++){
        this->setItemDelegateForColumn(i, new TableDelegate(this, columnTypes.at(i)));
    }
}

void TableView::sendModel(TableModel model){
    this->setRowCount(model.rowCount);
    for(int i = 0; i < (model.data.count() + 1) * colCount; i++){
        QString value = model.data.value(i);
        QTableWidgetItem *item = new QTableWidgetItem(value);
        if(i % colCount == 0)
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        this->setItem(i / colCount, i % colCount, item);
    }
}

TableModel TableView::getModel(){
    QVector<QString> itemList;
    for (int row = 0 ; row < this->rowCount(); ++row) {
        for (int col = 0 ; col < this->columnCount() ; ++col) {
            QString cell = this->item(row, col)->text();
            itemList << cell;
        }
    }
    TableModel updatedModel(itemList, itemList.count());
    return updatedModel;
}

void TableView::addNew(){
    this->setRowCount(this->rowCount()+1);
    QTableWidgetItem *item = new QTableWidgetItem(QString::number(this->rowCount()));
    this->setItem(this->rowCount()-1, 0, item);
    for(int i = 1; i < columnTypes.count(); i++){
        QString defaultValue = "";
        if(columnTypes.at(i) == "int")
            defaultValue = "0";
        else if(columnTypes.at(i) == "text")
            defaultValue = "new";

        this->setItem(rowCount()-1, i, new QTableWidgetItem(defaultValue));
    }
}

void TableView::deleteById(int id){
    if(id > this->rowCount())
        return;
    for (int row = id ; row < this->rowCount(); ++row) {
        for (int col = 0 ; col < this->columnCount() ; col++) {
            if(col == 0){
                auto item = new QTableWidgetItem(QString::number(row));
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                this->setItem(row-1, col, item);
            }
            else
                this->setItem(row-1, col, this->item(row, col)->clone());
        }
    }
    this->setRowCount(this->rowCount()-1);
}
