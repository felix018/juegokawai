#include "sangre.h"
#include "play2.h"
extern play2 *gamme;


sangre::sangre()
{
    setPixmap(QPixmap(":/imágenes del juego/sombra.png"));
    connect(tora,SIGNAL(timeout()),this, SLOT(teteike()));
    tora->start(50);
}
void sangre::teteike()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de elemntos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scenes->removeItem(this);

            if(colliding_items[i]==gamme->persona){
                gamme->vidas1->decreceN2();
                 qDebug()<<"bye1";
            }
            if(colliding_items[i]==gamme->personita){
                gamme->vidas2->decrecerN2();
            }
             gamme->vto=(gamme->vidas1->vid1)*10+gamme->vidas2->vid2;
             qDebug()<<gamme->vto<<"zzzzzzz";
             return;
        }
    }
    setPos(x()-20, y());
    if (x() < 0){
        gamme->scenes->removeItem(this);
        delete this;
    }
}
