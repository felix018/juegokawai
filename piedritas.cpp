#include "piedritas.h"
#include "game.h"
#include "villanos.h"
#include "personaje.h"
extern game *gamm;

piedritas::piedritas()
{

    setPixmap(QPixmap(":/imágenes del juego/roja.png"));
    connect(tel,SIGNAL(timeout()),this, SLOT(move()));
    //connect(vil,SIGNAL(timeout()),gamm->per, SLOT(generar()));
    //connect(vil,SIGNAL(timeout()),gamm->per, SLOT(generar2()));


    tel->start(50);


}




void piedritas::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de elemntos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamm->scene->removeItem(this);
            if(colliding_items[i]==gamm->per){
                gamm->vid->sayonara();
                vil->start(2500);


                 qDebug()<<"bye1";
            }
             gamm->vt=(gamm->vid->vid1)*10;
             qDebug()<<gamm->vt<<"zzzzzzz";
             return;
        }
    }
    //setPos(x()-20, y());
    if (x() < 0){
        gamm->scene->removeItem(this);
        delete this;
    }
}

