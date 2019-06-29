#include "reference.h"
#include "ui_reference.h"
#include <QtSql>
#include <QMessageBox>
#include <QString>

Reference::Reference(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reference)
{
    ui->setupUi(this);
}

Reference::~Reference()
{
    delete ui;
}

void Reference::on_pushButton_Load_clicked()
{
    QSqlQuery *getSubject = new QSqlQuery;
    getSubject->prepare("SELECT Code FROM SUBJECT");

    getSubject->exec();

    QSqlQueryModel *modal = new QSqlQueryModel();

    modal->setQuery(*getSubject);

    ui->comboBox_Subject->setModel(modal);
}

void Reference::on_comboBox_Subject_currentIndexChanged(const QString &arg1)
{
    QSqlQuery *getSyllabus = new QSqlQuery;
    getSyllabus->prepare("SELECT Topic FROM SYLLABUS WHERE SUBJECTid = :code");
    getSyllabus->bindValue(":code", ui->comboBox_Subject->currentText());

    getSyllabus->exec();

    QSqlQueryModel *modal = new QSqlQueryModel();

    modal->setQuery(*getSyllabus);
    ui->comboBox_Syllabus->setModel(modal);
}

void Reference::on_pushButton_Exit_clicked()
{
    this->close();
}

void Reference::on_pushButton_Add_clicked()
{
    QString BookName, URL, SUBJECTid, SYLLABUSid;

    BookName = ui->lineEdit_Bookname->text();
    URL = ui->lineEdit_URL->text();
    SUBJECTid = ui->comboBox_Subject->currentText();
    SYLLABUSid = ui->comboBox_Syllabus->currentText();

    QSqlQuery addReference;
    addReference.prepare("INSERT INTO REFERENCE (BookName, URLs, SUBJECTid, SYLLABUSid) VALUES (:BookName, :URL, :SUBJECTid, :SYLLABUSid)");
    addReference.bindValue(":BookName", BookName);
    addReference.bindValue(":URL", URL);
    addReference.bindValue(":SUBJECTid", SUBJECTid);
    addReference.bindValue(":SYLLABUSid", SYLLABUSid);

    if(BookName.isEmpty() && URL.isEmpty())
        QMessageBox::warning(this,"No Reference", "Please add a reference.");
    else if(SUBJECTid.isEmpty() || SYLLABUSid.isEmpty())
        QMessageBox::warning(this,"Error", "Please select the topic of the reference.");
    else
    {
        if(addReference.exec()){
            QMessageBox::information(this,"Success","Reference added to database.");
            ui->lineEdit_Bookname->clear();
            ui->lineEdit_URL->clear();
        }
        else
            QMessageBox::critical(this,"Error",addReference.lastError().text());
    }
}
