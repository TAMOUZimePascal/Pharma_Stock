#ifndef ENREGISTRER_FOURNISSEUR_H
#define ENREGISTRER_FOURNISSEUR_H

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>

#include <QWidget>

namespace Ui {
class Enregistrer_Fournisseur;
}

class Enregistrer_Fournisseur : public QWidget
{
    Q_OBJECT

public:
    explicit Enregistrer_Fournisseur(QWidget *parent = 0);
    ~Enregistrer_Fournisseur();
    void afficher();
    void effacer();

private slots:


    void on_Enregistrer_pushButton_clicked();

    void on_AnnulerpushButton_clicked();

    void on_Modifier_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_Suprimer_pushButton_clicked();

    void on_Imprimer_pushButton_clicked();

    void print(QPrinter *printer);

    void on_accueil_pushButton_clicked();

private:
    Ui::Enregistrer_Fournisseur *ui;
    QStandardItemModel *modele;
    QModelIndex indextable;
    QTextEdit *text;
};

#endif // ENREGISTRER_FOURNISSEUR_H
