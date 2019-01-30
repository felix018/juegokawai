#include "rubi.h"
#include "villanos.h"
#include "personaje.h"
#include "play2.h"
extern play2 *gamme;

rubi::rubi()
{
    //esta clase no pertenece al game principal......
    setPixmap(QPixmap(":/imágenes del juego/roja.png"));
    connect(tel,SIGNAL(timeout()),this, SLOT(mot()));
    connect(vil,SIGNAL(timeout()),gamme->persona, SLOT(generar3()));
    //connect(fil,SIGNAL(timeout()),gamme->persona, SLOT(generar2()));


    tel->start(50);

}
void rubi::mot(){
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de elemntos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scenes->removeItem(this);
            if(colliding_items[i]==gamme->persona){
                gamme->vidas1->muerteT();
                //vil->start(2000);
                //fil->start(2000);
                 qDebug()<<"bye1";
            }
            if(colliding_items[i]==gamme->personita){
                gamme->vidas2->muerteT2();
                //vil->start(2000);
                //fil->start(2000);
            }

             gamme->vto=(gamme->vidas1->vid1)*10;
             qDebug()<<gamme->vto<<"zzzzzzz";
             return;
        }
    }
    //setPos(x()-20, y());
    if (x() < 0){
        gamme->scenes->removeItem(this);
        delete this;
    }
}
