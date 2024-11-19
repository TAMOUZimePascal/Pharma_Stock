#include "commandenonsatisfaite.h"
#include "ui_commandenonsatisfaite.h"
#include "Connexion.h"
#include "QMessageBox"
#include "QSqlQuery"
#include "QSqlDatabase"
#include "QStringListModel"
#include "QModelIndex"
#include "QSqlError"
#include "QDateTime"
#include "QPrintPreviewDialog"
#include "iostream"

CommandeNonSatisfaite::CommandeNonSatisfaite(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommandeNonSatisfaite)
{
    ui->setupUi(this);
    showMaximized();

    detailModel = new QStandardItemModel(this);

    Connexion();
    Afficher();
    Completer();
    showMaximized();

    connect(ui->rechercher_lineEdit, &QLineEdit::textChanged, this, &CommandeNonSatisfaite::GenererCodeProduit);
    //connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &CommandeNonSatisfaite::afficherDetailsCommande);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &CommandeNonSatisfaite::afficherDetailsCommande);
}

CommandeNonSatisfaite::~CommandeNonSatisfaite()
{
    delete ui;
}

void CommandeNonSatisfaite::GenererCodeProduit(const QString &text)
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
    query.prepare("SELECT codeV FROM vente WHERE codeV LIKE ? AND statut = ?");
    query.addBindValue(text + '%');
    query.addBindValue("Non satisfait");

    if (!query.exec()) {
        // Gérer l'erreur si la requête échoue
        QMessageBox::warning(this, "Erreur", "Impossible d'exécuter la requête : " + query.lastError().text());
        return;
    }

    // Traiter les résultats de la requête
    QStringList suggestions;
    while (query.next()) {
        suggestions << query.value(0).toString();
    }

    completer->setModel(new QStringListModel(suggestions, completer));
    //CaracteristiqueProduit( &index);

    // Fermer la base de données proprement
    db.close();
}

void CommandeNonSatisfaite::Completer()
{
    completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->rechercher_lineEdit->setCompleter(completer);
}

void CommandeNonSatisfaite::CaracteristiqueProduit(const QModelIndex &index)
{
    int row = index.row();
    QString statut="Non satisfait";
    QAbstractItemModel* model = ui->tableView->model();
    codeV = model->data(model->index(row, 3)).toString();
    ui->rechercher_lineEdit->setText(codeV);
    QSqlQuery detailQuery;
    detailQuery.prepare("SELECT client.nomCli,   client.telephoneCli, client.adresseCli, vente.codeV, vente.montantV, vente.dateV, personnel.nomPers, personnel.prenomPers FROM client INNER JOIN vente ON client.codeCli = vente.codeCli INNER JOIN personnel ON vente.codePers = personnel.codePers WHERE vente.statut ='"+statut+"'");
    detailQuery.bindValue(":codeV", codeV);

    if (!detailQuery.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur d'exécution");
        return;
    }

    // Créer un modèle pour afficher les détails
    QStandardItemModel *detailModel = new QStandardItemModel(this);
    QStringList headers = { "Nom client", "Téléphone", "Adresse du client", "Code de la vente", "Montant ", "Date de la vente", "Nom du personnel","Prénom du personnel" };
    detailModel->setColumnCount(headers.size());
    for (int i = 0; i < headers.size(); ++i) {
        detailModel->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    // Remplir le modèle avec les résultats de la requête
    int rowCount = 0;
    while (detailQuery.next()) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(detailQuery.value("Nom client").toString()));
        items.append(new QStandardItem(detailQuery.value("Téléphone").toString()));
        items.append(new QStandardItem(detailQuery.value("Adresse du client").toString()));
        items.append(new QStandardItem(detailQuery.value("Code de la vente").toString()));
        items.append(new QStandardItem(detailQuery.value("Montant").toString()));
        items.append(new QStandardItem(detailQuery.value("Date de la vente").toString()));
        items.append(new QStandardItem(detailQuery.value("Nom du personnel").toString()));
        items.append(new QStandardItem(detailQuery.value("Prénom du personnel").toString()));
        detailModel->appendRow(items);
        rowCount++;
    }

    // Afficher le modèle dans tableView
    ui->tableView->setModel(detailModel);
}
  /*  QSqlQuery requet;
    QString nomproduit, typePro;
    int qte = 0 ;
    QDate date ;
    requet.exec("SELECT typeproduit.typePro, produit.nomPro, produit.qtePro, produit.dateExpiration FROM typeproduit INNER JOIN produit ON typeproduit.codeType = produit.codeType INNER JOIN vendre ON produit.codePro = vendre.codePro INNER JOIN vente ON vendre.codeV = vente.codeV  WHERE vente.codeV ='"+ui->rechercher_lineEdit->text()+"'");
    while(requet.next()){
        nomproduit = requet.value(0).toString();
        qte = requet.value(1).toInt();
        date = requet.value(2).toDate();
        typePro = requet.value(3).toString();
    }*/


