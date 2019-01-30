#include "jefe.h"
#include "personaje.h"
#include <random>
#include "play2.h"


extern play2 *gamme;

jefe::jefe()
{
    setPixmap(QPixmap(":/imágenes del juego/roja.png"));
    connect(telep,SIGNAL(timeout()),this, SLOT(mov()));
    telep->start(50);
}
void jefe::mov(){
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de elemntos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scenes->removeItem(this);
            if(colliding_items[i]==gamme->persona){
                //gamm->vid->decreceJazul();
                //vil->start(2500);
                //setPixmap(QPixmap(":/imágenes del juego/040.jpg"));
                        setPos(x(),160);


                        gamme->scenes->setBackgroundBrush(Qt::black);
                        gamme->scenes->removeItem(gamme->persona);

                        gamme->scenes->clear();
                        winni = new QGraphicsTextItem();
                        winni->setPlainText(QString("YOU WIN!"));

                        winni->setPos(300, 100);
                        winni->setDefaultTextColor(Qt::white);
                        winni->setFont(QFont("Dead Kansas",50));
                        gamme->scenes->addItem(winni);
                qDebug()<<"me mandan y obedesco";

                 qDebug()<<"bye1";
            }
             gamme->vto=(gamme->vidas1->vid1)*10+gamme->vidas2->vid2;
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
