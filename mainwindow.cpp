#include "mainwindow.h"
#include "StockReportWidget.h"
#include "acceuilrespooperation.h"
#include "approvisionnement.h"
#include "enregistrer_fournisseur.h"
#include "mainwindow.h"
#include "compta.h"
#include "interface_client.h"
#include "interface_vente.h"
#include "editionboncommandes.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QPieSeries>
#include <QHeaderView>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QDateTimeAxis>
#include <QtCharts/QLegend>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>
#include "QLabel"

#include "Connexion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    model(new QSqlQueryModel(this)),
    tableView(new QTableView(this)),
    lineChartView(new QChartView(this)),
    barChartView(new QChartView(this)),
    pieChartView(new QChartView(this)),
    scatterChartView(new QChartView(this)),
    stackedBarChartView(new QChartView(this)),
    generateButton(new QPushButton("Générer le rapport", this)),
    refreshButton(new QPushButton("Actualiser", this)),
    exitButton(new QPushButton("Fermer", this)),
    homeButton(new QPushButton("Accueil", this)),
    orderEditButton(new QPushButton("Edition bon de commande", this)),
    supplierButton(new QPushButton("Gestion fournisseur", this)),
    reportButton(new QPushButton("Rapport et statistiques de stock", this)),
    startDateEdit(new QDateEdit(this)),
    endDateEdit(new QDateEdit(this))
{
    showMaximized();
    Connexion();
    // Set up the main layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Add the top buttons
    QHBoxLayout *topButtonLayout = new QHBoxLayout;
    topButtonLayout->addWidget(homeButton);
    topButtonLayout->addWidget(orderEditButton);
    topButtonLayout->addWidget(supplierButton);
    topButtonLayout->addWidget(reportButton);
    topButtonLayout->addStretch(); // Add stretch to push buttons to the right
    mainLayout->addLayout(topButtonLayout);

    // Add horizontal line
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);

    // Add title
    QLabel *titleLabel = new QLabel("Rapport et statistiques de ventes", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: blue;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Add date edit and generate button
    QHBoxLayout *dateLayout = new QHBoxLayout;
    dateLayout->addWidget(startDateLabel = new QLabel ("Date début:", this));
    dateLayout->addWidget(startDateEdit);
    dateLayout->addWidget(endDateLabel = new QLabel("Date fin:", this));
    dateLayout->addWidget(endDateEdit);
    dateLayout->addWidget(generateButton);
    mainLayout->addLayout(dateLayout);

    // Add the table view to the layout
    mainLayout->addWidget(tableView);

    // Set up tab widget for charts
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(lineChartView, "Graphique Linéaire");
    tabWidget->addTab(barChartView, "Histogramme");
    tabWidget->addTab(pieChartView, "Graphique Circulaire");
    tabWidget->addTab(scatterChartView, "Diagramme de Dispersion");
    tabWidget->addTab(stackedBarChartView, "Graphique à Barres Empilées");

    mainLayout->addWidget(tabWidget);

    // Set up buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(refreshButton);
    buttonLayout->addWidget(exitButton);
    mainLayout->addLayout(buttonLayout);

    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->resizeColumnsToContents();
    tableView->resizeRowsToContents();

    setCentralWidget(centralWidget);
    setWindowTitle("PharmaStock - Rapport et statistique de ventes");
    setWindowIcon(QIcon(":/images/Rapport2.png"));

    connect(generateButton, &QPushButton::clicked, this, &MainWindow::on_generateButton_clicked);
    connect(refreshButton, &QPushButton::clicked, this, &MainWindow::on_refreshButton_clicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    connect(homeButton, &QPushButton::clicked, this, &MainWindow::on_homeButton_clicked);

    // Connexion du bouton "Edition bon de commande"
    connect(orderEditButton, &QPushButton::clicked, this, &MainWindow::on_orderEditButton_clicked);

    // Connexion du bouton "Gestion fournisseur"
    connect(supplierButton, &QPushButton::clicked, this, &MainWindow::on_supplierButton_clicked);

    // Connexion du bouton "Rapport et statistiques de stock"
    connect(reportButton, &QPushButton::clicked, this, &MainWindow::on_reportButton_clicked);

    loadReport();
    createLineChart();
    createBarChart();
    createPieChart();
    createScatterChart();
    createStackedBarChart();
    applyStyles();
}

MainWindow::~MainWindow()
{
}

void MainWindow::loadReport(const QDate &startDate, const QDate &endDate) {
    // Ouvrir la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.open())
    {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir la base de données.");
        return;
    }

    QSqlQuery query;
    QString queryString = R"(
        SELECT v.codeV, v.dateV, v.montantV, c.nomCli
        FROM vente v
        JOIN client c ON v.codeCli = c.codeCli
    )";
    if (startDate.isValid() && endDate.isValid()) {
        queryString += " WHERE v.dateV BETWEEN :startDate AND :endDate";
    }
    queryString += " ORDER BY v.dateV DESC";
    query.prepare(queryString);

    if (startDate.isValid() && endDate.isValid()) {
        query.bindValue(":startDate", startDate);
        query.bindValue(":endDate", endDate);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text(), QMessageBox::Cancel);
        return;
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, tr("Code Vente"));
    model->setHeaderData(1, Qt::Horizontal, tr("Date Vente"));
    model->setHeaderData(2, Qt::Horizontal, tr("Montant Vente"));
    model->setHeaderData(3, Qt::Horizontal, tr("Client"));

    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setStyleSheet("QTableView { background-color: #f0f0f0; color: #333; }"
                             "QTableView::item:selected { background-color: #ffa07a; }");
}

