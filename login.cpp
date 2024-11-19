#include "login.h"
#include "acceuilrespooperation.h"
#include "approvisionnement.h"
#include "interface_vente.h"
#include "Connexion.h"
#include <QMessageBox>
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QStackedLayout>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QSettings>
#include <QDateTime>
#include <QStackedWidget>


Login::Login(QWidget *parent) : QWidget(parent) {
    // Définir le titre de la fenêtre
    setWindowTitle("Connexion");
    showMaximized();

    // Section droite (connexion)
    titleLabel = new QLabel("Connexion", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(32); // Augmenter la taille du texte du label "Connexion"
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: blue; font-weight: bold; border: none;");

    usernameLabel = new QLabel("Nom d'utilisateur", this);
    QFont labelFont = usernameLabel->font();
    labelFont.setPointSize(16); // Augmenter la taille du texte des labels
    labelFont.setBold(true);
    usernameLabel->setFont(labelFont);
    usernameLabel->setStyleSheet("color: black; border: none;");

    usernameEdit = new QLineEdit(this);
    usernameEdit->setPlaceholderText("Entrez votre nom d'utilisateur");
    usernameEdit->setStyleSheet("color: black;"); // Texte en noir

    passwordLabel = new QLabel("Mot de passe", this);
    passwordLabel->setFont(labelFont);
    passwordLabel->setStyleSheet("color: black; border: none;");

    passwordEdit = new QLineEdit(this);
    passwordEdit->setPlaceholderText("Entrez votre mot de passe");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setStyleSheet("color: black;"); // Texte en noir

    rememberMeCheckBox = new QCheckBox("Se souvenir de moi", this);
    rememberMeCheckBox->setStyleSheet("color: black; border: none; background-color: none;"); // Texte en noir, couleur de fond retirée

    loginButton = new QPushButton("Connexion", this);
    QFont buttonFont = loginButton->font();
    buttonFont.setBold(true); // Mettre le texte du bouton en gras
    loginButton->setFont(buttonFont);
    loginButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #ff6600; color: white;" // Couleur bien visible
        "}"
        "QPushButton:hover {"
        "    background-color: #e65c00;" // Orange plus foncé au survol
        "}"
        );

    // Connecter le bouton de connexion à la fonction d'authentification
    connect(loginButton, &QPushButton::clicked, this, &Login::authenticate);

    // Disposition des widgets de connexion
    QVBoxLayout *loginLayout = new QVBoxLayout();
    loginLayout->addWidget(titleLabel, 0, Qt::AlignCenter); // Centrer le titre
    loginLayout->addWidget(usernameLabel);
    loginLayout->addWidget(usernameEdit);
    loginLayout->addWidget(passwordLabel);
    loginLayout->addWidget(passwordEdit);
    loginLayout->addWidget(rememberMeCheckBox);
    loginLayout->addWidget(loginButton);
    loginLayout->setSpacing(15); // Ajouter plus d'espace entre les widgets

    // Encadrer les widgets dans un QFrame
    loginFrame = new QFrame(this);
    loginFrame->setLayout(loginLayout);
    loginFrame->setFixedSize(400, 450); // Agrandir le cadre pour le bouton et les labels
    loginFrame->setFrameShape(QFrame::Box);
    loginFrame->setFrameShadow(QFrame::Raised);
    loginFrame->setStyleSheet(
        "QFrame { border: 2px solid #ccc; padding: 20px; background-color: white; }"
        "QLineEdit { background-color: white; border: 2px solid #4CAF50; border-radius: 4px; padding: 5px; color: black; }" // Texte en noir
        "QCheckBox { color: black; border: none; background-color: none; }" // Texte en noir
        );

    // Ajout de l'image de fond transparente
    QLabel *backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap(":/images/GestionStock.png"); // Remplacer par le chemin correct de ton image
    if (backgroundPixmap.isNull()) {
        qDebug() << "Erreur : L'image de fond n'a pas été trouvée !";
    } else {
        backgroundLabel->setPixmap(backgroundPixmap);
        backgroundLabel->setScaledContents(true);
        QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect;
        opacityEffect->setOpacity(0.5);  // Ajuster l'opacité (0.0 à 1.0)
        backgroundLabel->setGraphicsEffect(opacityEffect);
        backgroundLabel->setAlignment(Qt::AlignCenter);
    }

    // Layout pour superposer l'image et le formulaire
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(backgroundLabel, 0, 0);
    mainLayout->addWidget(loginFrame, 0, 0, Qt::AlignCenter);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    setLayout(mainLayout);
    setStyleSheet(
        "QWidget {"
        "    background-color: #4CAF50;" // Vert
        "}"
        "QLabel {"
        "    font-size: 18px;"
        "}"
        "QLineEdit {"
        "    font-size: 16px;"
        "    padding: 5px;"
        "    border: 2px solid #4CAF50;"
        "    border-radius: 4px;"
        "    color: black;" // Texte en noir
        "}"
        "QCheckBox {"
        "    font-size: 16px;"
        "    color: black;" // Texte en noir
        "    border: none;" // Retirer le cadre du QCheckBox
        "    background-color: none;" // Retirer la couleur de fond
        "}"
        "QPushButton {"
        "    font-size: 16px;"
        "    padding: 10px;"
        "    background-color: #ff6600;" // Orange pour contraste
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "    font-weight: bold;" // Texte en gras pour le bouton
        "}"
        "QPushButton:hover {"
        "    background-color: #e65c00;" // Orange plus foncé au survol
        "}"
        );

    // Charger les informations de connexion sauvegardées si elles existent
    loadLoginInfo();

    // Connexion à la base de données
    Connexion();
}