void CommandeNonSatisfaite::on_rechercher_pushButton_clicked()
{/*
    if(ui->rechercher_lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur","Veuillez renseigner le champs de recherche !");
    }else{
        int compteur = 0;
        QSqlQuery requete;
            requete.exec("SELECT COUNT( codeV) FROM vente WHERE codeV ='"+ui->rechercher_lineEdit->text()+"'");
        while (requete.next()) {

            compteur = requete.value(0).toInt();
        }
        if(compteur == 0)
        {
             QMessageBox::warning(this, "Erreur","Code invalide");
        }else{
            int row(0);
            model = new QStandardItemModel(0, 8);
            QString statut = "Non satisfait";
            QSqlQuery requete;
            requete.exec("SELECT client.nomCli,   client.telephoneCli, client.adresseCli, vente.codeV, vente.montantV, vente.dateV, personnel.nomPers, personnel.prenomPers FROM client INNER JOIN vente ON client.codeCli = vente.codeCli INNER JOIN personnel ON vente.codePers = personnel.codePers WHERE vente.statut ='"+statut+"'");
            while (requete.next()) {
                for(int i = 0; i<8; i++){
                    QStandardItem *item = new QStandardItem(requete.value(i).toString());
                    model->setItem(row, i, item);
                }
                row++;
            }

            model->setHeaderData(0,Qt::Horizontal, "Nom client");
            model->setHeaderData(1,Qt::Horizontal, "Téléphone");
            model->setHeaderData(2,Qt::Horizontal, "Adresse");
            model->setHeaderData(3,Qt::Horizontal, "Code de vente");
            model->setHeaderData(4,Qt::Horizontal, "Montant ");
            model->setHeaderData(5,Qt::Horizontal, "Date de la vente");
            model->setHeaderData(6,Qt::Horizontal, "Nom du personnel");
            model->setHeaderData(7,Qt::Horizontal, "Prénom du personnel");

            ui->tableView->setModel(model);
            ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tableView->resizeColumnsToContents();
            ui->tableView->resizeRowsToContents();
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        }
    }*/
}


