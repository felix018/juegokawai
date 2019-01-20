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


    interar=new QTimer;
    interar->start(10);

    scenes = new QGraphicsScene();
    scenes->setSceneRect(0,0,1000,400);
    ui->ver->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //Quita la barra de desplazamiento inferior
    ui->ver->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    //Quita la barra de desplazamineto lateral
    ui->ver->setScene(scenes);
    setFixedSize(WIDTH,HEIGHT);

//---------------------------personaje-----------------------------------

}
void play2::inicia()
{
    //if (a == 1) playe = true;
    scenes->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/levelP2e.png")));
//-------------------------------------------personajes---------------------------------------------------
    persona= new personaje();
    persona->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derechai.png"));
    persona->setPos(15,280) ;
    persona->setHeight(HEIGHT);
    scenes->addItem(persona);

    //----------------------------------------------------------------------------
    personita=new personaje();
    personita->setPixmap(QPixmap(":/imágenes del juego/muneco derecha1.png"));
    personita->setPos(15,280);
    personita->setHeight(HEIGHT);
    scenes->addItem(personita);
    //QObject::connect(Jtimen, SIGNAL(timeout()),personita,SLOT(jump()));
//-------------------------------Timers villanos y trampas-------------------------------
    QObject::connect(TGamen, SIGNAL(timeout()),persona,SLOT(generar()));
    QObject::connect(TGame2n, SIGNAL(timeout()),persona,SLOT(generar2()));
    vida1 = new vida();
    vida2 = new vida();

    QObject::connect(Jtimen, SIGNAL(timeout()),persona,SLOT(jump()));
    Jtimen->start(45);
}
void play2::keyPressEvent(QKeyEvent * event){
//----------------personaje 1-----------------------------------------
    if(event->key()==Qt::Key_M){
        persona->settBanRight();
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita1 derechai.png"));
        qDebug() << "left";
    }else if (event->key() == Qt::Key_N){
        persona->settBanLeft();
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita1 izquierdai2.png"));
        qDebug() << "right";
    }
}

play2::~play2()
{
    delete ui;
}
