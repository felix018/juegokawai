#include "histo1.h"
#include "ui_histo1.h"

histo1::histo1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::histo1)
{
    ui->setupUi(this);
}

histo1::~histo1()
{
    delete ui;
}
