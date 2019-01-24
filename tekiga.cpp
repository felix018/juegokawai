#include "tekiga.h"
#include <QDebug>
#include "game.h"
#include <QFont>
#include "personaje.h"
#include <typeinfo>
#include "proyectiles.h"
#include "play2.h"
#include <QFont>
#include "ultimod.h"
extern play2 *gamme;
tekiga::tekiga(QGraphicsItem  *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap((QPixmap(":/imágenes del juego/malpos1.png")));
    connect(chronol, SIGNAL(timeout()),this,SLOT(andate()));
    connect(tra, SIGNAL(timeout()),this,SLOT(shooting()));
    chronol->start(50);
    tra->start(3000);

}
void tekiga::andate()
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
void tekiga::shooting(){
    ultimoD *uld = new ultimoD();
    uld->setPos(this->x()-20,this->y()+25);
    gamme->scenes->addItem(uld);
}
