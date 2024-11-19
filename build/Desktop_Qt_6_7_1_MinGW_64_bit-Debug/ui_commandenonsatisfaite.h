/********************************************************************************
** Form generated from reading UI file 'commandenonsatisfaite.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDENONSATISFAITE_H
#define UI_COMMANDENONSATISFAITE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandeNonSatisfaite
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QSplitter *splitter_2;
    QPushButton *modifier_pushButton;
    QPushButton *pushButton;
    QSplitter *splitter_3;
    QLabel *label_4;
    QLineEdit *rechercher_lineEdit;
    QLabel *label_5;
    QLineEdit *codeProduit_lineEdit;
    QLabel *label_6;
    QSpinBox *qte_spinBox;
    QLabel *label;
    QTableView *tableView_2;
    QSplitter *splitter;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *CommandeNonSatisfaite)
    {
        if (CommandeNonSatisfaite->objectName().isEmpty())
            CommandeNonSatisfaite->setObjectName("CommandeNonSatisfaite");
        CommandeNonSatisfaite->resize(1279, 495);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Commande.png"), QSize(), QIcon::Normal, QIcon::Off);
        CommandeNonSatisfaite->setWindowIcon(icon);
        CommandeNonSatisfaite->setStyleSheet(QString::fromUtf8("/* Style pour les QPushButton */\n"
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
        gridLayout = new QGridLayout(CommandeNonSatisfaite);
        gridLayout->setObjectName("gridLayout");
        tableView = new QTableView(CommandeNonSatisfaite);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 3, 0, 1, 1);

        splitter_2 = new QSplitter(CommandeNonSatisfaite);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        modifier_pushButton = new QPushButton(splitter_2);
        modifier_pushButton->setObjectName("modifier_pushButton");
        splitter_2->addWidget(modifier_pushButton);
        pushButton = new QPushButton(splitter_2);
        pushButton->setObjectName("pushButton");
        splitter_2->addWidget(pushButton);

        gridLayout->addWidget(splitter_2, 1, 2, 1, 1);

        splitter_3 = new QSplitter(CommandeNonSatisfaite);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_3);
        label_4->setObjectName("label_4");
        splitter_3->addWidget(label_4);
        rechercher_lineEdit = new QLineEdit(splitter_3);
        rechercher_lineEdit->setObjectName("rechercher_lineEdit");
        splitter_3->addWidget(rechercher_lineEdit);
        label_5 = new QLabel(splitter_3);
        label_5->setObjectName("label_5");
        splitter_3->addWidget(label_5);
        codeProduit_lineEdit = new QLineEdit(splitter_3);
        codeProduit_lineEdit->setObjectName("codeProduit_lineEdit");
        splitter_3->addWidget(codeProduit_lineEdit);
        label_6 = new QLabel(splitter_3);
        label_6->setObjectName("label_6");
        splitter_3->addWidget(label_6);
        qte_spinBox = new QSpinBox(splitter_3);
        qte_spinBox->setObjectName("qte_spinBox");
        splitter_3->addWidget(qte_spinBox);

        gridLayout->addWidget(splitter_3, 1, 0, 1, 2);

        label = new QLabel(CommandeNonSatisfaite);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 3);

        tableView_2 = new QTableView(CommandeNonSatisfaite);
        tableView_2->setObjectName("tableView_2");

        gridLayout->addWidget(tableView_2, 3, 1, 1, 2);

        splitter = new QSplitter(CommandeNonSatisfaite);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName("label_2");
        splitter->addWidget(label_2);
        label_3 = new QLabel(splitter);
        label_3->setObjectName("label_3");
        splitter->addWidget(label_3);

        gridLayout->addWidget(splitter, 2, 0, 1, 3);


        retranslateUi(CommandeNonSatisfaite);

        QMetaObject::connectSlotsByName(CommandeNonSatisfaite);
    } // setupUi

    void retranslateUi(QWidget *CommandeNonSatisfaite)
    {
        CommandeNonSatisfaite->setWindowTitle(QCoreApplication::translate("CommandeNonSatisfaite", "Commande non satisfaite", nullptr));
        modifier_pushButton->setText(QCoreApplication::translate("CommandeNonSatisfaite", "Modifier statut de la vente", nullptr));
        pushButton->setText(QCoreApplication::translate("CommandeNonSatisfaite", "Imprimer", nullptr));
        label_4->setText(QCoreApplication::translate("CommandeNonSatisfaite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">Code de la vente</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("CommandeNonSatisfaite", "Code Produit ", nullptr));
        label_6->setText(QCoreApplication::translate("CommandeNonSatisfaite", "Saisir la quantit\303\251", nullptr));
        label->setText(QCoreApplication::translate("CommandeNonSatisfaite", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#00aa00;\">PharmaStock</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("CommandeNonSatisfaite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700;\">Liste des ventes non satisfaites</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("CommandeNonSatisfaite", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:700;\">D\303\251tail de la vente</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandeNonSatisfaite: public Ui_CommandeNonSatisfaite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDENONSATISFAITE_H
