/********************************************************************************
** Form generated from reading UI file 'compta.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPTA_H
#define UI_COMPTA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Compta
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout_7;
    QGroupBox *formGroupBox_5;
    QFormLayout *formLayout_8;
    QLabel *label_23;
    QLineEdit *code_transaction_lineEdit;
    QLabel *label_24;
    QLabel *label_35;
    QComboBox *action_comboBox;
    QLabel *label_36;
    QLineEdit *motif_lineEdit;
    QLabel *label_37;
    QLineEdit *Depositaire_lineEdit;
    QComboBox *moyen_payement_comboBox;
    QLabel *label_38;
    QDoubleSpinBox *montant_doubleSpinBox;
    QLabel *label_39;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *enregistrer_pushButton_4;
    QPushButton *modifier_pushButton_4;
    QPushButton *supprimer_pushButton_4;
    QPushButton *annuler_pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *editer_facture_pushButton_5;
    QLabel *label_40;
    QLabel *sortie_label;
    QLabel *label_42;
    QLabel *entree_label;
    QLabel *label_41;
    QLabel *solde_label;
    QLabel *label_43;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QTableView *tableView_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QTableView *tableView;

    void setupUi(QWidget *Compta)
    {
        if (Compta->objectName().isEmpty())
            Compta->setObjectName("Compta");
        Compta->resize(1610, 776);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/comptabilite.png"), QSize(), QIcon::Normal, QIcon::Off);
        Compta->setWindowIcon(icon);
        Compta->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
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
"/* Style pour les QDateEdit */\n"
"QDateTimeEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QComboBox{\n"
" background-color: white;\n"
"    border: 1px solid #4CAF50;\n"
"    padding: 5px;\n"
"    border-radius: 5px;\n"
"    color: "
                        "black;\n"
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
"\n"
"\n"
"/*QTableView::item {\n"
"    border: 1px solid #4CAF50;\n"
"}*/\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgb(18, 40, 241);\n"
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
        gridLayout = new QGridLayout(Compta);
        gridLayout->setObjectName("gridLayout");
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName("formLayout_7");
        formGroupBox_5 = new QGroupBox(Compta);
        formGroupBox_5->setObjectName("formGroupBox_5");
        formGroupBox_5->setFlat(false);
        formGroupBox_5->setCheckable(true);
        formGroupBox_5->setChecked(true);
        formLayout_8 = new QFormLayout(formGroupBox_5);
        formLayout_8->setObjectName("formLayout_8");
        label_23 = new QLabel(formGroupBox_5);
        label_23->setObjectName("label_23");

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_23);

        code_transaction_lineEdit = new QLineEdit(formGroupBox_5);
        code_transaction_lineEdit->setObjectName("code_transaction_lineEdit");

        formLayout_8->setWidget(0, QFormLayout::FieldRole, code_transaction_lineEdit);

        label_24 = new QLabel(formGroupBox_5);
        label_24->setObjectName("label_24");

        formLayout_8->setWidget(1, QFormLayout::LabelRole, label_24);

        label_35 = new QLabel(formGroupBox_5);
        label_35->setObjectName("label_35");

        formLayout_8->setWidget(2, QFormLayout::LabelRole, label_35);

        action_comboBox = new QComboBox(formGroupBox_5);
        action_comboBox->addItem(QString());
        action_comboBox->addItem(QString());
        action_comboBox->setObjectName("action_comboBox");

        formLayout_8->setWidget(2, QFormLayout::FieldRole, action_comboBox);

        label_36 = new QLabel(formGroupBox_5);
        label_36->setObjectName("label_36");

        formLayout_8->setWidget(3, QFormLayout::LabelRole, label_36);

        motif_lineEdit = new QLineEdit(formGroupBox_5);
        motif_lineEdit->setObjectName("motif_lineEdit");

        formLayout_8->setWidget(3, QFormLayout::FieldRole, motif_lineEdit);

        label_37 = new QLabel(formGroupBox_5);
        label_37->setObjectName("label_37");

        formLayout_8->setWidget(4, QFormLayout::LabelRole, label_37);

        Depositaire_lineEdit = new QLineEdit(formGroupBox_5);
        Depositaire_lineEdit->setObjectName("Depositaire_lineEdit");

        formLayout_8->setWidget(4, QFormLayout::FieldRole, Depositaire_lineEdit);

        moyen_payement_comboBox = new QComboBox(formGroupBox_5);
        moyen_payement_comboBox->addItem(QString());
        moyen_payement_comboBox->addItem(QString());
        moyen_payement_comboBox->addItem(QString());
        moyen_payement_comboBox->addItem(QString());
        moyen_payement_comboBox->addItem(QString());
        moyen_payement_comboBox->setObjectName("moyen_payement_comboBox");

        formLayout_8->setWidget(5, QFormLayout::FieldRole, moyen_payement_comboBox);

        label_38 = new QLabel(formGroupBox_5);
        label_38->setObjectName("label_38");

        formLayout_8->setWidget(6, QFormLayout::LabelRole, label_38);

        montant_doubleSpinBox = new QDoubleSpinBox(formGroupBox_5);
        montant_doubleSpinBox->setObjectName("montant_doubleSpinBox");
        montant_doubleSpinBox->setMaximum(999999999999.989990234375000);

        formLayout_8->setWidget(6, QFormLayout::FieldRole, montant_doubleSpinBox);

        label_39 = new QLabel(formGroupBox_5);
        label_39->setObjectName("label_39");

        formLayout_8->setWidget(5, QFormLayout::LabelRole, label_39);

        dateTimeEdit = new QDateTimeEdit(formGroupBox_5);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setCalendarPopup(true);

        formLayout_8->setWidget(1, QFormLayout::FieldRole, dateTimeEdit);


        formLayout_7->setWidget(0, QFormLayout::SpanningRole, formGroupBox_5);

        enregistrer_pushButton_4 = new QPushButton(Compta);
        enregistrer_pushButton_4->setObjectName("enregistrer_pushButton_4");
        enregistrer_pushButton_4->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image projet/ajouter.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        enregistrer_pushButton_4->setIcon(icon1);

        formLayout_7->setWidget(1, QFormLayout::SpanningRole, enregistrer_pushButton_4);

        modifier_pushButton_4 = new QPushButton(Compta);
        modifier_pushButton_4->setObjectName("modifier_pushButton_4");
        modifier_pushButton_4->setStyleSheet(QString::fromUtf8("background-color:blue;"));

        formLayout_7->setWidget(2, QFormLayout::SpanningRole, modifier_pushButton_4);

        supprimer_pushButton_4 = new QPushButton(Compta);
        supprimer_pushButton_4->setObjectName("supprimer_pushButton_4");
        supprimer_pushButton_4->setStyleSheet(QString::fromUtf8("background-color:red;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image projet/supprimer.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_pushButton_4->setIcon(icon2);
        supprimer_pushButton_4->setIconSize(QSize(20, 20));

        formLayout_7->setWidget(4, QFormLayout::SpanningRole, supprimer_pushButton_4);

        annuler_pushButton_4 = new QPushButton(Compta);
        annuler_pushButton_4->setObjectName("annuler_pushButton_4");
        annuler_pushButton_4->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;"));

        formLayout_7->setWidget(5, QFormLayout::SpanningRole, annuler_pushButton_4);

        pushButton_6 = new QPushButton(Compta);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;"));

        formLayout_7->setWidget(6, QFormLayout::SpanningRole, pushButton_6);

        editer_facture_pushButton_5 = new QPushButton(Compta);
        editer_facture_pushButton_5->setObjectName("editer_facture_pushButton_5");
        editer_facture_pushButton_5->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;"));

        formLayout_7->setWidget(7, QFormLayout::SpanningRole, editer_facture_pushButton_5);

        label_40 = new QLabel(Compta);
        label_40->setObjectName("label_40");

        formLayout_7->setWidget(8, QFormLayout::LabelRole, label_40);

        sortie_label = new QLabel(Compta);
        sortie_label->setObjectName("sortie_label");
        sortie_label->setStyleSheet(QString::fromUtf8("color: red;"));

        formLayout_7->setWidget(8, QFormLayout::FieldRole, sortie_label);

        label_42 = new QLabel(Compta);
        label_42->setObjectName("label_42");

        formLayout_7->setWidget(9, QFormLayout::LabelRole, label_42);

        entree_label = new QLabel(Compta);
        entree_label->setObjectName("entree_label");
        entree_label->setStyleSheet(QString::fromUtf8("color: #4CAF50;"));

        formLayout_7->setWidget(9, QFormLayout::FieldRole, entree_label);

        label_41 = new QLabel(Compta);
        label_41->setObjectName("label_41");

        formLayout_7->setWidget(10, QFormLayout::LabelRole, label_41);

        solde_label = new QLabel(Compta);
        solde_label->setObjectName("solde_label");
        solde_label->setStyleSheet(QString::fromUtf8("color: blue;"));

        formLayout_7->setWidget(10, QFormLayout::FieldRole, solde_label);


        gridLayout->addLayout(formLayout_7, 1, 1, 2, 1);

        label_43 = new QLabel(Compta);
        label_43->setObjectName("label_43");
        label_43->setStyleSheet(QString::fromUtf8("background-color:green;"));

        gridLayout->addWidget(label_43, 0, 0, 1, 2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_4 = new QLabel(Compta);
        label_4->setObjectName("label_4");

        verticalLayout_8->addWidget(label_4);

        tableView_8 = new QTableView(Compta);
        tableView_8->setObjectName("tableView_8");
        tableView_8->setTextElideMode(Qt::ElideRight);
        tableView_8->setGridStyle(Qt::SolidLine);

        verticalLayout_8->addWidget(tableView_8);


        gridLayout->addLayout(verticalLayout_8, 2, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_3 = new QLabel(Compta);
        label_3->setObjectName("label_3");

        verticalLayout_7->addWidget(label_3);

        tableView = new QTableView(Compta);
        tableView->setObjectName("tableView");

        verticalLayout_7->addWidget(tableView);


        gridLayout->addLayout(verticalLayout_7, 1, 0, 1, 1);


        retranslateUi(Compta);

        QMetaObject::connectSlotsByName(Compta);
    } // setupUi

    void retranslateUi(QWidget *Compta)
    {
        Compta->setWindowTitle(QCoreApplication::translate("Compta", "PharmaStock - Tr\303\251sorerie", nullptr));
        formGroupBox_5->setTitle(QCoreApplication::translate("Compta", "Nouvelle transaction", nullptr));
        label_23->setText(QCoreApplication::translate("Compta", "Code transaction", nullptr));
        label_24->setText(QCoreApplication::translate("Compta", "Date", nullptr));
        label_35->setText(QCoreApplication::translate("Compta", "Action", nullptr));
        action_comboBox->setItemText(0, QCoreApplication::translate("Compta", "Encaissement", nullptr));
        action_comboBox->setItemText(1, QCoreApplication::translate("Compta", "D\303\251caissement", nullptr));

        label_36->setText(QCoreApplication::translate("Compta", "Motif", nullptr));
        label_37->setText(QCoreApplication::translate("Compta", "D\303\251positaire", nullptr));
        moyen_payement_comboBox->setItemText(0, QCoreApplication::translate("Compta", "Carte Bancaire", nullptr));
        moyen_payement_comboBox->setItemText(1, QCoreApplication::translate("Compta", "Esp\303\250ces", nullptr));
        moyen_payement_comboBox->setItemText(2, QCoreApplication::translate("Compta", "Ch\303\250que", nullptr));
        moyen_payement_comboBox->setItemText(3, QCoreApplication::translate("Compta", "D\303\251biteurs", nullptr));
        moyen_payement_comboBox->setItemText(4, QCoreApplication::translate("Compta", "Autres", nullptr));

        label_38->setText(QCoreApplication::translate("Compta", "Montant", nullptr));
        label_39->setText(QCoreApplication::translate("Compta", "Moyen de payement", nullptr));
        enregistrer_pushButton_4->setText(QCoreApplication::translate("Compta", "Enregistrer", nullptr));
        modifier_pushButton_4->setText(QCoreApplication::translate("Compta", "Modifier", nullptr));
        supprimer_pushButton_4->setText(QCoreApplication::translate("Compta", "Supprimer", nullptr));
        annuler_pushButton_4->setText(QCoreApplication::translate("Compta", "Annuler", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Compta", "Imprimer", nullptr));
        editer_facture_pushButton_5->setText(QCoreApplication::translate("Compta", "Accueil", nullptr));
        label_40->setText(QCoreApplication::translate("Compta", "TOTAL SORTIE     :", nullptr));
        sortie_label->setText(QString());
        label_42->setText(QCoreApplication::translate("Compta", "TOTAL ENTREE     :", nullptr));
        entree_label->setText(QString());
        label_41->setText(QCoreApplication::translate("Compta", "SOLDE                 :", nullptr));
        solde_label->setText(QString());
        label_43->setText(QString());
        label_4->setText(QCoreApplication::translate("Compta", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#0055ff;\">R\303\251capitulatif des mouvements de caisse </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Compta", "<html><head/><body><p><span style=\" font-weight:600; color:#0055ff;\">TABLEAU DE FLUX DE TRESORERIE</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Compta: public Ui_Compta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPTA_H
