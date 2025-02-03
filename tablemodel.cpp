#include "tablemodel.h"

TableModel::TableModel(QVector<QString> d, int c) {
    data = d;
    rowCount = c;
}
TableModel::TableModel(){ }
