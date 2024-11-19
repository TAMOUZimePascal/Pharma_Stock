/********************************************************************************
** Form generated from reading UI file 'acceuilrespooperation.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCEUILRESPOOPERATION_H
#define UI_ACCEUILRESPOOPERATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AcceuilREspoOperation
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QSplitter *splitter_4;
    QSplitter *splitter_2;
    QPushButton *editerBonCommande_pushButton;
    QPushButton *rapport_vente_pushButton;
    QPushButton *gestion_fournisseurs_pushButton;
    QSplitter *splitter_3;
    QPushButton *tresorerie_pushButton;
    QPushButton *rapport_stock_pushButton;
    QPushButton *rapport_stock_pushButton_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *deconnexion_pushButton;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    QLabel *titrePosteLabel;
    QLabel *nomPersonnelLabel;

    void setupUi(QWidget *AcceuilREspoOperation)
    {
        if (AcceuilREspoOperation->objectName().isEmpty())
            AcceuilREspoOperation->setObjectName("AcceuilREspoOperation");
        AcceuilREspoOperation->resize(932, 747);
        AcceuilREspoOperation->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        AcceuilREspoOperation->setWindowIcon(icon);
        AcceuilREspoOperation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    color: #3498db;\n"
"    border-radius: 0px;\n"
"    padding: 20px;\n"
"    font-size: 27px;\n"
"    font-weight: bold;\n"
"    min-width: 100px; /* Taille carr\303\251e */\n"
"    min-height: 100px; /* Taille carr\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:rgb(222, 222, 222)\n"
"}\n"
"\n"
""));
        gridLayout = new QGridLayout(AcceuilREspoOperation);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(AcceuilREspoOperation);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("background-color: green;"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(AcceuilREspoOperation);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(" text-shadow: 2px 2px 5px rgba(0, 0, 0, 0.5);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        splitter_4 = new QSplitter(AcceuilREspoOperation);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Vertical);
        editerBonCommande_pushButton = new QPushButton(splitter_2);
        editerBonCommande_pushButton->setObjectName("editerBonCommande_pushButton");
        editerBonCommande_pushButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/BonCommandes.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        editerBonCommande_pushButton->setIcon(icon1);
        editerBonCommande_pushButton->setIconSize(QSize(70, 70));
        splitter_2->addWidget(editerBonCommande_pushButton);
        rapport_vente_pushButton = new QPushButton(splitter_2);
        rapport_vente_pushButton->setObjectName("rapport_vente_pushButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Rapport2.png"), QSize(), QIcon::Normal, QIcon::Off);
        rapport_vente_pushButton->setIcon(icon2);
        rapport_vente_pushButton->setIconSize(QSize(70, 70));
        splitter_2->addWidget(rapport_vente_pushButton);
        gestion_fournisseurs_pushButton = new QPushButton(splitter_2);
        gestion_fournisseurs_pushButton->setObjectName("gestion_fournisseurs_pushButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Fournisseurs.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        gestion_fournisseurs_pushButton->setIcon(icon3);
        gestion_fournisseurs_pushButton->setIconSize(QSize(70, 70));
        splitter_2->addWidget(gestion_fournisseurs_pushButton);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Vertical);
        tresorerie_pushButton = new QPushButton(splitter_3);
        tresorerie_pushButton->setObjectName("tresorerie_pushButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/comptabilite.png"), QSize(), QIcon::Normal, QIcon::Off);
        tresorerie_pushButton->setIcon(icon4);
        tresorerie_pushButton->setIconSize(QSize(70, 70));
        splitter_3->addWidget(tresorerie_pushButton);
        rapport_stock_pushButton = new QPushButton(splitter_3);
        rapport_stock_pushButton->setObjectName("rapport_stock_pushButton");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/Rapport1.png"), QSize(), QIcon::Normal, QIcon::Off);
        rapport_stock_pushButton->setIcon(icon5);
        rapport_stock_pushButton->setIconSize(QSize(70, 70));
        splitter_3->addWidget(rapport_stock_pushButton);
        rapport_stock_pushButton_4 = new QPushButton(splitter_3);
        rapport_stock_pushButton_4->setObjectName("rapport_stock_pushButton_4");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/Clients.png"), QSize(), QIcon::Normal, QIcon::Off);
        rapport_stock_pushButton_4->setIcon(icon6);
        rapport_stock_pushButton_4->setIconSize(QSize(70, 70));
        splitter_3->addWidget(rapport_stock_pushButton_4);
        splitter_4->addWidget(splitter_3);

        gridLayout->addWidget(splitter_4, 2, 0, 1, 1);

        label_2 = new QLabel(AcceuilREspoOperation);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        deconnexion_pushButton = new QPushButton(AcceuilREspoOperation);
        deconnexion_pushButton->setObjectName("deconnexion_pushButton");
        deconnexion_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;\n"
