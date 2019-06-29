#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QString>
#include <mainwindow.h>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //Connect to the database.
    ISUSdb = QSqlDatabase::addDatabase("QSQLITE");
    ISUSdb.setDatabaseName("E:/ISUS/db.db");

    //Display message about the connection.
    if(!ISUSdb.open())
        ui->label_Database->setText("Failed to connect to database");
    else
        ui->label_Database->setText("Connected to database");

    //Enable or disable signup.
    QSqlQuery checkquery;
    checkquery.prepare("SELECT * FROM USER");
    if(checkquery.exec()){
        if(checkquery.next())
            ui->pushButton_Signup->setEnabled(false);
    }
    else
        QMessageBox::critical(this,"Error",checkquery.lastError().text());
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked()
{
   //Declare variables
   QString username, password;

   //Assign values to the variable from textbox input.
   username = ui->lineEdit_Username->text();
   password = ui->lineEdit_Password->text();

   //Check whether the textboxes are empty.
   if(username.isEmpty())
       QMessageBox::warning(this,"Login","Please enter your Username.");
   else if(password.isEmpty())
       QMessageBox::warning(this,"Login","Please enter your password.");
   else {
       //If not empty start the login preocess.
       //Use SQL to check the username and password from database.
       QSqlQuery loginquery, selectuserid;
       loginquery.prepare("SELECT * FROM USER WHERE Username = :username AND Password = :password");
       loginquery.bindValue(":username", username);
       loginquery.bindValue(":password", password);
       selectuserid.prepare("SELECT idUSER FROM USER WHERE Username = :username");
       selectuserid.bindValue(":username", username);

       if(loginquery.exec()){
           //If match found
            if(loginquery.next()){
              this->hide();
              mainwindowform.show();
            }
        else
            //If match not found
            QMessageBox::critical(this,"Login","Incorrect user credentials.");
        }
        }
}

void Login::on_pushButton_About_clicked()
{
    //Display message about the project members
    QMessageBox::information(this,"Creators:","Created By:\nSaahil Mahato\nNiraj Tamang\nGyanas Luitel\nAayush Kafle");
}

void Login::on_pushButton_Signup_clicked()
{
    //show the signup form
    signupform.show();
}

void Login::on_pushButton_Exit_clicked()
{
    //Close the software
    this->close();
}
