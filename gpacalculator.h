#ifndef GPACALCULATOR_H
#define GPACALCULATOR_H

#include <QWidget>

namespace Ui {
class GPAcalculator;
}

class GPAcalculator : public QWidget
{
    Q_OBJECT

public:
    explicit GPAcalculator(QWidget *parent = 0);
    ~GPAcalculator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Calculate_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::GPAcalculator *ui;
    QString grades[8];
    int Credits[8];
    double GPA[8];
    double totalGPA = 0.00;
    int totalCredit = 0;
    int i = 0;
};

#endif // GPACALCULATOR_H
