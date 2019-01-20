#include "segundo.h"
#include "ui_segundo.h"
#include <QMessageBox>
#include <QString>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "histo3.h"
#include "play2.h"

extern play2 *gamme;

segundo::segundo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::segundo)
{
    ui->setupUi(this);
}

segundo::~segundo()
{
    delete ui;
}

void segundo::on_holi_clicked()
{
    gamme = new play2();
    gamme->show();
    close();
    gamme->inicia();
        //a=1;
}
