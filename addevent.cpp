#include "addevent.h"
#include "ui_addevent.h"
#include <mainwindow.h>
#include <QtSql>
#include <QMessageBox>
#include <QString>

AddEvent::AddEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddEvent)
{
    ui->setupUi(this);
}

AddEvent::~AddEvent()
{
    delete ui;
}

void AddEvent::on_pushButton_Add_clicked()
{
    QString Title, Place, Date, Time, Description;

    Title = ui->lineEdit_Title->text();
    Place = ui->lineEdit_Place->text();
    Date = ui->dateEdit_Event->date().toString();
    Time = ui->timeEdit_Event->time().toString();
    Description = ui->plainTextEdit_Description->toPlainText();

    QSqlQuery add;
    add.prepare("INSERT INTO TODO (Title, Place, Description, Date, Time) VALUES (:Title, :Place, :Description, :Date, :Time)");
    add.bindValue(":Title", Title);
    add.bindValue(":Place", Place);
    add.bindValue(":Description", Description);
    add.bindValue(":Date", Date);
    add.bindValue(":Time", Time);

    if(Title.isEmpty())
        QMessageBox::warning(this,"Empty title","Please enter the event title.");
    else if(Place.isEmpty())
        QMessageBox::warning(this,"Empty place","Please enter the event place.");
    else
    {
        if(add.exec()){
             QMessageBox::information(this,"Event added","Event added to database.");
             ui->lineEdit_Place->clear();
             ui->lineEdit_Title->clear();
             ui->plainTextEdit_Description->clear();
        }
        else
             QMessageBox::critical(this,"Event not added",add.lastError().text());
    }
}

void AddEvent::on_pushButton_Cancel_clicked()
{
    this->close();
}
