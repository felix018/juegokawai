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
#include "espada.h"
#include "segundo.h"
#include "rubi.h"
#include "kaita.h"
//#include "tekiga.h"
segundo *vamos;

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
    //qDebug()<<"resultado de u"<<vamos->u<<"mireloooo";
    //if(vamos->u==1){
        //outside=1;
    //}

//---------------------------personaje-----------------------------------

}
void play2::inicia(int u)
{

    if(u==1){
        outside=1;
    }
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
    QObject::connect(Jtimen, SIGNAL(timeout()),personita,SLOT(jump()));
//-------------------------------Timers villanos y trampas-------------------------------
    //QObject::connect(TGamen, SIGNAL(timeout()),persona,SLOT(generar()));
    QObject::connect(raptalia, SIGNAL(timeout()),persona,SLOT(generar4()));
    QObject::connect(alis, SIGNAL(timeout()),persona,SLOT(generar3()));
    rubi *port = new rubi();
    port->setPos(100,70);
    scenes->addItem(port);
    rubi *pringa = new rubi();
    pringa->setPos(200,70);
    scenes->addItem(pringa);
    rubi *peron = new rubi();
    peron->setPos(400,70);
    scenes->addItem(peron);
    rubi *kinge = new rubi();
    kinge->setPos(500,70);
    scenes->addItem(kinge);
    kaita *stares = new kaita();
    stares->setPos(700,70);
    scenes->addItem(stares);
    rubi *furei = new rubi();
    furei->setPos(800,70);
    scenes->addItem(furei);

    vidas1 = new vida();
    vidas2 = new vida();
    alis->start(2000);
    raptalia->start(2000);


    QObject::connect(Jtimen, SIGNAL(timeout()),persona,SLOT(jump()));
    Jtimen->start(45);
}
void play2::keyPressEvent(QKeyEvent * events){
//----------------personaje 1-----------------------------------------
    if(events->key()==Qt::Key_K){
        persona->settBanRight();
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita1 derechai.png"));
        qDebug() << "left";
    }else if (events->key() == Qt::Key_J){
        persona->settBanLeft();
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita1 izquierdai2.png"));
        qDebug() << "right";
    }else if(events->key()==Qt::Key_U){ //en esta se salta
        persona->setBandera();
    }else if(events->key()==Qt::Key_I){
        /*
        espada=new disparos();
        qDebug()<<"dispararrrrrrr";
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita shoot buen.png"));
        espada->setPixmap(QPixmap(":/imágenes del juego/espin.png"));
        espada->setPos(persona->x()+60,persona->y()+20); //posicionar la espada con respecto al per
        scenes->addItem(espada);
        qDebug() << "piu";
        */
        //qDebug()<<"resultado de u"<<vamos->u<<"mireloooo";
        espada *espol;
        espol=new espada();
        qDebug()<<"dispararrrrrrr";
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita shoot buen.png"));
        espol->setPixmap(QPixmap(":/imágenes del juego/espin.png"));
        espol->setPos(persona->x()+60,persona->y()+20);
        scenes->addItem(espol);
        qDebug()<< "piuuuuuu";
    }

//-------------------------------------------personaje2---------------------------------
    if(events->key()==Qt::Key_Z){
        personita->settBanRight();
        personita->setPixmap(QPixmap(":/imágenes del juego/muñequito1 derecha.png"));
        qDebug() << "left";
    }else if (events->key() == Qt::Key_X){
        personita->settBanLeft();
        personita->setPixmap(QPixmap(":/imágenes del juego/muñequito1 izquierdai2.png"));
        qDebug() << "right";
    }else if(events->key()==Qt::Key_A){ //en esta se salta
        personita->setBandera();
    }else if(events->key()==Qt::Key_S){
        espada *espi;
        espi = new espada();
        qDebug()<<"dispararrrrrrr";
        personita->setPixmap(QPixmap(":/imágenes del juego/muñequita shoot buen.png"));
        espi->setPixmap(QPixmap(":/imágenes del juego/espin.png"));
        espi->setPos(personita->x()+60,personita->y()+20);
        scenes->addItem(espi);
        qDebug()<< "piuuuuuu";
    }
}
void play2::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_K){
        persona->resettBanRight();
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita3 derechai.png"));
    }else if (event->key()==Qt::Key_J) {
        persona->resettBanLeft();
        persona->setPixmap(QPixmap(":/imágenes del juego/muñequita3 izquierdai.png"));
    }
//--------------------------personaje 2-------------------------------------------------
    if (event->key() == Qt::Key_Z){
        personita->resettBanRight();
        personita->setPixmap(QPixmap(":/imágenes del juego/muñequito1 derechai.png"));
    }else if (event->key()==Qt::Key_X) {
        personita->resettBanLeft();
        personita->setPixmap(QPixmap(":/imágenes del juego/muñequito1 izquierdaa.png"));
    }
}

play2::~play2()
{
    delete ui;
}
