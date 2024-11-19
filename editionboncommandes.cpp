#include "editionboncommandes.h"
#include "ui_editionboncommandes.h"
#include "Connexion.h"
#include "acceuilrespooperation.h"
#include "compta.h"
#include "mainwindow.h"

#include "QMessageBox"
#include <QStandardItemModel>
#include <QStandardItem>
#include "QSqlQuery"
#include <QDate>
#include <QTime>
#include <random>
#include <QCompleter>
#include <QtSql>
#include <QStringListModel>
#include <chrono>
#include <QPrinter>
#include <QDebug>
#include <QRegularExpression>
#include <QSqlError>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <iostream>

editionBonCommandes::editionBonCommandes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editionBonCommandes),
    panierModel(new QStandardItemModel(this)),
    ligneEnCours(-1)
{
    ui->setupUi(this);
    Connexion();
    remplirCombobox();
    currentDate();
    genererEtAfficherNumeroCommande();
    setupPanierModel();
    setupCommandeTableView();
    afficherCommandes();
    setupCompleter();
    showMaximized();

    connect(ui->codeproduit_lineEdit, &QLineEdit::textChanged, this, &editionBonCommandes::updateSuggestions);
    //connect(ui->codeproduit_lineEdit, &QLineEdit::editingFinished, this, &editionBonCommandes::fillDetails);
    connect(ui->tableView_2->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &editionBonCommandes::afficherDetailsCommande);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

editionBonCommandes::~editionBonCommandes()
{
    delete ui;
}
void editionBonCommandes::currentDate()
{
QDate dateCourante = QDate::currentDate();
QString dateStr = dateCourante.toString("dd/MM/yyyy");
ui->DateLabel->setText(dateStr);

}

void editionBonCommandes::genererEtAfficherNumeroCommande()
{
    // Initialiser le générateur de nombres aléatoires avec l'heure actuelle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    // Définir la distribution pour obtenir des nombres entre 1 et 1000
    std::uniform_int_distribution<int> distribution(1, 1000);

    // Générer un nombre aléatoire
    int nombreAleatoire = distribution(generator);

    // Obtenir l'année courante
    int anneeCourante = QDate::currentDate().year();

    // Créer le numéro de commande
    QString numeroCommande = QString("COM%1-%2").arg(anneeCourante).arg(nombreAleatoire, 3, 10, QChar('0'));

    // Afficher le numéro de commande dans l'interface utilisateur
    ui->numeroCommandeLabel->setText(numeroCommande);

    // Optionnel: afficher le numéro de commande dans la console pour le debug
    qDebug() << "Numéro de commande généré:" << numeroCommande;
}



void editionBonCommandes::remplirCombobox()
{
    QSqlQuery req;
    QString nomFournisseur;
    req.exec("SELECT nomF FROM fournisseur");
    ui->fournisseur_comboBox->clear();
    while(req.next())
    {
        nomFournisseur = req.value(0).toString();
        ui->fournisseur_comboBox->addItem(nomFournisseur);
    }

}


void editionBonCommandes::on_fournisseur_comboBox_currentTextChanged(const QString &arg1)
{
    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    QSqlQuery req;
    QString nomFournisseur, adresseFournisseur, contactFournisseur;

    req.exec("SELECT nomF, adresse, contact FROM fournisseur WHERE nomF='"+arg1+"'");
    if (req.next())
    {
        nomFournisseur = req.value(0).toString();
        adresseFournisseur = req.value(1).toString();
        contactFournisseur = req.value(2).toString();

        ui->NomFournisseurLabel->setText(nomFournisseur);
        ui->AdresseFournisseurLabel->setText(adresseFournisseur);
        ui->ContactFournisseurLabel->setText(contactFournisseur);
    }

    // Fermer la base de données proprement
    db.close();

}

void editionBonCommandes::setupPanierModel()
{
    // Définir les en-têtes de colonnes
    panierModel->setColumnCount(5); // Ajouter une colonne pour le code produit
    panierModel->setHeaderData(0, Qt::Horizontal, "Code Produit");
    panierModel->setHeaderData(1, Qt::Horizontal, "Description");
    panierModel->setHeaderData(2, Qt::Horizontal, "Quantité");
    panierModel->setHeaderData(3, Qt::Horizontal, "Prix U.");
    panierModel->setHeaderData(4, Qt::Horizontal, "Total");

    // Configurer le QTableView pour utiliser le modèle
    ui->tableView->setModel(panierModel);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Désactiver l'édition directe
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView { border: 1px solid #dcdcdc; }");

    // Ajuster les tailles des colonnes
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void editionBonCommandes::on_pushButton_4_clicked()
{
    // Obtenir les informations des champs du formulaire
       QString codeProduit = ui->codeproduit_lineEdit->text().trimmed();
       QString description = ui->description_lineEdit->text().trimmed();
       int quantite = ui->qte_spinBox->value();
       double prixUnitaire = ui->prixUnitaire_doubleSpinBox->value();
       double total = quantite * prixUnitaire;

       // Validation des champs
           if (codeProduit.isEmpty()) {
               QMessageBox::warning(this, "Erreur", "Le champ de code produit ne peut pas être vide.");
               return;
           }

          if (description.isEmpty()) {
              QMessageBox::warning(this, "Erreur", "Le champ de description ne peut pas être vide.");
              return;
          }

          if (quantite <= 0) {
              QMessageBox::warning(this, "Erreur", "Le champ de quantité doit être supérieur à 0.");
              return;
          }

          if (description.remove(" ").length() < 5) {
              QMessageBox::warning(this, "Erreur", "La description doit contenir au moins 5 caractères.");
              return;
          }

          // QRegularExpression re("\\d*");  // Expression régulière pour les entiers uniquement
          // if (re.match(description).hasMatch()) {
          //     QMessageBox::warning(this, "Erreur", "La description ne doit pas être composée uniquement de chiffres.");
          //     return;
          // }

       // Vérifier les doublons
       for (int row = 0; row < panierModel->rowCount(); ++row)
       {
           if (panierModel->item(row, 0)->text() == description)
           {
               // Le produit existe déjà dans le panier
               QMessageBox::StandardButton reply;
               reply = QMessageBox::question(this, "Produit existant", "Ce produit existe déjà dans le panier. Voulez-vous le modifier ?", QMessageBox::Yes | QMessageBox::No);
               if (reply == QMessageBox::Yes)
               {
                   // Modifier le produit existant
                   panierModel->item(row, 0)->setText(codeProduit);
                   panierModel->item(row, 1)->setText(QString::number(quantite));
                   panierModel->item(row, 2)->setText(QString::number(prixUnitaire, 'f', 2));
                   panierModel->item(row, 3)->setText(QString::number(total, 'f', 2));
               }
               return; // Sortir de la fonction
           }
       }

       // Créer des items pour chaque colonne
       QStandardItem *codeProduitItem = new QStandardItem(codeProduit);
       QStandardItem *descriptionItem = new QStandardItem(description);
       QStandardItem *quantiteItem = new QStandardItem(QString::number(quantite));
       QStandardItem *prixUnitaireItem = new QStandardItem(QString::number(prixUnitaire, 'f', 2));
       QStandardItem *totalItem = new QStandardItem(QString::number(total, 'f', 2));

       // Ajouter les items à une nouvelle ligne du modèle
       QList<QStandardItem*> rowItems;
       rowItems << codeProduitItem << descriptionItem << quantiteItem << prixUnitaireItem << totalItem;
       panierModel->appendRow(rowItems);
        // Optionnel : Vider les champs du formulaire après l'ajout
        ui->codeproduit_lineEdit->clear();
        ui->description_lineEdit->clear();
        ui->qte_spinBox->setValue(0);
        ui->prixUnitaire_doubleSpinBox->setValue(0.0);
        ui->total_doubleSpinBox->setValue(0.0);
}

void editionBonCommandes::on_pushButton_6_clicked()
{
    ui->description_lineEdit->clear();
    ui->qte_spinBox->setValue(0);
    ui->prixUnitaire_doubleSpinBox->setValue(0.0);
    ui->total_doubleSpinBox->setValue(0.0);
}

void editionBonCommandes::on_tableView_doubleClicked(const QModelIndex &index)
{
   ligneEnCours = index.row();
    QString codePro = panierModel->item(ligneEnCours, 0)->text();
   QString description = panierModel->item(ligneEnCours, 1)->text();
   int quantite = panierModel->item(ligneEnCours, 2)->text().toInt();
   double prixUnitaire = panierModel->item(ligneEnCours, 3)->text().toDouble();
   double totalPrixUnitaire = panierModel->item(ligneEnCours, 4)->text().toDouble();
   ui->codeproduit_lineEdit->setText(codePro);
   ui->description_lineEdit->setText(description);
   ui->qte_spinBox->setValue(quantite);
   ui->prixUnitaire_doubleSpinBox->setValue(prixUnitaire);
   ui->total_doubleSpinBox->setValue(totalPrixUnitaire);
}

void editionBonCommandes::on_modify_pushButton_clicked()
{
    if (ligneEnCours < 0) {
        return;
    }

    QString codeProduit = ui->codeproduit_lineEdit->text().trimmed();
    QString description = ui->description_lineEdit->text();
    int quantite = ui->qte_spinBox->value();
    double prixUnitaire = ui->prixUnitaire_doubleSpinBox->value();
    double total = quantite * prixUnitaire;

    // Validation des champs
    if (codeProduit.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les champs de code produit et description ne peuvent pas être vides.");
        return;
    }

    if (quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "Le champ de quantité doit être supérieur à 0.");
        return;
    }

    if (description.length() < 5) {
        QMessageBox::warning(this, "Erreur", "La description doit contenir au moins 5 caractères.");
        return;
    }

    QRegularExpression re("^\\d*$");
    QRegularExpressionMatch match = re.match(description);

    if (match.hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La description ne doit pas être composée uniquement de chiffres.");
        return;
    }

    panierModel->item(ligneEnCours, 0)->setText(codeProduit);
    panierModel->item(ligneEnCours, 1)->setText(description);
    panierModel->item(ligneEnCours, 2)->setText(QString::number(quantite));
    panierModel->item(ligneEnCours, 3)->setText(QString::number(prixUnitaire, 'f', 2));
    panierModel->item(ligneEnCours, 4)->setText(QString::number(total, 'f', 2));

    ui->codeproduit_lineEdit->clear();
    ui->description_lineEdit->clear();
    ui->qte_spinBox->setValue(0);
    ui->prixUnitaire_doubleSpinBox->setValue(0.0);
    ui->total_doubleSpinBox->setValue(0.0);

    ligneEnCours = -1;
}

void editionBonCommandes::on_tableView_clicked(const QModelIndex &index)
{
    ligneASupprimer = index.row();
}

void editionBonCommandes::on_delete_pushButton_clicked()
{
    if (ligneASupprimer < 0) {
            // Si aucune ligne n'est sélectionnée pour suppression, ne rien faire
            return;
        }

        // Afficher un message de confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation de suppression", "Êtes-vous sûr de vouloir supprimer cette ligne du panier ?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // Supprimer la ligne sélectionnée
            panierModel->removeRow(ligneASupprimer);

            // Réinitialiser l'index de la ligne à supprimer
            ligneASupprimer = -1;
        }
}

void editionBonCommandes::on_valider_pushButton_clicked()
{
    // Récupérer les informations des labels
    QString codeCommande = ui->numeroCommandeLabel->text();
    QString nomFournisseur = ui->NomFournisseurLabel->text();
    QString codeFournisseur;

    // Vérifier que le panier n'est pas vide
    if (panierModel->rowCount() == 0)
    {
        QMessageBox::warning(this, "Erreur", "Le panier est vide.");
        return;
    }

    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    // Vérifier si le code de commande existe déjà
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM commande WHERE codeCom = :codeCom");
    query.bindValue(":codeCom", codeCommande);
    if (!query.exec() || !query.next())
    {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification du code de commande.");
        return;
    }

    if (query.value(0).toInt() > 0)
    {
        // Le code de commande existe déjà, générer un nouveau code
        genererEtAfficherNumeroCommande();
        codeCommande = ui->numeroCommandeLabel->text();
        QMessageBox::information(this, "Nouveau code généré", "Le code de commande existe déjà. Un nouveau code a été généré : " + codeCommande);

        // Demander à l'utilisateur s'il souhaite poursuivre l'enregistrement
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Voulez-vous poursuivre l'enregistrement avec le nouveau code?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No)
        {
            return;
        }
    }

    // Utiliser une transaction pour garantir l'intégrité des données
    if (!db.transaction())
    {
        QMessageBox::critical(this, "Erreur", "Impossible de démarrer la transaction.");
        return;
    }

    // Rechercher le codeF du fournisseur
    query.prepare("SELECT codeF FROM fournisseur WHERE nomF = :nomFournisseur");
    query.bindValue(":nomFournisseur", nomFournisseur);
    if (!query.exec() || !query.next())
    {
        QMessageBox::critical(this, "Erreur", "Fournisseur non trouvé.");
        db.rollback(); // Annuler la transaction
        return;
    }
    codeFournisseur = query.value(0).toString();

    // Insérer chaque ligne du panier dans la table commande
    for (int row = 0; row < panierModel->rowCount(); ++row)
    {
        QString description = panierModel->item(row, 0)->text();
        int quantite = panierModel->item(row, 1)->text().toInt();
        double prixUnitaire = panierModel->item(row, 2)->text().toDouble();
        double totalPrixAchat = panierModel->item(row, 3)->text().toDouble();

        query.prepare("INSERT INTO commande (codeCom, dateCom, codeF, codePers, description, quantite, prixAchat, totalPrixAchat) "
                      "VALUES (:codeCom, :dateCom, :codeF, :codePers, :description, :quantite, :prixAchat, :totalPrixAchat)");
        query.bindValue(":codeCom", codeCommande);
        query.bindValue(":dateCom", QDate::currentDate().toString("yyyy-MM-dd"));
        query.bindValue(":codeF", codeFournisseur);
        query.bindValue(":codePers", "yourCodePers"); // Remplacez par le code personnel approprié
        query.bindValue(":description", description);
        query.bindValue(":quantite", quantite);
        query.bindValue(":prixAchat", prixUnitaire);
        query.bindValue(":totalPrixAchat", totalPrixAchat);

        if (!query.exec())
        {
            QMessageBox::critical(this, "Erreur", "Impossible d'enregistrer la commande : " + query.lastError().text());
            db.rollback(); // Annuler la transaction
            return;
        }
    }

    // Commiter la transaction
    if (!db.commit())
    {
        QMessageBox::critical(this, "Erreur", "Impossible de valider la transaction.");
        db.rollback(); // Annuler la transaction
        return;
    }

    QMessageBox::information(this, "Succès", "La commande a été enregistrée avec succès.");

    // Vider le panier
    panierModel->clear();
    setupPanierModel(); // Reconfigurer le modèle de table
    afficherCommandes();
    genererEtAfficherNumeroCommande();
    // Fermer la base de données proprement
    db.close();
}

void editionBonCommandes::setupCommandeTableView()
{
    // Configurer le modèle pour tableView_2
    commandeModel = new QStandardItemModel(this);
    commandeModel->setHorizontalHeaderLabels(QStringList() << "Code Commande" << "Date Commande" << "Fournisseur" << "Montant Total" << "Code Personnel");
    ui->tableView_2->setModel(commandeModel);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_2->setModel(commandeModel);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers); // Désactiver l'édition directe
    ui->tableView_2->setAlternatingRowColors(true);

    // Ajuster les tailles des colonnes
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void editionBonCommandes::afficherCommandes()
{
    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    // Requête pour récupérer les commandes avec les informations nécessaires
    QSqlQuery query;
    query.prepare(
        "SELECT c.codeCom, c.dateCom, f.nomF, SUM(c.totalPrixAchat) as montantTotal, c.codePers "
        "FROM commande c "
        "JOIN fournisseur f ON c.codeF = f.codeF "
        "GROUP BY c.codeCom, c.dateCom, f.nomF, c.codePers"
    );

    if (!query.exec())
    {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les commandes : " + query.lastError().text());
        return;
    }

    // Effacer le modèle existant
    commandeModel->removeRows(0, commandeModel->rowCount());

    // Remplir le modèle avec les résultats de la requête
    while (query.next())
    {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(query.value("codeCom").toString());
        rowItems << new QStandardItem(query.value("dateCom").toString());
        rowItems << new QStandardItem(query.value("nomF").toString());
        rowItems << new QStandardItem(query.value("montantTotal").toString());
        rowItems << new QStandardItem(query.value("codePers").toString());
        commandeModel->appendRow(rowItems);
    }

    // Fermer la base de données proprement
    db.close();
}


void editionBonCommandes::afficherDetailsCommande(const QModelIndex &current, const QModelIndex &previous)
{
    if (!current.isValid())
           return;

       // Récupérer le code de la commande de la ligne sélectionnée
       QString codeCommande = commandeModel->item(current.row(), 0)->text();

       // Ouvrir la base de données
       QSqlDatabase db = QSqlDatabase::database();
       if (!db.open())
       {
           QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
           return;
       }

       // Requête pour récupérer les détails de la commande
       QSqlQuery query;
       query.prepare("SELECT codePro, description, quantite, prixAchat, totalPrixAchat, dateCom, codeF, codePers FROM commande WHERE codeCom = :codeCom");
       query.bindValue(":codeCom", codeCommande);

       if (!query.exec())
       {
           QMessageBox::critical(this, "Erreur", "Impossible de récupérer les détails de la commande : " + query.lastError().text());
           return;
       }

       // Effacer le modèle existant du panier
       panierModel->clear();
       setupPanierModel(); // Reconfigurer le modèle de table

       QString codeFournisseur;
       QString dateCommande;
       QString codePersonnel;

       // Remplir le modèle du panier avec les résultats de la requête
       while (query.next())
       {
           QString codeProduit = query.value("codePro").toString();
           QString description = query.value("description").toString();
           int quantite = query.value("quantite").toInt();
           double prixUnitaire = query.value("prixAchat").toDouble();
           double total = query.value("totalPrixAchat").toDouble();
           dateCommande = query.value("dateCom").toString();
           codeFournisseur = query.value("codeF").toString();
           codePersonnel = query.value("codePers").toString();

           QStandardItem *codeProduitItem = new QStandardItem(codeProduit);
           QStandardItem *descriptionItem = new QStandardItem(description);
           QStandardItem *quantiteItem = new QStandardItem(QString::number(quantite));
           QStandardItem *prixUnitaireItem = new QStandardItem(QString::number(prixUnitaire, 'f', 2));
           QStandardItem *totalItem = new QStandardItem(QString::number(total, 'f', 2));

           QList<QStandardItem*> rowItems;
           rowItems <<codeProduitItem << descriptionItem << quantiteItem << prixUnitaireItem << totalItem;
           panierModel->appendRow(rowItems);
       }

       // Mettre à jour les labels de commande
       ui->numeroCommandeLabel->setText(codeCommande);
       ui->DateLabel->setText(dateCommande);

       // Requête pour récupérer les informations du fournisseur
       query.prepare("SELECT nomF, adresse, contact FROM fournisseur WHERE codeF = :codeF");
       query.bindValue(":codeF", codeFournisseur);

       if (!query.exec() || !query.next())
       {
           QMessageBox::critical(this, "Erreur", "Impossible de récupérer les informations du fournisseur : " + query.lastError().text());
           return;
       }

       QString nomFournisseur = query.value("nomF").toString();
       QString adresseFournisseur = query.value("adresse").toString();
       QString contactFournisseur = query.value("contact").toString();

       // Mettre à jour les labels du fournisseur
       ui->NomFournisseurLabel->setText(nomFournisseur);
       ui->AdresseFournisseurLabel->setText(adresseFournisseur);
       ui->ContactFournisseurLabel->setText(contactFournisseur);

       // Fermer la base de données proprement
       db.close();
}


void editionBonCommandes::setupCompleter()
{
    completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->codeproduit_lineEdit->setCompleter(completer);
}

void editionBonCommandes::updateSuggestions(const QString &text)
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
    fillDetails();

    // Fermer la base de données proprement
    db.close();
}