"    color: white;\n"
"    border-radius: 0px;\n"
"    padding: 2px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    min-width: 120px; /* Taille carr\303\251e */\n"
"    min-height: 20px; /* Taille carr\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:rgb(222, 222, 222)\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(deconnexion_pushButton);

        horizontalSpacer = new QSpacerItem(738, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        splitter = new QSplitter(AcceuilREspoOperation);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        titrePosteLabel = new QLabel(splitter);
        titrePosteLabel->setObjectName("titrePosteLabel");
        splitter->addWidget(titrePosteLabel);
        nomPersonnelLabel = new QLabel(splitter);
        nomPersonnelLabel->setObjectName("nomPersonnelLabel");
        splitter->addWidget(nomPersonnelLabel);

        horizontalLayout->addWidget(splitter);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        label_3->raise();
        label_2->raise();
        rapport_stock_pushButton_4->raise();

        retranslateUi(AcceuilREspoOperation);

        QMetaObject::connectSlotsByName(AcceuilREspoOperation);
    } // setupUi

    void retranslateUi(QWidget *AcceuilREspoOperation)
    {
        AcceuilREspoOperation->setWindowTitle(QCoreApplication::translate("AcceuilREspoOperation", "Accueil", nullptr));
        label_3->setText(QString());
        label->setText(QCoreApplication::translate("AcceuilREspoOperation", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700;\">BIENVENUE A L'ACCUEIL</span></p></body></html>", nullptr));
        editerBonCommande_pushButton->setText(QCoreApplication::translate("AcceuilREspoOperation", "Edition de bon commande", nullptr));
        rapport_vente_pushButton->setText(QCoreApplication::translate("AcceuilREspoOperation", "Rapport et statistique de ventes", nullptr));
        gestion_fournisseurs_pushButton->setText(QCoreApplication::translate("AcceuilREspoOperation", "Gestion des fournisseurs", nullptr));
        tresorerie_pushButton->setText(QCoreApplication::translate("AcceuilREspoOperation", "Tr\303\251sorerie", nullptr));
        rapport_stock_pushButton->setText(QCoreApplication::translate("AcceuilREspoOperation", "Rapport et statistique de stock", nullptr));
        rapport_stock_pushButton_4->setText(QCoreApplication::translate("AcceuilREspoOperation", "Gestion des clients", nullptr));
        label_2->setText(QString());
        deconnexion_pushButton->setText(QCoreApplication::translate("AcceuilREspoOperation", "D\303\251connexion", nullptr));
        titrePosteLabel->setText(QCoreApplication::translate("AcceuilREspoOperation", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Responsable des op\303\251rations</span></p></body></html>", nullptr));
        nomPersonnelLabel->setText(QCoreApplication::translate("AcceuilREspoOperation", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700; color:#00ff00;\">Jean-Thomas Pelletier Martin</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AcceuilREspoOperation: public Ui_AcceuilREspoOperation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCEUILRESPOOPERATION_H
