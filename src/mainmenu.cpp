#include "mainmenu.h"
#include <QDebug>

mainmenu::mainmenu(QWidget *parent)
    : Qmainmenu(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}


void mainmenu::on_startgame_clicked()
{
    qDebug() << "hi";
}

