#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QTableView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMap>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();
    void on_refreshButton_clicked();
    void on_exitButton_clicked();
    void on_homeButton_clicked();
    void on_orderEditButton_clicked();
    void on_supplierButton_clicked();
    void on_reportButton_clicked();

private:
    QSqlQueryModel *model;
    QTableView *tableView;
    QChartView *lineChartView;
    QChartView *barChartView;
    QChartView *pieChartView;
    QChartView *scatterChartView;
    QChartView *stackedBarChartView;
    QPushButton *generateButton;
    QPushButton *refreshButton;
    QPushButton *exitButton;
    QPushButton *homeButton;
    QPushButton *orderEditButton;
    QPushButton *supplierButton;
    QPushButton *reportButton;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QLabel *startDateLabel;
    QLabel *endDateLabel;

    void loadReport();
    void createLineChart();
    void createBarChart(const QDate &startDate, const QDate &endDate);
    void createPieChart();
    void createBarChart();
    void createScatterChart();
    void createStackedBarChart();
    void applyStyles();

    void loadReport(const QDate &startDate, const QDate &endDate);
    void createLineChart(const QDate &startDate, const QDate &endDate);
    //void createBarChart(const QDate &startDate, const QDate &endDate);
    void createPieChart(const QDate &startDate, const QDate &endDate);
    void createScatterChart(const QDate &startDate, const QDate &endDate);
    void createStackedBarChart(const QDate &startDate, const QDate &endDate);
};

#endif // MAINWINDOW_H
