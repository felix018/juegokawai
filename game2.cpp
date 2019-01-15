#include "game2.h"
#include "ui_game2.h"
#include <iostream>
#include <QMessageBox>
#include <fstream>
#include "mainwindow.h"
#include "trampa.h"
#include "caida.h"
#include "piedritas.h"
#include <QString>
#include <ctype.h>
#include "stdlib.h"
#include "gemare.h"

using namespace std;
game2::game2(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::game2)
{
    ui->setupUi(this);
}

game2::~game2()
{
    delete ui;
}
