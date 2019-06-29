#include "syllabus.h"
#include "ui_syllabus.h"
#include <QtSql>
#include <QSqlQueryModel>
#include <QMessageBox>


Syllabus::Syllabus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Syllabus)
{
    ui->setupUi(this);
}

Syllabus::~Syllabus()
{
    delete ui;
}

void Syllabus::on_pushButton_clicked()
{
    QString Subject, Topic;
    Subject = ui->comboBox->currentText();
    Topic = ui->lineEdit_Topic->text();

    QSqlQuery addSyllabus;
    addSyllabus.prepare("INSERT INTO SYLLABUS (Topic, SUBJECTid) VALUES (:Topic, :Subject)");
    addSyllabus.bindValue(":Topic", Topic);
    addSyllabus.bindValue(":Subject", Subject);

    if(Subject.isEmpty())
        QMessageBox::warning(this,"No Subject","Please select a subject");
    else if(Topic.isEmpty())
        QMessageBox::warning(this,"No topic","Please enter a topic");
    else
    {
        if(addSyllabus.exec()){
            QMessageBox::warning(this,"Success", "Syllabus added");
            ui->lineEdit_Topic->clear();
        }
        else
            QMessageBox::critical(this,"Error", addSyllabus.lastError().text());
    }
}

void Syllabus::on_pushButton_load_clicked()
{
    QSqlQuery *getSubject = new QSqlQuery;

    getSubject->prepare("SELECT Code FROM SUBJECT");

    getSubject->exec();

    QSqlQueryModel *modal = new QSqlQueryModel();

    modal->setQuery(*getSubject);
    ui->comboBox->setModel(modal);
}

void Syllabus::on_pushButton_2_clicked()
{
    this->close();
}
