#include "huevi.h"
#include "personaje.h"
#include "play2.h"

extern play2 *gamme;

huevi::huevi(QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/imágenes del juego/plumi.png"));
    connect(vel,SIGNAL(timeout()),this,SLOT(anda()));                  //Timer para mover el huevo
    vel->start(60);

}
void huevi::anda()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();         //Crea la lista con los elementos a colisionar(huevos)
        for (int i = 0, n = colliding_items.size(); i < n; i++ ){          //Ciclo que recorre la lista
            if (typeid(*(colliding_items[i])) == typeid(personaje)){
                gamme->scenes->removeItem(this);
                delete this;
                if(colliding_items[i]==gamme->persona){                      //Si el huevo colisiona con el personaje 1
                    gamme->vidas1->decrece1();                               //Reste 1 vida
                    qDebug()<<"bye1";
                }else if(colliding_items[i]==gamme->personita){              //Si el huevo colisiona con el personaje 2
                    gamme->vidas2->decrece2();                               //Resta una vida
                    qDebug()<<"bye2";
                }
                return;
            }
        }
        if(y()<=290) setPos(x(), y()+20);                 //Si la posicion en y es menor o igual a 290 que sume 20.
        if(y()>291){                                                       //Si la posicion es mayor a 291 que empiece a rodar
                setPos(x()-20, y());                                           //Se mueva en x
        }
        if(x()<0){                                                        //Si la posicion en x es menor a 0
                gamme->scenes->removeItem(this);                               //Elimine el objeto de la escena
                delete this;                                                  //Elimine el puntero
        }
}
