#ifndef READONLY_H
#define READONLY_H


#include <QItemDelegate>

class ReadOnlyDelegate : public QItemDelegate
{
public:
    ReadOnlyDelegate(QWidget *parent = NULL):QItemDelegate(parent)
    {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const override;
};

#endif // READONLY_H
