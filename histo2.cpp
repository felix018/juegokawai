#include "histo2.h"
#include "ui_histo2.h"
#include <QMessageBox>
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"

histo2::histo2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::histo2)
{
    ui->setupUi(this);
}

histo2::~histo2()
{
    delete ui;
}
