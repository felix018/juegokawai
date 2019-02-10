#include "personaje.h"
#include <iostream>
#include<QDebug>
#include <QGraphicsPixmapItem>
//#include "alien2.h"
#include "play2.h"
//#include "tekiga.h"
#include "huevi.h"
#include "amenaza.h"
#include "fy.h"
#include "juguemos.h"
extern play2 *gamme;
extern juguemos *jut;

personaje::personaje(QGraphicsItem *parent): QObject (), QGraphicsPixmapItem(parent)
{
    //draw player
    ban_left=0;                                    //Bandera para mover a la izquierda
        ban_right=0;                               //Bandera para mover a la derecha
        delta=0;                                   //coeficiente de friccion del aire
        delta2=0.1;
        bandera=0;

     QTimer * timer = new QTimer();                                      //Timer de movimiento
        connect(timer, SIGNAL(timeout()),this,SLOT(move_left()));           //Timer para mover a la izquierda
        connect(timer, SIGNAL(timeout()),this,SLOT(move_right()));          //Timer para mover a la derecha
        timer->start(45);
}
void personaje::settBanLeft()
{
    ban_left = 1;                                                       //Define la baldera de izquierda en 1
}

void personaje::settBanRight()
{
    ban_right=1;                                                        //Define la bandera de derecha en 1
}

void personaje::resettBanLeft()
{
    ban_left=0;                                                         //Resetea la bandera izquierda
}

void personaje::resettBanRight()
{
    ban_right=0;                                                        //Resetea la bandera derecha
}

void personaje::setBandera()
{
    bandera=1;                                                          //Bandera para el salto
}



void personaje::set_jump(int jum)
{
    jum=ban_jump;
}
void personaje::move_right()
{
    if (ban_right == 1){
        if (pos().x() + 100  < 980){
            setPos(x() + 20-delta2, y());
        }
    }
}

void personaje::move_left()
{
    if (ban_left == 1){
        if (pos().x() > 0){
            setPos(x() - 20+delta2, y());
        }
     }
}
void personaje::setHeight(int w)
{
    height = w;
}
void personaje::jump()
{
    int posy=0;
    if (bandera == 1){
        if(ban_jump==1){
            posy=posy;

        }else{
            delta+=0.1;
            posy = y() -35*delta + 20*delta*delta ;
            setPos(x()+10,posy);
            if (y() > height - 100){
                bandera = 0;
                delta=0;
                setPos(x(),height - 100);
            }
        }

    }
}
void personaje::generar(){
    c++;
    if(c<12){
        enemigo = new villanos();
        enemigo->setPos(WIDTH-100,HEIGHT-180);
        scene()->addItem(enemigo);
    }
}
void personaje::generar2(){
     aliens *alien = new aliens();
     alien->setPos(WIDTH-100, 15);  //se define posición del aire
     scene()->addItem(alien);

}
void personaje::generar3(){
    amenaza *ame = new amenaza();
    ame->setPos(WIDTH-100, 15);
    gamme->scenes->addItem(ame);

}
void personaje::generar4(){
    c++;
    if(c<12){
        kilua = new FY();
        kilua->setPos(WIDTH-100,HEIGHT-180);
        gamme->scenes->addItem(kilua);
    }

}



