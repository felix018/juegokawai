#include "rubi.h"
#include "villanos.h"
#include "personaje.h"
#include "play2.h"
#include "juguemos.h"
extern play2 *gamme;
extern juguemos *jut;

rubi::rubi()
{
    //esta clase no pertenece al game principal......
    setPixmap(QPixmap(":/imágenes del juego/azul.png"));
    connect(tel,SIGNAL(timeout()),this, SLOT(mot()));
    //connect(vil,SIGNAL(timeout()),gamme->persona, SLOT(generar3()));
    //connect(fil,SIGNAL(timeout()),gamme->persona, SLOT(generar2()));


    tel->start(50);

}
void rubi::mot(){
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de elemntos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scenes->removeItem(this);
            //jut->scenas->removeItem(this);
            if(colliding_items[i]==gamme->persona){
                gamme->vivir1->muerteT();
                //jut->vidas1e->muerteT();
                //vil->start(2000);
                //fil->start(2000);
                 qDebug()<<"bye1";
            }
            if(colliding_items[i]==gamme->personita){
                gamme->vivir2->muerteT2();
                //jut->vidas2e->muerteT2();
                //vil->start(2000);
                //fil->start(2000);
            }
               /*
             jut->vtoi=(jut->vidas1e->vid1)*10;
             qDebug()<<jut->vtoi<<"zzzzzzz";

             return;
             */
        }
    }
    //setPos(x()-20, y());
    if (x() < 0){
        //jut->scenas->removeItem(this);
        gamme->scenes->removeItem(this);
        delete this;
    }
}
