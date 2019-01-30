#include "fy.h"
#include <QDebug>
#include "sangre.h"
#include <QFont>
#include "personaje.h"
#include <typeinfo>
#include "proyectiles.h"
#include "play2.h"
#include <QFont>
#include "sangre.h"
extern play2 *gamme;

FY::FY(QGraphicsItem  *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap((QPixmap(":/imágenes del juego/malpos1.png")));
    connect(firolai, SIGNAL(timeout()),this,SLOT(satesate()));
    connect(nevermind, SIGNAL(timeout()),this,SLOT(samaland()));
    firolai->start(50);
    nevermind->start(2000);

}
void FY::satesate(){
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
void FY::samaland(){
    sangre *hurara = new sangre();
    hurara->setPos(this->x()-20,this->y()+25);
    gamme->scenes->addItem(hurara);
}

