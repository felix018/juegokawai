#include "amenaza.h"
#include <QDebug>
#include "game.h"
#include <QFont>
#include "personaje.h"
#include "prum.h"
#include <typeinfo>
#include "play2.h"
extern play2 *gamme;

amenaza::amenaza(QObject *parent)
{
    connect(tempura, SIGNAL(timeout()),this,SLOT(partite()));//timer para mover del alien raro
    connect(kusoda, SIGNAL(timeout()),this,SLOT(zepar())); //timer para los disparos
    tempura->start(50);
    kusoda->start(2000);


}
void amenaza::partite()
{
    if(pos().x() > 0){ //si el alien raro está en una posición mayor a 0
        setPos(x()-5,y()); //se resta 5 a la posición
        if(cont==0){
            setPixmap((QPixmap(":/imágenes del juego/alien1.png")));
            cont=1;
        }else if(cont==1){
            setPixmap((QPixmap(":/imágenes del juego/alien2.png")));
            cont=2;
        }else if(cont==2){
            setPixmap((QPixmap(":/imágenes del juego/alien3.png")));
            cont=3;
        }else if(cont==3){
            setPixmap((QPixmap(":/imágenes del juego/alien4.png")));
            cont=0;
        }
    }else setPos(x(),y()); //si no se queda quieto
    if(pos().x()<=0){  //si la posición es menor o igual a 0
        gamme->scenes->removeItem(this);
        delete this;
    }


}
void amenaza::zepar(){
    prum *sol = new prum();
    sol->setPos(this->x(),this->y());
    gamme->scenes->addItem(sol);
}
