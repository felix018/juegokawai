#include "histo4.h"
#include "ui_histo4.h"
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "menu1.h"
menu1 *elecci;

histo4::histo4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::histo4)
{
    ui->setupUi(this);
    ui->siguelo->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
}

histo4::~histo4()
{
    delete ui;
}

void histo4::on_siguelo_clicked()
{
    elecci = new menu1();
    elecci->show();
    close();

}
