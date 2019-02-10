#include "prum.h"
#include "personaje.h"
#include "play2.h"
extern play2 *gamme;
prum::prum()
{
    setPixmap(QPixmap(":/imágenes del juego/plumi.png"));
    connect(chronos,SIGNAL(timeout()),this, SLOT(movi()));
    chronos->start(50);
}
void prum::movi()
{
    setPos(x(), y()+20);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scenes->removeItem(this);
            if(colliding_items[i]==gamme->persona){
                 gamme->vivir1->decreceraN2();
            }
            if(colliding_items[i]==gamme->personita){
                gamme->vivir2->decrecereN2();
            }
            qDebug()<<"bye1";
            return;
        }
    }

    if(y() >380){
        setPos(x(),y());
        gamme->scenes->removeItem(this);
        delete this;
    }
}
