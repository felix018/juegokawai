#include "play2.h"
#include "ui_play2.h"
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

play2::play2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::play2)
{
    ui->setupUi(this);
    interaccion=new QTimer;
    interaccion->start(10);

    scenes = new QGraphicsScene();
    scenes->setSceneRect(0,0,1000,400);
    ui->ver->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //Quita la barra de desplazamiento inferior
    ui->ver->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    //Quita la barra de desplazamineto lateral
    ui->ver->setScene(scenes);
    setFixedSize(WIDTH,HEIGHT);
}
void play2::inicia(int a)
{
    if (a == 1) playe = true;
    //scenes->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/fondo kawai 1.png")));
//-------------------------------------------personajes---------------------------------------------------
    persona= new personaje();
    persona->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derechai.png"));
    persona->setPos(15,280) ;
    persona->setHeight(HEIGHT);
    scenes->addItem(persona);
    QObject::connect(Jtimen, SIGNAL(timeout()),persona,SLOT(jump()));
    Jtimen->start(45);
}

play2::~play2()
{
    delete ui;
}
