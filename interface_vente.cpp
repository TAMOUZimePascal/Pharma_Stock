#include "interface_vente.h"
#include "ui_interface_vente.h"
#include "Connexion.h"
#include "interface_client.h"
#include "qtedelegate.h"
#include "login.h"
#include "interface_client.h"

#include "QMessageBox"
#include "QSqlQuery"
#include "QDate"
#include "QSqlError"
#include "QAbstractItemModel"
#include "QStandardItemModel"
#include "QTableView"
#include <QSqlDatabase>
#include <QPrintDialog>
#include <QPainter>
#include <QCompleter>
#include <QStringListModel>
#include "iostream"
#include "QPrintPreviewDialog"


Interface_Vente::Interface_Vente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface_Vente)
{
    ui->setupUi(this);
    showMaximized();
    Connexion();
    Afficher();
    populateNomClientComboBox();
    setupCompleter();
    on_Annuler_pushButton_clicked();


    connect(ui->code_produit_lineEdit, &QLineEdit::textChanged, this, &Interface_Vente::updateSuggestions);


    model = new QStandardItemModel(0, 7, this);
    model->setHorizontalHeaderLabels({"Code Produit", "Nom du Produit", "Type de Produit", "Prix du Produit", "Quantité", "Montant ", "Date d'expiration"});
    ui->detailVente_tableView->setModel(model);
    ui->detailVente_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->detailVente_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->detailVente_tableView->resizeColumnsToContents();
    ui->detailVente_tableView->resizeRowsToContents();
    ui->detailVente_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QteDelegate *delegate = new QteDelegate(this);
    ui->detailVente_tableView->setItemDelegateForColumn(4, delegate); // Appliquer le délégué à la colonne de la quantité

}

Interface_Vente::~Interface_Vente()
{
    delete ui;
}

void Interface_Vente::on_quantite_produit_spinBox_valueChanged(int arg1)
{
    ui->montant_doubleSpinBox->clear();
    qte = ui->quantite_produit_spinBox->value();
    prix = ui->prix_unitaire_doubleSpinBox->value();
    montant = qte*prix;
    ui->montant_doubleSpinBox->setValue(montant);


}


void Interface_Vente::populateNomClientComboBox()
{
    ui->nomClient_comboBox->clear(); // Efface les éléments existants

    QSqlQuery query;
    query.prepare("SELECT nomCli FROM client");

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les noms des clients");
        return;
    }

    while (query.next()) {
        QString nomClient = query.value("nomCli").toString();
        ui->nomClient_comboBox->addItem(nomClient);
    }
}



