#ifndef COMMANDENONSATISFAITE_H
#define COMMANDENONSATISFAITE_H

#include <QWidget>
#include "QStandardItemModel"
#include "QCompleter"
#include "QModelIndex"
#include "QTextEdit"
#include <QPrinter>
#include "QPrinter"
#include "QPrintDialog"
#include "QPainter"

namespace Ui {
class CommandeNonSatisfaite;
}

class CommandeNonSatisfaite : public QWidget
{
    Q_OBJECT

public:
    explicit CommandeNonSatisfaite(QWidget *parent = nullptr);
    ~CommandeNonSatisfaite();
    void Afficher();
    void GenererCodeProduit(const QString &text);
    void Completer();
    void CaracteristiqueProduit(const QModelIndex &index);
    void displaySaleDetails(const QString &codeV);
    void setupPanierModel();
    void print(QPrinter *printer);

private slots:
    void on_rechercher_pushButton_clicked();

    void on_modifier_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void afficherDetailsCommande(const QModelIndex &current, const QModelIndex &previous);


    void on_tableView_2_clicked(const QModelIndex &index);

private:
    Ui::CommandeNonSatisfaite *ui;
    QStandardItemModel *model;
    QModelIndex indextable;
    QCompleter *completer;
    QTextEdit *text;
    QString codeV;

        QStandardItemModel *detailModel;
};

#endif // COMMANDENONSATISFAITE_H
