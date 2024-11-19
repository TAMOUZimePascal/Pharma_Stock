#include "interface_client.h"
#include "ui_interface_client.h"
#include "Connexion.h"
#include "interface_vente.h"
#include "login.h"

#include "QMessageBox"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <iostream>

interface_client::interface_client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface_client)
{
    ui->setupUi(this);
    Connexion();
    afficher();
    showMaximized();
}

interface_client::~interface_client()
{
    delete ui;
}

void interface_client::on_Enregistrer_pushButton_clicked()
{
    if(ui->Nom_client_lineEdit->text().isEmpty() || ui->Contact_client_lineEdit->text().isEmpty() || ui->Adresse_electronique_client_lineEdit->text().isEmpty() || ui->Adresse_client_lineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
    }else{
            QSqlQuery req;
        int compteur = 0;
            req.exec("SELECT COUNT(mailCli) FROM client WHERE mailCli='"+ui->Adresse_electronique_client_lineEdit->text()+"'");
        while (req.next()) {

             compteur = req.value(0).toInt();
        }

        if(compteur == 0)
        {
            QString codeCli;
            int num = 0;
            QSqlQuery selectcodeCli;
            selectcodeCli.exec("SELECT idCli FROM client");
            while(selectcodeCli.next()){
                num = selectcodeCli.value(0).toInt();
            }

            num = num + 1;
            codeCli = "0000"+QString::number(num);
            QSqlQuery query;
            query.prepare("INSERT INTO client(codeCli, nomCli, telephoneCli, mailCli, adresseCli) VALUES(:codeCli, :nomCli, :telephoneCli, :mailCli, :adresseCli)");
            query.bindValue(":codeCli", codeCli);
            query.bindValue(":telephoneCli", ui->Contact_client_lineEdit->text());
            query.bindValue(":nomCli", ui->Nom_client_lineEdit->text());
            query.bindValue(":mailCli", ui->Adresse_electronique_client_lineEdit->text());
            query.bindValue(":adresseCli", ui->Adresse_client_lineEdit->text());
            query.exec();
            afficher();
            QMessageBox::information(this, "statut enregistrement", "Enregistrement réussi !");

        }else{
            QMessageBox::warning(this,"Error", "Ce client existe deja");
            on_AnnulerpushButton_clicked();
        }
    }
}


void interface_client::afficher()
{
    QSqlQuery requet;
    int row(0);
    modele = new QStandardItemModel(0,5);
    requet.exec("SELECT codeCli, nomCli, telephoneCli,  mailCli, adresseCli FROM client");
    while(requet.next()){
        for(int i = 0; i<5; i++){
            QStandardItem *item = new QStandardItem(requet.value(i).toString());
            modele->setItem(row, i, item);
        }
        row++;
    }
    modele->setHeaderData(0,Qt::Horizontal, "Code Client");
    modele->setHeaderData(1,Qt::Horizontal, "Nom Client");
    modele->setHeaderData(2,Qt::Horizontal, "Contact");
    modele->setHeaderData(3,Qt::Horizontal, "Adresse Electronique");
    modele->setHeaderData(4,Qt::Horizontal, "Adresse");

    ui->tableView->setModel(modele);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void interface_client::effacer()
{
    ui->Nom_client_lineEdit->clear();
    ui->Contact_client_lineEdit->clear();
    ui->Adresse_electronique_client_lineEdit->clear();
    ui->Adresse_client_lineEdit->clear();
    ui->code_client->clear();
}

void interface_client::on_AnnulerpushButton_clicked()
{
    effacer();
}

void interface_client::on_Modifier_pushButton_clicked()
{
    if(ui->code_client->text().isEmpty()){
        QMessageBox::warning(this, "ERREUR", "Veuillez sélectionner l'enregistrement à modifier");
    }else{ if(ui->Nom_client_lineEdit->text().isEmpty() || ui->Contact_client_lineEdit->text().isEmpty() || ui->Adresse_electronique_client_lineEdit->text().isEmpty() || ui->Adresse_client_lineEdit->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
        }else{
            int compteur = 0;
            QSqlQuery requet;
            requet.exec("SELECT count(idCli) FROM client WHERE CodeCli='" +ui->code_client->text()+"'");
            while(requet.next()){
                compteur = requet.value(0).toInt();
            }

            QSqlQuery query;
            query.prepare("UPDATE client SET nomCli=:nom, telephoneCli=:contact, mailCli=:mail, adresseCli=:adresse WHERE codeCli=:code");
            query.bindValue(":contact", ui->Contact_client_lineEdit->text());
            query.bindValue(":nom", ui->Nom_client_lineEdit->text());
            query.bindValue(":mail", ui->Adresse_electronique_client_lineEdit->text());
            query.bindValue(":adresse", ui->Adresse_client_lineEdit->text());
            query.bindValue(":code", ui->code_client->text());
            query.exec();
            afficher();
            QMessageBox::information(this, "Statut modification", "Modification réussi");
            effacer();
        }
    }
}


void interface_client::on_tableView_doubleClicked(const QModelIndex &index)
{
    indextable = modele->index(index.row(),0);
    ui->code_client->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),1);
    ui->Nom_client_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),2);
    ui->Contact_client_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),3);
    ui->Adresse_electronique_client_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),4);
    ui->Adresse_client_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());

}


