#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <signup.h>
#include <mainwindow.h>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    QSqlDatabase ISUSdb;

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_About_clicked();

    void on_pushButton_Signup_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::Login *ui;
    Signup signupform;
    MainWindow mainwindowform;
};

#endif // LOGIN_H