void Login::loadLoginInfo() {
    QSettings settings("Yerikissi", "PharmaStock");
    QDateTime lastLoginTime = settings.value("lastLoginTime").toDateTime();
    QDateTime currentTime = QDateTime::currentDateTime();

    // Vérifier si les informations de connexion sont toujours valides (moins de 30 jours)
    if (lastLoginTime.isValid() && lastLoginTime.addDays(30) > currentTime) {
        usernameEdit->setText(settings.value("username").toString());
        passwordEdit->setText(settings.value("password").toString());
        rememberMeCheckBox->setChecked(true);
    } else {
        // Si les informations sont expirées, les supprimer
        settings.remove("username");
        settings.remove("password");
        settings.remove("lastLoginTime");
    }
}

void Login::saveLoginInfo() {
    QSettings settings("YourCompany", "YourApp");
    settings.setValue("username", usernameEdit->text());
    settings.setValue("password", passwordEdit->text());
    settings.setValue("lastLoginTime", QDateTime::currentDateTime());
}

void Login::authenticate() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Vérification des champs vides
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Vérification de l'adresse email
    QRegularExpression emailRegex(R"((^[^\s@]+@[^\s@]+\.[^\s@]+$))");
    if (!emailRegex.match(username).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Requête à la base de données pour vérifier les informations de l'utilisateur
    QSqlQuery query;
    query.prepare("SELECT codePers, nomPers, prenomPers, contactPers, mailPers, password, rolePers FROM personnel WHERE mailPers = :mailPers");
    query.bindValue(":mailPers", username);

    if (!query.exec()) {
        qDebug() << "Erreur de requête : " << query.lastError().text();
        return;
    }

    if (query.next()) {
        QString storedPassword = query.value("password").toString();
        QString prenomPers = query.value("prenomPers").toString();
        QString rolePers = query.value("rolePers").toString();

        if (password == storedPassword) {
            // Sauvegarder les informations de connexion si "Se souvenir de moi" est coché
            if (rememberMeCheckBox->isChecked()) {
                saveLoginInfo();
            } else {
                QSettings settings("Yerikissi", "PharmaStock");
                settings.remove("username");
                settings.remove("password");
                settings.remove("lastLoginTime");
            }

         //   QMessageBox::information(this, "Succès", "Connexion réussie ! Bienvenue " + prenomPers + " (" + rolePers + ").");

            // Rediriger vers l'interface appropriée en fonction du rôle
            if (rolePers == "Responsable des opérations") {
                AcceuilREspoOperation *acceuilRespoOperationRe = new AcceuilREspoOperation();
                acceuilRespoOperationRe->show();
            } else if (rolePers == "Responsable de stock") {
                Approvisionnement *approvisionnement = new Approvisionnement();
                approvisionnement->show();
            } else if (rolePers == "Responsable de vente") {
                Interface_Vente *interfaceVenteRe = new Interface_Vente();
                interfaceVenteRe->show();
            }

            // Fermer ou cacher la fenêtre de connexion
            this->close();
        } else {
            QMessageBox::warning(this, "Échec", "Nom d'utilisateur ou mot de passe incorrect.");
        }
    } else {
        QMessageBox::warning(this, "Échec", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}
