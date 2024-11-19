#include "customdelegate.h"
#include <QDate>
#include <QApplication>
#include <QDebug>

CustomDelegate::CustomDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);

    if (!index.isValid()) {
        return;
    }

    painter->save();

    if (index.column() == 3) { // Date d'expiration
        QDate expirationDate = index.data().toDate();
        if (expirationDate.isValid()) {
            QFont font = option.font;
            font.setPointSize(option.font.pointSize() - 2);
            font.setStyle(QFont::StyleItalic);
            painter->setFont(font);
            painter->setPen(Qt::red); // Mettre le texte en rouge

            if (expirationDate < QDate::currentDate() || expirationDate == QDate::currentDate()) {
                painter->drawText(option.rect, Qt::AlignRight, "expiré");
            } else {
                int daysRemaining = QDate::currentDate().daysTo(expirationDate);
                painter->drawText(option.rect, Qt::AlignRight, QString("%1 jours").arg(daysRemaining));
            }
        }
    }

    painter->restore();
}
