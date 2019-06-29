#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addevent.h>
#include <addsubjects.h>
#include <syllabus.h>
#include <reference.h>
#include <gpacalculator.h>
#include <schedule.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_AddEvent_clicked();

    void on_calendarWidget_selectionChanged();

    void on_pushButton_ShowEvents_clicked();

    void on_pushButton_AddSubjects_clicked();

    void on_pushButton_ViewSubjects_clicked();

    void on_pushButton_References_clicked();

    void on_pushButton_Syllabus_clicked();

    void on_pushButton_Load_clicked();

    void on_comboBox_References_currentIndexChanged(const QString &arg1);

    void on_pushButton_RetrieveSyllabus_clicked();

    void on_pushButton_RetrieveReferences_clicked();

    void on_pushButton_GPAcalculator_clicked();

    void on_pushButton_Schedule_clicked();

    void on_pushButton_viewSchedule_clicked();

private:
    Ui::MainWindow *ui;
    AddEvent addeventform;
    AddSubjects addsubjectsform;
    Syllabus syllabusform;
    Reference referenceform;
    GPAcalculator gpacalculatorform;
    Schedule scheduleform;
};

#endif // MAINWINDOW_H
