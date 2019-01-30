#include "huevi.h"
#include "personaje.h"
#include "play2.h"
#include <QDebug>
#include "game.h"
#include <QFont>
#include "personaje.h"
#include <typeinfo>
#include "proyectiles.h"
#include <QFont>
#include "sangre.h"

extern play2 *gamme;

huevi::huevi(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/imágenes del juego/malpos1.png"));
    connect(vel,SIGNAL(timeout()),this,SLOT(anda()));                  //Timer para mover el huevo
    connect(tras, SIGNAL(timeout()),this,SLOT(anda()));

    vel->start(60);
    tras->start(3000);

}
void huevi::anda()
{
    if(pos().x() > 300){
        setPos(x()-5,y());
        if(cont==0){
            setPixmap((QPixmap(":/imágenes del juego/malpos1.png")));
            cont=1;
        }else if(cont==1){
             setPixmap((QPixmap(":/imágenes del juego/malpos2.png")));
             cont=2;
        }else if(cont==2){
            setPixmap((QPixmap(":/imágenes del juego/malpos3.png")));
            cont=3;
        }else if(cont==3){
            setPixmap((QPixmap(":/imágenes del juego/malpos4.png")));
            cont=4;
        }else if(cont==4){
            setPixmap((QPixmap(":/imágenes del juego/malpos5.png")));
            cont=0;
        }
    }else setPos(x(),y());


}
void huevi::muera(){

}
