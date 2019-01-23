#include "game.h"
#include "ui_game.h"
#include "menu1.h"
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
#define RUTA_ARCHIVO "guardar.txt"

extern menu1 *eleccion;
using namespace std;

game::game(QWidget *parent) :

    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    interacion=new QTimer;
    interacion->start(10);
    //connect(interacion,SIGNAL (timeout()),SLOT (F()));

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,400);
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //Quita la barra de desplazamiento inferior
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    //Quita la barra de desplazamineto lateral
    ui->view->setScene(scene);
    setFixedSize(WIDTH,HEIGHT);
    qDebug()<<cont<<" "<<p1;






//-----------------------------comienzo intento del personaje-------------------------------------


}

void game::iniciar(int a){
    if (a == 1) player = true;
    if(cont==0){
         scene->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/fondo kawai 1.png")));




//------------------------------timer y personaje-------------------------------------------------
        per= new personaje();
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derechai.png"));
        per->setPos(15,280) ;
        per->setHeight(HEIGHT);
        scene->addItem(per);
        QObject::connect(Jtime, SIGNAL(timeout()),per,SLOT(jump()));
        Jtime->start(45);
//---------------------------personaje2----------------------------------------------------------

        //if(a==1){
            //per2=new personaje();
            //per2->setPixmap(QPixmap(":/imágenes del juego/per2.png"));
            //per2->setPos(15,280);
            //per2->setHeight(HEIGHT);
            //scene->addItem(per2);
            //QObject::connect(Jtime, SIGNAL(timeout()),per2,SLOT(jump()));


        //}

//------------------------------------timers de los villanos y de las trampas----------------------
        QObject::connect(TGame, SIGNAL(timeout()),per,SLOT(generar()));
        QObject::connect(TGame2, SIGNAL(timeout()),per,SLOT(generar2()));
        //QObject::connect(Tcaer, SIGNAL(timeout()),per,SLOT(generar3()));
        TGame->start(2000);
        //TGame2->start(2000);
        //Tcaer->start(2000);

        vid = new vida();
        niveles();

//--------------------------------------pinchos---------------------------------------------------
        plat->setPixmap(QPixmap(":/imágenes del juego/pini.png"));
        rect = new QGraphicsRectItem();
        rect->setRect(400,288,140,10);

        plat->setPos(400,288);
        scene->addItem(rect);
        scene->addItem(plat);



    }



}
//-------------------teclas del juego-------------------------------------------------------------
void game::keyPressEvent(QKeyEvent *event)
{
    //personaje 1
    if(event->key()==Qt::Key_M){
        per->settBanRight();
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita1 derechai.png"));
        qDebug() << "left";
    }else if (event->key() == Qt::Key_N){
        per->settBanLeft();
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita1 izquierdai2.png"));
        qDebug() << "right";

    }else if(event->key()==Qt::Key_J){ //en esta se salta
        per->setBandera();
    }else if(event->key()==Qt::Key_K){
        balin=new disparos();
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita shoot buen.png"));
        balin->setPixmap(QPixmap(":/imágenes del juego/espin.png"));
        balin->setPos(per->x()+60,per->y()+20); //posicionar la espada con respecto al per
        scene->addItem(balin);
        qDebug() << "piu";
    }
    if(per->pos().x()>800 && per->c>=5){
        cont++;
        niveles();
        puntajes();
    }
    if(cont==0){
        if(rect->collidesWithItem(per)){
            vid->decrece1();
            qDebug()<<"mori";
            //if(player==true){
              //  vid2->decrece2();
                //qDebug()<<"mori2";
            //}

        }

    }

/*
    if(player==true){
        if(event->key()==Qt::Key_Z){
            per2->settBanRight();
            per2->setPixmap(QPixmap(":/imágenes del juego/per22.png"));
            qDebug() << "left2";
        }else if (event->key() == Qt::Key_X){
            per2->settBanLeft();
            per2->setPixmap(QPixmap(":/imágenes del juego/per3 izquierda.png"));
            qDebug() << "right2";
        }else if(event->key()==Qt::Key_S){ //en esta se salta
            per2->setBandera();
        }else if(event->key()==Qt::Key_A){
            balin1=new disparos();
            per2->setPixmap(QPixmap(":/imágenes del juego/per2 atack.png"));
            balin1->setPixmap(QPixmap(":/imágenes del juego/espin.png"));
            balin1->setPos(per2->x()+60,per2->y()+20); //posicionar la espada con respecto al per
            scene->addItem(balin1);
            qDebug() << "piu2";
        }
        if(vid->vid1<=0){
            scene->removeItem(balin1);
        }

    }
    */

}
void game::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_M){
        per->resettBanRight();
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita3 derechai.png"));
    }else if (event->key()==Qt::Key_N) {
        per->resettBanLeft();
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita3 izquierdai.png"));
    }
    /*
    if(player==true){
        if(event->key()==Qt::Key_Z){
            per2->resettBanRight();
        }else if(event->key() == Qt::Key_X){
            per2->resettBanLeft();
        }

    }
    */
}
void game::puntajes(){
    p1+=10;
    p2+=10;
    //tex->setPlainText(QString("puntaje"));
    ui->puntaje->display(p1);
    if(player==true){
        ui->puntaje2->display(p2);
    }
}
void game::niveles(){
//--------------------------------------------------------------------level 2 :3
    if(cont==1){
//----------se paran los timers------------
        TGame->stop();
        TGame2->stop();
        scene->removeItem(per);
        scene->clear();
        if(player==true){
            scene->removeItem(per2);
            qDebug()<<"ya me fui amiguito";
        }
//-------------------------------------------

        //comienza nivel 2
        scene->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/fondo kawai 4.png")));
        scene->addItem(per);
        if(player==true){
            scene->addItem(per2);
        }

        //definimos al personaje otra vez
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derecha.png"));
        per->setHeight(HEIGHT);   //altura máxima

        per->setPos(15, 250);//posición del personaje
        /*
        if(player==true){
            per2->setPixmap(QPixmap(":/imágenes del juego/per2.png"));
            per2->setPos(15,280);
            per2->setHeight(HEIGHT);
        }
        */
        per->c=0;   //para volver a ver villanos

        TGame->start(2500); //comienza de nuevo los timers
        //TGame2->start(2800);  //timer de los aliens
        trap=new trampa();  //se añade una trampa
        trap->setPos(550,300);
        scene->addItem(trap);
        trick=new trampa();
        trick->setPos(800,300);
        scene->addItem(trick);
        team=new trampa();
        team->setPos(250,300);
        scene->addItem(team);

        huevo2=new caida();
        huevo2->setPixmap(QPixmap(":/imágenes del juego/boom.png"));
        huevos--;

        huevo2->setPos(500,20);

        scene->addItem(huevo2);
        huevo=new caida();
        huevo->setPos(700,20);
        huevo->setPixmap(QPixmap(":/imágenes del juego/boom.png"));
        scene->addItem(huevo);
        huevo3=new caida();
        huevo3->setPos(350,20);
        huevo3->setPixmap(QPixmap(":/imágenes del juego/boom.png"));
        scene->addItem(huevo3);





    }else if(cont==2){
        TGame->stop();
        TGame2->stop();
        scene->removeItem(per);
        scene->removeItem(huevo);
        scene->removeItem(huevo2);
        scene->removeItem(huevo3);
        scene->clear();
//----------------------------------------------------------------------------------------
        scene->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/esc3.png")));
        scene->addItem(per);
       //------------definir otra vez--------------------------------------
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derecha.png"));
        per->setHeight(HEIGHT);   //altura máxima

        per->setPos(15, 250);//posición del personaje
        per->c=0;   //para volver a ver villanos
        TGame2->start(2000);
        TGame->start(2000);
        trick=new trampa();
        trick->setPos(800,300);
        scene->addItem(trick);
        team=new trampa();
        team->setPos(250,300);
        scene->addItem(team);

        //piedritas *pier = new piedritas();
        //pier->setPos(100,70);
        //scene->addItem(pier);
        //gemare *gemi = new gemare();
        //gemi->setPos(730,70);
        //scene->addItem(gemi);




    }else if(cont==3){
        TGame->stop();
        TGame2->stop();
        scene->removeItem(per);
        scene->clear();
//----------------------------------------rellenar--------------------------------
        scene->setBackgroundBrush(QBrush(QImage(":/imágenes del juego/esc4.png")));
        scene->addItem(per);
//---------------------------------------------------------------------------------
        per->setPixmap(QPixmap(":/imágenes del juego/muñequita2 derecha.png"));
        per->setHeight(HEIGHT);   //altura máxima

        per->setPos(15, 250);//posición del personaje
        per->c=0;   //para volver a ver villanos

        piedritas *pier = new piedritas();
        pier->setPos(100,70);
        scene->addItem(pier);
        gemare *gemi = new gemare();
        gemi->setPos(730,70);
        scene->addItem(gemi);

    }
//-----------------------------------------------------------------------------------level3

}





game::~game()
{
    delete ui;
}



void game::on_guardado_clicked()
{
    ofstream save;                                                   //Define el archivo en modo de escritura
       save.open(eleccion->b,ios::out);                                     //Abre el archivo
       cout<<"estoy guardando"<<endl;
       save<<cont<<endl;                                                //Escribe el nivel actual
       //save<<p1<<endl;                                                  //Escriber el puntaje del jugador 1

                                                        //Escribe el puntaje del jugador 2
       save.close();

}
