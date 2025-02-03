#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>

class TableDelegate : public QStyledItemDelegate
{
    QString dataType;
public:
    TableDelegate(QWidget *parent, QString dataType);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index)  const override;
};

#endif // TABLEDELEGATE_H
