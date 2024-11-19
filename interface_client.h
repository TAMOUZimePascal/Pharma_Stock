#ifndef INTERFACE_CLIENT_H
#define INTERFACE_CLIENT_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>

namespace Ui {
class interface_client;
}

class interface_client : public QWidget
{
    Q_OBJECT

public:
    explicit interface_client(QWidget *parent = 0);
    ~interface_client();
    void afficher();
    void effacer();

private slots:
    void on_Enregistrer_pushButton_clicked();

    void on_AnnulerpushButton_clicked();

    void on_Modifier_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_Rechercher_pushButton_clicked();

    void on_Suprimer_pushButton_clicked();

    void on_Imprimer_pushButton_clicked();

    void print(QPrinter *printer);

    void on_pushButton_2_clicked();

private:
    Ui::interface_client *ui;
    QStandardItemModel *modele;
    QModelIndex indextable;
    QTextEdit *text;
};

#endif // INTERFACE_CLIENT_H
