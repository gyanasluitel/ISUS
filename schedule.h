#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QWidget>

namespace Ui {
class Schedule;
}

class Schedule : public QWidget
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = 0);
    ~Schedule();

private slots:
    void on_pushButton_Load_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Add_clicked();

private:
    Ui::Schedule *ui;
};

#endif // SCHEDULE_H
