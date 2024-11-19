#include "qtedelegate.h"
#include <QDate>
#include <QApplication>
#include <QDebug>

QteDelegate::QteDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

void QteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);

    if (!index.isValid()) {
        return;
    }

    painter->save();

    if (index.column() == 4) { // Colonne de la quantité
        int qteNonSatisfaite = index.data(Qt::UserRole + 1).toInt();
        if(qteNonSatisfaite > 0){
        QString displayText = QString("NS: %1").arg(qteNonSatisfaite);

        QFont font = option.font;
        font.setPointSize(option.font.pointSize() + 1);
        font.setStyle(QFont::StyleItalic);
        painter->setFont(font);
        font.setBold(true);
        painter->setPen(Qt::cyan); // Mettre le texte en rouge

        QRect textRect = option.rect;
        painter->drawText(textRect, Qt::AlignRight, displayText);
        }else{
            QStyledItemDelegate::paint(painter, option, index);
        }

    }

    painter->restore();
}
