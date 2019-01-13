#include "histo2.h"
#include "ui_histo2.h"
#include <QMessageBox>
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "histo3.h"
histo3 *histor;

histo2::histo2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::histo2)
{
    ui->setupUi(this);
    ui->seguiri->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
}

histo2::~histo2()
{
    delete ui;
}

void histo2::on_seguiri_clicked()
{
    histor = new histo3();
    histor->show();
    close();

}
