/********************************************************************************
** Form generated from reading UI file 'approvisionnement.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPROVISIONNEMENT_H
#define UI_APPROVISIONNEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Approvisionnement
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *code_lineEdit;
    QLabel *label_5;
    QLineEdit *nom_lineEdit;
    QLabel *label_6;
    QLabel *label_8;
    QSpinBox *qte_spinBox;
    QLabel *label_10;
    QDateEdit *dateExpiration_dateEdit;
    QLabel *label_11;
    QDateEdit *dateApprovisionnement_dateEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ajouter_pushButton;
    QPushButton *annuler_pushButton;
    QPushButton *supprimer_pushButton;
    QPushButton *vider_pushButton;
    QLineEdit *typeProduit_lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *enregistrer_pushButton_2;
    QPushButton *imprime_pushButton;
    QPushButton *imprimeContenu_pushButton;
    QLabel *label_3;
    QTableView *tableView_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_10;
    QTableView *tableView;
    QLabel *label_7;
    QSplitter *splitter;
    QLabel *label_13;
    QPushButton *rechercher_pushButton;
    QLineEdit *rechercher_lineEdit;
    QPushButton *retour_pushButton;
    QSplitter *splitter_3;
    QLabel *label_12;
    QPushButton *deconnexion_pushButton;
    QSpacerItem *horizontalSpacer_11;

    void setupUi(QWidget *Approvisionnement)
    {
        if (Approvisionnement->objectName().isEmpty())
            Approvisionnement->setObjectName("Approvisionnement");
        Approvisionnement->resize(1204, 650);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/GestionStock.png"), QSize(), QIcon::Normal, QIcon::Off);
        Approvisionnement->setWindowIcon(icon);
        Approvisionnement->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
"QPushButton {\n"
"    background-color: none;  /* Vert */\n"
"    color:  #4CAF50;\n"
"    border: 2px solid #4CAF50;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:white;  /* Vert plus fonc\303\251 */\n"
"	   font-weight: bold;\n"
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
"/* Style pour les QDateEdit */\n"
"QDateEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style pour les QSpinBox */\n"
"QSpinBox {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
""
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
"}\n"
""));
        gridLayout = new QGridLayout(Approvisionnement);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(Approvisionnement);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color:#4CAF50;"));

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_4 = new QLabel(Approvisionnement);
        label_4->setObjectName("label_4");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        code_lineEdit = new QLineEdit(Approvisionnement);
        code_lineEdit->setObjectName("code_lineEdit");
        code_lineEdit->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, code_lineEdit);

        label_5 = new QLabel(Approvisionnement);
        label_5->setObjectName("label_5");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        nom_lineEdit = new QLineEdit(Approvisionnement);
        nom_lineEdit->setObjectName("nom_lineEdit");
        nom_lineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, nom_lineEdit);

        label_6 = new QLabel(Approvisionnement);
        label_6->setObjectName("label_6");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        label_8 = new QLabel(Approvisionnement);
        label_8->setObjectName("label_8");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        qte_spinBox = new QSpinBox(Approvisionnement);
        qte_spinBox->setObjectName("qte_spinBox");

        formLayout->setWidget(3, QFormLayout::FieldRole, qte_spinBox);

        label_10 = new QLabel(Approvisionnement);
        label_10->setObjectName("label_10");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        dateExpiration_dateEdit = new QDateEdit(Approvisionnement);
        dateExpiration_dateEdit->setObjectName("dateExpiration_dateEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, dateExpiration_dateEdit);

        label_11 = new QLabel(Approvisionnement);
        label_11->setObjectName("label_11");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_11);

        dateApprovisionnement_dateEdit = new QDateEdit(Approvisionnement);
        dateApprovisionnement_dateEdit->setObjectName("dateApprovisionnement_dateEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, dateApprovisionnement_dateEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ajouter_pushButton = new QPushButton(Approvisionnement);
        ajouter_pushButton->setObjectName("ajouter_pushButton");
        ajouter_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(ajouter_pushButton);

        annuler_pushButton = new QPushButton(Approvisionnement);
        annuler_pushButton->setObjectName("annuler_pushButton");
        annuler_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:none;\n"
"    color:;\n"
"}"));

        horizontalLayout_2->addWidget(annuler_pushButton);

        supprimer_pushButton = new QPushButton(Approvisionnement);
        supprimer_pushButton->setObjectName("supprimer_pushButton");
        supprimer_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:none;\n"
