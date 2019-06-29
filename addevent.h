#ifndef ADDEVENT_H
#define ADDEVENT_H

#include <QWidget>

namespace Ui {
class AddEvent;
}

class AddEvent : public QWidget
{
    Q_OBJECT

public:
    explicit AddEvent(QWidget *parent = 0);
    ~AddEvent();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::AddEvent *ui;
};

#endif // ADDEVENT_H
