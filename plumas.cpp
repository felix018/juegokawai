#include "plumas.h"
#include "game.h"
#include "personaje.h"
extern game *gamm;

plumas::plumas()
{
    setPixmap(QPixmap(":/imágenes del juego/plumi.png"));
    connect(timer,SIGNAL(timeout()),this, SLOT(moves())); //conecto el timer
    timer->start(50); //inicio el timer
}
void plumas::moves()
{
    setPos(x(), y()+20);
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de plumas
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamm->scene->removeItem(this);
            if(colliding_items[i]==gamm->per){
                 gamm->vid->decrece1();
            }
            qDebug()<<"bye1";
            return;
        }
    }


    if(y() >380){
        setPos(x(),y());
        gamm->scene->removeItem(this);
        delete this;
    }
}
