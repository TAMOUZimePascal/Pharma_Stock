#include "enregistrement_produit.h"
#include "ui_enregistrement_produit.h"
#include "Connexion.h"

#include "QMessageBox"
#include "QSqlQuery"
#include "QStandardItemModel"
#include "QDebug"
#include "QSqlError"
#include "QVariant"
#include "QModelIndex"

enregistrement_produit::enregistrement_produit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::enregistrement_produit)
{
    ui->setupUi(this);
    Connexion();
    Afficher();
}

enregistrement_produit::~enregistrement_produit()
{
    delete ui;
}

void enregistrement_produit::on_enregistrer_pushButton_clicked()
{
     if(ui->nom_lineEdit->text().isEmpty() || ui->type_produit_typecomboBox->currentText().isEmpty() || ui->prix_doubleSpinBox->value() == 0.00 || ui->dosage_lineEdit->text().isEmpty() || ui->caracteristique_lineEdit->text().isEmpty() || ui->caracteristique_lineEdit->text().isEmpty()){
            QMessageBox::warning(this, "Error", "Champ invalide");
        } else {
            int qtePro = 0;

            QString codeV = " ";
            QSqlQuery requet;
            requet.exec("SELECT codeV FROM vente INNER JOIN vendre ON vente.codeV = vendre.codeVente INNER JOIN produit ON vendre.codePro = produit.codePro");
            while(requet.next())
            {
                codeV = requet.value(0).toString();
            }
            QSqlQuery r;
            int idPro = 0;
            r.exec("SELECT IFNULL(MAX(idPro), 0) + 1 FROM produit");

            while(r.next()) {
                idPro = r.value(0).toInt();
            }

            QString codePro;
            QString mot = ui->nom_lineEdit->text();
            QString troisPremiereLettre = mot.left(3).toUpper();
            codePro = troisPremiereLettre +"00"+QString::number(idPro);

            int idType = 0;
            QSqlQuery re;
            re.exec("SELECT IFNULL(MAX(idType), 0) + 1 FROM typeproduit");

            while(re.next()) {
                idType = re.value(0).toInt();
            }

            QString codeType;
            QString word = ui->type_produit_typecomboBox->currentText();
            QString troisPremieresLettres = word.left(3).toUpper();
            codeType = troisPremieresLettres +"00"+QString::number(idType);
            ui->code_lineEdit->setText(codePro);

            QSqlQuery req;
            req.prepare("INSERT INTO typeproduit(codeType, typePro) VALUES(:codeType, :typePro)");
            req.bindValue(":codeType",codeType);
            req.bindValue(":typePro",ui->type_produit_typecomboBox->currentText());
            req.exec();

            QSqlQuery query;
            query.prepare("INSERT INTO produit (codePro, nomPro, dosage, caracteristique, prixUnit, qtePro, dateExpiration, codeType) "
                               "VALUES (:codePro, :nomPro, :dosage,:caracteristique, :prixPro, :qtePro, :dateExpiration, :codeType)");
            query.bindValue(":codePro",ui->code_lineEdit->text());
            query.bindValue(":nomPro",ui->nom_lineEdit->text());
            query.bindValue(":dosage", ui->dosage_lineEdit->text());
            query.bindValue(":caracteristique", ui->caracteristique_lineEdit->text());
            query.bindValue(":prixPro",ui->prix_doubleSpinBox->value());
            query.bindValue(":qtePro", qtePro);
            query.bindValue(":dateExpiration",QVariant(QVariant::Date));
            query.bindValue(":codeType", codeType);
            query.exec();
            QMessageBox::information(this,"Statut !", "Enregistré avec succès");
            Afficher();

            QSqlQuery requete;
            requete.prepare("INSERT INTO vendre (codeVente, codePro) VALUES (:codeVente, :codePro)");
            requete.bindValue(":codeVente", codeV);
            requete.bindValue(":codePro",codePro);
            requete.exec();
            on_annuler_pushButton_clicked();

        }
    }

void enregistrement_produit::on_annuler_pushButton_clicked()
{
    ui->code_lineEdit->clear();
    ui->nom_lineEdit->clear();
    ui->caracteristique_lineEdit->clear();
    ui->prix_doubleSpinBox->setValue(0.00);
    ui->dosage_lineEdit->clear();
}

void enregistrement_produit::on_modifier_pushButton_clicked()
{
   if (ui->rechercher_lineEdit->text().isEmpty())
       {
          QMessageBox::warning(this, "Erreur", "Veuillez saisir un code");
       }
        else
        {
            QString codePro = ui->rechercher_lineEdit->text();
            int compteur = 0;

            QSqlQuery requet;
            requet.prepare("SELECT COUNT(codePro) FROM produit WHERE codePro = :codePro");
            requet.bindValue(":codePro", codePro);

            if (!requet.exec())
            {
                QMessageBox::warning(this, "Erreur", "Échec de l'exécution de la requête de vérification.");
                return;
            }

            if (requet.next())
            {
                compteur = requet.value(0).toInt();
            }

            if (compteur == 0)
            {
                QMessageBox::warning(this, "Statut", "Code invalide");
            }
            else
            {
                QString codeType;
                QSqlQuery re;
                re.exec("SELECT codeType FROM produit INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType WHERE produit.codePro = :codePro");
                while(re.next())
                {
                    codeType = re.value(0).toString();
                }

                QSqlQuery req;
                req.prepare("UPDATE typeproduit SET typePro = :typePro, caracteristique = :desc WHERE codeType = :codeType");
                req.bindValue(":typePro", ui->type_produit_typecomboBox->currentText());
                req.bindValue(":desc", ui->caracteristique_lineEdit->text());
                if (!req.exec())
                {
                    QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du type de produit.");
                    return;
                }

                QSqlQuery query;
                query.prepare("UPDATE produit SET nomPro = :nomPro, dosage = :dosage, prixUnit = :prixPro WHERE codePro ='"+ui->rechercher_lineEdit->text()+"'");
                query.bindValue(":nomPro", ui->nom_lineEdit->text());
                query.bindValue(":dosage", ui->dosage_lineEdit->text());
                query.bindValue(":prixPro", ui->prix_doubleSpinBox->value());
                if (!query.exec())
                {
                    QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du produit.");
                    return;
                }

                Afficher();
                on_annuler_pushButton_clicked();
                QMessageBox::information(this, "Information", "Mise à jour réussie");
                ui->rechercher_lineEdit->setText("");
            }
        }
  }