void editionBonCommandes::fillDetails()
{
    QString codePro = ui->codeproduit_lineEdit->text();
    if (codePro.isEmpty()) {
        clearFields();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT p.nomPro, p.dosage, p.nbrePieces, t.typePro "
                  "FROM produit p "
                  "JOIN typeproduit t ON p.codeType = t.codeType "
                  "WHERE p.codePro = ?");
    query.addBindValue(codePro);
    query.exec();

    if (query.next()) {
        QString nomPro = query.value(0).toString();
        QString dosage = query.value(1).toString();
        int nbrePieces = query.value(2).toInt();
        QString typePro = query.value(3).toString();

        QString description = nomPro + " " + dosage + " " + typePro;
        ui->description_lineEdit->setText(description);
        ui->nbrePieces_doubleSpinBox->setValue(nbrePieces);
    } else {
        clearFields();
    }
}

void editionBonCommandes::clearFields()
{
    ui->description_lineEdit->clear();
    ui->nbrePieces_doubleSpinBox->setValue(0);
}

void editionBonCommandes::on_qte_spinBox_valueChanged(int arg1)
{
    double prix = ui->prixUnitaire_doubleSpinBox->value();
    ui->total_doubleSpinBox->setValue(arg1*prix);

}


void editionBonCommandes::on_prixUnitaire_doubleSpinBox_valueChanged(double arg1)
{
    int qte = ui->qte_spinBox->value();
    ui->total_doubleSpinBox->setValue(qte*arg1);
}



