#ifndef ACCEUILRESPOOPERATION_H
#define ACCEUILRESPOOPERATION_H

#include <QWidget>

namespace Ui {
class AcceuilREspoOperation;
}

class AcceuilREspoOperation : public QWidget
{
    Q_OBJECT

public:
    explicit AcceuilREspoOperation(QWidget *parent = 0);
    ~AcceuilREspoOperation();

    void fetchAndDisplayPersonnel();

private slots:
    void on_editerBonCommande_pushButton_clicked();

    void on_rapport_vente_pushButton_clicked();

    void on_rapport_stock_pushButton_clicked();

    void on_gestion_fournisseurs_pushButton_clicked();

    void on_tresorerie_pushButton_clicked();

    void on_deconnexion_pushButton_clicked();

private:
    Ui::AcceuilREspoOperation *ui;
};

#endif // ACCEUILRESPOOPERATION_H