void CommandeNonSatisfaite::Afficher()
{

    int row(0);
    model = new QStandardItemModel(0, 8);
    QString statut = "Non satisfait";
    QSqlQuery requete;
    requete.exec("SELECT client.nomCli,   client.telephoneCli, client.adresseCli, vente.codeV, vente.montantV, vente.dateV, personnel.nomPers, personnel.prenomPers FROM client INNER JOIN vente ON client.codeCli = vente.codeCli INNER JOIN personnel ON vente.codePers = personnel.codePers WHERE vente.statut ='"+statut+"'");
    while (requete.next()) {
        for(int i = 0; i<8; i++){
            QStandardItem *item = new QStandardItem(requete.value(i).toString());
            model->setItem(row, i, item);
        }
        row++;
    }

    model->setHeaderData(0,Qt::Horizontal, "Nom client");
    model->setHeaderData(1,Qt::Horizontal, "Téléphone");
    model->setHeaderData(2,Qt::Horizontal, "Adresse");
    model->setHeaderData(3,Qt::Horizontal, "Code de vente");
    model->setHeaderData(4,Qt::Horizontal, "Montant ");
    model->setHeaderData(5,Qt::Horizontal, "Date de la vente");
    model->setHeaderData(6,Qt::Horizontal, "Nom du personnel");
    model->setHeaderData(7,Qt::Horizontal, "Prénom du personnel");

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void CommandeNonSatisfaite::on_modifier_pushButton_clicked()
{
    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

        QString codeV = ui->rechercher_lineEdit->text();
        QString codePro = ui->codeProduit_lineEdit->text();
        int qteSaisie = ui->qte_spinBox->value();

        if (codeV.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez renseigner le champ de recherche !");
            return;
        }

        // Vérifier l'existence du code de vente
        QSqlQuery requete;
        requete.prepare("SELECT COUNT(codeV) FROM vente WHERE codeV = :codeV");
        requete.bindValue(":codeV", codeV);

        if (!requete.exec() || !requete.next() || requete.value(0).toInt() == 0) {
            QMessageBox::warning(this, "Erreur", "Code de vente invalide");
            return;
        }

        // Vérifier l'existence du code produit
        requete.prepare("SELECT COUNT(codePro) FROM vendre WHERE codePro = :codePro AND codeV = :codeV");
        requete.bindValue(":codePro", codePro);
        requete.bindValue(":codeV", codeV);

        if (!requete.exec() || !requete.next() || requete.value(0).toInt() == 0) {
            QMessageBox::warning(this, "Erreur", "Code produit n'existe pas pour cette vente");
            return;
        }

        // Récupérer la quantité non satisfaite
        int qteNonSatisfaite = 0;
        requete.prepare("SELECT qteNonSatisfait FROM vendre WHERE codePro = :codePro AND codeV = :codeV");
        requete.bindValue(":codePro", codePro);
        requete.bindValue(":codeV", codeV);

        if (requete.exec() && requete.next()) {
            qteNonSatisfaite = requete.value(0).toInt();

            // Vérifier que la quantité saisie ne dépasse pas la quantité non satisfaite
            if (qteSaisie > qteNonSatisfaite) {
                QMessageBox::warning(this, "Erreur", "La quantité saisie est supérieure à la quantité non satisfaite");
                return;
            }

            // Mettre à jour les quantités dans la table "vendre"
            requete.prepare("UPDATE vendre SET qteNonSatisfait = qteNonSatisfait - :qteSaisie WHERE codePro = :codePro AND codeV = :codeV");
            requete.bindValue(":qteSaisie", qteSaisie);
            requete.bindValue(":codePro", codePro);
            requete.bindValue(":codeV", codeV);

            if (!requete.exec()) {
                QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour des quantités");
                return;
            }

            // Si la quantité non satisfaite est maintenant nulle, mettre à jour le statut de la vente
            if (qteNonSatisfaite - qteSaisie == 0) {
                requete.prepare("UPDATE vente SET statut = 'Satisfait' WHERE codeV = :codeV");
                requete.bindValue(":codeV", codeV);

                if (!requete.exec()) {
                    QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour du statut de la vente");
                    return;
                }
            }

            // Rafraîchir l'affichage
            Afficher();
            QMessageBox::information(this, "Statut modification", "Modification réussie");

        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de récupérer la quantité non satisfaite");
            return;
        }
    }


void CommandeNonSatisfaite::on_tableView_clicked(const QModelIndex &index)
{

/*        if (!index.isValid()) {
            QMessageBox::warning(this, "Erreur", "Index non valide");
            return;
        }

        int row = index.row();
        QAbstractItemModel* model = ui->tableView->model();
        QString codeV = model->data(model->index(row, 3)).toString();

        if (codeV.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Code de vente non valide");
            return;
        }

        ui->rechercher_lineEdit->setText(codeV);

    QSqlQuery detailQuery;
    detailQuery.prepare(R"(
        SELECT tp.typePro, p.codePro, p.nomPro, p.prixUnit,
               p.dateExpiration, vd.qteNonSatisfait, v.codeV
        FROM typeproduit tp
        INNER JOIN produit p ON tp.codeType = p.codeType
        INNER JOIN vendre vd ON p.codePro = vd.codePro
        INNER JOIN vente v ON vd.codeV = v.codeV
        WHERE v.codeV = :codeV
    )");
    detailQuery.bindValue(":codeV",codeV);

    if (!detailQuery.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les détails de la vente : " + detailQuery.lastError().text());
        return;
    }

    // Créer un modèle pour afficher les détails
    QStandardItemModel *detailModel = new QStandardItemModel(this);
    QStringList headers = { "Type du produit", "Code Produit", "Nom du produit", "Prix unitaire", "Date Expiration", "Quantité Non Satisfaite", "Code de Vente" };
    detailModel->setColumnCount(headers.size());
    for (int i = 0; i < headers.size(); ++i) {
        detailModel->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    // Remplir le modèle avec les résultats de la requête
    while (detailQuery.next()) {
        QList<QStandardItem *> items;
        QString typePro = detailQuery.value("typePro").toString();
        QString codePro = detailQuery.value("codePro").toString();
        QString nomPro = detailQuery.value("nomPro").toString();
        QString prixUnit = detailQuery.value("prixUnit").toString();
        QString dateExpiration = detailQuery.value("dateExpiration").toString();
        QString qteNonSatisfait = detailQuery.value("qteNonSatisfait").toString();
        QString codeVente = detailQuery.value("codeV").toString();

        QStandardItem *itemTypePro = new QStandardItem(typePro);
        QStandardItem *itemCodePro = new QStandardItem(codePro);
        QStandardItem *itemNomPro = new QStandardItem(nomPro);
        QStandardItem *itemPrixUnit = new QStandardItem(prixUnit);
        QStandardItem *itemDateExpiration = new QStandardItem(dateExpiration);
        QStandardItem *itemQteNonSatisfait = new QStandardItem(qteNonSatisfait);
        QStandardItem *itemCodeV = new QStandardItem(codeVente);

        items.append(itemTypePro);
        items.append(itemCodePro);
        items.append(itemNomPro);
        items.append(itemPrixUnit);
        items.append(itemDateExpiration);
        items.append(itemQteNonSatisfait);
        items.append(itemCodeV);

        detailModel->appendRow(items);
    }

    // Afficher le modèle dans tableView_2
    ui->tableView_2->setModel(detailModel);
*/
}

// imprimé
void CommandeNonSatisfaite::on_pushButton_clicked()
{
    QSqlQuery query;
    if (!query.exec("SELECT tp.typePro, p.nomPro, p.dosage, p.prixUnit, vd.qteVendue, vd.qteNonSatisfait, v.montantV FROM typeproduit tp INNER JOIN produit p ON tp.codeType = p.codeType INNER JOIN vendre vd ON p.codePro = vd.codePro INNER JOIN vente v ON vd.codeV = v.codeV WHERE v.codeV ='" + ui->rechercher_lineEdit->text() + "'")) {
        std::cout << "Échec de l'exécution de la requête: " << query.lastError().text().toStdString() << std::endl;
        return;
    }

    QDateTime currentDate = QDateTime::currentDateTime();
    QString DateCourante = currentDate.toString("yyyy-MM-dd");

    text = new QTextEdit;
    QString texte;
    texte += "<!DOCTYPE html><html>"
             "<head>"
             "<link rel='stylesheet' type='text/css' href='styles.css'>"
             "</head>"
             "<body>";

    texte += "<header>"
             "<img src='Mes_images/GestionStock.png' class='logo-gauche'>"
             "<h1>PHARMASTOCK</h1>"
             "<img src='Mes_images/GestionStock.png' class='logo-droite'>"
             "<p>Vente de produits pharmaceutiques, laboratoire de recherche, distributeur de produits pharmaceutiques.</p>"
             "<p>Lieu: Parakou, Qtier: Arafat, situé à 200m du campus en allant à baka<br>"
             "Tél: 61359067 / 55375315</p>"
             "</header>";

    texte += "<main>"
             "<h2>Liste des fournisseurs</h2>"
             "<table>"
             "<thead>"
             "<tr>"
             "<th>Type de produit</th>"
             "<th>Nom du produit</th>"
             "<th>Dosage</th>"
             "<th>Prix unitaire</th>"
             "<th>Quantité</th>"
             "<th>Montant par produit</th>"
             "</tr>"
             "</thead>"
             "<tbody>";

    double montant_total = 0;

    while (query.next()) {
        QString col1 = query.value(0).toString();
        QString col2 = query.value(1).toString();
        QString col3 = query.value(2).toString();
        double col4 = query.value(3).toDouble();
        int col5 = query.value(4).toInt();
        double col6 = query.value(5).toDouble();

        montant_total += col6;

        texte += "<tr>"
                 "<td>" + col1 + "</td>"
                          "<td>" + col2 + "</td>"
                          "<td>" + col3 + "</td>"
                          "<td>" + QString::number(col4, 'f', 2) + "</td>"
                                                   "<td>" + QString::number(col5) + "</td>"
                                           "<td>" + QString::number(col6, 'f', 2) + "</td>"
                                                   "</tr>";
    }

    texte += "<tr><td colspan='5'>Montant total</td><td>" + QString::number(montant_total, 'f', 2) + "</td></tr>";

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

    connect(&dialog, &QPrintPreviewDialog::paintRequested, this, &CommandeNonSatisfaite::print);

    dialog.showMaximized();
    dialog.exec();
}

void CommandeNonSatisfaite::print(QPrinter *printer)
{
    text->print(printer);
}


void CommandeNonSatisfaite::afficherDetailsCommande(const QModelIndex &current, const QModelIndex &previous)
{
    if (!current.isValid())
        return;

    // Récupérer le code de la vente de la ligne sélectionnée
    QString codeV = model->item(current.row(), 3)->text();

    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    // Requête pour récupérer les détails de la commande
    QSqlQuery query;
    query.prepare(R"(
        SELECT tp.typePro, p.codePro, p.nomPro, p.prixUnit,
               p.dateExpiration, vd.qteNonSatisfait, v.codeV
        FROM typeproduit tp
        INNER JOIN produit p ON tp.codeType = p.codeType
        INNER JOIN vendre vd ON p.codePro = vd.codePro
        INNER JOIN vente v ON vd.codeV = v.codeV
        WHERE v.codeV = :codeV
    )");
    query.bindValue(":codeV", codeV);

    if (!query.exec())
    {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les détails de la vente : " + query.lastError().text());
        return;
    }

    // Effacer le modèle existant du panier
    detailModel->clear();
    setupPanierModel(); // Reconfigurer le modèle de table


    // Remplir le modèle du panier avec les résultats de la requête
    while (query.next())
    {
        QString typePro = query.value("typePro").toString();
        QString codePro = query.value("codePro").toString();
        QString nomPro = query.value("nomPro").toString();
        double prixUnit = query.value("prixUnit").toDouble();
        QString dateExpiration = query.value("dateExpiration").toString();
        int qteNonSatisfait = query.value("qteNonSatisfait").toInt();
        QString codeVente = query.value("codeV").toString();

        QStandardItem *itemTypePro = new QStandardItem(typePro);
        QStandardItem *itemCodePro = new QStandardItem(codePro);
        QStandardItem *itemNomPro = new QStandardItem(nomPro);
        QStandardItem *itemPrixUnit = new QStandardItem(QString::number(prixUnit, 'f', 2));
        QStandardItem *itemDateExpiration = new QStandardItem(dateExpiration);
        QStandardItem *itemQteNonSatisfait = new QStandardItem(QString::number(qteNonSatisfait));
        QStandardItem *itemCodeV = new QStandardItem(codeVente);

        QList<QStandardItem*> rowItems;
        rowItems << itemTypePro << itemCodePro << itemNomPro << itemPrixUnit << itemDateExpiration << itemQteNonSatisfait << itemCodeV;
        detailModel->appendRow(rowItems);
    }

    // Mettre à jour les labels de commande
    ui->rechercher_lineEdit->setText(codeV);


    // Fermer la base de données proprement
    db.close();
}


void CommandeNonSatisfaite::setupPanierModel()
{
    // Définir les en-têtes de colonnes
    detailModel->setColumnCount(7); // Ajouter une colonne pour le code produit
    detailModel->setHeaderData(0, Qt::Horizontal, "Type Produit");
    detailModel->setHeaderData(1, Qt::Horizontal, "Code Produit");
    detailModel->setHeaderData(2, Qt::Horizontal, "Nom produit");
    detailModel->setHeaderData(3, Qt::Horizontal, "Prix U.");
    detailModel->setHeaderData(4, Qt::Horizontal, "Date d'expiration");
    detailModel->setHeaderData(5, Qt::Horizontal, "Quantité non satisfaite");
    detailModel->setHeaderData(6, Qt::Horizontal, "Code vente");

    // Configurer le QTableView pour utiliser le modèle
    ui->tableView_2->setModel(detailModel);

    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers); // Désactiver l'édition directe
    ui->tableView_2->setAlternatingRowColors(true);
    ui->tableView_2->setStyleSheet("QTableView { border: 1px solid #dcdcdc; }");

    // Ajuster les tailles des colonnes
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void CommandeNonSatisfaite::on_tableView_2_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Index non valide");
        return;
    }

    int row = index.row();
    QAbstractItemModel* model = ui->tableView_2->model();
    QString codePro = model->data(model->index(row, 1)).toString();

    if (codePro.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Code de vente non valide");
        return;
    }

    ui->codeProduit_lineEdit->setText(codePro);


}

