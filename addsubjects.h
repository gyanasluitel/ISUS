#ifndef ADDSUBJECTS_H
#define ADDSUBJECTS_H

#include <QWidget>

namespace Ui {
class AddSubjects;
}

class AddSubjects : public QWidget
{
    Q_OBJECT

public:
    explicit AddSubjects(QWidget *parent = 0);
    ~AddSubjects();

private slots:
    void on_pushButton_Cancel_clicked();

    void on_pushButton_Add_clicked();

private:
    Ui::AddSubjects *ui;
};

#endif // ADDSUBJECTS_H
