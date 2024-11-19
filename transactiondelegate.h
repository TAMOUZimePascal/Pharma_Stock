#ifndef TRANSACTIONDELEGATE_H
#define TRANSACTIONDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class TransactionDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit TransactionDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        // Déterminer la couleur de fond en fonction de la valeur de la colonne "action"
        if (index.sibling(index.row(), 2).data().toString() == "décaissement") {
            opt.backgroundBrush = QBrush(Qt::red);
        } else if (index.sibling(index.row(), 2).data().toString() == "encaissement") {
            opt.backgroundBrush = QBrush(Qt::green);
        }

        QStyledItemDelegate::paint(painter, opt, index);
    }
};

#endif // TRANSACTIONDELEGATE_H