void Interface_Vente::on_code_produit_lineEdit_textChanged(const QString &arg1)
{
    // ui->nom_produit_lineEdit->clear();
    // ui->type_produit_lineEdit->clear();
    // ui->prix_unitaire_doubleSpinBox->setValue(0);
    // ui->quantite_produit_spinBox->setValue(0);
    // ui->montant_doubleSpinBox->setValue(0);

    // QSqlQuery requete;
    // requete.prepare("SELECT produit.nomPro, produit.prixUnit, produit.qtePro, typeproduit.typePro "
    //                     "FROM produit "
    //                     "INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType "
    //                     "WHERE produit.codePro = :codePro");
    // requete.bindValue(":codePro", ui->code_produit_lineEdit->text());

    // if (requete.exec()) {
    //      if (requete.next()) {
    //           QString nomPro = requete.value(0).toString();
    //           double prix = requete.value(1).toDouble();
    //           int qtePro = requete.value(2).toInt();
    //           QString typePro = requete.value(3).toString();

    //           ui->nom_produit_lineEdit->setText(nomPro);
    //           ui->quantite_produit_spinBox->setValue(qtePro);
    //           ui->type_produit_lineEdit->setText(typePro);
    //           ui->prix_unitaire_doubleSpinBox->setValue(prix);
    //         }
    //   } else{
    //        QMessageBox::warning(this, "Error","Erreur lors de l'exécution de la requête");
    //     }
    //     codePro = ui->code_produit_lineEdit->text();
  }



  void Interface_Vente::recalculateMontantTotal()
  {
      QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->detailVente_tableView->model());
      if (!model) {
          QMessageBox::warning(this, "Erreur", "Modèle de la table de détail non trouvé");
          return;
      }

      montant_total = 0.0;
      for (int row = 0; row < model->rowCount(); ++row) {
          montant_total += model->item(row, 5)->text().toDouble();
      }

      ui->montant_total_doubleSpinBox->setValue(montant_total);
  }


  void Interface_Vente::on_AjouterPanier_pushButton_clicked()
  {
      // Ouvrir la base de données
      QSqlDatabase db = QSqlDatabase::database();
      if (!db.open())
      {
          QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
          return;
      }

      if (ui->code_produit_lineEdit->text().isEmpty() ||
          ui->nom_produit_lineEdit->text().isEmpty() ||
          ui->type_produit_lineEdit->text().isEmpty() ||
          ui->prix_unitaire_doubleSpinBox->value() == 0.00 ||
          ui->quantite_produit_spinBox->value() == 0 ||
          ui->montant_doubleSpinBox->value() == 0.00)
      {
          QMessageBox::warning(this, "Attention", "Veuillez renseigner des informations correctes");
          return;
      }

      QString codePro = ui->code_produit_lineEdit->text();
      QString nomPro = ui->nom_produit_lineEdit->text();
      QString typePro = ui->type_produit_lineEdit->text();
      double prix = ui->prix_unitaire_doubleSpinBox->value();
      int qteDemandee = ui->quantite_produit_spinBox->value();
      double montant = ui->montant_doubleSpinBox->value();

      QSqlQuery req;
      QDate date;
      int qteDispo = 0;

      // Vérifier la date d'expiration et la quantité disponible
      req.prepare("SELECT dateExpiration, qtePro FROM produit WHERE codePro = :codePro");
      req.bindValue(":codePro", codePro);

      if (!req.exec()) {
          QMessageBox::warning(this, "Erreur", "Échec de l'exécution de la requête: " + req.lastError().text());
          return;
      }

      if (req.next()) {
          date = req.value(0).toDate();
          qteDispo = req.value(1).toInt();
      } else {
          QMessageBox::warning(this, "Erreur", "Produit non trouvé ou quantités non disponibles");
          return;
      }

      int qteNonSatisfaite = 0;
      if (qteDemandee > qteDispo) {
          QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Quantité Insuffisante",
                                        QString("La quantité demandée ne peut pas être livrée actuellement car il ne reste que %1 en stock. Voulez-vous enregistrer les %2 restants comme quantité non satisfaite ?")
                                            .arg(qteDispo).arg(qteDemandee - qteDispo),
                                        QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::No) {
              return;
          }
          ui->statut_comboBox->setCurrentText("Non satisfait");
          qteNonSatisfaite = qteDemandee - qteDispo;
      }

      // Vérifier les doublons
      QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->detailVente_tableView->model());

      if (!model) {
          QMessageBox::warning(this, "Erreur", "Modèle de la table de détail non trouvé");
          return;
      }

      for (int row = 0; row < model->rowCount(); ++row) {
          if (model->item(row, 0)->text() == codePro) {
              // Le produit existe déjà dans la vente
              QMessageBox::StandardButton reply;
              reply = QMessageBox::question(this, "Produit Existant",
                                            "Le produit existe déjà dans le panier. Voulez-vous le modifier ?",
                                            QMessageBox::Yes|QMessageBox::No);
              if (reply == QMessageBox::No) {
                  return;
              }

              // Utiliser la nouvelle quantité saisie
              int newQte = qteDemandee;

              // Vérifier à nouveau la quantité disponible
              if (newQte > qteDispo) {
                  qteNonSatisfaite = newQte - qteDispo;
              }

              double newMontant = newQte * prix;

              model->item(row, 4)->setText(QString::number(newQte));
              model->item(row, 5)->setText(QString::number(newMontant, 'f', 2));
              model->item(row, 6)->setText(date.toString("yyyy-MM-dd"));
              model->item(row, 4)->setData(qteNonSatisfaite, Qt::UserRole + 1); // Stocker la quantité non satisfaite

              // Notifier la vue que les données ont changé
              model->dataChanged(model->index(row, 4), model->index(row, 4));
              model->dataChanged(model->index(row, 5), model->index(row, 5));
              model->dataChanged(model->index(row, 6), model->index(row, 6));

              recalculateMontantTotal();

              on_Annuler_pushButton_clicked();
              return;
          }
      }

      // Ajouter un nouveau produit
      QList<QStandardItem*> items;
      items.append(new QStandardItem(codePro));
      items.append(new QStandardItem(nomPro));
      items.append(new QStandardItem(typePro));
      items.append(new QStandardItem(QString::number(prix, 'f', 2)));
      items.append(new QStandardItem(QString::number(qteDemandee))); // Afficher la quantité demandée
      items.last()->setData(qteNonSatisfaite, Qt::UserRole + 1); // Stocker la quantité non satisfaite
      items.append(new QStandardItem(QString::number(montant, 'f', 2)));
      items.append(new QStandardItem(date.toString("yyyy-MM-dd")));

      model->appendRow(items);

      if (!db.isOpen()) {
          QMessageBox::warning(this, "Erreur", "La base de données n'est pas ouverte");
          return;
      }

      int idVente = 0;
      QSqlQuery reqet;
      if (reqet.exec("SELECT IFNULL(MAX(idVente), 0) + 1 FROM vente") && reqet.next()) {
          idVente = reqet.value(0).toInt();
      } else {
          QMessageBox::warning(this, "Erreur", "Impossible de récupérer le nouvel ID de la vente");
          db.rollback(); // Annulez la transaction en cas d'erreur
          return;
      }

      QString word = "Facture";
      QString PremiereLettre = word.left(1).toUpper();
      QString codeV = PremiereLettre + "00" + QString::number(idVente);
      ui->numero_facture_lineEdit->setText(codeV);
      ui->date_courante_dateEdit->setDate(QDate::currentDate());
      montant_total += montant;

      recalculateMontantTotal();

      on_Annuler_pushButton_clicked();
  }




