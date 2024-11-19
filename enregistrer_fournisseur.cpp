#include "enregistrer_fournisseur.h"
#include "ui_enregistrer_fournisseur.h"
#include "Connexion.h"
#include "acceuilrespooperation.h"

#include "QMessageBox"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <iostream>

Enregistrer_Fournisseur::Enregistrer_Fournisseur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Enregistrer_Fournisseur)
{
    ui->setupUi(this);
    Connexion();
    afficher();
    showMaximized();
  //  QString styleSheet = "QHeaderView::section{background-color:#40fff9;}";
//    styleSheet += "QTableView{color:rgb(0, 255, 0);}";
//    ui->tableView->setMouseTracking(true);
//    ui->tableView->viewport()->installEventFilter(this);
//    ui->tableView->setStyleSheet(styleSheet);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    //ui->tableView->setColumnWidth(0, 100);
}

Enregistrer_Fournisseur::~Enregistrer_Fournisseur()
{
    delete ui;
}


void Enregistrer_Fournisseur::on_Enregistrer_pushButton_clicked()
{
    if(ui->Nom_fournisseurs_lineEdit->text().isEmpty() || ui->Contact_fournisseurs_lineEdit->text().isEmpty() || ui->Adresse_electronique_fournisseurs_lineEdit->text().isEmpty() || ui->Adresse_fournisseurs_lineEdit->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
    }else{
            QString codeF;
            int num = 0;
            QSqlQuery selectcodeF;
            selectcodeF.exec("SELECT idF FROM fournisseur");
            while(selectcodeF.next()){
                num = selectcodeF.value(0).toInt();
            }

            num = num + 1;
            codeF = "0000"+QString::number(num);
            QSqlQuery query;
            query.prepare("INSERT INTO fournisseur(codeF, contact, nomF, mail, adresse) VALUES(:codeF, :contact, :nomF, :mail, :adresse)");
            query.bindValue(":codeF", codeF);
            query.bindValue(":contact", ui->Contact_fournisseurs_lineEdit->text());
            query.bindValue(":nomF", ui->Nom_fournisseurs_lineEdit->text());
            query.bindValue(":mail", ui->Adresse_electronique_fournisseurs_lineEdit->text());
            query.bindValue(":adresse", ui->Adresse_fournisseurs_lineEdit->text());
            query.exec();
            afficher();
            QMessageBox::information(this, "statut enregistrement", "Enregistrement réussi !");

    }
}

void Enregistrer_Fournisseur::afficher()
{
    QSqlQuery requet;
    int row(0);
    modele = new QStandardItemModel(0,5);
    requet.exec("SELECT codeF, nomF, contact,  mail, adresse FROM fournisseur");
    while(requet.next()){
        QColor color = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for(int i = 0; i<5; i++){
            QStandardItem *item = new QStandardItem(requet.value(i).toString());
            item->setBackground(color);
            modele->setItem(row, i, item);
        }
        ++row;
    }
    modele->setHeaderData(0,Qt::Horizontal, "Code Fournisseur");
    modele->setHeaderData(1,Qt::Horizontal, "Nom Fournisseur");
    modele->setHeaderData(2,Qt::Horizontal, "Contact");
    modele->setHeaderData(3,Qt::Horizontal, "Adresse Electronique");
    modele->setHeaderData(4,Qt::Horizontal, "Adresse");

    ui->tableView->setModel(modele);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void Enregistrer_Fournisseur::effacer()
{
    ui->Nom_fournisseurs_lineEdit->clear();
    ui->Contact_fournisseurs_lineEdit->clear();
    ui->Adresse_electronique_fournisseurs_lineEdit->clear();
    ui->Adresse_fournisseurs_lineEdit->clear();
    ui->code_fournisseur->clear();
}


void Enregistrer_Fournisseur::on_AnnulerpushButton_clicked()
{
    effacer();
}


void Enregistrer_Fournisseur::on_Modifier_pushButton_clicked()
{
    if(ui->code_fournisseur->text().isEmpty()){
        QMessageBox::warning(this, "ERREUR", "Veuillez sélectionner l'enregistrement à modifier");
    }else{ if(ui->Nom_fournisseurs_lineEdit->text().isEmpty() || ui->Contact_fournisseurs_lineEdit->text().isEmpty() || ui->Adresse_electronique_fournisseurs_lineEdit->text().isEmpty() || ui->Adresse_fournisseurs_lineEdit->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
        }else{
            int compteur = 0;
            QSqlQuery requet;
            requet.exec("SELECT count(idF) FROM fournisseur WHERE CodeF='" +ui->code_fournisseur->text()+"'");
            while(requet.next()){
                compteur = requet.value(0).toInt();
            }

            QSqlQuery query;
            query.prepare("UPDATE fournisseur SET contact=:contact, nomF=:nomF, mail=:mail, adresse=:adresse WHERE codeF=:codeF");
            query.bindValue(":contact", ui->Contact_fournisseurs_lineEdit->text());
            query.bindValue(":nomF", ui->Nom_fournisseurs_lineEdit->text());
            query.bindValue(":mail", ui->Adresse_electronique_fournisseurs_lineEdit->text());
            query.bindValue(":adresse", ui->Adresse_fournisseurs_lineEdit->text());
            query.bindValue(":codeF", ui->code_fournisseur->text());
            query.exec();
            afficher();
            QMessageBox::information(this, "Statut modification", "Modification réussi");
            effacer();
        }
    }
}


void Enregistrer_Fournisseur::on_tableView_doubleClicked(const QModelIndex &index)
{
    indextable = modele->index(index.row(),0);
    ui->code_fournisseur->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),1);
    ui->Nom_fournisseurs_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),2);
    ui->Contact_fournisseurs_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),3);
    ui->Adresse_electronique_fournisseurs_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());
    indextable = modele->index(index.row(),4);
    ui->Adresse_fournisseurs_lineEdit->setText(modele->data(indextable,Qt::DisplayRole).toString());

}

void Enregistrer_Fournisseur::on_Suprimer_pushButton_clicked()
{
    if(ui->code_fournisseur->text().isEmpty()){
        QMessageBox::warning(this, "ERREUR", "Veuillez sélectionner l'enregistrement à supprimer");
    }else{
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT count(idF) FROM fournisseur WHERE codeF='" +ui->code_fournisseur->text()+"'");
        while(requet.next()){
            compteur = requet.value(0).toInt();
        }
        int reponse = QMessageBox::question(this, "Statut suppression", "Voulez-vous vraiment supprimer le fournisseur "+ui->code_fournisseur->text()+" ?",QMessageBox::No, QMessageBox::Yes);
        if(reponse == QMessageBox::Yes){
        QSqlQuery requet;
        requet.exec("DELETE FROM fournisseur WHERE codeF='" +ui->code_fournisseur->text()+"'");
        afficher();
        QMessageBox::information(this,"Information","Suppression réussie " );
        effacer();
        }
    }
}




void Enregistrer_Fournisseur::on_Imprimer_pushButton_clicked()
{
    QSqlQuery query;
    if(!query.exec("SELECT nomF, contact,  mail, adresse FROM fournisseur")){
        std::cout <<"Echec de l'éxécution de la requête";
        return;;
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
                 "<th>Nom </th>"
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

void Enregistrer_Fournisseur::print(QPrinter *printer)
{
    text->print(printer);
}

void Enregistrer_Fournisseur::on_accueil_pushButton_clicked()
{
    // Fermer la fenêtre principale

    // Ouvrir l'interface AcceuilREspoOperation
    AcceuilREspoOperation *acceuilWindow = new AcceuilREspoOperation();
    acceuilWindow->show();
    close();

}