void MainWindow::createLineChart(const QDate &startDate, const QDate &endDate) {
    QLineSeries *series = new QLineSeries();

    QSqlQuery query;
    QString queryString = R"(
        SELECT v.dateV, SUM(v.montantV) as total
        FROM vente v
    )";
    if (startDate.isValid() && endDate.isValid()) {
        queryString += " WHERE v.dateV BETWEEN :startDate AND :endDate";
    }
    queryString += " GROUP BY v.dateV ORDER BY v.dateV";
    query.prepare(queryString);

    if (startDate.isValid() && endDate.isValid()) {
        query.bindValue(":startDate", startDate);
        query.bindValue(":endDate", endDate);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text(), QMessageBox::Cancel);
        return;
    }

    while (query.next()) {
        QDateTime dateTime = query.value(0).toDateTime();
        double total = query.value(1).toDouble();
        series->append(dateTime.toMSecsSinceEpoch(), total);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Total des ventes par date");
    chart->setAnimationOptions(QChart::AllAnimations);

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("dd-MM-yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Total des ventes");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    lineChartView->setChart(chart);
}

void MainWindow::createBarChart(const QDate &startDate, const QDate &endDate) {
    QBarSeries *series = new QBarSeries();
    QSqlQuery query;
    query.prepare(R"(
        SELECT tp.typePro, p.nomPro, p.dosage, SUM(vd.qteVendue) as TotalVendu
        FROM typeproduit tp
        JOIN produit p ON tp.codeType = p.codeType
        JOIN vendre vd ON p.codePro = vd.codePro
        JOIN vente v ON vd.codeV = v.codeV
        WHERE v.dateV BETWEEN :startDate AND :endDate
        GROUP BY tp.typePro, p.nomPro, p.dosage
        ORDER BY TotalVendu DESC
    )");
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text(), QMessageBox::Cancel);
        return;
    }

    QChart *chart = new QChart();

    while (query.next()) {
        QString typePro = query.value(0).toString();
        QString productName = query.value(1).toString();
        QString dosage = query.value(2).toString();
        int totalVendu = query.value(3).toInt();

        QString fullProductName = QString("%1 (%2, %3)").arg(productName).arg(dosage).arg(typePro);
        QBarSet *set = new QBarSet(fullProductName); // Utilisez le nom complet ici
        *set << totalVendu;
        series->append(set);
    }

    chart->addSeries(series);
    chart->setTitle("Ventes par Produit");
    chart->setAnimationOptions(QChart::SeriesAnimations); // Ajoute des animations pour rendre le graphique plus attrayant
    chart->createDefaultAxes();

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Quantité Vendue");
    chart->setAxisY(axisY, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom); // Place la légende en bas du graphique

    barChartView->setChart(chart);
}