void Interface_Vente::on_Annuler_pushButton_clicked()
{
    ui->code_produit_lineEdit->clear();
    ui->nom_produit_lineEdit->clear();
    ui->quantite_produit_spinBox->setValue(0);
    ui->prix_unitaire_doubleSpinBox->setValue(0.00);
    ui->montant_doubleSpinBox->setValue(0.00);

}


void Interface_Vente::on_supprimer_pushButton_clicked()
{
    QString codeToDelete = ui->code_produit_lineEdit->text();
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);
            if (index.data().toString() == codeToDelete) {
                model->removeRow(row);
                return;
        }
}
    on_Annuler_pushButton_clicked();
}

void Interface_Vente::on_ValiderFacture_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Erreur", "La base de données n'est pas ouverte");
        return;
    }

    db.transaction();

    // Récupérer le code du client
    QSqlQuery re;
    QString codeCli;
    re.exec("SELECT codeCli FROM client WHERE nomCli ='" + ui->nomClient_comboBox->currentText() + "'");
    if (re.next()) {
        codeCli = re.value(0).toString();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le code client");
        db.rollback();
        return;
    }

    // Récupérer le code du personnel
    QSqlQuery req;
    QString codePers, fonction = "Responsable de vente";
    req.exec("SELECT codePers FROM personnel WHERE rolePers ='" + fonction + "' ORDER BY idPers DESC LIMIT 1");
    if (req.next()) {
        codePers = req.value(0).toString();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le code personnel");
        db.rollback();
        return;
    }

    // Générer le code de la vente une seule fois
    int idVente = 0;
    QSqlQuery venteQuery;
    if (venteQuery.exec("SELECT IFNULL(MAX(idVente), 0) + 1 FROM vente") && venteQuery.next()) {
        idVente = venteQuery.value(0).toInt();
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le nouvel ID de la vente");
        db.rollback();
        return;
    }

    QString word = "Facture";
    QString PremiereLettre = word.left(2).toUpper();
    QString codeV = PremiereLettre + "00" + QString::number(idVente);

    ui->numero_facture_lineEdit->setText(codeV);
    ui->date_courante_dateEdit->setDate(QDate::currentDate());

    // Vérifier les quantités disponibles et préparer les mises à jour
    QVector<QPair<QString, int>> produits; // stocker les produits avec leurs quantités demandées
    for (int row = 0; row < model->rowCount(); ++row) {
        QString codePro = model->data(model->index(row, 0)).toString();
        int qteVendue = model->data(model->index(row, 4)).toInt();
        produits.append(qMakePair(codePro, qteVendue));
    }

    // Dictionnaire pour stocker les quantités disponibles
    QMap<QString, int> qteDisponibles;

    // Vérifier et stocker les quantités disponibles
    for (const auto &produit : produits) {
        QString codePro = produit.first;
        QSqlQuery qt;
        qt.exec("SELECT qtePro FROM produit WHERE codePro ='" + codePro + "'");
        if (qt.next()) {
            qteDisponibles[codePro] = qt.value(0).toInt();
        } else {
            QMessageBox::warning(this, "Erreur", "Impossible de récupérer la quantité disponible pour le produit: " + codePro);
            db.rollback();
            return;
        }

    }

    // Insérer la vente
    QSqlQuery insertVenteQuery;
    insertVenteQuery.prepare("INSERT INTO vente (codeV, montantV, dateV, statut, codeCli, codePers) VALUES (:codeV, :montantV, :dateV, :statut, :codeCli, :codePers)");
    insertVenteQuery.bindValue(":codeV", codeV);
    insertVenteQuery.bindValue(":montantV", montant_total);
    insertVenteQuery.bindValue(":dateV", ui->date_courante_dateEdit->date());
    insertVenteQuery.bindValue(":statut", ui->statut_comboBox->currentText());
    insertVenteQuery.bindValue(":codeCli", codeCli);
    insertVenteQuery.bindValue(":codePers", codePers);
    if (!insertVenteQuery.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table vente: " + insertVenteQuery.lastError().text());
        db.rollback();
        return;
    }

    // Mise à jour de la table produit et insertion dans vendre
    for (const auto &produit : produits) {
        QString codePro = produit.first;
        int qteVendue = produit.second;
        int qtePro = qteDisponibles[codePro];
        int qteNonSatisfait = 0;

        if (qtePro >= qteVendue) {
            // Mettre à jour la table produit
            QSqlQuery updateProduitQuery;
            updateProduitQuery.prepare("UPDATE produit SET qtePro = qtePro - :qteVendue WHERE codePro = :codePro");
            updateProduitQuery.bindValue(":qteVendue", qteVendue);
            updateProduitQuery.bindValue(":codePro", codePro);
            if (!updateProduitQuery.exec()) {
                QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la quantité dans la table produit: " + updateProduitQuery.lastError().text());
                db.rollback();
                return;
            }

            qteNonSatisfait = 0;
        } else {
            // Mettre à jour la table produit avec la quantité disponible
            QSqlQuery updateProduitQuery;
            updateProduitQuery.prepare("UPDATE produit SET qtePro = 0 WHERE codePro = :codePro");
            updateProduitQuery.bindValue(":codePro", codePro);
            if (!updateProduitQuery.exec()) {
                QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la quantité dans la table produit: " + updateProduitQuery.lastError().text());
                db.rollback();
                return;
            }

            qteNonSatisfait = qteVendue - qtePro;
            qteVendue = qtePro;
        }

        QSqlQuery insertVendreQuery;
        insertVendreQuery.prepare("INSERT INTO vendre (codeV, codePro, qteVendue, qteNonSatisfait) VALUES (:codeV, :codePro, :qteVendue, :qteNonSatisfait)");
        insertVendreQuery.bindValue(":codeV", codeV);
        insertVendreQuery.bindValue(":codePro", codePro);
        insertVendreQuery.bindValue(":qteVendue", qteVendue);
        insertVendreQuery.bindValue(":qteNonSatisfait", qteNonSatisfait);
        if (!insertVendreQuery.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table vendre: " + insertVendreQuery.lastError().text());
            db.rollback();
            return;
        }
    }

    // Gestion des transactions
    QDate dateVente = ui->date_courante_dateEdit->date();
    QString action = "Encaissement";
    QString motif = "Ventes";
    QString depositaire = "Caissière";
    QString moyenPaiement = "Espèces";

    QString codeTrans;
    QSqlQuery selectCodeTrans;
    selectCodeTrans.exec("SELECT MAX(id) FROM transactions");
    if (selectCodeTrans.next()) {
        int maxId = selectCodeTrans.value(0).toInt();
        codeTrans = "T" + QString::number(maxId + 1).rightJustified(5, '0'); // Génère un code transaction avec un préfixe 'T' et 5 chiffres
    } else {
        codeTrans = "T00001"; // Premier code si la table est vide
    }

    QSqlQuery transactionQuery;
    transactionQuery.prepare("SELECT montant FROM transactions WHERE motif = :motif AND action = :action AND depositaire = :depositaire AND date = :date");
    transactionQuery.bindValue(":motif", motif);
    transactionQuery.bindValue(":action", action);
    transactionQuery.bindValue(":depositaire", depositaire);
    transactionQuery.bindValue(":date", dateVente);
    if (!transactionQuery.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la vérification de la transaction existante: " + transactionQuery.lastError().text());
        db.rollback();
        return;
    }

    if (transactionQuery.next()) {
        // Mettre à jour la transaction existante
        double montantExistant = transactionQuery.value(0).toDouble();
        double nouveauMontant = montantExistant + montant_total;

        QSqlQuery updateTransactionQuery;
        updateTransactionQuery.prepare("UPDATE transactions SET montant = :nouveauMontant WHERE motif = :motif AND action = :action AND depositaire = :depositaire AND date = :date");
        updateTransactionQuery.bindValue(":nouveauMontant", nouveauMontant);
        updateTransactionQuery.bindValue(":motif", motif);
        updateTransactionQuery.bindValue(":action", action);
        updateTransactionQuery.bindValue(":depositaire", depositaire);
        updateTransactionQuery.bindValue(":date", dateVente);
        if (!updateTransactionQuery.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de la mise à jour de la transaction: " + updateTransactionQuery.lastError().text());
            db.rollback();
            return;
        }
    } else {
        // Insérer une nouvelle transaction
        QSqlQuery insertTransactionQuery;
        insertTransactionQuery.prepare("INSERT INTO transactions (codeTrans, date, action, motif, depositaire, moyenPaiement, montant) VALUES (:codeTrans, :date, :action, :motif, :depositaire, :moyenPaiement, :montant)");
        insertTransactionQuery.bindValue(":codeTrans", codeTrans);
        insertTransactionQuery.bindValue(":date", dateVente);
        insertTransactionQuery.bindValue(":action", action);
        insertTransactionQuery.bindValue(":motif", motif);
        insertTransactionQuery.bindValue(":depositaire", depositaire);
        insertTransactionQuery.bindValue(":moyenPaiement", moyenPaiement);
        insertTransactionQuery.bindValue(":montant", montant_total);
        if (!insertTransactionQuery.exec()) {
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'insertion dans la table transaction: " + insertTransactionQuery.lastError().text());
            db.rollback();
            return;
        }
    }

    db.commit();

    QMessageBox::information(this, "Succès", "Vente enregistrée avec succès");

    // Réinitialiser le montant total
    montant_total = 0.0;
    ui->montant_total_doubleSpinBox->setValue(montant_total);

    // Effacer les lignes de la table après l'enregistrement de la vente
    model->removeRows(0, model->rowCount());
    ui->numero_facture_lineEdit->clear();
    ui->contact_lineEdit->clear();
    ui->adresse_lineEdit->clear();

}



        /*QPrinter printer;
        QPrintDialog dialog(&printer, this);

        if (dialog.exec() != QDialog::Accepted) {
            return;
        }

        QPainter painter(&printer);
        if (!painter.begin(&printer)) {
            QMessageBox::warning(this, "Erreur", "Impossible de commencer l'impression");
            return;
        }

        int currentY = 100; // Initial y position
        int lineHeight = 20; // Height between lines

        // Drawing the header
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(100, currentY, "Facture");
        currentY += lineHeight;

        // Drawing invoice details
        painter.setFont(QFont("Arial", 10));
        painter.drawText(100, currentY, "Numéro de facture: " + ui->numero_facture_lineEdit->text());
        currentY += lineHeight;
        painter.drawText(100, currentY, "Date: " + ui->date_courante_dateEdit->date().toString("dd/MM/yyyy"));
        currentY += lineHeight;
        painter.drawText(100, currentY, "Client: " + ui->nomClient_comboBox->currentText());
        currentY += lineHeight;
        painter.drawText(100, currentY, "Contact: " + ui->contact_lineEdit->text());
        currentY += lineHeight;
        painter.drawText(100, currentY, "Adresse: " + ui->adresse_lineEdit->text());
        currentY += lineHeight;

        // Drawing table headers
        currentY += lineHeight;
        painter.drawText(100, currentY, "Code Produit");
        painter.drawText(200, currentY, "Nom Produit");
        painter.drawText(300, currentY, "Type Produit");
        painter.drawText(400, currentY, "Prix Unitaire");
        painter.drawText(500, currentY, "Quantité");
        painter.drawText(600, currentY, "Montant");
        currentY += lineHeight;

        // Drawing table rows
        for (int row = 0; row < model->rowCount(); ++row) {
            painter.drawText(100, currentY, model->item(row, 0)->text());
            painter.drawText(200, currentY, model->item(row, 1)->text());
            painter.drawText(300, currentY, model->item(row, 2)->text());
            painter.drawText(400, currentY, QString::number(model->item(row, 3)->text().toDouble(), 'f', 2));
            painter.drawText(500, currentY, QString::number(model->item(row, 4)->text().toInt()));
            painter.drawText(600, currentY, QString::number(model->item(row, 5)->text().toDouble(), 'f', 2));
            currentY += lineHeight;
        }

        // Drawing the total amount
        currentY += lineHeight;
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.drawText(500, currentY, "Total: ");
        painter.drawText(600, currentY, QString::number(ui->montant_total_doubleSpinBox->value(), 'f', 2));

        painter.end();*/





