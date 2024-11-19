// main.cpp

#include <QApplication>
#include "StockReportWidget.h"
#include "acceuilrespooperation.h"
#include "approvisionnement.h"
#include "enregistrer_fournisseur.h"
#include "mainwindow.h"
#include "compta.h"
#include "interface_client.h"
#include "interface_vente.h"
#include "editionboncommandes.h"
#include "connexion.h"
#include "login.h"
#include "commandenonsatisfaite.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Connexion();
    Login widget;
    widget.show();

    int ret = app.exec();

    return ret;
}
