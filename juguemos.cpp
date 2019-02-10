#include "juguemos.h"
#include "ui_juguemos.h"
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
#include "espada.h"
#include "segundo.h"
#include "rubi.h"
#include "kaita.h"

using namespace std;

juguemos::juguemos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::juguemos)
{
    ui->setupUi(this);

    interacciones=new QTimer;
    interacciones->start(10);

    scenas = new QGraphicsScene();
    scenas->setSceneRect(0,0,1000,400);
    ui->ptm->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //Quita la barra de desplazamiento inferior
    ui->ptm->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    //Quita la barra de desplazamineto lateral
    ui->ptm->setScene(scenas);
    setFixedSize(WIDTH,HEIGHT);
}

void juguemos::socrates(int u){
    scenas->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/levelP2e.png")));
//------------------------------personajes__-------------------------------------------------------
    link= new personaje();
    link->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derechai.png"));
    link->setPos(15,280) ;
    link->setHeight(HEIGHT);
    scenas->addItem(link);
    zelda = new personaje();
    zelda->setPixmap(QPixmap(":/imágenes del juego/muneco derecha1.png"));
    zelda->setPos(15,280);
    zelda->setHeight(HEIGHT);
    scenas->addItem(zelda);
    QObject::connect(Jasmin, SIGNAL(timeout()),link,SLOT(jump()));
//-------------------------villanos---------------------------------------------------------
    QObject::connect(raptalias, SIGNAL(timeout()),link,SLOT(generar4()));
    QObject::connect(alisae, SIGNAL(timeout()),link,SLOT(generar3()));
    rubi *porte = new rubi();
    porte->setPos(100,70);
    scenas->addItem(porte);
    rubi *pringado = new rubi();
    pringado->setPos(200,70);
    scenas->addItem(pringado);
    rubi *perron = new rubi();
    perron->setPos(400,70);
    scenas->addItem(perron);
    rubi *kinger = new rubi();
    kinger->setPos(500,70);
    scenas->addItem(kinger);
    kaita *staresr = new kaita();
    staresr->setPos(700,70);
    scenas->addItem(staresr);
    rubi *fureil = new rubi();
    fureil->setPos(800,70);
    scenas->addItem(fureil);

    //vidas1e = new vida();
    //vidas2e = new vida();
    vivire1 = new vivamos();
    vivire2 = new vivamos();
    raptalias->start(2000);

}

juguemos::~juguemos()
{
    delete ui;
}
