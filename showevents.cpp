#include "showevents.h"
#include "ui_showevents.h"

ShowEvents::ShowEvents(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowEvents)
{
    ui->setupUi(this);
}

ShowEvents::~ShowEvents()
{
    delete ui;
}