"    color:red;\n"
"}"));

        horizontalLayout_2->addWidget(supprimer_pushButton);

        vider_pushButton = new QPushButton(Approvisionnement);
        vider_pushButton->setObjectName("vider_pushButton");

        horizontalLayout_2->addWidget(vider_pushButton);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_2);

        typeProduit_lineEdit = new QLineEdit(Approvisionnement);
        typeProduit_lineEdit->setObjectName("typeProduit_lineEdit");
        typeProduit_lineEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, typeProduit_lineEdit);


        gridLayout->addLayout(formLayout, 3, 0, 2, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        enregistrer_pushButton_2 = new QPushButton(Approvisionnement);
        enregistrer_pushButton_2->setObjectName("enregistrer_pushButton_2");
        enregistrer_pushButton_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(enregistrer_pushButton_2);

        imprime_pushButton = new QPushButton(Approvisionnement);
        imprime_pushButton->setObjectName("imprime_pushButton");
        imprime_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(imprime_pushButton);

        imprimeContenu_pushButton = new QPushButton(Approvisionnement);
        imprimeContenu_pushButton->setObjectName("imprimeContenu_pushButton");
        imprimeContenu_pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(imprimeContenu_pushButton);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 4);

        label_3 = new QLabel(Approvisionnement);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 1, 1, 2);

        tableView_2 = new QTableView(Approvisionnement);
        tableView_2->setObjectName("tableView_2");

        gridLayout->addWidget(tableView_2, 7, 0, 1, 4);

        label = new QLabel(Approvisionnement);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color:#4CAF50;"));

        gridLayout->addWidget(label, 0, 0, 1, 4);

        horizontalSpacer_10 = new QSpacerItem(474, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 3, 1, 1);

        tableView = new QTableView(Approvisionnement);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 4, 2, 1, 2);

        label_7 = new QLabel(Approvisionnement);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        splitter = new QSplitter(Approvisionnement);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(splitter);
        label_13->setObjectName("label_13");
        splitter->addWidget(label_13);
        rechercher_pushButton = new QPushButton(splitter);
        rechercher_pushButton->setObjectName("rechercher_pushButton");
        rechercher_pushButton->setStyleSheet(QString::fromUtf8(""));
        splitter->addWidget(rechercher_pushButton);
        rechercher_lineEdit = new QLineEdit(splitter);
        rechercher_lineEdit->setObjectName("rechercher_lineEdit");
        splitter->addWidget(rechercher_lineEdit);
        retour_pushButton = new QPushButton(splitter);
        retour_pushButton->setObjectName("retour_pushButton");
        retour_pushButton->setStyleSheet(QString::fromUtf8(""));
        splitter->addWidget(retour_pushButton);

        gridLayout->addWidget(splitter, 6, 0, 1, 4);

        splitter_3 = new QSplitter(Approvisionnement);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(splitter_3);
        label_12->setObjectName("label_12");
        splitter_3->addWidget(label_12);
        deconnexion_pushButton = new QPushButton(splitter_3);
        deconnexion_pushButton->setObjectName("deconnexion_pushButton");
        deconnexion_pushButton->setStyleSheet(QString::fromUtf8("color: red;"));
        splitter_3->addWidget(deconnexion_pushButton);

        gridLayout->addWidget(splitter_3, 3, 2, 1, 2);

        horizontalSpacer_11 = new QSpacerItem(474, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 2, 0, 1, 1);


        retranslateUi(Approvisionnement);

        QMetaObject::connectSlotsByName(Approvisionnement);
    } // setupUi

    void retranslateUi(QWidget *Approvisionnement)
    {
        Approvisionnement->setWindowTitle(QCoreApplication::translate("Approvisionnement", "Gestion d'approvisionnement", nullptr));
        label_2->setText(QCoreApplication::translate("Approvisionnement", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">PharmaStock</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Approvisionnement", "Code Produit ", nullptr));
        label_5->setText(QCoreApplication::translate("Approvisionnement", "Nom du produit", nullptr));
        label_6->setText(QCoreApplication::translate("Approvisionnement", "Type du produit", nullptr));
        label_8->setText(QCoreApplication::translate("Approvisionnement", "Quantit\303\251", nullptr));
        label_10->setText(QCoreApplication::translate("Approvisionnement", "Date d'expiration", nullptr));
        label_11->setText(QCoreApplication::translate("Approvisionnement", "Date d'approvisionnement", nullptr));
        ajouter_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Ajouter au panier", nullptr));
        annuler_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Annuler ", nullptr));
        supprimer_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Supprimer du panier", nullptr));
        vider_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Vider le panier", nullptr));
        enregistrer_pushButton_2->setText(QCoreApplication::translate("Approvisionnement", "Enregistrer un approvisionnement", nullptr));
        imprime_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Imprimer  la liste des approvisionnements", nullptr));
        imprimeContenu_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Imprimer  le contenu d' approvisionnement", nullptr));
        label_3->setText(QCoreApplication::translate("Approvisionnement", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Gestion d'approvisionnement</span></p></body></html>", nullptr));
        label->setText(QString());
        label_7->setText(QString());
        label_13->setText(QCoreApplication::translate("Approvisionnement", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Nos approvisionnements</span></p></body></html>", nullptr));
        rechercher_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Rechercher un approvisionnement", nullptr));
        retour_pushButton->setText(QCoreApplication::translate("Approvisionnement", "Retour", nullptr));
        label_12->setText(QCoreApplication::translate("Approvisionnement", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Contenu du panier</span></p></body></html>", nullptr));
        deconnexion_pushButton->setText(QCoreApplication::translate("Approvisionnement", "D\303\251connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Approvisionnement: public Ui_Approvisionnement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPROVISIONNEMENT_H
