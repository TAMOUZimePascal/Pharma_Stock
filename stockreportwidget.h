#ifndef STOCKREPORTWIDGET_H
#define STOCKREPORTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QDateEdit>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QDebug>
#include <QPrinter>

#include "connexion.h"

class StockReportWidget : public QWidget {
    Q_OBJECT

public:
    explicit StockReportWidget(QWidget *parent = nullptr);


private slots:
    void on_exitButton_clicked();
    void on_homeButton_clicked();
    void on_orderEditButton_clicked();
    void on_reportButton_clicked();
    void on_supplierButton_clicked();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *dateLayout;
    QTableView *tableView;
    QTableView *expiryTableView;
    QStandardItemModel *stockModel;
    QStandardItemModel *expiryModel;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *refreshButton;
    QPushButton *exitButton;
    QPushButton *homeButton;
    QPushButton *orderEditButton;
    QPushButton *supplierButton;
    QPushButton *reportButton;
    QPushButton *generateButton;
    QPushButton *exportButton;
    QChartView *barChartView;
    QChartView *pieChartView;
    QChartView *typeChartView;

    void generateAndDisplayReports();
    void generateStockReport();
    void generateExpiryReport();
    void createBarChart();
    void createTypeChart();
    void createPieChart();
    void updateCharts();
    void printReport();
    void applyStyles();
    void renderReport(QPrinter *printer);
    QImage captureChartAsImage(QChartView *chartView);
};

#endif // STOCKREPORTWIDGET_H
