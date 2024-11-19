/********************************************************************************
** Form generated from reading UI file 'interface_vente.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_VENTE_H
#define UI_INTERFACE_VENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface_Vente
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *gestion_client_pushButton;
    QPushButton *commande_non_satistfaite_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *deconnexion_pushButton;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *code_produit_lineEdit;
    QLabel *label_4;
    QLineEdit *nom_produit_lineEdit;
    QLabel *label_5;
    QLineEdit *type_produit_lineEdit;
    QLabel *label_6;
    QDoubleSpinBox *prix_unitaire_doubleSpinBox;
    QLabel *label_7;
    QSpinBox *quantite_produit_spinBox;
    QLabel *label_8;
    QDoubleSpinBox *montant_doubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AjouterPanier_pushButton;
    QPushButton *Annuler_pushButton;
    QPushButton *supprimer_pushButton;
    QPushButton *viderPanier_pushButton;
    QFormLayout *formLayout_3;
    QLabel *label_15;
    QLabel *label_9;
    QLineEdit *numero_facture_lineEdit;
    QLabel *label_11;
    QDateEdit *date_courante_dateEdit;
    QLabel *label_10;
    QComboBox *nomClient_comboBox;
    QLabel *label_12;
    QLineEdit *contact_lineEdit;
    QLabel *label_16;
    QLineEdit *adresse_lineEdit;
    QLabel *label_3;
    QComboBox *statut_comboBox;
    QTableView *detailVente_tableView;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QDoubleSpinBox *montant_total_doubleSpinBox;
    QPushButton *ValiderFacture_pushButton;
    QPushButton *Imprimer_pushButton;
    QPushButton *modifier_pushButton;
    QLabel *label_14;
    QTableView *tableView;

    void setupUi(QWidget *Interface_Vente)
    {
        if (Interface_Vente->objectName().isEmpty())
            Interface_Vente->setObjectName("Interface_Vente");
        Interface_Vente->resize(1213, 655);
        Interface_Vente->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: #4CAF50;  /* Vert */\n"
"    color: white;\n"
"    border: 2px solid #4CAF50;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"	font-weight: bold;\n"
"	font-size: 15px\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;  /* Vert plus fonc\303\251 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;  /* Vert encore plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Style pour les QLineEdit */\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QComboBox{\n"
"	background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style pour les QDateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: blac"
                        "k;\n"
"}\n"
"\n"
"/* Style pour les QSpinBox */\n"
"QSpinBox {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style pour les QDoubleSpinBox */\n"
"QDoubleSpinBox {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style pour le QTableView */\n"
"QTableView {\n"
"    background-color: white;\n"
"    gridline-color: #4CAF50;\n"
"    border: 1px solid #4CAF50;\n"
"	color:black;\n"
"\n"
"}\n"
"QTableView:pressed {\n"
"	bacground-color:rgb(188, 188, 188);\n"
"	 gridline-color: #4CAF50;\n"
"    border: 1px solid #4CAF50;\n"
"	color:black;\n"
"}\n"
"\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    padding: 4px;\n"
"    border: 1px solid #4CAF50;\n"
"}\n"
"\n"
"/* Style pour les QLabel */\n"
"QLabel {\n"
"    color: black;\n"
"    font-weight: bold;\n"
"}"
                        "\n"