void Interface_Vente::on_detailVente_tableView_clicked(const QModelIndex &index)
{
    indextable = model->index(index.row(),0);
    ui->code_produit_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),1);
    ui->nom_produit_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),2);
    ui->type_produit_lineEdit->setText(model->data(indextable,Qt::DisplayRole).toString());
    indextable = model->index(index.row(),3);
    ui->prix_unitaire_doubleSpinBox->setValue(model->data(indextable,Qt::DisplayRole).toInt());
    indextable = model->index(index.row(),4);
    ui->quantite_produit_spinBox->setValue(model->data(indextable,Qt::DisplayRole).toInt());
}

void Interface_Vente::Afficher()
{
    int row(0);
    model = new QStandardItemModel(0, 5);
   QSqlQuery requete;
   requete.exec("SELECT client.nomCli,   client.telephoneCli, client.adresseCli, vente.codeV, vente.montantV, vente.dateV, personnel.nomPers, personnel.prenomPers FROM client INNER JOIN vente ON client.codeCli = vente.codeCli INNER JOIN personnel ON vente.codePers = personnel.codePers");
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


void Interface_Vente::on_nomClient_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery req;
    QString tel, adresse;
    req.exec("SELECT telephoneCli, adresseCli FROM client WHERE nomCli ='"+arg1+"'");
    while (req.next()) {

        tel = req.value(0).toString();
        adresse = req.value(1).toString();

    }
    ui->contact_lineEdit->setText(tel);
    ui->adresse_lineEdit->setText(adresse);
}

