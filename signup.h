#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = 0);
    ~Signup();

private slots:
    void on_pushButton_Signup_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
