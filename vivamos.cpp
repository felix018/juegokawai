#include "vivamos.h"
#include <QDebug>
#include "game.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QFont>
#include "personaje.h"
#include "trampa.h"
#include "play2.h"
#include "juguemos.h"
extern play2 *gamme;
extern juguemos *jut;

vivamos::vivamos(QObject *parent) : QObject(parent)
{
    overlord = new QGraphicsTextItem();

}
void vivamos::decreceraN2(){
    vida1--;
    qDebug()<<vida1;
    if(vida1<=0) condenaros();
}
void vivamos::decrecereN2(){
    vida2--;
    if(vida2<1){
            vida1=0;
            decreceraN2();
        };

}

void vivamos::muerteT(){
    vida1=0;
    qDebug()<<vida1;
    if(vida1<=0) condenaros();
}
void vivamos::muerteT2(){
    vida2=0;
    if(vida2<1){
            vida1=0;
            muerteT();
        };
}
void vivamos::condenaros(){
     qDebug()<<"de malas";
    gamme->scenes->clear();

    gamme->scenes->setBackgroundBrush(Qt::black);

    gamme->scenes->removeItem(gamme->persona);
    gamme->scenes->removeItem(gamme->personita);
    gamme->alis->stop();
    gamme->raptalia->stop();

    overlord->setPlainText(QString("GAME OVER"));
    overlord->setPos(300,100);
    overlord->setDefaultTextColor(Qt::white);
    overlord->setFont(QFont("DEATH",50));
    gamme->scenes->addItem(overlord);

}
