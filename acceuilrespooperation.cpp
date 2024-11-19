#include "acceuilrespooperation.h"
#include "ui_acceuilrespooperation.h"
#include "StockReportWidget.h"
#include "approvisionnement.h"
#include "enregistrer_fournisseur.h"
#include "mainwindow.h"
#include "compta.h"
#include "interface_client.h"
#include "interface_vente.h"
#include "editionboncommandes.h"
#include "connexion.h"
#include "login.h"

#include "QSqlDatabase"
#include "QSqlQuery"

AcceuilREspoOperation::AcceuilREspoOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AcceuilREspoOperation)
{
    ui->setupUi(this);
    showMaximized();
    Connexion();
    fetchAndDisplayPersonnel();
}

AcceuilREspoOperation::~AcceuilREspoOperation()
{
    delete ui;
}

void AcceuilREspoOperation::on_editerBonCommande_pushButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface editionBonCommandes
    editionBonCommandes *editionBonCommandesWindow = new editionBonCommandes();
    editionBonCommandesWindow->show();
}


void AcceuilREspoOperation::on_rapport_vente_pushButton_clicked()
{
    close();
    MainWindow *rapportStatistiquesVentes = new MainWindow();
    rapportStatistiquesVentes->show();
}


void AcceuilREspoOperation::on_rapport_stock_pushButton_clicked()
{
    close();
    StockReportWidget *rapportStatistiquesStock = new StockReportWidget();
    rapportStatistiquesStock->show();
}


void AcceuilREspoOperation::on_gestion_fournisseurs_pushButton_clicked()
{
    close();
    Enregistrer_Fournisseur *gestionFournisseurs = new Enregistrer_Fournisseur();
    gestionFournisseurs->show();
}


void AcceuilREspoOperation::on_tresorerie_pushButton_clicked()
{
    close();
    Compta *tresorerie = new Compta();
    tresorerie->show();
}

void AcceuilREspoOperation::fetchAndDisplayPersonnel() {


    QSqlQuery query;
    query.prepare("SELECT nomPers, prenomPers FROM personnel WHERE rolePers = :rolePers ORDER BY codePers DESC LIMIT 1");
    query.bindValue(":rolePers", "Responsable des opérations");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, QObject::tr("Query Error"),
                              query.lastError().text());
        return;
    }

    if (query.next()) {
        QString nomPers = query.value("nomPers").toString();
        QString prenomPers = query.value("prenomPers").toString();
        QString fullName = prenomPers + " " + nomPers;

        // Assurez-vous que le label existe et est valide
        if (ui->nomPersonnelLabel) {
            ui->nomPersonnelLabel->setText(fullName);
            ui->nomPersonnelLabel->setStyleSheet("font-size:12pt; font-weight:700; color:#00ff00;");
        }
    } else {
        QMessageBox::information(nullptr, QObject::tr("No Result"),
                                 QObject::tr("No personnel found with the specified role."));
    }


}


void AcceuilREspoOperation::on_deconnexion_pushButton_clicked()
{
    Login *deconnexion = new Login();
    deconnexion->show();
    close();
}