void MainWindow::createPieChart(const QDate &startDate, const QDate &endDate) {
    QPieSeries *series = new QPieSeries();

    QSqlQuery query;
    QString queryString = R"(
        SELECT c.nomCli, SUM(v.montantV) as total
        FROM vente v
        JOIN client c ON v.codeCli = c.codeCli
    )";
    if (startDate.isValid() && endDate.isValid()) {
        queryString += " WHERE v.dateV BETWEEN :startDate AND :endDate";
    }
    queryString += " GROUP BY c.nomCli ORDER BY total DESC";
    query.prepare(queryString);

    if (startDate.isValid() && endDate.isValid()) {
        query.bindValue(":startDate", startDate);
        query.bindValue(":endDate", endDate);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text(), QMessageBox::Cancel);
        return;
    }

    while (query.next()) {
        QString clientName = query.value(0).toString();
        double total = query.value(1).toDouble();
        QPieSlice *slice = series->append(clientName, total);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1%").arg(100 * slice->percentage(), 0, 'f', 1));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des ventes par client");
    chart->setAnimationOptions(QChart::AllAnimations);

    // Afficher les noms des clients dans la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom); // Place la légende en bas du graphique

    pieChartView->setChart(chart);
}


void MainWindow::createScatterChart(const QDate &startDate, const QDate &endDate) {
    QScatterSeries *series = new QScatterSeries();

    QSqlQuery query;
    QString queryString = R"(
        SELECT v.dateV, v.montantV
        FROM vente v
    )";
    if (startDate.isValid() && endDate.isValid()) {
        queryString += " WHERE v.dateV BETWEEN :startDate AND :endDate";
    }
    queryString += " ORDER BY v.dateV";
    query.prepare(queryString);

    if (startDate.isValid() && endDate.isValid()) {
        query.bindValue(":startDate", startDate);
        query.bindValue(":endDate", endDate);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text(), QMessageBox::Cancel);
        return;
    }

    while (query.next()) {
        QDateTime dateTime = query.value(0).toDateTime();
        double montant = query.value(1).toDouble();
        series->append(dateTime.toMSecsSinceEpoch(), montant);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ventes individuelles par date");
    chart->setAnimationOptions(QChart::AllAnimations);

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("dd-MM-yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Montant Vente");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    scatterChartView->setChart(chart);
}

