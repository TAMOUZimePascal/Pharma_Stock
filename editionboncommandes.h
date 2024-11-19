#ifndef EDITIONBONCOMMANDES_H
#define EDITIONBONCOMMANDES_H

#include <QWidget>

#include "QMessageBox"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QCompleter>
#include <QPrinter>
#include <QStringListModel>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <QStyledItemDelegate>
#include <QPainter>
#include <iostream>

namespace Ui {
class editionBonCommandes;
}

class editionBonCommandes : public QWidget
{
    Q_OBJECT

public:
    explicit editionBonCommandes(QWidget *parent = 0);
    ~editionBonCommandes();

    void remplirCombobox();

    void currentDate();

    void genererEtAfficherNumeroCommande();

    void clearFields();


private slots:


    void on_fournisseur_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_modify_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_delete_pushButton_clicked();

    void on_valider_pushButton_clicked();

    void afficherDetailsCommande(const QModelIndex &current, const QModelIndex &previous);

    void updateSuggestions(const QString &text);

    void fillDetails();
    void print(QPrinter *printer);


    void on_prixUnitaire_doubleSpinBox_valueChanged(double arg1);

    void on_qte_spinBox_valueChanged(int arg1);

    void on_Accueil_clicked();

    void on_tresorerie_clicked();

    void on_rapport_statistique_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_print_pushButton_clicked();

private:
    Ui::editionBonCommandes *ui;
    QStandardItemModel *panierModel;
    int ligneEnCours;
    int ligneASupprimer;
    QTextEdit *text;

    QCompleter *completer;
    QStandardItemModel *commandeModel;

    void setupCommandeTableView();

    void afficherCommandes();

    void setupPanierModel();

     void setupCompleter();

};

#endif // EDITIONBONCOMMANDES_H
