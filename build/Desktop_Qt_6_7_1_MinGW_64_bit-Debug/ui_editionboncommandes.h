/********************************************************************************
** Form generated from reading UI file 'editionboncommandes.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITIONBONCOMMANDES_H
#define UI_EDITIONBONCOMMANDES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editionBonCommandes
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *Accueil;
    QPushButton *tresorerie;
    QPushButton *rapport_statistique;
    QSpacerItem *horizontalSpacer;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QFormLayout *formLayout_6;
    QLabel *label_17;
    QComboBox *fournisseur_comboBox;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *qte_spinBox;
    QLabel *label_3;
    QLineEdit *description_lineEdit;
    QLabel *label_4;
    QDoubleSpinBox *prixUnitaire_doubleSpinBox;
    QLabel *label_5;
    QDoubleSpinBox *total_doubleSpinBox;
    QLineEdit *codeproduit_lineEdit;
    QLabel *label_18;
    QDoubleSpinBox *nbrePieces_doubleSpinBox;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *modify_pushButton;
    QPushButton *pushButton_6;
    QTableView *tableView_2;
    QFormLayout *formLayout_4;
    QLineEdit *lineEdit_2;
    QPushButton *search_pushButton;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout_3;
    QLabel *label_11;
    QLabel *numeroCommandeLabel;
    QLabel *label_12;
    QLabel *DateLabel;
    QSpacerItem *verticalSpacer;
    QLabel *label_13;
    QLabel *NomFournisseurLabel;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *AdresseFournisseurLabel;
    QLabel *ContactFournisseurLabel;
    QSpacerItem *verticalSpacer_3;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *delete_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *valider_pushButton;
    QPushButton *print_pushButton;
    QPushButton *validerEtImprimer_pushButton;

    void setupUi(QWidget *editionBonCommandes)
    {
        if (editionBonCommandes->objectName().isEmpty())
            editionBonCommandes->setObjectName("editionBonCommandes");
        editionBonCommandes->resize(1157, 745);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/BonCommandes.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        editionBonCommandes->setWindowIcon(icon);
        editionBonCommandes->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
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
        gridLayout_3 = new QGridLayout(editionBonCommandes);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Accueil = new QPushButton(editionBonCommandes);
        Accueil->setObjectName("Accueil");
        Accueil->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        horizontalLayout->addWidget(Accueil);

        tresorerie = new QPushButton(editionBonCommandes);
        tresorerie->setObjectName("tresorerie");
        tresorerie->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        horizontalLayout->addWidget(tresorerie);

        rapport_statistique = new QPushButton(editionBonCommandes);
        rapport_statistique->setObjectName("rapport_statistique");
        rapport_statistique->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        horizontalLayout->addWidget(rapport_statistique);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(628, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_16 = new QLabel(editionBonCommandes);
        label_16->setObjectName("label_16");
        label_16->setStyleSheet(QString::fromUtf8("background-color: green;"));

        gridLayout_3->addWidget(label_16, 1, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_6 = new QLabel(editionBonCommandes);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName("formLayout_6");
        label_17 = new QLabel(editionBonCommandes);
        label_17->setObjectName("label_17");

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_17);

        fournisseur_comboBox = new QComboBox(editionBonCommandes);
        fournisseur_comboBox->setObjectName("fournisseur_comboBox");

        formLayout_6->setWidget(0, QFormLayout::FieldRole, fournisseur_comboBox);


        verticalLayout_3->addLayout(formLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(editionBonCommandes);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        qte_spinBox = new QSpinBox(editionBonCommandes);
        qte_spinBox->setObjectName("qte_spinBox");
        qte_spinBox->setMaximum(1000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, qte_spinBox);

        label_3 = new QLabel(editionBonCommandes);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        description_lineEdit = new QLineEdit(editionBonCommandes);
        description_lineEdit->setObjectName("description_lineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, description_lineEdit);

        label_4 = new QLabel(editionBonCommandes);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        prixUnitaire_doubleSpinBox = new QDoubleSpinBox(editionBonCommandes);
        prixUnitaire_doubleSpinBox->setObjectName("prixUnitaire_doubleSpinBox");
        prixUnitaire_doubleSpinBox->setMaximum(10000000000000000000000.000000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, prixUnitaire_doubleSpinBox);

        label_5 = new QLabel(editionBonCommandes);
        label_5->setObjectName("label_5");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        total_doubleSpinBox = new QDoubleSpinBox(editionBonCommandes);
        total_doubleSpinBox->setObjectName("total_doubleSpinBox");
        total_doubleSpinBox->setMaximum(999999999999999945575230987042816.000000000000000);

        formLayout->setWidget(7, QFormLayout::FieldRole, total_doubleSpinBox);

        codeproduit_lineEdit = new QLineEdit(editionBonCommandes);
        codeproduit_lineEdit->setObjectName("codeproduit_lineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, codeproduit_lineEdit);

        label_18 = new QLabel(editionBonCommandes);
        label_18->setObjectName("label_18");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_18);

        nbrePieces_doubleSpinBox = new QDoubleSpinBox(editionBonCommandes);
        nbrePieces_doubleSpinBox->setObjectName("nbrePieces_doubleSpinBox");
        nbrePieces_doubleSpinBox->setMaximum(9999.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, nbrePieces_doubleSpinBox);

        label_19 = new QLabel(editionBonCommandes);
        label_19->setObjectName("label_19");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_19);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_4 = new QPushButton(editionBonCommandes);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_2->addWidget(pushButton_4);

        modify_pushButton = new QPushButton(editionBonCommandes);
        modify_pushButton->setObjectName("modify_pushButton");
        modify_pushButton->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;"));

        horizontalLayout_2->addWidget(modify_pushButton);

        pushButton_6 = new QPushButton(editionBonCommandes);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        horizontalLayout_2->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        tableView_2 = new QTableView(editionBonCommandes);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setFrameShape(QFrame::WinPanel);
        tableView_2->setFrameShadow(QFrame::Plain);

        verticalLayout_3->addWidget(tableView_2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        lineEdit_2 = new QLineEdit(editionBonCommandes);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_2);

        search_pushButton = new QPushButton(editionBonCommandes);
        search_pushButton->setObjectName("search_pushButton");
        search_pushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, search_pushButton);


        verticalLayout_3->addLayout(formLayout_4);


        gridLayout_3->addLayout(verticalLayout_3, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_7 = new QLabel(editionBonCommandes);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_9 = new QLabel(editionBonCommandes);
        label_9->setObjectName("label_9");

        verticalLayout->addWidget(label_9);

        label_8 = new QLabel(editionBonCommandes);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        label = new QLabel(editionBonCommandes);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_10 = new QLabel(editionBonCommandes);
        label_10->setObjectName("label_10");

        verticalLayout->addWidget(label_10);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(128, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 2, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_11 = new QLabel(editionBonCommandes);
        label_11->setObjectName("label_11");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_11);

        numeroCommandeLabel = new QLabel(editionBonCommandes);
        numeroCommandeLabel->setObjectName("numeroCommandeLabel");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, numeroCommandeLabel);

        label_12 = new QLabel(editionBonCommandes);
        label_12->setObjectName("label_12");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_12);

        DateLabel = new QLabel(editionBonCommandes);
        DateLabel->setObjectName("DateLabel");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, DateLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_3->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        label_13 = new QLabel(editionBonCommandes);
        label_13->setObjectName("label_13");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_13);

        NomFournisseurLabel = new QLabel(editionBonCommandes);
        NomFournisseurLabel->setObjectName("NomFournisseurLabel");

        formLayout_3->setWidget(3, QFormLayout::FieldRole, NomFournisseurLabel);

        label_14 = new QLabel(editionBonCommandes);
        label_14->setObjectName("label_14");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(editionBonCommandes);
        label_15->setObjectName("label_15");

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_15);

        AdresseFournisseurLabel = new QLabel(editionBonCommandes);
        AdresseFournisseurLabel->setObjectName("AdresseFournisseurLabel");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, AdresseFournisseurLabel);

        ContactFournisseurLabel = new QLabel(editionBonCommandes);
        ContactFournisseurLabel->setObjectName("ContactFournisseurLabel");

        formLayout_3->setWidget(5, QFormLayout::FieldRole, ContactFournisseurLabel);


        gridLayout->addLayout(formLayout_3, 1, 2, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 88, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tableView = new QTableView(editionBonCommandes);
        tableView->setObjectName("tableView");

        gridLayout_2->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        delete_pushButton = new QPushButton(editionBonCommandes);
        delete_pushButton->setObjectName("delete_pushButton");
        delete_pushButton->setStyleSheet(QString::fromUtf8("background-color:red;\n"
"color:white;"));

        horizontalLayout_3->addWidget(delete_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        valider_pushButton = new QPushButton(editionBonCommandes);
        valider_pushButton->setObjectName("valider_pushButton");

        horizontalLayout_3->addWidget(valider_pushButton);

        print_pushButton = new QPushButton(editionBonCommandes);
        print_pushButton->setObjectName("print_pushButton");
        print_pushButton->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;"));

        horizontalLayout_3->addWidget(print_pushButton);

        validerEtImprimer_pushButton = new QPushButton(editionBonCommandes);
        validerEtImprimer_pushButton->setObjectName("validerEtImprimer_pushButton");
        validerEtImprimer_pushButton->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;"));

        horizontalLayout_3->addWidget(validerEtImprimer_pushButton);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 1, 1, 1);

        label_16->raise();

        retranslateUi(editionBonCommandes);

        QMetaObject::connectSlotsByName(editionBonCommandes);
    } // setupUi

    void retranslateUi(QWidget *editionBonCommandes)
    {
        editionBonCommandes->setWindowTitle(QCoreApplication::translate("editionBonCommandes", "Edition bon de commande", nullptr));
        Accueil->setText(QCoreApplication::translate("editionBonCommandes", "Acceuil", nullptr));
        tresorerie->setText(QCoreApplication::translate("editionBonCommandes", "Tr\303\251sorerie", nullptr));
        rapport_statistique->setText(QCoreApplication::translate("editionBonCommandes", "Rapport et statistique", nullptr));
        label_16->setText(QString());
        label_6->setText(QCoreApplication::translate("editionBonCommandes", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Edition  du bon de commande</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("editionBonCommandes", "Fournisseur", nullptr));
        label_2->setText(QCoreApplication::translate("editionBonCommandes", "Quantit\303\251", nullptr));
        label_3->setText(QCoreApplication::translate("editionBonCommandes", "Description", nullptr));
        label_4->setText(QCoreApplication::translate("editionBonCommandes", "Prix U.", nullptr));
        label_5->setText(QCoreApplication::translate("editionBonCommandes", "Total", nullptr));
        label_18->setText(QCoreApplication::translate("editionBonCommandes", "Code produit", nullptr));
        label_19->setText(QCoreApplication::translate("editionBonCommandes", "Nbre de Pi\303\250ces", nullptr));
        pushButton_4->setText(QCoreApplication::translate("editionBonCommandes", "Ajouter", nullptr));
        modify_pushButton->setText(QCoreApplication::translate("editionBonCommandes", "Modifier", nullptr));
        pushButton_6->setText(QCoreApplication::translate("editionBonCommandes", "Annuler", nullptr));
        search_pushButton->setText(QCoreApplication::translate("editionBonCommandes", "Rechercher", nullptr));
        label_7->setText(QCoreApplication::translate("editionBonCommandes", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; color:#00aa00;\">PharmaStock</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("editionBonCommandes", "Arafat", nullptr));
        label_8->setText(QCoreApplication::translate("editionBonCommandes", "118 Parakou", nullptr));
        label->setText(QCoreApplication::translate("editionBonCommandes", "+229 61359067", nullptr));
        label_10->setText(QCoreApplication::translate("editionBonCommandes", "pharmastock@gmail.fr", nullptr));
        label_11->setText(QCoreApplication::translate("editionBonCommandes", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Commande N\302\260 :</span></p></body></html>", nullptr));
        numeroCommandeLabel->setText(QCoreApplication::translate("editionBonCommandes", "00 XXX", nullptr));
        label_12->setText(QCoreApplication::translate("editionBonCommandes", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Date :</span></p></body></html>", nullptr));
        DateLabel->setText(QCoreApplication::translate("editionBonCommandes", "15/03/2024", nullptr));
        label_13->setText(QCoreApplication::translate("editionBonCommandes", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Fournisseur :</span></p></body></html>", nullptr));
        NomFournisseurLabel->setText(QCoreApplication::translate("editionBonCommandes", "Ninho Laboratoire", nullptr));
        label_14->setText(QCoreApplication::translate("editionBonCommandes", "Adresse", nullptr));
        label_15->setText(QCoreApplication::translate("editionBonCommandes", "Contact", nullptr));
        AdresseFournisseurLabel->setText(QCoreApplication::translate("editionBonCommandes", "USA", nullptr));
        ContactFournisseurLabel->setText(QCoreApplication::translate("editionBonCommandes", "+1 45\"689876689", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("editionBonCommandes", "Supprimer", nullptr));
        valider_pushButton->setText(QCoreApplication::translate("editionBonCommandes", "Valider", nullptr));
        print_pushButton->setText(QCoreApplication::translate("editionBonCommandes", "Imprimer", nullptr));
        validerEtImprimer_pushButton->setText(QCoreApplication::translate("editionBonCommandes", "Valider et imprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editionBonCommandes: public Ui_editionBonCommandes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITIONBONCOMMANDES_H