void MainWindow::createStackedBarChart(const QDate &startDate, const QDate &endDate) {
    QStackedBarSeries *series = new QStackedBarSeries();

    QSqlQuery query;
    QString queryString = R"(
        SELECT c.nomCli, v.dateV, SUM(v.montantV) as total
        FROM vente v
        JOIN client c ON v.codeCli = c.codeCli
    )";
    if (startDate.isValid() && endDate.isValid()) {
        queryString += " WHERE v.dateV BETWEEN :startDate AND :endDate";
    }
    queryString += " GROUP BY c.nomCli, v.dateV ORDER BY v.dateV";
    query.prepare(queryString);

    if (startDate.isValid() && endDate.isValid()) {
        query.bindValue(":startDate", startDate);
        query.bindValue(":endDate", endDate);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text(), QMessageBox::Cancel);
        return;
    }

    QMap<QDate, QMap<QString, double>> dateClientData;
    QStringList clientList;
    while (query.next()) {
        QString clientName = query.value(0).toString();
        QDate date = query.value(1).toDate();
        double total = query.value(2).toDouble();

        if (!clientList.contains(clientName)) {
            clientList << clientName;
        }
        dateClientData[date][clientName] = total;
    }

    QMap<QString, QBarSet*> clientBarSets;
    for (const QString &client : clientList) {
        clientBarSets[client] = new QBarSet(client);
    }

    for (auto it = dateClientData.begin(); it != dateClientData.end(); ++it) {
        for (const QString &client : clientList) {
            double total = it.value().value(client, 0.0);
            *clientBarSets[client] << total;
        }
    }

    for (auto it = clientBarSets.begin(); it != clientBarSets.end(); ++it) {
        series->append(it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Total des ventes empilées par client et par date");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (auto it = dateClientData.begin(); it != dateClientData.end(); ++it) {
        categories << it.key().toString("dd-MM-yyyy");
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Total des ventes");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    stackedBarChartView->setChart(chart);
}

void MainWindow::on_generateButton_clicked()
{
    QDate startDate = startDateEdit->date();
    QDate endDate = endDateEdit->date();

    loadReport(startDate, endDate);
    createLineChart(startDate, endDate);
    createBarChart(startDate, endDate);
    createPieChart(startDate, endDate);
    createScatterChart(startDate, endDate);
    createStackedBarChart(startDate, endDate);
}

void MainWindow::on_refreshButton_clicked()
{
    loadReport();
    createLineChart();
    createBarChart();
    createPieChart();
    createScatterChart();
    createStackedBarChart();
}

void MainWindow::loadReport() {
    QDate defaultStartDate = QDate::currentDate().addMonths(-1); // Par défaut, un mois en arrière
    QDate defaultEndDate = QDate::currentDate(); // Par défaut, aujourd'hui

    loadReport(defaultStartDate, defaultEndDate);
}

void MainWindow::createLineChart() {
    QDate defaultStartDate = QDate::currentDate().addMonths(-1); // Par défaut, un mois en arrière
    QDate defaultEndDate = QDate::currentDate(); // Par défaut, aujourd'hui

    createLineChart(defaultStartDate, defaultEndDate);
}

void MainWindow::createBarChart() {
    QDate defaultStartDate = QDate::currentDate().addMonths(-1);
    QDate defaultEndDate = QDate::currentDate();
    createBarChart(defaultStartDate, defaultEndDate);
}

void MainWindow::createPieChart() {
    QDate defaultStartDate = QDate::currentDate().addMonths(-1);
    QDate defaultEndDate = QDate::currentDate();
    createPieChart(defaultStartDate, defaultEndDate);
}

void MainWindow::createScatterChart() {
    QDate defaultStartDate = QDate::currentDate().addMonths(-1);
    QDate defaultEndDate = QDate::currentDate();
    createScatterChart(defaultStartDate, defaultEndDate);
}

void MainWindow::createStackedBarChart() {
    QDate defaultStartDate = QDate::currentDate().addMonths(-1);
    QDate defaultEndDate = QDate::currentDate();
    createStackedBarChart(defaultStartDate, defaultEndDate);
}

void MainWindow::applyStyles() {
    // Set style for the main window
    this->setStyleSheet("QMainWindow { background-color: #f5f5f5; }");

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
    generateButton->setStyleSheet(buttonStyle);
    refreshButton->setStyleSheet(buttonStyle);
    exitButton->setStyleSheet(buttonStyle);


    QString labelStyle = "QLabel {"
                         "color: #333;"
                         "font-size: 14px;"
                         "}";

        startDateLabel->setStyleSheet(labelStyle);
        endDateLabel->setStyleSheet(labelStyle);

}
void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::on_homeButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface AcceuilREspoOperation
    AcceuilREspoOperation *acceuilWindow = new AcceuilREspoOperation();
    acceuilWindow->show();
}

void MainWindow::on_orderEditButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface editionBonCommandes
    editionBonCommandes *editionBonCommandesWindow = new editionBonCommandes();
    editionBonCommandesWindow->show();
}

void MainWindow::on_reportButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface StockReportWidget
    StockReportWidget *stockReportWindow = new StockReportWidget();
    stockReportWindow->show();
}

void MainWindow::on_supplierButton_clicked()
{
    // Fermer la fenêtre principale
    close();

    // Ouvrir l'interface Enregistrer_Fournisseur
    Enregistrer_Fournisseur *enregistrerFournisseurWindow = new Enregistrer_Fournisseur();
    enregistrerFournisseurWindow->show();
}
