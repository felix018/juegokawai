#include "kaita.h"
#include "personaje.h"
#include "fy.h"
#include "play2.h"
extern play2 *gamme;

kaita::kaita()
{
    setPixmap(QPixmap(":/imágenes del juego/azul.png"));
    connect(kief,SIGNAL(timeout()),this, SLOT(vamp()));


    kief->start(50);

}
void kaita::vamp(){
    QList<QGraphicsItem *> colliding_items = collidingItems(); //lista de elemntos que colisionan
    for (int i = 0, n = colliding_items.size(); i < n; i++ ){
        if (typeid(*(colliding_items[i])) == typeid(personaje)){
            gamme->scenes->removeItem(this);
            if(colliding_items[i]==gamme->persona){

                        setPos(x(),160);
                        gamme->scenes->setBackgroundBrush(Qt::black);
                        gamme->scenes->removeItem(gamme->persona);
                        gamme->scenes->removeItem(gamme->personita);
                        gamme->scenes->clear();
                        gamme->alis->stop();
                        gamme->raptalia->stop();
                        winner = new QGraphicsTextItem();
                        winner->setPlainText(QString("YOU WIN!"));
                        winner->setPos(300, 100);
                        winner->setDefaultTextColor(Qt::white);
                        winner->setFont(QFont("Dead Kansas",50));
                        gamme->scenes->addItem(winner);
                qDebug()<<"me mandan y obedesco";

                 qDebug()<<"bye1";
            }

        }
    }
    //setPos(x()-20, y());
    if (x() < 0){
        gamme->scenes->removeItem(this);
        delete this;
    }
}
