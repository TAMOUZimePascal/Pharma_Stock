#ifndef INTERFACE_VENTE_H
#define INTERFACE_VENTE_H

#include <QWidget>
#include "QStandardItemModel"
#include "QModelIndex"
#include "QTextEdit"
#include <QCompleter>
#include <QPrinter>

namespace Ui {
class Interface_Vente;
}

class Interface_Vente : public QWidget
{
    Q_OBJECT

public:
    explicit Interface_Vente(QWidget *parent = 0);
    ~Interface_Vente();
    void Afficher();

    void updateSuggestions(const QString &text);

    void fillDetails();

    void clearFields();

    void setupCompleter();

    void print(QPrinter *printer);

    void recalculateMontantTotal();

    void displaySaleDetails(const QString &codeV);

    void populateNomClientComboBox();




private slots:
    void on_AjouterPanier_pushButton_clicked();

    void on_Annuler_pushButton_clicked();

    void on_supprimer_pushButton_clicked();

    void on_ValiderFacture_pushButton_clicked();

    void on_code_produit_lineEdit_textChanged(const QString &arg1);

    void on_quantite_produit_spinBox_valueChanged(int arg1);

    void on_detailVente_tableView_clicked(const QModelIndex &index);

    void on_nomClient_comboBox_currentIndexChanged(const QString &arg1);

    void on_tableView_clicked(const QModelIndex &index);


    void on_nomClient_comboBox_currentTextChanged(const QString &arg1);

    void on_Imprimer_pushButton_clicked();

    void on_viderPanier_pushButton_clicked();

    void on_deconnexion_pushButton_clicked();

    void on_gestion_client_pushButton_clicked();

    void on_modifier_pushButton_clicked();

private:
    Ui::Interface_Vente *ui;
    QStandardItemModel *model;
    QModelIndex indextable;
    QTextEdit *text;
    QStandardItemModel *detailVente_tableView;
    QCompleter *completer;



    QString codePro, nomPro, typePro, caracteristique;
    int qte = 0;
    int surplus = 0;
    double prix = 0.00;
    double montant = 0.00;
    double montant_total = 0.00;
    QString codeV;
};

#endif // INTERFACE_VENTE_H
