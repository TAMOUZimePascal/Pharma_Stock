#include "compta.h"
#include "ui_compta.h"
#include "Connexion.h"
#include "transactiondelegate.h"
#include "acceuilrespooperation.h"

#include "QMessageBox"
#include <QSqlError>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <iostream>

Compta::Compta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Compta)
{
    ui->setupUi(this);
    showMaximized();
    Connexion();
    afficher();


}

Compta::~Compta()
{
    delete ui;
}

void Compta::on_enregistrer_pushButton_4_clicked()
{
    if (ui->code_transaction_lineEdit->text().isEmpty() ||
        ui->dateTimeEdit->dateTime().isNull() ||
        ui->action_comboBox->currentText().isEmpty() ||
        ui->motif_lineEdit->text().isEmpty() ||
        ui->Depositaire_lineEdit->text().isEmpty() ||
        ui->moyen_payement_comboBox->currentText().isEmpty() ||
        ui->montant_doubleSpinBox->value() <= 0) {

        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
    } else {
        QString codeTrans;
        QSqlQuery selectCodeTrans;
        selectCodeTrans.exec("SELECT MAX(id) FROM transactions");
        if (selectCodeTrans.next()) {
            int maxId = selectCodeTrans.value(0).toInt();
            codeTrans = "T" + QString::number(maxId + 1).rightJustified(5, '0'); // Génère un code transaction avec un préfixe 'T' et 5 chiffres
        } else {
            codeTrans = "T00001"; // Premier code si la table est vide
        }

        QSqlQuery query;
        query.prepare("INSERT INTO transactions (codeTrans, date, action, motif, depositaire, moyenPaiement, montant) "
                      "VALUES (:codeTrans, :date, :action, :motif, :depositaire, :moyenPaiement, :montant)");
        query.bindValue(":codeTrans", codeTrans);
        query.bindValue(":date", ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss"));
        query.bindValue(":action", ui->action_comboBox->currentText());
        query.bindValue(":motif", ui->motif_lineEdit->text());
        query.bindValue(":depositaire", ui->Depositaire_lineEdit->text());
        query.bindValue(":moyenPaiement", ui->moyen_payement_comboBox->currentText());
        query.bindValue(":montant", ui->montant_doubleSpinBox->value());

        if (query.exec()) {
            afficher(); // Appel de la fonction pour mettre à jour l'affichage
            effacer();
            QMessageBox::information(this, "Statut enregistrement", "Enregistrement réussi !");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'enregistrement : " + query.lastError().text());
        }
    }

}

void Compta::afficher()
{
    QSqlQuery requet;
    int row = 0;
    modele = new QStandardItemModel(0, 7);
    requet.exec("SELECT codeTrans, date, action, motif, depositaire, moyenPaiement, montant FROM transactions");

    double totalEncaissements = 0.0;
    double totalDecaissements = 0.0;

    while (requet.next()) {
        QString action = requet.value(2).toString(); // Colonne "action"
        double montant = requet.value(6).toDouble(); // Colonne "montant"

        if (action == "Décaissement") {
            totalDecaissements += montant;
        } else if (action == "Encaissement") {
            totalEncaissements += montant;
        }

        QColor color = (action == "Décaissement") ? Qt::red : Qt::green;
        for (int i = 0; i < 7; i++) {
            QStandardItem *item = new QStandardItem(requet.value(i).toString());
            item->setBackground(color);
            modele->setItem(row, i, item);
        }
        ++row;
    }

    modele->setHeaderData(0, Qt::Horizontal, "Code Transaction");
    modele->setHeaderData(1, Qt::Horizontal, "Date");
    modele->setHeaderData(2, Qt::Horizontal, "Action");
    modele->setHeaderData(3, Qt::Horizontal, "Motif");
    modele->setHeaderData(4, Qt::Horizontal, "Dépositaire");
    modele->setHeaderData(5, Qt::Horizontal, "Moyen de Paiement");
    modele->setHeaderData(6, Qt::Horizontal, "Montant");

    ui->tableView->setModel(modele);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Afficher les totaux dans les labels
    ui->entree_label->setText(QString::number(totalEncaissements, 'f', 2));
    ui->sortie_label->setText(QString::number(totalDecaissements, 'f', 2));
    ui->solde_label->setText(QString::number(totalEncaissements - totalDecaissements, 'f', 2));
    afficherRecapitulatif();
}

void Compta::on_modifier_pushButton_4_clicked()
{
    if(ui->code_transaction_lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "ERREUR", "Veuillez sélectionner l'enregistrement à modifier");
    } else {
        if(ui->dateTimeEdit->dateTime().isNull() ||
           ui->action_comboBox->currentText().isEmpty() ||
           ui->motif_lineEdit->text().isEmpty() ||
           ui->Depositaire_lineEdit->text().isEmpty() ||
           ui->moyen_payement_comboBox->currentText().isEmpty() ||
           ui->montant_doubleSpinBox->value() == 0) {

            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires");
        } else {
            int compteur = 0;
            QSqlQuery requet;
            requet.exec("SELECT count(id) FROM transactions WHERE codeTrans='" + ui->code_transaction_lineEdit->text() + "'");
            while(requet.next()) {
                compteur = requet.value(0).toInt();
            }

            QSqlQuery query;
            query.prepare("UPDATE transactions SET date=:date, action=:action, motif=:motif, depositaire=:depositaire, moyenPaiement=:moyenPaiement, montant=:montant WHERE codeTrans=:code");
            query.bindValue(":date", ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss"));
            query.bindValue(":action", ui->action_comboBox->currentText());
            query.bindValue(":motif", ui->motif_lineEdit->text());
            query.bindValue(":depositaire", ui->Depositaire_lineEdit->text());
            query.bindValue(":moyenPaiement", ui->moyen_payement_comboBox->currentText());
            query.bindValue(":montant", ui->montant_doubleSpinBox->value());
            query.bindValue(":code", ui->code_transaction_lineEdit->text());

            if(query.exec()) {
                afficher(); // Met à jour l'affichage après la modification
                QMessageBox::information(this, "Statut modification", "Modification réussie");
                effacer(); // Efface les champs après la modification
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la modification : " + query.lastError().text());
            }
        }
    }

}

void Compta::on_tableView_doubleClicked(const QModelIndex &index)
{
    QModelIndex indextable = modele->index(index.row(), 0);
    ui->code_transaction_lineEdit->setText(modele->data(indextable, Qt::DisplayRole).toString());
    indextable = modele->index(index.row(), 1);
    ui->dateTimeEdit->setDateTime(QDateTime::fromString(modele->data(indextable, Qt::DisplayRole).toString(), "yyyy-MM-dd HH:mm:ss"));
    indextable = modele->index(index.row(), 2);
    ui->action_comboBox->setCurrentText(modele->data(indextable, Qt::DisplayRole).toString());
    indextable = modele->index(index.row(), 3);
    ui->motif_lineEdit->setText(modele->data(indextable, Qt::DisplayRole).toString());
    indextable = modele->index(index.row(), 4);
    ui->Depositaire_lineEdit->setText(modele->data(indextable, Qt::DisplayRole).toString());
    indextable = modele->index(index.row(), 5);
    ui->moyen_payement_comboBox->setCurrentText(modele->data(indextable, Qt::DisplayRole).toString());
    indextable = modele->index(index.row(), 6);
    ui->montant_doubleSpinBox->setValue(modele->data(indextable, Qt::DisplayRole).toDouble());
}

void Compta::effacer()
{
    ui->code_transaction_lineEdit->clear();
    ui->dateTimeEdit->clear();
    ui->action_comboBox->setCurrentIndex(0); // Réinitialise la sélection à l'élément 0
    ui->motif_lineEdit->clear();
    ui->Depositaire_lineEdit->clear();
    ui->moyen_payement_comboBox->setCurrentIndex(0); // Réinitialise la sélection à l'élément 0
    ui->montant_doubleSpinBox->setValue(0.0); // Réinitialise la valeur à 0.0
}

void Compta::on_annuler_pushButton_4_clicked()
{
    effacer();
}

void Compta::on_supprimer_pushButton_4_clicked()
{
    if(ui->code_transaction_lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "ERREUR", "Veuillez sélectionner l'enregistrement à supprimer");
    } else {
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT count(id) FROM transactions WHERE codeTrans='" + ui->code_transaction_lineEdit->text() + "'");
        while(requet.next()) {
            compteur = requet.value(0).toInt();
        }

        int reponse = QMessageBox::question(this, "Statut suppression", "Voulez-vous vraiment supprimer la transaction " + ui->code_transaction_lineEdit->text() + " ?", QMessageBox::No, QMessageBox::Yes);

        if(reponse == QMessageBox::Yes) {
            QSqlQuery requet;
            requet.exec("DELETE FROM transactions WHERE codeTrans='" + ui->code_transaction_lineEdit->text() + "'");
            afficher(); // Met à jour l'affichage après la suppression
            QMessageBox::information(this, "Information", "Suppression réussie");
            effacer(); // Efface les champs après la suppression
        }
    }

}