void Interface_Vente::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QAbstractItemModel* model = ui->tableView->model();
    QString codeV = model->data(model->index(row, 3)).toString();
    ui->numero_facture_lineEdit->setText(codeV);

    displaySaleDetails(codeV);


    QSqlQuery detailQuery;
    detailQuery.prepare(R"(
        SELECT vente.codeV, produit.codePro, produit.nomPro, produit.prixUnit,
               produit.dateExpiration, typeproduit.typePro,
               vendre.qteVendue, vendre.qteNonSatisfait
        FROM vente
        INNER JOIN vendre ON vente.codeV = vendre.codeV
        INNER JOIN produit ON vendre.codePro = produit.codePro
        INNER JOIN typeproduit ON produit.codeType = typeproduit.codeType
        WHERE vente.codeV = :codeV
    )");
    detailQuery.bindValue(":codeV", codeV);

    if (!detailQuery.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les détails de la vente");
        return;
    }

    // Créer un modèle pour afficher les détails
    QStandardItemModel *detailModel = new QStandardItemModel(this);
    QStringList headers = { "Code de Vente", "Code Produit", "Nom du produit", "Prix unitaire", "Quantité", "Date Expiration", "Type du produit" };
    detailModel->setColumnCount(headers.size());
    for (int i = 0; i < headers.size(); ++i) {
        detailModel->setHeaderData(i, Qt::Horizontal, headers[i]);
    }

    // Remplir le modèle avec les résultats de la requête
    while (detailQuery.next()) {
        QList<QStandardItem *> items;
        QString codePro = detailQuery.value("codePro").toString();
        QString nomPro = detailQuery.value("nomPro").toString();
        QString prixUnit = detailQuery.value("prixUnit").toString();
        QString dateExpiration = detailQuery.value("dateExpiration").toString();
        QString typePro = detailQuery.value("typePro").toString();
        int qteVendue = detailQuery.value("qteVendue").toInt();
        int qteNonSatisfait = detailQuery.value("qteNonSatisfait").toInt();
        int qteTotal = qteVendue + qteNonSatisfait;

        QStandardItem *itemCodeV = new QStandardItem(codeV);
        QStandardItem *itemCodePro = new QStandardItem(codePro);
        QStandardItem *itemNomPro = new QStandardItem(nomPro);
        QStandardItem *itemPrixUnit = new QStandardItem(prixUnit);
        QStandardItem *itemQuantite = new QStandardItem(QString::number(qteTotal));
        QStandardItem *itemDateExpiration = new QStandardItem(dateExpiration);
        QStandardItem *itemTypePro = new QStandardItem(typePro);

        // Stocker les informations supplémentaires dans le rôle de données utilisateur
        itemQuantite->setData(qteNonSatisfait, Qt::UserRole + 1);

        items.append(itemCodeV);
        items.append(itemCodePro);
        items.append(itemNomPro);
        items.append(itemPrixUnit);
        items.append(itemQuantite);
        items.append(itemDateExpiration);
        items.append(itemTypePro);

        detailModel->appendRow(items);
    }

    // Afficher le modèle dans detailVente_tableview
    ui->detailVente_tableView->setModel(detailModel);

    // Utiliser un delegate pour la colonne "Quantité" pour mettre en évidence la quantité non satisfaite
    ui->detailVente_tableView->setItemDelegateForColumn(4, new QteDelegate(this));
}



