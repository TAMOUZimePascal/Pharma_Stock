/********************************************************************************
** Form generated from reading UI file 'enregistrer_fournisseur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENREGISTRER_FOURNISSEUR_H
#define UI_ENREGISTRER_FOURNISSEUR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Enregistrer_Fournisseur
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *accueil_pushButton;
    QPushButton *Suprimer_pushButton;
    QPushButton *Imprimer_pushButton;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *Nom_fournisseurs_lineEdit;
    QLabel *label_3;
    QLineEdit *Contact_fournisseurs_lineEdit;
    QLabel *label_4;
    QLineEdit *Adresse_electronique_fournisseurs_lineEdit;
    QLabel *label_5;
    QLineEdit *Adresse_fournisseurs_lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *Enregistrer_pushButton;
    QPushButton *Modifier_pushButton;
    QPushButton *AnnulerpushButton;
    QLabel *label_7;
    QLineEdit *code_fournisseur;
    QLabel *label_6;

    void setupUi(QWidget *Enregistrer_Fournisseur)
    {
        if (Enregistrer_Fournisseur->objectName().isEmpty())
            Enregistrer_Fournisseur->setObjectName("Enregistrer_Fournisseur");
        Enregistrer_Fournisseur->resize(1121, 836);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Fournisseurs.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Enregistrer_Fournisseur->setWindowIcon(icon);
        Enregistrer_Fournisseur->setStyleSheet(QString::fromUtf8("QWidget {\n"
"  font-family: Arial, sans-serif;\n"
"\n"
"}\n"
"\n"
"/* Style pour les QPushButton */\n"
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
""
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
""
                        "QLabel {\n"
"    color: black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        gridLayout_2 = new QGridLayout(Enregistrer_Fournisseur);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        tableView = new QTableView(Enregistrer_Fournisseur);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        accueil_pushButton = new QPushButton(Enregistrer_Fournisseur);
        accueil_pushButton->setObjectName("accueil_pushButton");

        horizontalLayout_2->addWidget(accueil_pushButton);

        Suprimer_pushButton = new QPushButton(Enregistrer_Fournisseur);
        Suprimer_pushButton->setObjectName("Suprimer_pushButton");
        Suprimer_pushButton->setStyleSheet(QString::fromUtf8("background-color:red;\n"
"color: white;"));

        horizontalLayout_2->addWidget(Suprimer_pushButton);

        Imprimer_pushButton = new QPushButton(Enregistrer_Fournisseur);
        Imprimer_pushButton->setObjectName("Imprimer_pushButton");
        Imprimer_pushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        horizontalLayout_2->addWidget(Imprimer_pushButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        label = new QLabel(Enregistrer_Fournisseur);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(Enregistrer_Fournisseur);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Nom_fournisseurs_lineEdit = new QLineEdit(Enregistrer_Fournisseur);
        Nom_fournisseurs_lineEdit->setObjectName("Nom_fournisseurs_lineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, Nom_fournisseurs_lineEdit);

        label_3 = new QLabel(Enregistrer_Fournisseur);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        Contact_fournisseurs_lineEdit = new QLineEdit(Enregistrer_Fournisseur);
        Contact_fournisseurs_lineEdit->setObjectName("Contact_fournisseurs_lineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, Contact_fournisseurs_lineEdit);

        label_4 = new QLabel(Enregistrer_Fournisseur);
        label_4->setObjectName("label_4");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        Adresse_electronique_fournisseurs_lineEdit = new QLineEdit(Enregistrer_Fournisseur);
        Adresse_electronique_fournisseurs_lineEdit->setObjectName("Adresse_electronique_fournisseurs_lineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, Adresse_electronique_fournisseurs_lineEdit);

        label_5 = new QLabel(Enregistrer_Fournisseur);
        label_5->setObjectName("label_5");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        Adresse_fournisseurs_lineEdit = new QLineEdit(Enregistrer_Fournisseur);
        Adresse_fournisseurs_lineEdit->setObjectName("Adresse_fournisseurs_lineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, Adresse_fournisseurs_lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Enregistrer_pushButton = new QPushButton(Enregistrer_Fournisseur);
        Enregistrer_pushButton->setObjectName("Enregistrer_pushButton");

        horizontalLayout->addWidget(Enregistrer_pushButton);

        Modifier_pushButton = new QPushButton(Enregistrer_Fournisseur);
        Modifier_pushButton->setObjectName("Modifier_pushButton");
        Modifier_pushButton->setStyleSheet(QString::fromUtf8("background-color:blue;\n"
"color:white;"));

        horizontalLayout->addWidget(Modifier_pushButton);

        AnnulerpushButton = new QPushButton(Enregistrer_Fournisseur);
        AnnulerpushButton->setObjectName("AnnulerpushButton");
        AnnulerpushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        horizontalLayout->addWidget(AnnulerpushButton);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout);

        label_7 = new QLabel(Enregistrer_Fournisseur);
        label_7->setObjectName("label_7");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        code_fournisseur = new QLineEdit(Enregistrer_Fournisseur);
        code_fournisseur->setObjectName("code_fournisseur");
        code_fournisseur->setReadOnly(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, code_fournisseur);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);

        label_6 = new QLabel(Enregistrer_Fournisseur);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Enregistrer_Fournisseur);

        QMetaObject::connectSlotsByName(Enregistrer_Fournisseur);
    } // setupUi

    void retranslateUi(QWidget *Enregistrer_Fournisseur)
    {
        Enregistrer_Fournisseur->setWindowTitle(QCoreApplication::translate("Enregistrer_Fournisseur", "PharmaStock - Gestion des fournisseurs", nullptr));
        accueil_pushButton->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Accueil", nullptr));
        Suprimer_pushButton->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Suprimer", nullptr));
        Imprimer_pushButton->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Imprimer", nullptr));
        label->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600;\">Enregistrement des fournisseurs</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Nom ", nullptr));
        label_3->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Contact", nullptr));
        label_4->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Adresse \303\251lectronique", nullptr));
        label_5->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Adresse", nullptr));
        Enregistrer_pushButton->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Enregistrer", nullptr));
        Modifier_pushButton->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Modifier", nullptr));
        AnnulerpushButton->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Annuler", nullptr));
        label_7->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "Code", nullptr));
        label_6->setText(QCoreApplication::translate("Enregistrer_Fournisseur", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Liste des fournisseurs</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Enregistrer_Fournisseur: public Ui_Enregistrer_Fournisseur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRER_FOURNISSEUR_H
