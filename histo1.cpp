#include "histo1.h"
#include "ui_histo1.h"
#include <QMessageBox>
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
histo2 *histi;

histo1::histo1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::histo1)
{
    ui->setupUi(this);
     ui->siguiente->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
}

histo1::~histo1()
{
    delete ui;
}

void histo1::on_siguiente_clicked()
{
    histi = new histo2;
    histi->show();
    close();
}
