#include "schedule.h"
#include "ui_schedule.h"
#include <QtSql>
#include <QMessageBox>

Schedule::Schedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::on_pushButton_Load_clicked()
{
    QSqlQuery *getSubject = new QSqlQuery;
    getSubject->prepare("SELECT Code FROM SUBJECT");

    getSubject->exec();

    QSqlQueryModel *modal = new QSqlQueryModel();
    modal -> setQuery(*getSubject);
    ui->comboBox_Subject->setModel(modal);
}

void Schedule::on_pushButton_Cancel_clicked()
{
    this->close();
}

void Schedule::on_pushButton_Add_clicked()
{
    QString Code, Time, Days;

    Code = ui->comboBox_Subject->currentText();
    Time = ui->timeEdit->time().toString();
    Days = ui->comboBox_Days->currentText();

    QSqlQuery addSchedule;
    addSchedule.prepare("INSERT INTO SCHEDULE (Subject, Time, Days) VALUES (:Code, :Time, :Days)");
    addSchedule.bindValue(":Code", Code);
    addSchedule.bindValue(":Time", Time);
    addSchedule.bindValue(":Days", Days);

    if(Code.isEmpty())
        QMessageBox::warning(this, "No Subject Selected", "Please select a subject.");
    else if(Time.isEmpty())
        QMessageBox::warning(this, "No Time selected", "Please select a time.");
    else if(Days.isEmpty())
        QMessageBox::warning(this, "No Day selected", "Please select a day.");
    else
    {
        if(addSchedule.exec())
            QMessageBox::information(this,"Success", "Schedule added to database.");
        else
            QMessageBox::critical(this,"Error", addSchedule.lastError().text());
    }
}