void enregistrement_produit::on_supprimer_pushButton_clicked()
{
    if(ui->rechercher_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Veuillez saisir un code");
    }else{
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT COUNT(codePro) FROM produit WHERE codePro='"+ ui->rechercher_lineEdit->text()+"' ");
        while(requet.next())
        {
            compteur = requet.value(0).toInt();
        }

        if(compteur == 0)
        {
            QMessageBox::warning(this,"Statut", "Code invalide");
        }else{
            int reponse = QMessageBox::question(this,"Question","Voulez-vous vraiment supprimer cet enregistrement ?",QMessageBox::No,QMessageBox::Yes);
            if(reponse == QMessageBox::Yes){
            QSqlQuery requet;
            requet.exec("DELETE FROM produit WHERE CodePro= '" +ui->rechercher_lineEdit->text()+"'");
            Afficher();
            on_annuler_pushButton_clicked();
            QMessageBox::information(this,"Information","Suppression réussie " );
            ui->rechercher_lineEdit->setText("");}
        }
    }


}

void enregistrement_produit::on_rechercher_pushButton_clicked()
{
    if(ui->rechercher_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Veuillez saisir un code");
    }else{
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT COUNT(codePro) FROM produit WHERE codePro='"+ ui->rechercher_lineEdit->text()+"' ");
        while(requet.next())
        {
            compteur = requet.value(0).toInt();
        }

        if(compteur == 0)
        {
            QMessageBox::warning(this,"Statut", "Code invalide");
        }else{
            int row(0);
            QSqlQuery requet;
            model = new QStandardItemModel(0, 8);
            requet.exec("SELECT produit.codePro, produit.nomPro, produit.dosage, produit.prixUnit, produit.qtePro, produit.dateExpiration, typeproduit.typePro, typeproduit.caracteristique FROM produit INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType WHERE codePro ='"+ ui->rechercher_lineEdit->text()+"'");
            while(requet.next()){
                for(int i = 0; i<8; i++){
                    QStandardItem *item = new QStandardItem(requet.value(i).toString());
                    model->setItem(row, i, item);
                }
                row++;
            }

            model->setHeaderData(0,Qt::Horizontal, "Code Produit");
            model->setHeaderData(1,Qt::Horizontal, "Nom du produit");
            model->setHeaderData(2,Qt::Horizontal, "Dosage");
            model->setHeaderData(3,Qt::Horizontal, "Prix unitaire");
            model->setHeaderData(4,Qt::Horizontal, "Quantité");
            model->setHeaderData(5,Qt::Horizontal, "Date d'expiration");
            model->setHeaderData(6,Qt::Horizontal, "Type du produit");
            model->setHeaderData(7,Qt::Horizontal, "Caractéristiques");


            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableView->resizeColumnsToContents();
            ui->tableView->resizeRowsToContents();
        }
    }

}

void enregistrement_produit::Afficher()
{
     int row(0);
     QSqlQuery requet;
     model = new QStandardItemModel(0, 8);
     requet.exec("SELECT produit.codePro, produit.nomPro, produit.dosage, produit.prixUnit, produit.qtePro, produit.dateExpiration, typeproduit.typePro, typeproduit.caracteristique FROM produit INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType");
     while(requet.next()){
         for(int i = 0; i<8; i++){
             QStandardItem *item = new QStandardItem(requet.value(i).toString());
             model->setItem(row, i, item);
         }
         row++;
     }

     model->setHeaderData(0,Qt::Horizontal, "Code Produit");
     model->setHeaderData(1,Qt::Horizontal, "Nom du produit");
     model->setHeaderData(2,Qt::Horizontal, "Dosage");
     model->setHeaderData(3,Qt::Horizontal, "Prix unitaire");
     model->setHeaderData(4,Qt::Horizontal, "Quantité");
     model->setHeaderData(5,Qt::Horizontal, "Date d'expiration");
     model->setHeaderData(6,Qt::Horizontal, "Type du produit");
     model->setHeaderData(7,Qt::Horizontal, "Caractéristiques");


     ui->tableView->setModel(model);
     ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tableView->resizeColumnsToContents();
     ui->tableView->resizeRowsToContents();

}

void enregistrement_produit::on_tableView_clicked(const QModelIndex &index)
{
    indextable = model->index(index.row(),0);
    ui->rechercher_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),0);
    ui->code_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),1);
    ui->nom_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),2);
    ui->dosage_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),3);
    ui->prix_doubleSpinBox->setValue(model->data(indextable,Qt::DisplayRole).toDouble());
    indextable = model->index(index.row(),6);
    ui->type_produit_typecomboBox->setCurrentText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),7);
    ui->caracteristique_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());


}
