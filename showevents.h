#ifndef SHOWEVENTS_H
#define SHOWEVENTS_H

#include <QWidget>

namespace Ui {
class ShowEvents;
}

class ShowEvents : public QWidget
{
    Q_OBJECT

public:
    explicit ShowEvents(QWidget *parent = 0);
    ~ShowEvents();

private:
    Ui::ShowEvents *ui;
};

#endif // SHOWEVENTS_H
