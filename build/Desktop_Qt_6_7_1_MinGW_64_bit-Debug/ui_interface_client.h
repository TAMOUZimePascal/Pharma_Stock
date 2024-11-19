/********************************************************************************
** Form generated from reading UI file 'interface_client.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_CLIENT_H
#define UI_INTERFACE_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface_client
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *Nom_client_lineEdit;
    QLabel *label_3;
    QLineEdit *Contact_client_lineEdit;
    QLabel *label_4;
    QLineEdit *Adresse_electronique_client_lineEdit;
    QLabel *label_5;
    QLineEdit *Adresse_client_lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *Enregistrer_pushButton;
    QPushButton *Modifier_pushButton;
    QPushButton *AnnulerpushButton;
    QLabel *label_6;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QLineEdit *code_client;
    QPushButton *Rechercher_pushButton;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Suprimer_pushButton;
    QPushButton *Imprimer_pushButton;

    void setupUi(QWidget *interface_client)
    {
        if (interface_client->objectName().isEmpty())
            interface_client->setObjectName("interface_client");
        interface_client->resize(1189, 969);
        interface_client->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
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
"    color:black;\n"
"    font-weight: bold;\n"
"}\n"
""));
        gridLayout = new QGridLayout(interface_client);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_2 = new QPushButton(interface_client);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(interface_client);
        pushButton->setObjectName("pushButton");

        horizontalLayout_3->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        lineEdit = new QLineEdit(interface_client);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:green;"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label = new QLabel(interface_client);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_2 = new QLabel(interface_client);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Nom_client_lineEdit = new QLineEdit(interface_client);
        Nom_client_lineEdit->setObjectName("Nom_client_lineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, Nom_client_lineEdit);

        label_3 = new QLabel(interface_client);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        Contact_client_lineEdit = new QLineEdit(interface_client);
        Contact_client_lineEdit->setObjectName("Contact_client_lineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, Contact_client_lineEdit);

        label_4 = new QLabel(interface_client);
        label_4->setObjectName("label_4");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        Adresse_electronique_client_lineEdit = new QLineEdit(interface_client);
        Adresse_electronique_client_lineEdit->setObjectName("Adresse_electronique_client_lineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, Adresse_electronique_client_lineEdit);

        label_5 = new QLabel(interface_client);
        label_5->setObjectName("label_5");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        Adresse_client_lineEdit = new QLineEdit(interface_client);
        Adresse_client_lineEdit->setObjectName("Adresse_client_lineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, Adresse_client_lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Enregistrer_pushButton = new QPushButton(interface_client);
        Enregistrer_pushButton->setObjectName("Enregistrer_pushButton");

        horizontalLayout->addWidget(Enregistrer_pushButton);

        Modifier_pushButton = new QPushButton(interface_client);
        Modifier_pushButton->setObjectName("Modifier_pushButton");
        Modifier_pushButton->setStyleSheet(QString::fromUtf8("background-color: blue;"));

        horizontalLayout->addWidget(Modifier_pushButton);

        AnnulerpushButton = new QPushButton(interface_client);
        AnnulerpushButton->setObjectName("AnnulerpushButton");
        AnnulerpushButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: green;"));

        horizontalLayout->addWidget(AnnulerpushButton);


        formLayout->setLayout(7, QFormLayout::FieldRole, horizontalLayout);


        gridLayout->addLayout(formLayout, 3, 0, 1, 1);

        label_6 = new QLabel(interface_client);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_7 = new QLabel(interface_client);
        label_7->setObjectName("label_7");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        code_client = new QLineEdit(interface_client);
        code_client->setObjectName("code_client");
        code_client->setReadOnly(false);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, code_client);

        Rechercher_pushButton = new QPushButton(interface_client);
        Rechercher_pushButton->setObjectName("Rechercher_pushButton");
        Rechercher_pushButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: green;"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, Rechercher_pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        formLayout_3->setItem(2, QFormLayout::LabelRole, horizontalSpacer);


        gridLayout->addLayout(formLayout_3, 5, 0, 1, 1);

        tableView = new QTableView(interface_client);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Suprimer_pushButton = new QPushButton(interface_client);
        Suprimer_pushButton->setObjectName("Suprimer_pushButton");
        Suprimer_pushButton->setStyleSheet(QString::fromUtf8("background-color: red;\n"
"color: white;"));

        horizontalLayout_2->addWidget(Suprimer_pushButton);

        Imprimer_pushButton = new QPushButton(interface_client);
        Imprimer_pushButton->setObjectName("Imprimer_pushButton");
        Imprimer_pushButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: green;"));

        horizontalLayout_2->addWidget(Imprimer_pushButton);


        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 1);


        retranslateUi(interface_client);

        QMetaObject::connectSlotsByName(interface_client);
    } // setupUi

    void retranslateUi(QWidget *interface_client)
    {
        interface_client->setWindowTitle(QCoreApplication::translate("interface_client", "Gestion des clients", nullptr));
        pushButton_2->setText(QCoreApplication::translate("interface_client", "Effectuer une vente", nullptr));
        pushButton->setText(QCoreApplication::translate("interface_client", "Deconnexion", nullptr));
        label->setText(QCoreApplication::translate("interface_client", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:600;\">Enregistrement des clients</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("interface_client", "Nom ", nullptr));
        label_3->setText(QCoreApplication::translate("interface_client", "contact", nullptr));
        label_4->setText(QCoreApplication::translate("interface_client", "Adresse \303\251lectronique", nullptr));
        label_5->setText(QCoreApplication::translate("interface_client", "Adresse", nullptr));
        Enregistrer_pushButton->setText(QCoreApplication::translate("interface_client", "Enregistrer", nullptr));
        Modifier_pushButton->setText(QCoreApplication::translate("interface_client", "Modifier", nullptr));
        AnnulerpushButton->setText(QCoreApplication::translate("interface_client", "Annuler", nullptr));
        label_6->setText(QCoreApplication::translate("interface_client", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Liste des clients</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("interface_client", "Code", nullptr));
        Rechercher_pushButton->setText(QCoreApplication::translate("interface_client", "Rechercher", nullptr));
        Suprimer_pushButton->setText(QCoreApplication::translate("interface_client", "Suprimer", nullptr));
        Imprimer_pushButton->setText(QCoreApplication::translate("interface_client", "Imprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface_client: public Ui_interface_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_CLIENT_H
