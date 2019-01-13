#include "histo3.h"
#include "ui_histo3.h"
#include <QMessageBox>
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "histo4.h"
histo4 *hero;

histo3::histo3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::histo3)
{
    ui->setupUi(this);
    ui->seguir->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
}

histo3::~histo3()
{
    delete ui;
}

void histo3::on_seguir_clicked()
{
    hero= new histo4();
    hero->show();
    close();

}
