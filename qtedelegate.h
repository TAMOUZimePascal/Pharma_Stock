#ifndef QTEDELEGATE_H
#define QTEDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class QteDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit QteDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // QTEDELEGATE_H
