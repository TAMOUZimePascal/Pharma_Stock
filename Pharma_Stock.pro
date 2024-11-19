QT       += core gui
QT       += sql
QT       += printsupport
QT       += core gui network
QT       += core sql widgets charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuilrespooperation.cpp \
    approvisionnement.cpp \
    commandenonsatisfaite.cpp \
    compta.cpp \
    customdelegate.cpp \
    editionboncommandes.cpp \
    enregistrer_fournisseur.cpp \
    interface_client.cpp \
    interface_vente.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    qtedelegate.cpp \
    stockreportwidget.cpp

HEADERS += \
    Connexion.h \
    acceuilrespooperation.h \
    approvisionnement.h \
    commandenonsatisfaite.h \
    compta.h \
    customdelegate.h \
    editionboncommandes.h \
    enregistrer_fournisseur.h \
    interface_client.h \
    interface_vente.h \
    login.h \
    mainwindow.h \
    qtedelegate.h \
    stockreportwidget.h \
    transactiondelegate.h

FORMS += \
    acceuilrespooperation.ui \
    approvisionnement.ui \
    commandenonsatisfaite.ui \
    compta.ui \
    editionboncommandes.ui \
    enregistrer_fournisseur.ui \
    interface_client.ui \
    interface_vente.ui \
    mainwindow.ui \
    stockreportwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    images/32958685-bouton-accueil-icône.jpg
