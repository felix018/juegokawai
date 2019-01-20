#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <personaje.h>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QObject>
#include "menu1.h"
#include "menus2.h"
#include "game.h"
#include "histo1.h"
#include "play2.h"
#include "segundo.h"
game *gamm;
menu1 *eleccion;
histo1 *hist;
play2 *gamme;
segundo *sec;
int a = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //gamm=new game();
    //gamm->player=true;
    ui->load->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    ui->pushButton->setStyleSheet("QPushButton { background-color : transparent; color : white; }");
    ui->pushButton_3->setStyleSheet("QPushButton { background-color : transparent; color : white; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //eleccion = new menu1();
    //eleccion->show();
    //close();
    hist = new histo1();
    hist->show();
    close();
}

void MainWindow::on_pushButton_3_clicked()
{
    //gamm=new game();
    //gamm->player=true;

//eleccion = new menu1();
    //eleccion->show();
    //close();
    sec=new segundo;
    sec->show();
    close();
    //gamme = new play2();
    //gamme->show();
    //close();
    //a=1;

}

void MainWindow::on_load_clicked()
{
    menus2 *men = new menus2();
    men->show();
    close();

}
