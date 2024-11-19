#ifndef APPROVISIONNEMENT_H
#define APPROVISIONNEMENT_H

#include <QWidget>
#include "QStandardItemModel"
#include "QModelIndex"
#include "QTextEdit"
#include "QList"
#include "QDate"
#include "QCompleter"
#include <QPrinter>

namespace Ui {
class Approvisionnement;
}

class Approvisionnement : public QWidget
{
    Q_OBJECT

public:
    explicit Approvisionnement(QWidget *parent = 0);
    ~Approvisionnement();
    void Afficher();
    void GenererCodeProduit(const QString &text);
    void Completer();
    void CaracteristiqueProduit();
    void print(QPrinter *printer);



private slots:
    void on_ajouter_pushButton_clicked();

    void on_annuler_pushButton_clicked();

    void on_enregistrer_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_supprimer_pushButton_clicked();

    void on_rechercher_pushButton_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_code_lineEdit_textChanged(const QString &arg1);

    void on_vider_pushButton_clicked();

    void on_retour_pushButton_clicked();

    void on_deconnexion_pushButton_clicked();

    void on_imprime_pushButton_clicked();

    void on_enregistrer_pushButton_2_clicked();

private:
    Ui::Approvisionnement *ui;
    QStandardItemModel *model;
    QModelIndex indextable;
    QCompleter *completer;
    QTextEdit *text;
    QString codePro, nomPro, typePro, caracteristique;
    int qtePro = 0;
    int qte = 0;
    QDate dateExpiration, dateApprovisionnement;
    QString codeAp;
    QString codeApp;
};

#endif // APPROVISIONNEMENT_H
