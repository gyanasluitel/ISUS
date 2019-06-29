#ifndef SYLLABUS_H
#define SYLLABUS_H

#include <QWidget>

namespace Ui {
class Syllabus;
}

class Syllabus : public QWidget
{
    Q_OBJECT

public:
    explicit Syllabus(QWidget *parent = 0);
    ~Syllabus();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_load_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Syllabus *ui;
};

#endif // SYLLABUS_H
