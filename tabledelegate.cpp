#include "tabledelegate.h"

TableDelegate::TableDelegate(QWidget *parent, QString dataType) : QStyledItemDelegate(parent) {
    this->dataType = dataType;
};
QWidget* TableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &)  const {
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}
void TableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const  {
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(editor);
    if (!lineEdit) return;

    QString value = lineEdit->text();
    if(dataType == "int"){
        bool isInt;
        int intValue = value.toInt(&isInt);
        if(!isInt || intValue < 0)
            return;
    }
    else if (dataType == "text"){
        if(value.length() < 3){
            qDebug() << "The length should be more than 2 symbols!";
            return;
        }
    }
    model->setData(index, value, Qt::EditRole);
}
