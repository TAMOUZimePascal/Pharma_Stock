#include "approvisionnement.h"
#include "ui_approvisionnement.h"
#include "Connexion.h"
#include "QModelIndex"
#include "QVariant"
#include "login.h"

#include "QDate"
#include "QDateEdit"
#include "QStandardItemModel"
#include "QList"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlError"
#include "QMessageBox"
#include <QStringListModel>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <iostream>


Approvisionnement::Approvisionnement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Approvisionnement)
{
    ui->setupUi(this);

    Afficher();
    Completer();
    showMaximized();
    on_annuler_pushButton_clicked();
    Connexion();
    connect(ui->code_lineEdit, &QLineEdit::textChanged, this, &Approvisionnement::GenererCodeProduit);


    model = new QStandardItemModel(0, 5, this);
    model->setHorizontalHeaderLabels({"Code Produit", "Nom du Produit", "Type de Produit", "Quantité", "Date d'expiration", "Date d'approvisionnement"});
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Approvisionnement::~Approvisionnement()
{
    delete ui;
}

void Approvisionnement::on_code_lineEdit_textChanged(const QString &arg1)
{
    ui->nom_lineEdit->clear();
        ui->typeProduit_lineEdit->clear();
        QSqlQuery requete;
        requete.exec("SELECT produit.nomPro, produit.qtePro, typeproduit.typePro, produit.caracteristique FROM produit INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType WHERE produit.codePro='"+ui->code_lineEdit->text()+"'");
        while (requete.next()) {
            nomPro = requete.value(0).toString();
            qtePro = requete.value(1).toInt();
            typePro = requete.value(2).toString();
            caracteristique = requete.value(3).toString();
        }
        ui->nom_lineEdit->setText(nomPro);
        ui->qte_spinBox->setValue(qtePro);
        ui->typeProduit_lineEdit->setText(typePro);
        codePro = ui->code_lineEdit->text();
}


void Approvisionnement::on_ajouter_pushButton_clicked()
{
        if (ui->nom_lineEdit->text().isEmpty() ||
            ui->typeProduit_lineEdit->text().isEmpty() ||
            ui->qte_spinBox->value() == 0 ||
            ui->dateApprovisionnement_dateEdit->date() < QDate::currentDate() ||
            ui->dateExpiration_dateEdit->date() < QDate::currentDate())
        {
            QMessageBox::warning(this, "Attention", "Veuillez renseigner des informations correctes");
            return;
        }

        QString codePro = ui->code_lineEdit->text();
        QString nomPro = ui->nom_lineEdit->text();
        QString typePro = ui->typeProduit_lineEdit->text();
        int qte = ui->qte_spinBox->value();
        QDate dateExpiration = ui->dateExpiration_dateEdit->date();
        QDate dateApprovisionnement = ui->dateApprovisionnement_dateEdit->date();

        QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->tableView->model());
        if (!model) {
            QMessageBox::warning(this, "Erreur", "Modèle de la table non trouvé");
            return;
        }

        // Vérifier les doublons
        for (int row = 0; row < model->rowCount(); ++row) {
            if (model->item(row, 0)->text() == codePro) {
                // Le produit existe déjà dans la table
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Produit existant", "Ce produit existe déjà dans la liste. Voulez-vous le modifier ?", QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    // Modifier le produit existant
                    model->item(row, 1)->setText(nomPro);
                    model->item(row, 2)->setText(typePro);
                    model->item(row, 3)->setText(QString::number(qte));
                    model->item(row, 4)->setText(dateExpiration.toString("yyyy-MM-dd"));
                    model->item(row, 5)->setText(dateApprovisionnement.toString("yyyy-MM-dd"));
                }
                return; // Sortir de la fonction
            }
        }

        // Ajouter un nouveau produit
        QList<QStandardItem*> items;
        items.append(new QStandardItem(codePro));
        items.append(new QStandardItem(nomPro));
        items.append(new QStandardItem(typePro));
        items.append(new QStandardItem(QString::number(qte)));
        items.append(new QStandardItem(dateExpiration.toString("yyyy-MM-dd")));
        items.append(new QStandardItem(dateApprovisionnement.toString("yyyy-MM-dd")));
        model->appendRow(items);

        // Réinitialiser les champs du formulaire
        ui->code_lineEdit->clear();
        ui->nom_lineEdit->clear();
        ui->typeProduit_lineEdit->clear();
        ui->qte_spinBox->setValue(0);
        ui->dateExpiration_dateEdit->setDate(QDate::currentDate());
        ui->dateApprovisionnement_dateEdit->setDate(QDate::currentDate());
}