void Interface_Vente::displaySaleDetails(const QString &codeV)
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT vente.dateV, client.nomCli, client.telephoneCli, client.adresseCli, vente.statut
        FROM vente
        INNER JOIN client ON vente.codeCli = client.codeCli
        WHERE vente.codeV = :codeV
    )");
    query.bindValue(":codeV", codeV);

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les informations de la vente");
        return;
    }

    if (query.next()) {
        QDate dateVente = query.value("dateV").toDate();
        QString nomClient = query.value("nomCli").toString();
        QString contactClient = query.value("telephoneCli").toString();
        QString adresseClient = query.value("adresseCli").toString();
        QString statut = query.value("statut").toString();

        ui->date_courante_dateEdit->setDate(dateVente);
        ui->nomClient_comboBox->setCurrentText(nomClient);
        ui->contact_lineEdit->setText(contactClient);
        ui->adresse_lineEdit->setText(adresseClient);
        ui->statut_comboBox->setCurrentText(statut);
    }
}






void Interface_Vente::on_nomClient_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlQuery req;
    QString tel, adresse;
    req.exec("SELECT telephoneCli, adresseCli FROM client WHERE nomCli ='"+arg1+"'");
    while (req.next()) {

        tel = req.value(0).toString();
        adresse = req.value(1).toString();

    }
    ui->contact_lineEdit->setText(tel);
    ui->adresse_lineEdit->setText(adresse);
}




