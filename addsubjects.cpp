#include "addsubjects.h"
#include "ui_addsubjects.h"
#include <QtSql>
#include <QMessageBox>
#include <QString>

AddSubjects::AddSubjects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSubjects)
{
    ui->setupUi(this);
}

AddSubjects::~AddSubjects()
{
    delete ui;
}

void AddSubjects::on_pushButton_Cancel_clicked()
{
    this->close();
}

void AddSubjects::on_pushButton_Add_clicked()
{
    QString Code, Name;
    qint8 Credit=0;

    Code = ui->lineEdit_Code->text();
    Name = ui->lineEdit_Name->text();
    Credit = ui->lineEdit_Credits->text().toInt();

    QSqlQuery setSubject;
    setSubject.prepare("INSERT INTO SUBJECT (Code, Name, Credit) VALUES (:Code, :Name, :Credit)");
    setSubject.bindValue(":Code", Code);
    setSubject.bindValue(":Name", Name);
    setSubject.bindValue(":Credit", Credit);

    if(Code.isEmpty())
        QMessageBox::warning(this,"Empty Code","Please enter the subject code.");
    else if(Name.isEmpty())
        QMessageBox::warning(this,"Empty Name","Please enter the subject name.");
    else if(Credit<=0)
        QMessageBox::warning(this,"Empty Credits","Please enter the subject credit.");
    else
    {
      if(setSubject.exec()){
          QMessageBox::information(this,"Subject Added","Subject has been added to database.");
          ui->lineEdit_Code->clear();
          ui->lineEdit_Credits->clear();
          ui->lineEdit_Name->clear();
      }
      else
          QMessageBox::critical(this,"Subject not added","Subject has not been added to database.");
    }
}