void Compta::afficherRecapitulatif()
{
    QSqlQuery requet;
    modeleRecapitulatif = new QStandardItemModel(0, 3);

    // Query to get the summary of transactions grouped by date
    requet.exec("SELECT date(date) as jour, "
                "SUM(CASE WHEN action = 'Encaissement' THEN montant ELSE 0 END) as totalEncaissements, "
                "SUM(CASE WHEN action = 'Décaissement' THEN montant ELSE 0 END) as totalDecaissements "
                "FROM transactions "
                "GROUP BY date(date)");

    int row = 0;
    while (requet.next()) {
        QString jour = requet.value("jour").toString();
        double totalEncaissements = requet.value("totalEncaissements").toDouble();
        double totalDecaissements = requet.value("totalDecaissements").toDouble();

        modeleRecapitulatif->setItem(row, 0, new QStandardItem(jour));
        modeleRecapitulatif->setItem(row, 1, new QStandardItem(QString::number(totalEncaissements, 'f', 2)));
        modeleRecapitulatif->setItem(row, 2, new QStandardItem(QString::number(totalDecaissements, 'f', 2)));

        ++row;
    }

    modeleRecapitulatif->setHeaderData(0, Qt::Horizontal, "Date");
    modeleRecapitulatif->setHeaderData(1, Qt::Horizontal, "Total Encaissements");
    modeleRecapitulatif->setHeaderData(2, Qt::Horizontal, "Total Décaissements");

    ui->tableView_8->setModel(modeleRecapitulatif);

    ui->tableView_8->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_8->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_8->resizeColumnsToContents();
    ui->tableView_8->resizeRowsToContents();
    ui->tableView_8->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Compta::on_editer_facture_pushButton_5_clicked()
{
    close();
    AcceuilREspoOperation *acceuilWindow = new AcceuilREspoOperation();
    acceuilWindow->show();
}


void Compta::on_pushButton_6_clicked()
{
 QDateTime currentDate = QDateTime::currentDateTime();
        QString DateCourante = currentDate.toString("yyyy-MM-dd");

        QSqlQuery requet;
        QString texte;
        texte += "<!DOCTYPE html><html>"
                 "<head>"
                 "<link rel='stylesheet' type='text/css' href='styles.css'>"
                 "</head>"
                 "<body>";

        // En-tête
        texte += "<header>"
                 "<img src='Mes_images/GestionStock.png' class='logo-gauche'>"
                 "<h1>PHARMASTOCK</h1>"
                 "<img src='Mes_images/GestionStock.png' class='logo-droite'>"
                 "<p>Vente de produits pharmaceutiques, laboratoire de recherche, distributeur de produits pharmaceutiques.</p>"
                 "<p>Lieu: Parakou, Qtier: Arafat, situé à 200m du campus en allant à baka<br>"
                 "Tél: 61359067 / 55375315</p>"
                 "</header>";

        texte += "</tbody>"
                 "</table>"
                 "</main>";

 // Table des flux de trésorerie
 texte += "<main>"
          "<h2>Flux de Trésorerie</h2>"
          "<table>"
          "<thead>"
          "<tr>"
          "<th>Code Transaction</th>"
          "<th>Date</th>"
          "<th>Action</th>"
          "<th>Motif</th>"
          "<th>Dépositaire</th>"
          "<th>Moyen de Paiement</th>"
          "<th>Montant</th>"
          "</tr>"
          "</thead>"
          "<tbody>";

 requet.exec("SELECT codeTrans, date, action, motif, depositaire, moyenPaiement, montant FROM transactions");
 while (requet.next()) {
     texte += "<tr>"
              "<td>" + requet.value(0).toString() + "</td>"
                                             "<td>" + requet.value(1).toString() + "</td>"
                                             "<td>" + requet.value(2).toString() + "</td>"
                                             "<td>" + requet.value(3).toString() + "</td>"
                                             "<td>" + requet.value(4).toString() + "</td>"
                                             "<td>" + requet.value(5).toString() + "</td>"
                                             "<td>" + requet.value(6).toString() + "</td>"
                                             "</tr>";
 }

 texte += "</tbody>"
          "</table>";

 // Table des récapitulatifs
 texte += "<h2>Récapitulatif des Mouvements de Caisse</h2>"
          "<table>"
          "<thead>"
          "<tr>"
          "<th>Date</th>"
          "<th>Total Encaissements</th>"
          "<th>Total Décaissements</th>"
          "</tr>"
          "</thead>"
          "<tbody>";

 requet.exec("SELECT date(date) as jour, "
             "SUM(CASE WHEN action = 'Encaissement' THEN montant ELSE 0 END) as totalEncaissements, "
             "SUM(CASE WHEN action = 'Décaissement' THEN montant ELSE 0 END) as totalDecaissements "
             "FROM transactions "
             "GROUP BY date(date)");
 while (requet.next()) {
     texte += "<tr>"
              "<td>" + requet.value(0).toString() + "</td>"
                                             "<td>" + requet.value(1).toString() + "</td>"
                                             "<td>" + requet.value(2).toString() + "</td>"
                                             "</tr>";
 }


 texte += "</tbody>"
          "</table>"
          "</main>";

 texte += "<footer>"
          "<p>Imprimé le " + DateCourante + "</p>"
                           "</footer>";

 texte += "</body></html>";

 text->setHtml(texte);

 QPrinter imprimer;
 imprimer.setPageOrientation(QPageLayout::Portrait);

 QPrintPreviewDialog dialog(&imprimer, this);

 connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));

 dialog.showMaximized();
 dialog.exec();
    }


void Compta::print(QPrinter *printer)
{
    text->print(printer);
}