void Interface_Vente::setupCompleter()
{
    completer = new QCompleter(this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->code_produit_lineEdit->setCompleter(completer);
}

void Interface_Vente::updateSuggestions(const QString &text)
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

void Interface_Vente::fillDetails()
{
    QString codePro = ui->code_produit_lineEdit->text();
    if (codePro.isEmpty()) {
        clearFields();
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT p.nomPro, p.dosage, p.prixUnit, p.qtePro, t.typePro "
                  "FROM produit p "
                  "JOIN typeproduit t ON p.codeType = t.codeType "
                  "WHERE p.codePro = ?");
    query.addBindValue(codePro);
    query.exec();

    if (query.next()) {
        QString nomPro = query.value(0).toString();
        QString dosage = query.value(1).toString();
        double prixUnit = query.value(2).toDouble();
        int qtePro = query.value(3).toInt();
        QString typePro = query.value(4).toString();

        QString nomProComplet = nomPro + " " + dosage;
        ui->nom_produit_lineEdit->setText(nomProComplet);
        ui->type_produit_lineEdit->setText(typePro);
        ui->prix_unitaire_doubleSpinBox->setValue(prixUnit);
        ui->quantite_produit_spinBox->setValue(qtePro);
    } else {
        clearFields();
    }
}

void Interface_Vente::clearFields()
{
    ui->nom_produit_lineEdit->clear();
    ui->type_produit_lineEdit->clear();
    ui->prix_unitaire_doubleSpinBox->setValue(0);
    ui->quantite_produit_spinBox->setValue(0);
}

void Interface_Vente::on_Imprimer_pushButton_clicked()
{
    QSqlQuery query;
    QString codeVente = ui->numero_facture_lineEdit->text();

    if (!query.exec("SELECT tp.typePro, p.nomPro, p.dosage, p.prixUnit, vd.qteVendue, v.montantV FROM typeproduit tp INNER JOIN produit p ON tp.codeType = p.codeType INNER JOIN vendre vd ON p.codePro = vd.codePro INNER JOIN vente v ON vd.codeV = v.codeV WHERE v.codeV ='" + codeVente + "'")) {
        std::cout << "Échec de l'exécution de la requête: " << query.lastError().text().toStdString() << std::endl;
        return;
    }

    QSqlQuery clientQuery;
    if (!clientQuery.exec("SELECT c.nomCli, c.telephoneCli, c.mailCli, c.adresseCli FROM client c INNER JOIN vente v ON c.codeCli = v.codeCli WHERE v.codeV = '" + codeVente + "'")) {
        std::cout << "Échec de l'exécution de la requête client: " << clientQuery.lastError().text().toStdString() << std::endl;
        return;
    }

    QString nomClient, telClient, mailClient, adresseClient;
    if (clientQuery.next()) {
        nomClient = clientQuery.value(0).toString();
        telClient = clientQuery.value(1).toString();
        mailClient = clientQuery.value(2).toString();
        adresseClient = clientQuery.value(3).toString();
    }

    QDateTime currentDate = QDateTime::currentDateTime();
    QString DateCourante = currentDate.toString("yyyy-MM-dd");

    text = new QTextEdit;
    QString texte;
    texte += "<!DOCTYPE html><html>"
             "<head>"
             "<style>"
             "body { font-family: 'Arial', sans-serif; margin: 20px; color: #333; }"
             "header { display: flex; align-items: center; justify-content: space-between; background-color: white; padding: 10px; border-radius: 10px; }"
             "header img { width: 80px; height: auto; }"
             "header div { flex-grow: 1; text-align: center; margin: 0 10px; }"
             "header h1 { margin: 0; font-size: 24px; font-family: 'Georgia', serif; }"
             "header p { margin: 5px 0; font-size: 14px; }"
             "section.client-info { margin-bottom: 20px; padding: 15px; background-color: #f7f7f7; border-radius: 10px; }"
             "section.client-info h2 { font-size: 18px; margin-bottom: 10px; color: #4CAF50; }"
             "section.client-info p { margin: 5px 0; font-size: 14px; }"
             "main { margin-top: 20px; }"
             "main h2 { font-size: 20px; margin-bottom: 10px; color: #4CAF50; border-bottom: 2px solid #4CAF50; display: inline-block; padding-bottom: 5px; }"
             "table { width: 100%; border-collapse: collapse; margin-top: 10px; }"
             "table, th, td { border: 1px solid #ddd; }"
             "th, td { padding: 8px; text-align: left; }"
             "th { background-color: #f2f2f2; color: #333; }"
             "tr:nth-child(even) { background-color: #f9f9f9; }"
             "tfoot td { font-weight: bold; background-color: #f2f2f2; }"
             "footer { text-align: right; margin-top: 20px; font-size: 12px; color: #666; }"
             "footer p { margin: 5px 0; }"
             "</style>"
             "</head>"
             "<body>";

    texte += "<header>"
             "<div>"
             "<h1>PHARMASTOCK</h1>"
             "<p>Vente de produits pharmaceutiques, laboratoire de recherche, distributeur de produits pharmaceutiques.</p>"
             "<p>Lieu: Parakou, Qtier: Arafat, situé à 200m du campus en allant à baka<br>"
             "Tél: 61359067 / 55375315</p>"
             "</div>"
             "</header>";

    texte += "<section class='client-info'>"
             "<h2>Informations du Client</h2>"
             "<p><strong>Nom:</strong> " + nomClient + "</p>"
                           "<p><strong>Téléphone:</strong> " + telClient + "</p>"
                           "<p><strong>Email:</strong> " + mailClient + "</p>"
                            "<p><strong>Adresse:</strong> " + adresseClient + "</p>"
                               "</section>";

    texte += "<main>"
             "<h2>Liste des produits vendus</h2>"
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

    texte += "<tr><td colspan='5' style='text-align: right; font-weight: bold;'>Montant total</td><td>" + QString::number(montant_total, 'f', 2) + "</td></tr>";
    texte += "</tbody>"
             "</table>";

    // Requête pour les produits non satisfaits
    if (!query.exec("SELECT tp.typePro, p.nomPro, p.dosage, vd.qteNonSatisfait FROM typeproduit tp INNER JOIN produit p ON tp.codeType = p.codeType INNER JOIN vendre vd ON p.codePro = vd.codePro WHERE vd.codeV ='" + codeVente + "' AND vd.qteNonSatisfait > 0")) {
        std::cout << "Échec de l'exécution de la requête des produits non satisfaits: " << query.lastError().text().toStdString() << std::endl;
        return;
    }

    if (query.size() > 0) {
        texte += "<h2>Produits non satisfaits</h2>"
                 "<table>"
                 "<thead>"
                 "<tr>"
                 "<th>Type de produit</th>"
                 "<th>Nom du produit</th>"
                 "<th>Dosage</th>"
                 "<th>Quantité non satisfaite</th>"
                 "</tr>"
                 "</thead>"
                 "<tbody>";

        while (query.next()) {
            QString col1 = query.value(0).toString();
            QString col2 = query.value(1).toString();
            QString col3 = query.value(2).toString();
            int col4 = query.value(3).toInt();

            texte += "<tr>"
                     "<td>" + col1 + "</td>"
                              "<td>" + col2 + "</td>"
                              "<td>" + col3 + "</td>"
                              "<td>" + QString::number(col4) + "</td>"
                                               "</tr>";
        }
        texte += "</tbody>"
                 "</table>";
    }

    texte += "</main>";


    texte += "<footer>"
             "<p>Arrêté la présente facture à la somme de '" + QString::number( montant_total) + "' francs CFA.</p>"
                                       "<p>Imprimé le " + DateCourante + "</p>"
                              "</footer>";

    texte += "</body></html>";

    text->setHtml(texte);

    QPrinter imprimer;
    imprimer.setPageOrientation(QPageLayout::Portrait);

    QPrintPreviewDialog dialog(&imprimer, this);

    connect(&dialog, &QPrintPreviewDialog::paintRequested, this, &Interface_Vente::print);

    dialog.showMaximized();
    dialog.exec();
}

void Interface_Vente::print(QPrinter *printer)
{
    text->print(printer);
}



void Interface_Vente::on_viderPanier_pushButton_clicked()
{
    QAbstractItemModel* model = ui->detailVente_tableView->model(); // Récupérer le modèle de la tableView du panier
    if (model) {
        model->removeRows(0, model->rowCount()); // Supprimer toutes les lignes du modèle
    }
    ui->numero_facture_lineEdit->clear();
    ui->date_courante_dateEdit->setDate(QDate::currentDate());
}


void Interface_Vente::on_deconnexion_pushButton_clicked()
{
    Login *deconnexion = new Login();
    deconnexion->show();
    close();
}


void Interface_Vente::on_gestion_client_pushButton_clicked()
{
    interface_client *interfaceCli = new interface_client();
    interfaceCli->show();
    close();
}


void Interface_Vente::on_modifier_pushButton_clicked()
{
    Afficher();
}

