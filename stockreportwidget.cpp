#include "stockreportwidget.h"
#include "customdelegate.h"
#include "acceuilrespooperation.h"
#include "mainwindow.h"
#include "interface_client.h"
#include "enregistrer_fournisseur.h"
#include "compta.h"
#include "editionboncommandes.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QDateEdit>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include <QFileDialog>
#include <QPainter>
#include <QPrinter>
#include <QPdfWriter>
#include <QPrintDialog>
#include <QInputDialog>
#include <QSqlRecord>
#include <QHeaderView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QLegendMarker>
#include <QSqlError>
#include <QStandardItemModel>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QPrintPreviewDialog>
#include <QTextTableCell>
#include <QTextTableFormat>
#include <QImage>
#include <QBuffer>
#include <QByteArray>

// Constructeur
StockReportWidget::StockReportWidget(QWidget *parent) : QWidget(parent),
    exitButton(new QPushButton("Fermer", this)),
    homeButton(new QPushButton("Accueil", this)),
    orderEditButton(new QPushButton("Edition bon de commande", this)),
    supplierButton(new QPushButton("Gestion fournisseur", this)),
    reportButton(new QPushButton("Rapport et statistiques de vente", this))
{
    // Configuration de la connexion à la base de données
    Connexion();
    showMaximized();
    // Configuration des layouts et des widgets
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Add the top buttons
    QHBoxLayout *topButtonLayout = new QHBoxLayout;
    topButtonLayout->addWidget(homeButton);
    topButtonLayout->addWidget(orderEditButton);
    topButtonLayout->addWidget(supplierButton);
    topButtonLayout->addWidget(reportButton);
    topButtonLayout->addWidget(exitButton);
    topButtonLayout->addStretch(); // Add stretch to push buttons to the right
    mainLayout->addLayout(topButtonLayout);

    // Add horizontal line
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);

    // Ajouter le titre
    QLabel *title = new QLabel("RAPPORT ET STATISTIQUES DES STOCKS", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold; color: #2E86C1; margin-bottom: 20px;");
    mainLayout->addWidget(title);

    // Layout pour les champs de date et le bouton
    QHBoxLayout *dateLayout = new QHBoxLayout();
    startDateEdit = new QDateEdit(QDate::currentDate().addMonths(-1), this);
    endDateEdit = new QDateEdit(QDate::currentDate(), this);
    startDateEdit->setCalendarPopup(true);
    endDateEdit->setCalendarPopup(true);
    startDateEdit->setStyleSheet("font-size: 16px;");
    endDateEdit->setStyleSheet("font-size: 16px;");
    QPushButton *generateButton = new QPushButton("Générer le rapport", this);
    generateButton->setStyleSheet("font-size: 16px; padding: 10px; background-color: #5DADE2; color: white;");

    dateLayout->addWidget(new QLabel("Date de début:", this));
    dateLayout->addWidget(startDateEdit);
    dateLayout->addWidget(new QLabel("Date de fin:", this));
    dateLayout->addWidget(endDateEdit);
    dateLayout->addWidget(generateButton);

    QPushButton *exportButton = new QPushButton("Imprimer", this);
    exportButton->setStyleSheet("font-size: 16px; padding: 10px; background-color: #28B463; color: white;");
    dateLayout->addWidget(exportButton);

    mainLayout->addLayout(dateLayout);

    // Connexion des boutons
    connect(generateButton, &QPushButton::clicked, this, &StockReportWidget::generateAndDisplayReports);
    connect(exportButton, &QPushButton::clicked, this, &StockReportWidget::printReport);

    // Layout pour les labels et les tableaux
    QHBoxLayout *tableLayout = new QHBoxLayout();

    // Layout pour la vue globale des stocks
    QVBoxLayout *globalStockLayout = new QVBoxLayout();
    QLabel *globalStockLabel = new QLabel("Vue globale des stocks:", this);
    tableView = new QTableView(this);
    stockModel = new QStandardItemModel(this);
    tableView->setModel(stockModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setStyleSheet("font-size: 16px;");
    globalStockLayout->addWidget(globalStockLabel);
    globalStockLayout->addWidget(tableView);

    // Layout pour les produits en voie de péremption
    QVBoxLayout *expiryLayout = new QVBoxLayout();
    QLabel *expiryLabel = new QLabel("Produits en voie de péremption (3 mois):", this);
    expiryTableView = new QTableView(this);
    expiryModel = new QStandardItemModel(this);
    expiryTableView->setModel(expiryModel);
    expiryTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    expiryTableView->setStyleSheet("font-size: 16px;");
    expiryLayout->addWidget(expiryLabel);
    expiryLayout->addWidget(expiryTableView);

    // Ajouter les deux layouts de tableau au layout horizontal
    tableLayout->addLayout(globalStockLayout);
    tableLayout->addLayout(expiryLayout);

    // Ajouter le layout des tableaux au layout principal
    mainLayout->addLayout(tableLayout);

    // Layout pour les graphiques
    QHBoxLayout *chartsLayout = new QHBoxLayout();
    barChartView = new QChartView(this);
    pieChartView = new QChartView(this);
    typeChartView = new QChartView(this);
    chartsLayout->addWidget(barChartView);
    chartsLayout->addWidget(pieChartView);
    chartsLayout->addWidget(typeChartView);

    // Ajouter les layouts au layout principal
    mainLayout->addLayout(chartsLayout);

    // Appliquer le délégué personnalisé
    CustomDelegate *customDelegate = new CustomDelegate(this);
    expiryTableView->setItemDelegateForColumn(3, customDelegate); // Date d'expiration

    setLayout(mainLayout);
    qDebug() << "StockReportWidget initialisé avec succès";

    connect(exitButton, &QPushButton::clicked, this, &StockReportWidget::on_exitButton_clicked);
    connect(homeButton, &QPushButton::clicked, this, &StockReportWidget::on_homeButton_clicked);

    // Connexion du bouton "Edition bon de commande"
    connect(orderEditButton, &QPushButton::clicked, this, &StockReportWidget::on_orderEditButton_clicked);

    // Connexion du bouton "Gestion fournisseur"
    connect(supplierButton, &QPushButton::clicked, this, &StockReportWidget::on_supplierButton_clicked);

    // Connexion du bouton "Rapport et statistiques de vente"
    connect(reportButton, &QPushButton::clicked, this, &StockReportWidget::on_reportButton_clicked);

    applyStyles();
    generateAndDisplayReports();
}


// Function to generate and display reports
void StockReportWidget::generateAndDisplayReports() {
    qDebug() << "Génération du rapport de stock";
    generateStockReport();
    generateExpiryReport();
    updateCharts();
}

void StockReportWidget::generateStockReport() {
    QSqlQuery query;
    query.prepare(R"(
        SELECT DISTINCT p.codePro, p.nomPro, p.qtePro, p.prixUnit, p.dosage, tp.typePro
        FROM produit p
        JOIN typeproduit tp ON p.codeType = tp.codeType
        JOIN approvisionner a ON p.codePro = a.codePro
        JOIN approvisionnement ap ON a.codeAp = ap.codeAp
        WHERE ap.dateAp BETWEEN :startDate AND :endDate
        ORDER BY p.qtePro DESC
    )");

    query.bindValue(":startDate", startDateEdit->date());
    query.bindValue(":endDate", endDateEdit->date());

    if (!query.exec()) {
        qCritical() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
    } else {
        qDebug() << "Requête exécutée avec succès. Nombre de résultats:" << query.size();

        stockModel->clear();
        stockModel->setHorizontalHeaderLabels({"Code Produit", "Nom Produit", "Quantité", "Prix Unitaire", "Type Produit"});

        while (query.next()) {
            QList<QStandardItem*> row;
            row << new QStandardItem(query.value("codePro").toString());
            QString nomComplet = query.value("nomPro").toString() + " " + query.value("dosage").toString();
            row << new QStandardItem(nomComplet);
            row << new QStandardItem(query.value("qtePro").toString());
            row << new QStandardItem(query.value("prixUnit").toString());
            row << new QStandardItem(query.value("typePro").toString());
            stockModel->appendRow(row);
        }

        qDebug() << "Rapport de stock généré avec succès";
    }
}


// Génération du rapport des produits en voie de péremption
void StockReportWidget::generateExpiryReport() {
    QSqlQuery query;
    query.prepare(R"(
        SELECT p.codePro, p.nomPro, p.dateExpiration, p.dosage, tp.typePro
        FROM produit p
        JOIN typeproduit tp ON p.codeType = tp.codeType
        WHERE p.dateExpiration BETWEEN :currentDate AND :expiryDate
        ORDER BY p.dateExpiration ASC
    )");

    query.bindValue(":currentDate", QDate::currentDate());
    query.bindValue(":expiryDate", QDate::currentDate().addMonths(3));

    if (!query.exec()) {
        qCritical() << "Erreur lors de l'exécution de la requête pour les produits en voie de péremption:" << query.lastError().text();
    } else {
        qDebug() << "Requête exécutée avec succès. Nombre de résultats:" << query.size();

        expiryModel->clear();
        expiryModel->setHorizontalHeaderLabels({"Code Produit", "Nom Produit", "Type Produit", "Date d'Expiration"});

        while (query.next()) {
            QList<QStandardItem*> row;
            row << new QStandardItem(query.value("codePro").toString());
            QString nomComplet = query.value("nomPro").toString() + " " + query.value("dosage").toString();
            row << new QStandardItem(nomComplet);
            row << new QStandardItem(query.value("typePro").toString());
            row << new QStandardItem(query.value("dateExpiration").toString());
            expiryModel->appendRow(row);
        }

        qDebug() << "Rapport des produits en voie de péremption généré avec succès";
    }
}



void StockReportWidget::createBarChart() {
    // Vérifiez que le modèle contient des données
    if (stockModel->rowCount() == 0) {
        qDebug() << "Le modèle de stock est vide.";
        return;
    }

    // Création de la série de barres
    QBarSeries *series = new QBarSeries();

    // Remplir le QBarSet avec les quantités de produits et attribuer une couleur spécifique à chaque barre
    QList<QBarSet *> sets;
    for (int i = 0; i < stockModel->rowCount(); ++i) {
        bool ok;
        double value = stockModel->item(i, 2)->text().toDouble(&ok);
        QString productName = stockModel->item(i, 1)->text();

        QBarSet *set = new QBarSet(productName);
        if (ok) {
            *set << value;
        } else {
            qDebug() << "Erreur de conversion de la quantité à la ligne" << i;
            *set << 0; // Ajoutez une valeur par défaut en cas d'erreur de conversion
        }

        // Attribuer une couleur spécifique à chaque barre
        QColor color = QColor::fromHsv((i * 30) % 360, 255, 200); // Cycle through hues
        set->setColor(color);

        sets << set;
        series->append(set);
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Quantité de Produits en Stock");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Configuration de l'axe X (catégories sans les noms des produits)
    QStringList categories;
    for (int i = 0; i < stockModel->rowCount(); ++i) {
        categories << QString::number(i + 1); // Use indices or other labels instead of product names
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configuration de l'axe Y (quantités)
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Quantité");
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Configuration de la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Définir la vue du graphique
    barChartView->setChart(chart);
}


// Création du graphique à secteurs
void StockReportWidget::createPieChart() {
    QPieSeries *series = new QPieSeries();

    for (int i = 0; i < stockModel->rowCount(); ++i) {
        series->append(stockModel->item(i, 1)->text(), stockModel->item(i, 2)->text().toDouble());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Produits en Stock");

    pieChartView->setChart(chart);
}

// Création du graphique par type de produit
void StockReportWidget::createTypeChart() {
    QPieSeries *series = new QPieSeries();
    QMap<QString, double> typeData;

    for (int i = 0; i < stockModel->rowCount(); ++i) {
        QString type = stockModel->item(i, 4)->text();
        double quantity = stockModel->item(i, 2)->text().toDouble();
        typeData[type] += quantity;
    }

    QMapIterator<QString, double> it(typeData);
    while (it.hasNext()) {
        it.next();
        series->append(it.key(), it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Produits par Type");

    typeChartView->setChart(chart);
}

// Mise à jour des graphiques
void StockReportWidget::updateCharts() {
    createBarChart();
    createPieChart();
    createTypeChart();
}



// Fonction pour capturer les graphiques sous forme d'image
QImage StockReportWidget::captureChartAsImage(QChartView *chartView) {
    QSize size = chartView->size();
    QImage image(size, QImage::Format_ARGB32);
    QPainter painter(&image);
    chartView->render(&painter);
    return image;
}

QString imageToBase64(const QImage &image) {
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG");
    return QString::fromLatin1(byteArray.toBase64().data());
}

void StockReportWidget::printReport() {
    QPrinter printer(QPrinter::HighResolution);

    // Créer une boîte de dialogue d'aperçu avant impression
    QPrintPreviewDialog previewDialog(&printer, this);
    connect(&previewDialog, &QPrintPreviewDialog::paintRequested, this, &StockReportWidget::renderReport);

    // Afficher la boîte de dialogue d'aperçu en plein écran
    previewDialog.setWindowState(Qt::WindowMaximized);
    previewDialog.showFullScreen();

    // Afficher la boîte de dialogue d'aperçu
    previewDialog.exec();
}

void StockReportWidget::renderReport(QPrinter *printer) {
    QTextDocument document;
    QTextCursor cursor(&document);

    // Titre principal
    cursor.insertHtml("<h1 style='text-align: center; color: #2E86C1;'>Rapport de Stock</h1>");

    // Tableau du rapport de stock
    cursor.insertHtml("<h2>Vue globale des stocks:</h2>");
    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setCellPadding(4);
    tableFormat.setCellSpacing(0);
    tableFormat.setAlignment(Qt::AlignLeft);
    tableFormat.setHeaderRowCount(1);

    QTextTable *table = cursor.insertTable(stockModel->rowCount() + 1, stockModel->columnCount(), tableFormat);

    // Ajouter les en-têtes
    for (int j = 0; j < stockModel->columnCount(); ++j) {
        QTextTableCell cell = table->cellAt(0, j);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(stockModel->horizontalHeaderItem(j)->text());
    }

    // Ajouter les données
    for (int i = 0; i < stockModel->rowCount(); ++i) {
        for (int j = 0; j < stockModel->columnCount(); ++j) {
            QTextTableCell cell = table->cellAt(i + 1, j);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(stockModel->item(i, j)->text());
        }
    }

    // Espace entre les sections
    cursor.insertHtml("<br><br>");

    // Tableau des produits en voie de péremption
    cursor.insertHtml("<h2>Produits en voie de péremption (3 mois):</h2>");
    table = cursor.insertTable(expiryModel->rowCount() + 1, expiryModel->columnCount(), tableFormat);

    // Ajouter les en-têtes
    for (int j = 0; j < expiryModel->columnCount(); ++j) {
        QTextTableCell cell = table->cellAt(0, j);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(expiryModel->horizontalHeaderItem(j)->text());
    }

    // Ajouter les données
    for (int i = 0; i < expiryModel->rowCount(); ++i) {
        for (int j = 0; j < expiryModel->columnCount(); ++j) {
            QTextTableCell cell = table->cellAt(i + 1, j);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(expiryModel->item(i, j)->text());
        }
    }

    // Espace entre les sections
    cursor.insertHtml("<br><br>");

    // Capturer les graphiques et les ajouter au document
    QImage barChartImage = captureChartAsImage(barChartView);
    QImage pieChartImage = captureChartAsImage(pieChartView);
    QImage typeChartImage = captureChartAsImage(typeChartView);

    cursor.insertHtml("<h2>Graphiques:</h2>");

    // Ajouter l'image du graphique des barres
    if (!barChartImage.isNull()) {
        cursor.insertHtml("<p><img src='data:image/png;base64," + imageToBase64(barChartImage) + "' width='400' height='300'></p>");
    }
    cursor.insertHtml("<br><br>");

    // Ajouter l'image du graphique en secteurs
    if (!pieChartImage.isNull()) {
        cursor.insertHtml("<p><img src='data:image/png;base64," + imageToBase64(pieChartImage) + "' width='400' height='300'></p>");
    }
    cursor.insertHtml("<br><br>");

    // Ajouter l'image du graphique par type
    if (!typeChartImage.isNull()) {
        cursor.insertHtml("<p><img src='data:image/png;base64," + imageToBase64(typeChartImage) + "' width='400' height='300'></p>");
    }

    // Imprimer le document
    document.print(printer);

    qDebug() << "Rapport imprimé avec succès";
}


void StockReportWidget::on_exitButton_clicked()
{
    close();
}

void StockReportWidget::on_homeButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface AcceuilREspoOperation
    AcceuilREspoOperation *acceuilWindow = new AcceuilREspoOperation();
    acceuilWindow->show();
}

void StockReportWidget::on_orderEditButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface editionBonCommandes
    editionBonCommandes *editionBonCommandesWindow = new editionBonCommandes();
    editionBonCommandesWindow->show();
}

void StockReportWidget::on_reportButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface StockReportWidget
    MainWindow *venteReportWindow = new MainWindow();
    venteReportWindow->show();
}

void StockReportWidget::on_supplierButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface Enregistrer_Fournisseur
    Enregistrer_Fournisseur *enregistrerFournisseurWindow = new Enregistrer_Fournisseur();
    enregistrerFournisseurWindow->show();
}

void StockReportWidget::applyStyles() {
    // Set style for the main window
    this->setStyleSheet("QStockReportWidget { background-color: #f5f5f5; }");

    // Set style for the buttons
    QString buttonStyle = "QPushButton {"
                          "background-color: #4CAF50;"
                          "color: white;"
                          "border: none;"
                          "padding: 10px 20px;"
                          "text-align: center;"
                          "text-decoration: none;"
                          "display: inline-block;"
                          "font-size: 16px;"
                          "margin: 4px 2px;"
                          "transition-duration: 0.4s;"
                          "cursor: pointer;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: white;"
                          "color: black;"
                          "border: 2px solid #4CAF50;"
                          "}";
    homeButton->setStyleSheet(buttonStyle);
    orderEditButton->setStyleSheet(buttonStyle);
    supplierButton->setStyleSheet(buttonStyle);
    reportButton->setStyleSheet(buttonStyle);
    exitButton->setStyleSheet(buttonStyle);


    QString labelStyle = "QLabel {"
                         "color: #333;"
                         "font-size: 14px;"
                         "}";

    // startDateLabel->setStyleSheet(labelStyle);
    // endDateLabel->setStyleSheet(labelStyle);

}
