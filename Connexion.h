#ifndef CONNEXION_H
#define CONNEXION_H

#include "QSqlDatabase"
#include "QSqlQuery"

static bool Connexion()
{
    QSqlDatabase Connexion = QSqlDatabase::addDatabase("QMYSQL");
    Connexion.setHostName("127.0.0.1");
    Connexion.setUserName("root");
    Connexion.setDatabaseName("pharmastock");
        Connexion.setPort(3306);
    if(Connexion.open())
    {
        return true;
    }else
    {
        return false;
    }
}

#endif // CONNEXION_H
