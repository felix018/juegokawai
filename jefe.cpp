#include "jefe.h"
#include "personaje.h"
#include "prum.h"
#include <random>
#include "play2.h"
#include "huevi.h"

extern play2 *gamme;

jefe::jefe(QObject *parent) : QObject(parent)
{
    connect(chron,SIGNAL(timeout()),this,SLOT(move()));
    //connect(plumas,SIGNAL(timeout()),this,SLOT(pluma1()));
    connect(huevos,SIGNAL(timeout()),this,SLOT(huevo()));
    //chron->start(100);
    //plumas->start(2000);

}
void jefe::win()
{
    vidaR--;
    if(vidaR==80){
        //huevos->stop();
        //plumas->start(1000);
        //flag=1;
    }
}
void jefe::pluma1(){
    numplumas++;
    if(numplumas<21){
        int r=10+rand()%801;
        prum *plumi= new prum();
        plumi->setPos(r,0);
        qDebug()<<"hooooooooola";
        gamme->scenes->addItem(plumi);
    }else {
        flag=0;
        huevos->start(2000);
        plumas->stop();
    }

}
void jefe::huevo(){
    huevi *hues = new huevi();
    hues->setPos(this->x(),this->y());
    gamme->scenes->addItem(hues);
}
