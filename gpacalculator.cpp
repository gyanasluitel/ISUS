#include "gpacalculator.h"
#include "ui_gpacalculator.h"
#include <QString>
#include <QMessageBox>

GPAcalculator::GPAcalculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GPAcalculator)
{
    ui->setupUi(this);
}

GPAcalculator::~GPAcalculator()
{
    delete ui;
}

void GPAcalculator::on_pushButton_clicked()
{
    {
       grades[i] = ui->lineEdit->text();
       Credits[i] = ui->lineEdit_2->text().toInt();
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       i++;
    }

}

void GPAcalculator::on_pushButton_Calculate_clicked()
{
    for (int i=0; i<8; i++)
    {
        if(grades[i]=="A")
            GPA[i]= 4.00;
        else if(grades[i]=="A-")
            GPA[i]= 3.70;
        else if(grades[i]=="B+")
            GPA[i]= 3.30;
        else if(grades[i]=="B")
            GPA[i]= 3.00;
        else if(grades[i]=="B-")
            GPA[i]= 2.70;
        else if(grades[i]== "C+")
            GPA[i]= 2.30;
        else if(grades[i]=="C")
            GPA[i]= 2.00;
        else if(grades[i]=="C-")
            GPA[i]= 1.70;
        else if(grades[i]=="D")
            GPA[i]= 1.00;
        else
            GPA[i]= 0.00;
    }

    for(int i=0;i<8;i++)
    {
        totalCredit += Credits[i];
        totalGPA += GPA[i]*Credits[i];
    }

    double scoredGPA = totalGPA/totalCredit;

    QMessageBox::information(this,"GPA is",QString::number(scoredGPA));

}

void GPAcalculator::on_pushButton_Exit_clicked()
{
    this->close();
}
