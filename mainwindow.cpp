#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QSqlQueryModel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_AddEvent_clicked()
{
    addeventform.show();
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    ui->dateEdit_Date->setDate(ui->calendarWidget->selectedDate());
}

void MainWindow::on_pushButton_ShowEvents_clicked()
{
    QString Date = ui->dateEdit_Date->date().toString();

    QSqlQuery *getEvent = new QSqlQuery;
    getEvent->prepare("SELECT * FROM TODO WHERE Date = :Date");
    getEvent->bindValue(":Date", Date);

    if(getEvent->exec())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(*getEvent);
        ui->tableView_Event->setModel(modal);
    }
    else
        QMessageBox::critical(this,"Error",getEvent->lastError().text());
}

void MainWindow::on_pushButton_AddSubjects_clicked()
{
    addsubjectsform.show();
}

void MainWindow::on_pushButton_ViewSubjects_clicked()
{
    QSqlQuery *getSubject = new QSqlQuery;
    getSubject->prepare("SELECT * FROM SUBJECT");

    if(getSubject->exec())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(*getSubject);
        ui->tableView_Event->setModel(modal);
    }
    else
        QMessageBox::critical(this,"Error",getSubject->lastError().text());
}

void MainWindow::on_pushButton_References_clicked()
{
    referenceform.show();
}

void MainWindow::on_pushButton_Syllabus_clicked()
{
    syllabusform.show();
}

void MainWindow::on_pushButton_Load_clicked()
{
    QSqlQuery *getSubject = new QSqlQuery;
    getSubject->prepare("SELECT Code FROM SUBJECT");

    if(getSubject->exec())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(*getSubject);
        ui->comboBox_Syllabus->setModel(modal);
        ui->comboBox_References->setModel(modal);
    }
    else
        QMessageBox::critical(this,"Error",getSubject->lastError().text());
}

void MainWindow::on_comboBox_References_currentIndexChanged(const QString &arg1)
{
    QSqlQuery *getSyllabus = new QSqlQuery;
    getSyllabus->prepare("SELECT Topic FROM SYLLABUS WHERE SUBJECTid = :code");
    getSyllabus->bindValue(":code", ui->comboBox_References->currentText());

    if(getSyllabus->exec())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(*getSyllabus);
        ui->comboBox_References2->setModel(modal);
    }
    else
        QMessageBox::critical(this,"Error",getSyllabus->lastError().text());
}

void MainWindow::on_pushButton_RetrieveSyllabus_clicked()
{
    QSqlQuery *getSyllabus = new QSqlQuery;
    getSyllabus->prepare("SELECT Topic FROM SYLLABUS WHERE SUBJECTid = :code");
    getSyllabus->bindValue(":code", ui->comboBox_Syllabus->currentText());

    if(getSyllabus->exec())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(*getSyllabus);
        ui->tableView_Event->setModel(modal);
    }
    else
        QMessageBox::critical(this,"Error",getSyllabus->lastError().text());
}

void MainWindow::on_pushButton_RetrieveReferences_clicked()
{
    QSqlQuery *getReference = new QSqlQuery;
    getReference->prepare("SELECT BookName, URLs FROM REFERENCE WHERE SUBJECTid = :subject AND SYLLABUSid = :syllabus");
    getReference->bindValue(":subject", ui->comboBox_References->currentText());
    getReference->bindValue(":syllabus", ui->comboBox_References2->currentText());

    if(getReference->exec())
    {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(*getReference);
        ui->tableView_Event->setModel(modal);
    }
    else
        QMessageBox::critical(this,"Error",getReference->lastError().text());
}

void MainWindow::on_pushButton_GPAcalculator_clicked()
{
    gpacalculatorform.show();
}

void MainWindow::on_pushButton_Schedule_clicked()
{
    scheduleform.show();
}

void MainWindow::on_pushButton_viewSchedule_clicked()
{
    QSqlQuery *getClasses = new QSqlQuery;
    getClasses->prepare("SELECT Subject, Time FROM SCHEDULE WHERE Days = :Days ");
    getClasses->bindValue(":Days", ui->comboBox_Schedule->currentText());

    getClasses -> exec();

    QSqlQueryModel *modal = new QSqlQueryModel();
    modal ->setQuery(*getClasses);
    ui->tableView_Event->setModel(modal);
}
