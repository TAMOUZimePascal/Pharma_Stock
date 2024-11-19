#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QFrame>

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    void loadLoginInfo();

    void saveLoginInfo();

private slots:
    void authenticate();

private:
    QLabel *titleLabel;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QCheckBox *rememberMeCheckBox;
    QPushButton *loginButton;
    QPushButton *forgotPasswordButton;
    QPushButton *facebookButton;
    QPushButton *twitterButton;
    QLabel *welcomeLabel;
    QLabel *descriptionLabel;
    QFrame *loginFrame;
    QLabel *backgroundLabel;
};

#endif // LOGIN_H
