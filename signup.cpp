#include "signup.h"
#include "ui_signup.h"
#include <QMessagebox>
#include <QString>

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_pushButton_Signup_clicked()
{
    QString username, password, confirmpassword;
        username = ui->lineEdit_Username->text();
        password = ui->lineEdit_Password->text();
        confirmpassword = ui->lineEdit_ConfirmPassword->text();

        QSqlQuery signupquery, checkUsername;
        signupquery.prepare("INSERT INTO USER (Username, Password) VALUES (:username, :password)");
        signupquery.bindValue(":username", username);
        signupquery.bindValue(":password", password);
        checkUsername.prepare("SELECT * FROM USER WHERE Username = :username");
        checkUsername.bindValue(":username", username);

        if(username.isEmpty() || password.isEmpty() || confirmpassword.isEmpty())
            QMessageBox::warning(this,"Sign up","Please fill up all fields");
        else if(password != confirmpassword)
            QMessageBox::warning(this,"Sign up","Passwords do not match");
        else if(checkUsername.exec()){
                if(checkUsername.next())
                QMessageBox::critical(this,"Sign up","Username already exists.");
                else if(signupquery.exec())
                QMessageBox::information(this,"Sign up","Account created Successfully.");
                else
                QMessageBox::critical(this,"Sign up",signupquery.lastError().text());
        }
}

void Signup::on_pushButton_Cancel_clicked()
{
    this->close();
}