void editionBonCommandes::on_Accueil_clicked()
{
    close();

    AcceuilREspoOperation *acceuilWindow = new AcceuilREspoOperation();
    acceuilWindow->show();
}


void editionBonCommandes::on_tresorerie_clicked()
{
    close();

    Compta *tresorerie = new Compta();
    tresorerie->show();
}


void editionBonCommandes::on_rapport_statistique_clicked()
{
    close();

    MainWindow *rapportVente = new MainWindow();
    rapportVente->show();
}


void editionBonCommandes::on_tableView_2_clicked(const QModelIndex &index)
{

}


void editionBonCommandes::on_print_pushButton_clicked()
{
    QSqlQuery query;
    if(!query.exec("SELECT  description, quantite, prixAchat, totalPrixAchat, dateCom FROM commande")){
        std::cout <<"Echec de l'éxécution de la requête";
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
             "<th>Type Produit</th>"
             "<th> Produit</th>"
             "<th>Quantité</th>"
             "<th>Prix achat</th>"
             "<th>Total</th>"
             "</tr>"
             "</thead>"
             "<tbody>";

    while (query.next()) {
        QString col1 = query.value(0).toString();
        QString col2 = query.value(1).toString();
        QString col3 = query.value(2).toString();
        QString col4 = query.value(3).toString();
        QString col5 = query.value(4).toString();

        texte += "<tr>"
                 "<td>" + col1 + "</td>"
                          "<td>" + col2 + "</td>"
                          "<td>" + col3 + "</td>"
                          "<td>" + col4 + "</td>"
                          "<td>" + col5 + "</td>"
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

void editionBonCommandes::print(QPrinter *printer)
{
    text->print(printer);
}
