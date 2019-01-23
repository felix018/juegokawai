#include "alien2.h"
#include "play2.h"
#include "prum.h"
extern play2 *gamme;

alien2::alien2(QObject *parent)
{
    connect(tempoi, SIGNAL(timeout()),this,SLOT(movero()));//timer para mover del alien raro
    connect(pumi, SIGNAL(timeout()),this,SLOT(shootu())); //timer para los disparos
    tempoi->start(50);
    pumi->start(2500);

}
void alien2::movero()
{
    if(pos().x() > 0){ //si el alien raro está en una posición mayor a 0
        setPos(x()-5,y()); //se resta 5 a la posición
        if(cont==0){
            setPixmap((QPixmap(":/imágenes del juego/alien1.png")));
            cont=1;
        }else if(cont==1){
            setPixmap((QPixmap(":/imágenes del juego/alien2.png")));
            cont=2;
        }else if(cont==2){
            setPixmap((QPixmap(":/imágenes del juego/alien3.png")));
            cont=3;
        }else if(cont==3){
            setPixmap((QPixmap(":/imágenes del juego/alien4.png")));
            cont=0;
        }
    }else setPos(x(),y()); //si no se queda quieto
    if(pos().x()<=0){  //si la posición es menor o igual a 0
        gamme->scenes->removeItem(this);
        delete this;
    }


}
void alien2::shootu()
{
    prum *pollo = new prum();
    pollo->setPos(this->x(),this->y());
    gamme->scenes->addItem(pollo);
}