void Approvisionnement::on_annuler_pushButton_clicked()
{
    ui->code_lineEdit->clear();
    ui->nom_lineEdit->clear();
    ui->typeProduit_lineEdit->clear();
    ui->qte_spinBox->setValue(0);
    ui->dateExpiration_dateEdit->setDate(QDate::currentDate());
    ui->dateApprovisionnement_dateEdit->setDate(QDate::currentDate());
}


void Approvisionnement::on_enregistrer_pushButton_clicked()
{
    // Vérifier si la tableView est vide
    if (model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "La table est vide. Veuillez ajouter des produits avant d'enregistrer.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Erreur", "La base de données n'est pas ouverte");
        return;
    }

    db.transaction();

    // Générer un nouvel ID pour l'approvisionnement
    int idAp = 0;
    QSqlQuery r;
    if (r.exec("SELECT IFNULL(MAX(idAp), 0) + 1 FROM approvisionnement") && r.next()) {
        idAp = r.value(0).toInt();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le nouvel ID d'approvisionnement");
        db.rollback();
        return;
    }

    // Générer le codeAp basé sur le nouvel ID
    QString word = "Approvisionnement";
    QString troisPremiereLettre = word.left(3).toUpper();
    QString codeAp = troisPremiereLettre + QString("%1").arg(idAp, 2, 10, QChar('0'));

    // Vérifier si le codeAp existe déjà dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(codeAp) FROM approvisionnement WHERE codeAp = :codeAp");
    checkQuery.bindValue(":codeAp", codeAp);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Un approvisionnement avec ce code existe déjà.");
        db.rollback();
        return;
    }

    // Récupérer le code du personnel responsable de stock
    QSqlQuery req;
    QString codePers;
    QString role = "Responsable de stock";
    req.prepare("SELECT codePers FROM personnel WHERE rolePers = :role ORDER BY idPers DESC LIMIT 1");
    req.bindValue(":role", role);
    if (req.exec() && req.next()) {
        codePers = req.value(0).toString();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le code personnel");
        db.rollback();
        return;
    }

    // Insérer les informations dans la table approvisionnement (en dehors de la boucle)
    QSqlQuery requete;
    requete.prepare("INSERT INTO approvisionnement (codeAp, dateAp, codePers) VALUES (?, ?, ?)");
    requete.addBindValue(codeAp);
    requete.addBindValue(QDate::currentDate());
    requete.addBindValue(codePers);
    if (!requete.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table approvisionnement: " + requete.lastError().text());
        db.rollback();
        return;
    }

    // Insérer les produits du panier dans la table approvisionner et mettre à jour la table produit
    for (int row = 0; row < model->rowCount(); ++row) {
        QString codePro = model->data(model->index(row, 0)).toString();
        QString nomPro = model->data(model->index(row, 1)).toString();
        QString typePro = model->data(model->index(row, 2)).toString();
        QString caracteristique = model->data(model->index(row, 4)).toString();
        int qtePro = model->data(model->index(row, 3)).toInt();
        QDate dateExpiration = QDate::fromString(model->data(model->index(row, 5)).toString(), "yyyy-MM-dd");
        QDate dateApprovisionnement = QDate::fromString(model->data(model->index(row, 6)).toString(), "yyyy-MM-dd");

        // Insérer dans la table approvisionner
        QSqlQuery reqApprovisionner;
        reqApprovisionner.prepare("INSERT INTO approvisionner (codeAp, codePro) VALUES (?, ?)");
        reqApprovisionner.addBindValue(codeAp);
        reqApprovisionner.addBindValue(codePro);
        if (!reqApprovisionner.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table approvisionner: " + reqApprovisionner.lastError().text());
            db.rollback();
            return;
        }

        // Mettre à jour la table produit
        QSqlQuery reqProduit;
        reqProduit.prepare("UPDATE produit SET qtePro = qtePro + ?, dateExpiration = ?, caracteristique = ? WHERE codePro = ?");
        reqProduit.addBindValue(qtePro);
        reqProduit.addBindValue(dateExpiration);
        reqProduit.addBindValue(caracteristique);
        reqProduit.addBindValue(codePro);
        if (!reqProduit.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la table produit: " + reqProduit.lastError().text());
            db.rollback();
            return;
        }
    }

    // Commit transaction after the loop
    if (db.commit()) {
        QMessageBox::information(this, "Succès", "Approvisionnement enregistré avec succès");
        model->removeRows(0, model->rowCount());
        on_annuler_pushButton_clicked();
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'enregistrement de l'approvisionnement");
        db.rollback();
    }
    Afficher();
}

