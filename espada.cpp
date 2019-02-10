#include "espada.h"
//#include "villanos.h"
#include "play2.h"
#include "fy.h"



extern play2 *gamme;

espada::espada()
{
    connect(toma,SIGNAL(timeout()),this, SLOT(mueve()));
    toma->start(50);

}
void espada::mueve()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); // lista de proyectiles
       for (int i = 0, n = colliding_items.size(); i < n; i++ ){ // se recorre la lista  proyectiles
           if (typeid(*(colliding_items[i])) == typeid(FY)){//condición para eliminación
               gamme->scenes->removeItem(colliding_items[i]);//se remueve al villano de la escena
               gamme->scenes->removeItem(this);  //adiós proyectil
               //gamm->p1=gamm->p1+10;  //se suman 10 al puntaje
               delete colliding_items[i]; //liberar memoria
               return;
           } //por aquí irá lo del jefe final
       }
        setPos(x()+20, y()); //posición en x
        if (x()==1000){
            gamme->scenes->removeItem(this);
            delete this;  //se libera la memoria
        }
        if(gamme->vivir1->vida1<=0){
             toma->stop();  //se para el timer
        }
        //if(gamme->vidas1->vid1<=0){
            //tim->stop();
        //}

}
