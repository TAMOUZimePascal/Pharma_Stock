#ifndef COMPTA_H
#define COMPTA_H

#include <QWidget>
#include "QMessageBox"
#include <QSqlError>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <iostream>

namespace Ui {
class Compta;
}

class Compta : public QWidget
{
    Q_OBJECT

public:
    explicit Compta(QWidget *parent = 0);
    ~Compta();

    void afficher();

    void effacer();

    void afficherRecapitulatif();
    void print(QPrinter *printer);

private slots:
    void on_enregistrer_pushButton_4_clicked();

    void on_modifier_pushButton_4_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_annuler_pushButton_4_clicked();

    void on_supprimer_pushButton_4_clicked();

    void on_editer_facture_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Compta *ui;
    QStandardItemModel *modele;
    QModelIndex indextable;
    QStandardItemModel *modeleRecapitulatif;
    QTextEdit *text;

    //QTextEdit *text;
};

#endif // COMPTA_H
