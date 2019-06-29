#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <QWidget>

namespace Ui {
class Attendance;
}

class Attendance : public QWidget
{
    Q_OBJECT

public:
    explicit Attendance(QWidget *parent = 0);
    ~Attendance();

private:
    Ui::Attendance *ui;
};

#endif // ATTENDANCE_H