void Approvisionnement::on_tableView_clicked(const QModelIndex &index)
{
    indextable = model->index(index.row(),0);
    ui->code_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),1);
    ui->nom_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),2);
    ui->typeProduit_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),3);
    ui->qte_spinBox->setValue(model->data(indextable,Qt::DisplayRole).toInt());
    indextable = model->index(index.row(),4);
    ui->dateExpiration_dateEdit->setDate(model->data(indextable,Qt::DisplayRole).toDate());
    indextable = model->index(index.row(),5);
    ui->dateApprovisionnement_dateEdit->setDate(model->data(indextable,Qt::DisplayRole).toDate());

}

void Approvisionnement::on_supprimer_pushButton_clicked()
{
    QString codeToDelete = ui->code_lineEdit->text();
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
            if (index.data().toString() == codeToDelete) {
                model->removeRow(row);
                return;
        }
}
    on_annuler_pushButton_clicked();
}

void Approvisionnement::on_rechercher_pushButton_clicked()
{
    if(ui->rechercher_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Veuillez saisir un code");
    }else{
        int compteur = 0;
        QSqlQuery requet;
        requet.exec("SELECT COUNT(codeAp) FROM approvisionnement WHERE codeAp='"+ ui->rechercher_lineEdit->text()+"' ");
        while(requet.next())
        {
            compteur = requet.value(0).toInt();
        }

        if(compteur == 0)
        {
            QMessageBox::warning(this,"Statut", "Code invalide");
        }else{
           QSqlQuery requet;
           int row(0);
            model = new QStandardItemModel(0, 5);
            requet.exec("SELECT approvisionnement.codeAp, approvisionnement.dateAp, personnel.prenomPers, personnel.nomPers, personnel.rolePers FROM approvisionnement INNER JOIN personnel ON approvisionnement.codePers = personnel.codePers WHERE codeAp='"+ ui->rechercher_lineEdit->text()+"'");
            while(requet.next()){
                for(int i = 0; i<5; i++){
                    QStandardItem *item = new QStandardItem(requet.value(i).toString());
                    model->setItem(row, i, item);
                }
                row++;
            }

            model->setHeaderData(0,Qt::Horizontal, "Code d'approvisionnement");
            model->setHeaderData(1,Qt::Horizontal, "Date d'approvisionnement");
            model->setHeaderData(2,Qt::Horizontal, "Prenom du personnel");
            model->setHeaderData(3,Qt::Horizontal, "Nom du personnel");
            model->setHeaderData(4,Qt::Horizontal, "Fonction");

            ui->tableView_2->setModel(model);
            ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_2->resizeRowsToContents();
            ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        }
    }
}
void Approvisionnement::Afficher()
{
    QSqlQuery requet;
    int row(0);
     model = new QStandardItemModel(0, 5);
     requet.exec("SELECT approvisionnement.codeAp, approvisionnement.dateAp, personnel.prenomPers, personnel.nomPers, personnel.rolePers FROM approvisionnement INNER JOIN personnel ON approvisionnement.codePers = personnel.codePers");
     while(requet.next()){
         QColor color = (row % 2 == 0) ? Qt::lightGray : Qt::white;

         for(int i = 0; i<5; i++){
             QStandardItem *item = new QStandardItem(requet.value(i).toString());
             item->setBackground(color);
             model->setItem(row, i, item);
         }
         ++row;
     }

     model->setHeaderData(0,Qt::Horizontal, "Code d'approvisionnement");
     model->setHeaderData(1,Qt::Horizontal, "Date d'approvisionnement");
     model->setHeaderData(2,Qt::Horizontal, "Prenom du personnel");
     model->setHeaderData(3,Qt::Horizontal, "Nom du personnel");
     model->setHeaderData(4,Qt::Horizontal, "Fonction");

     ui->tableView_2->setModel(model);
     ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tableView_2->resizeColumnsToContents();
     ui->tableView_2->resizeRowsToContents();
     ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Approvisionnement::on_tableView_2_clicked(const QModelIndex &index)
{
        int row = index.row();
        QAbstractItemModel* model = ui->tableView_2->model();
        codeApp = model->data(model->index(row, 0)).toString();
        QSqlQuery detailQuery;
        detailQuery.prepare("SELECT approvisionnement.codeAp, produit.codePro, produit.nomPro, produit.qtePro, produit.dateExpiration, typeproduit.typePro FROM approvisionnement INNER JOIN approvisionner ON approvisionnement.codeAp = approvisionner.codeAp INNER JOIN produit ON approvisionner.codePro = produit.codePro INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType WHERE approvisionnement.codeAp = :codeApp");
        detailQuery.bindValue(":codeApp", codeApp);
        ui->rechercher_lineEdit->setText(codeApp);

        if (!detailQuery.exec()) {
            QMessageBox::warning(this, "Erreur", "Impossible de récupérer les détails de l'approvisionnement");
            return;
        }

        // Créer un modèle pour afficher les détails
        QStandardItemModel *detailModel = new QStandardItemModel(this);
        QStringList headers = { "Code Approvisionnement", "Code Produit", "Nom du produit", "Quantité", "Date Expiration", "Type du produit" };
        detailModel->setColumnCount(headers.size());
        for (int i = 0; i < headers.size(); ++i) {
            detailModel->setHeaderData(i, Qt::Horizontal, headers[i]);
        }

        // Remplir le modèle avec les résultats de la requête
        int rowCount = 0;
        while (detailQuery.next()) {
            QList<QStandardItem *> items;
            items.append(new QStandardItem(detailQuery.value("codeAp").toString()));
            items.append(new QStandardItem(detailQuery.value("codePro").toString()));
            items.append(new QStandardItem(detailQuery.value("nomPro").toString()));
            items.append(new QStandardItem(detailQuery.value("qtePro").toString()));
            items.append(new QStandardItem(detailQuery.value("dateExpiration").toString()));
            items.append(new QStandardItem(detailQuery.value("typePro").toString()));
            detailModel->appendRow(items);
            rowCount++;
        }

        // Afficher le modèle dans tableView
        ui->tableView->setModel(detailModel);

}

void Approvisionnement::GenererCodeProduit(const QString &text)
{
    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    if (text.isEmpty()) return;

    QSqlQuery query;
    query.prepare("SELECT codePro FROM produit WHERE codePro LIKE ?");
    query.addBindValue(text + '%');
    query.exec();

    QStringList suggestions;
    while (query.next()) {
        suggestions << query.value(0).toString();
    }

    completer->setModel(new QStringListModel(suggestions, completer));
    CaracteristiqueProduit();

    // Fermer la base de données proprement
    db.close();
}

void Approvisionnement::Completer()
{
    completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->code_lineEdit->setCompleter(completer);
}

void Approvisionnement::CaracteristiqueProduit()
{
    QString codePro = ui->code_lineEdit->text();
    if (codePro.isEmpty()) {
        //clearFields();
        return;
    }

    QSqlQuery requet;
    QString nomproduit, typePro;
    int qte = 0 ;
    QDate date ;
    requet.exec("SELECT produit.nomPro, produit.qtePro, produit.dateExpiration, typeproduit.typePro FROM produit INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType WHERE codePro ='"+ui->code_lineEdit->text()+"'");
    while(requet.next()){
        nomproduit = requet.value(0).toString();
        qte = requet.value(1).toInt();
        date = requet.value(2).toDate();
        typePro = requet.value(3).toString();
    }

    ui->nom_lineEdit->setText(nomproduit);
    ui->qte_spinBox->setValue(qte);
    ui->dateExpiration_dateEdit->setDate(date);
    ui->typeProduit_lineEdit->setText(typePro);
}

void Approvisionnement::on_vider_pushButton_clicked()
{
    QAbstractItemModel* model = ui->tableView->model(); // Récupérer le modèle de la tableView du panier
    if (model) {
        model->removeRows(0, model->rowCount()); // Supprimer toutes les lignes du modèle
    }
    ui->rechercher_lineEdit->clear();
}


void Approvisionnement::on_retour_pushButton_clicked()
{
    Afficher();
}


void Approvisionnement::on_deconnexion_pushButton_clicked()
{
    Login *deconnexion = new Login();
    deconnexion->show();
    close();

}


void Approvisionnement::on_imprime_pushButton_clicked()
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
                          "<td><center>" + col5 + "</center></td>"
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


void Approvisionnement::print(QPrinter *printer)
{
    text->print(printer);
}

void Approvisionnement::on_enregistrer_pushButton_2_clicked()
{
    // Vérifier si la tableView est vide
    if (model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "La table est vide. Veuillez ajouter des produits avant d'enregistrer.");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Erreur", "La base de données n'est pas ouverte");
        return;
    }

    db.transaction();

    // Générer un nouvel ID pour l'approvisionnement
    int idAp = 0;
    QSqlQuery r;
    if (r.exec("SELECT IFNULL(MAX(idAp), 0) + 1 FROM approvisionnement") && r.next()) {
        idAp = r.value(0).toInt();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le nouvel ID d'approvisionnement");
        db.rollback();
        return;
    }

    // Générer le codeAp basé sur le nouvel ID
    QString word = "Approvisionnement";
    QString troisPremiereLettre = word.left(3).toUpper();
    QString codeAp = troisPremiereLettre + QString("%1").arg(idAp, 2, 10, QChar('0'));

    // Vérifier si le codeAp existe déjà dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(codeAp) FROM approvisionnement WHERE codeAp = :codeAp");
    checkQuery.bindValue(":codeAp", codeAp);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Erreur", "Un approvisionnement avec ce code existe déjà.");
        db.rollback();
        return;
    }

    // Récupérer le code du personnel responsable de stock
    QSqlQuery req;
    QString codePers;
    QString role = "Responsable de stock";
    req.prepare("SELECT codePers FROM personnel WHERE rolePers = :role ORDER BY idPers DESC LIMIT 1");
    req.bindValue(":role", role);
    if (req.exec() && req.next()) {
        codePers = req.value(0).toString();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le code personnel");
        db.rollback();
        return;
    }

    // Insérer les informations dans la table approvisionnement (en dehors de la boucle)
    QSqlQuery requete;
    requete.prepare("INSERT INTO approvisionnement (codeAp, dateAp, codePers) VALUES (?, ?, ?)");
    requete.addBindValue(codeAp);
    requete.addBindValue(QDate::currentDate());
    requete.addBindValue(codePers);
    if (!requete.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table approvisionnement: " + requete.lastError().text());
        db.rollback();
        return;
    }

    // Insérer les produits du panier dans la table approvisionner et mettre à jour la table produit
    for (int row = 0; row < model->rowCount(); ++row) {
        QString codePro = model->data(model->index(row, 0)).toString();
        QString nomPro = model->data(model->index(row, 1)).toString();
        QString typePro = model->data(model->index(row, 2)).toString();
        QString caracteristique = model->data(model->index(row, 4)).toString();
        int qtePro = model->data(model->index(row, 3)).toInt();
        QDate dateExpiration = QDate::fromString(model->data(model->index(row, 5)).toString(), "yyyy-MM-dd");
        QDate dateApprovisionnement = QDate::fromString(model->data(model->index(row, 6)).toString(), "yyyy-MM-dd");

        // Insérer dans la table approvisionner
        QSqlQuery reqApprovisionner;
        reqApprovisionner.prepare("INSERT INTO approvisionner (codeAp, codePro) VALUES (?, ?)");
        reqApprovisionner.addBindValue(codeAp);
        reqApprovisionner.addBindValue(codePro);
        if (!reqApprovisionner.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table approvisionner: " + reqApprovisionner.lastError().text());
            db.rollback();
            return;
        }

        // Mettre à jour la table produit
        QSqlQuery reqProduit;
        reqProduit.prepare("UPDATE produit SET qtePro = qtePro + ?, dateExpiration = ?, caracteristique = ? WHERE codePro = ?");
        reqProduit.addBindValue(qtePro);
        reqProduit.addBindValue(dateExpiration);
        reqProduit.addBindValue(caracteristique);
        reqProduit.addBindValue(codePro);
        if (!reqProduit.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la table produit: " + reqProduit.lastError().text());
            db.rollback();
            return;
        }
    }

    // Commit transaction after the loop
    if (db.commit()) {
        QMessageBox::information(this, "Succès", "Approvisionnement enregistré avec succès");
        model->removeRows(0, model->rowCount());
        on_annuler_pushButton_clicked();
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'enregistrement de l'approvisionnement");
        db.rollback();
    }
    Afficher();
}
