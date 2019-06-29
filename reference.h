#ifndef REFERENCE_H
#define REFERENCE_H

#include <QWidget>

namespace Ui {
class Reference;
}

class Reference : public QWidget
{
    Q_OBJECT

public:
    explicit Reference(QWidget *parent = 0);
    ~Reference();

private slots:
    void on_pushButton_Load_clicked();

    void on_comboBox_Subject_currentIndexChanged(const QString &arg1);

    void on_pushButton_Exit_clicked();

    void on_pushButton_Add_clicked();

private:
    Ui::Reference *ui;
};

#endif // REFERENCE_H