void interface_client::on_Rechercher_pushButton_clicked()
{
    if(ui->code_client->text().isEmpty()){
        QMessageBox::warning(this, "ERREUR", "Veuillez entrer un identifiant de recherche");
    }else{
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT count(idCli) FROM client WHERE CodeCli='" +ui->code_client->text()+"'");
        while(requet.next()){
            compteur = requet.value(0).toInt();
        }
        if(compteur == 0){
            QMessageBox::warning(this, "Statut recherche", "Enregistrement non trouvé");
        }else{
            QSqlQuery requet;
            int row(0);
            modele = new QStandardItemModel(0,5);
            requet.exec("SELECT codeCli, nomCli, telephoneCli,  mailCli, adresseCli FROM client WHERE CodeCli='" +ui->code_client->text()+"'");
            while(requet.next()){
                for(int i = 0; i<5; i++){
                    QStandardItem *item = new QStandardItem(requet.value(i).toString());
                    modele->setItem(row, i, item);
                }
                row++;
            }
            modele->setHeaderData(0,Qt::Horizontal, "Code Client");
            modele->setHeaderData(1,Qt::Horizontal, "Nom Client");
            modele->setHeaderData(2,Qt::Horizontal, "Contact");
            modele->setHeaderData(3,Qt::Horizontal, "Adresse Electronique");
            modele->setHeaderData(4,Qt::Horizontal, "Adresse");

            ui->tableView->setModel(modele);

            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableView->resizeColumnsToContents();
            ui->tableView->resizeRowsToContents();
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            //ui->code_client->clear();
        }
    }
}

void interface_client::on_Suprimer_pushButton_clicked()
{
    if(ui->code_client->text().isEmpty()){
        QMessageBox::warning(this, "ERREUR", "Veuillez sélectionner l'enregistrement à supprimer");
    }else{
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT count(idCli) FROM client WHERE codeCli='" +ui->code_client->text()+"'");
        while(requet.next()){
            compteur = requet.value(0).toInt();
        }
        int reponse = QMessageBox::question(this, "Statut suppression", "Voulez-vous vraiment supprimer le fournisseur "+ui->code_client->text()+" ?",QMessageBox::No, QMessageBox::Yes);
        if(reponse == QMessageBox::Yes){
        QSqlQuery requet;
        requet.exec("DELETE FROM client WHERE codeCli='" +ui->code_client->text()+"'");
        afficher();
        QMessageBox::information(this,"Information","Suppression réussie " );
        effacer();
        }
    }
}


void interface_client::on_Imprimer_pushButton_clicked()
{
    QSqlQuery query;
    if(!query.exec("SELECT nomCli, telephoneCli, mailCli, adresseCli FROM client")){
        std::cout << "Echec de l'éxécution de la requête" << std::endl;
        return;
    }
    QDateTime currentDate = QDateTime::currentDateTime();
    QString DateCourante = currentDate.toString("yyyy-MM-dd");

    text = new QTextEdit;
    QString texte;
    texte += "<!DOCTYPE html><html>"
             "<body>";

    // Inserting the company logo at the top
    texte += "<div style='text-align: center;'>";
    texte += "<img src=':/images/logo.jpg' style='height: 10px; float: left;'/>";
    texte += "<img src=':/images/logo.jpg' style='height: 80px; float: right;'/>";
    texte += "</div>";

    texte += "<div style='font-size: xx-large;'>";
    texte += "<h1 style='color: green; text-align: center;'>PHARMASTOCK</h1>";
    texte += "<center><b>Vente de produits pharmaceutiques, laboratoire de recherche, distributeur de produits pharmaceutiques.</b></center>";
    texte += "<center><b>Lieu: </b>Parakou <b>Qtier: </b>Arafat, situé à 200m du campus en allant à baka<b>Tél: </b>61359067/55375315</center>";
    texte += "</div><hr>";

    texte += "<h1><center>Liste des fournisseurs</center></h1><br>";
    texte += "<table border='1' width='100%' cellspacing='0' style='font-size: medium;'>";
    texte += "<thead>"
             "<tr bgcolor='lightgray' style='font-size: medium;'>"
             "<th>Nom client</th>"
             "<th>Contact</th>"
             "<th>Adresse électronique</th>"
             "<th>Adresse</th>"
             "</tr>"
             "</thead>";

    while(query.next()){
        QString col1 = query.value(0).toString();
        QString col2 = query.value(1).toString();
        QString col3 = query.value(2).toString();
        QString col4 = query.value(3).toString();
        QString col5 = query.value(4).toString();

        texte += "<tbody style='font-size: x-large;'>";
        texte += "<tr>"
                 "<td><center>" + col1 + "</center></td>"
                          "<td><center>" + col2 + "</center></td>"
                          "<td><center>" + col3 + "</center></td>"
                          "<td><center>" + col4 + "</center></td>"
                          "</tr>";
    }

    texte += "</tbody></table>";
    texte += "<br><br><br>Imprimé le " + DateCourante +
             "</body>"
             "</html>";

    text->setHtml(texte);
    QPrinter imprimer;
    imprimer.setPageOrientation(QPageLayout::Portrait);

    QPrintPreviewDialog dialog(&imprimer, this);

    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));

    dialog.showMaximized();
    dialog.exec();
}

void interface_client::print(QPrinter *printer)
{
    text->print(printer);
}


void interface_client::on_pushButton_2_clicked()
{
    Interface_Vente *ventes = new Interface_Vente();
    ventes->show();
    close();
}