""));
        gridLayout = new QGridLayout(Interface_Vente);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        gestion_client_pushButton = new QPushButton(Interface_Vente);
        gestion_client_pushButton->setObjectName("gestion_client_pushButton");

        horizontalLayout->addWidget(gestion_client_pushButton);

        commande_non_satistfaite_pushButton = new QPushButton(Interface_Vente);
        commande_non_satistfaite_pushButton->setObjectName("commande_non_satistfaite_pushButton");

        horizontalLayout->addWidget(commande_non_satistfaite_pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        deconnexion_pushButton = new QPushButton(Interface_Vente);
        deconnexion_pushButton->setObjectName("deconnexion_pushButton");
        deconnexion_pushButton->setStyleSheet(QString::fromUtf8("QPushButton{	\n"
"background-color: white;  /* Vert */\n"
"    color: red;\n"
"    border: 1px solid red;\n"
"    border-radius: 0px;\n"
"    padding: 5px;\n"
"	font-weight: bold;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: red;  /* Vert plus fonc\303\251 */\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(179, 33, 20) ;/* Vert encore plus fonc\303\251 */\n"
"	color: white; \n"
"}"));

        horizontalLayout->addWidget(deconnexion_pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        label = new QLabel(Interface_Vente);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(Interface_Vente);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        code_produit_lineEdit = new QLineEdit(Interface_Vente);
        code_produit_lineEdit->setObjectName("code_produit_lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, code_produit_lineEdit);

        label_4 = new QLabel(Interface_Vente);
        label_4->setObjectName("label_4");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        nom_produit_lineEdit = new QLineEdit(Interface_Vente);
        nom_produit_lineEdit->setObjectName("nom_produit_lineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, nom_produit_lineEdit);

        label_5 = new QLabel(Interface_Vente);
        label_5->setObjectName("label_5");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        type_produit_lineEdit = new QLineEdit(Interface_Vente);
        type_produit_lineEdit->setObjectName("type_produit_lineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, type_produit_lineEdit);

        label_6 = new QLabel(Interface_Vente);
        label_6->setObjectName("label_6");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        prix_unitaire_doubleSpinBox = new QDoubleSpinBox(Interface_Vente);
        prix_unitaire_doubleSpinBox->setObjectName("prix_unitaire_doubleSpinBox");
        prix_unitaire_doubleSpinBox->setMaximum(1000000000000000000.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, prix_unitaire_doubleSpinBox);

        label_7 = new QLabel(Interface_Vente);
        label_7->setObjectName("label_7");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        quantite_produit_spinBox = new QSpinBox(Interface_Vente);
        quantite_produit_spinBox->setObjectName("quantite_produit_spinBox");
        quantite_produit_spinBox->setMaximum(1000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, quantite_produit_spinBox);

        label_8 = new QLabel(Interface_Vente);
        label_8->setObjectName("label_8");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        montant_doubleSpinBox = new QDoubleSpinBox(Interface_Vente);
        montant_doubleSpinBox->setObjectName("montant_doubleSpinBox");
        montant_doubleSpinBox->setReadOnly(true);
        montant_doubleSpinBox->setMaximum(99999999999999991433150857216.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, montant_doubleSpinBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AjouterPanier_pushButton = new QPushButton(Interface_Vente);
        AjouterPanier_pushButton->setObjectName("AjouterPanier_pushButton");

        horizontalLayout_3->addWidget(AjouterPanier_pushButton);

        Annuler_pushButton = new QPushButton(Interface_Vente);
        Annuler_pushButton->setObjectName("Annuler_pushButton");

        horizontalLayout_3->addWidget(Annuler_pushButton);

        supprimer_pushButton = new QPushButton(Interface_Vente);
        supprimer_pushButton->setObjectName("supprimer_pushButton");

        horizontalLayout_3->addWidget(supprimer_pushButton);

        viderPanier_pushButton = new QPushButton(Interface_Vente);
        viderPanier_pushButton->setObjectName("viderPanier_pushButton");

        horizontalLayout_3->addWidget(viderPanier_pushButton);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_3);


        gridLayout->addLayout(formLayout, 2, 0, 2, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName("formLayout_3");
        label_15 = new QLabel(Interface_Vente);
        label_15->setObjectName("label_15");

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, label_15);

        label_9 = new QLabel(Interface_Vente);
        label_9->setObjectName("label_9");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_9);

        numero_facture_lineEdit = new QLineEdit(Interface_Vente);
        numero_facture_lineEdit->setObjectName("numero_facture_lineEdit");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, numero_facture_lineEdit);

        label_11 = new QLabel(Interface_Vente);
        label_11->setObjectName("label_11");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        date_courante_dateEdit = new QDateEdit(Interface_Vente);
        date_courante_dateEdit->setObjectName("date_courante_dateEdit");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, date_courante_dateEdit);

        label_10 = new QLabel(Interface_Vente);
        label_10->setObjectName("label_10");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_10);

        nomClient_comboBox = new QComboBox(Interface_Vente);
        nomClient_comboBox->setObjectName("nomClient_comboBox");

        formLayout_3->setWidget(3, QFormLayout::FieldRole, nomClient_comboBox);

        label_12 = new QLabel(Interface_Vente);
        label_12->setObjectName("label_12");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_12);

        contact_lineEdit = new QLineEdit(Interface_Vente);
        contact_lineEdit->setObjectName("contact_lineEdit");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, contact_lineEdit);

        label_16 = new QLabel(Interface_Vente);
        label_16->setObjectName("label_16");

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_16);

        adresse_lineEdit = new QLineEdit(Interface_Vente);
        adresse_lineEdit->setObjectName("adresse_lineEdit");

        formLayout_3->setWidget(5, QFormLayout::FieldRole, adresse_lineEdit);

        label_3 = new QLabel(Interface_Vente);
        label_3->setObjectName("label_3");

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_3);

        statut_comboBox = new QComboBox(Interface_Vente);
        statut_comboBox->addItem(QString());
        statut_comboBox->addItem(QString());
        statut_comboBox->setObjectName("statut_comboBox");

        formLayout_3->setWidget(6, QFormLayout::FieldRole, statut_comboBox);


        gridLayout->addLayout(formLayout_3, 2, 1, 1, 1);

        detailVente_tableView = new QTableView(Interface_Vente);
        detailVente_tableView->setObjectName("detailVente_tableView");

        gridLayout->addWidget(detailVente_tableView, 3, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_13 = new QLabel(Interface_Vente);
        label_13->setObjectName("label_13");

        horizontalLayout_4->addWidget(label_13);

        montant_total_doubleSpinBox = new QDoubleSpinBox(Interface_Vente);
        montant_total_doubleSpinBox->setObjectName("montant_total_doubleSpinBox");
        montant_total_doubleSpinBox->setMaximum(9999999999999999583119736832.000000000000000);

        horizontalLayout_4->addWidget(montant_total_doubleSpinBox);

        ValiderFacture_pushButton = new QPushButton(Interface_Vente);
        ValiderFacture_pushButton->setObjectName("ValiderFacture_pushButton");

        horizontalLayout_4->addWidget(ValiderFacture_pushButton);

        Imprimer_pushButton = new QPushButton(Interface_Vente);
        Imprimer_pushButton->setObjectName("Imprimer_pushButton");

        horizontalLayout_4->addWidget(Imprimer_pushButton);

        modifier_pushButton = new QPushButton(Interface_Vente);
        modifier_pushButton->setObjectName("modifier_pushButton");

        horizontalLayout_4->addWidget(modifier_pushButton);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 2);

        label_14 = new QLabel(Interface_Vente);
        label_14->setObjectName("label_14");

        gridLayout->addWidget(label_14, 5, 0, 1, 2);

        tableView = new QTableView(Interface_Vente);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 6, 0, 1, 2);


        retranslateUi(Interface_Vente);

        QMetaObject::connectSlotsByName(Interface_Vente);
    } // setupUi

    void retranslateUi(QWidget *Interface_Vente)
    {
        Interface_Vente->setWindowTitle(QCoreApplication::translate("Interface_Vente", "Interface_Vente", nullptr));
        gestion_client_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Gestion des clients ", nullptr));
        commande_non_satistfaite_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Gestion des commandes non satisfaites", nullptr));
        deconnexion_pushButton->setText(QCoreApplication::translate("Interface_Vente", "D\303\251connexion", nullptr));
        label->setText(QCoreApplication::translate("Interface_Vente", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#55ff00;\">Enregistrement des ventes</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Interface_Vente", "Code du produit", nullptr));
        label_4->setText(QCoreApplication::translate("Interface_Vente", "Nom du produit", nullptr));
        label_5->setText(QCoreApplication::translate("Interface_Vente", "Type de produit", nullptr));
        label_6->setText(QCoreApplication::translate("Interface_Vente", "Prix unitaire", nullptr));
        label_7->setText(QCoreApplication::translate("Interface_Vente", "Quantit\303\251 du produit", nullptr));
        label_8->setText(QCoreApplication::translate("Interface_Vente", "Montant", nullptr));
        AjouterPanier_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Ajouter au papier", nullptr));
        Annuler_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Annuler", nullptr));
        supprimer_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Supprimer", nullptr));
        viderPanier_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Vider le panier", nullptr));
        label_15->setText(QCoreApplication::translate("Interface_Vente", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Facturation</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("Interface_Vente", "Num\303\251ro de la facture", nullptr));
        label_11->setText(QCoreApplication::translate("Interface_Vente", "Date", nullptr));
        label_10->setText(QCoreApplication::translate("Interface_Vente", "Nom du client", nullptr));
        label_12->setText(QCoreApplication::translate("Interface_Vente", "Conctate du client ", nullptr));
        label_16->setText(QCoreApplication::translate("Interface_Vente", "Adresse du client", nullptr));
        label_3->setText(QCoreApplication::translate("Interface_Vente", "Statut de la vente", nullptr));
        statut_comboBox->setItemText(0, QCoreApplication::translate("Interface_Vente", "Satisfait", nullptr));
        statut_comboBox->setItemText(1, QCoreApplication::translate("Interface_Vente", "Non satisfait", nullptr));

        label_13->setText(QCoreApplication::translate("Interface_Vente", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Montant total de la facture</span></p></body></html>", nullptr));
        ValiderFacture_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Enregistrer la vente", nullptr));
        Imprimer_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Imprimer facture", nullptr));
        modifier_pushButton->setText(QCoreApplication::translate("Interface_Vente", "Actualiser", nullptr));
        label_14->setText(QCoreApplication::translate("Interface_Vente", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Liste des commandes satisfaites</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface_Vente: public Ui_Interface_Vente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_VENTE_H
