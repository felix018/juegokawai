#include "vida.h"
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
extern play2 *gamme;

extern game *gamm;



vida::vida(QObject *parent) : QObject(parent)
{
    over = new QGraphicsTextItem();
    arduino_is_available = false;
    arduino_port_name = "COM3";
    arduino = new QSerialPort;
    connect(will,SIGNAL(timeout()),this,SLOT(vim()));
    will->start(2000);

    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
            if(serialPortInfo.hasVendorIdentifier()){
                qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
            }
            qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
            if(serialPortInfo.hasProductIdentifier()){
                qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
            }
        }
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
               if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
                   if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                       if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                           arduino_port_name = serialPortInfo.portName();
                           arduino_is_available = true;
                       }
                   }
               }
           }

        if(arduino_is_available){
               // open and configure the serialport
               arduino->setPortName(arduino_port_name);
               arduino->open(QSerialPort::WriteOnly);
               arduino->setBaudRate(QSerialPort::Baud115200);
               arduino->setDataBits(QSerialPort::Data8);
               arduino->setParity(QSerialPort::NoParity);
               arduino->setStopBits(QSerialPort::OneStop);
               arduino->setFlowControl(QSerialPort::NoFlowControl);
           }
}
void vida::decrece1(){
    vid1--;
    qDebug()<<vid1;
    if(vid1<=0) GameOver();
}
void vida::decrece2(){
    vid2--;
    qDebug()<<vid2;
    if(vid2<1){
            vid1=0;
            decrece1();
        };
}
void vida::decreceN2(){
    vid1--;
    qDebug()<<vid1;
    if(vid1<=0) gameover();
}
void vida::decrecerN2(){
    vid2--;
    if(vid2<1){
            vid1=0;
            decreceN2();
        };

}

void vida::muerteT(){
    vid1=0;
    qDebug()<<vid1;
    if(vid1<=0) gameover();
}
void vida::muerteT2(){
    vid2=0;
    if(vid2<1){
            vid1=0;
            muerteT();
        };
}
void vida::decreceJazul(){
    vid1=3;
    qDebug()<<"joya azul";
}
void vida::GameOver(){
     qDebug()<<"Game  Over";
      gamm->scene->setBackgroundBrush(Qt::black);
      gamm->scene->removeItem(gamm->per);
      gamm->TGame->stop();
      gamm->TGame2->stop();
      gamm->puntos->stop();
      gamm->scene->clear();
      over->setPlainText(QString("GAME OVER"));
      over->setPos(300, 100);
      over->setDefaultTextColor(Qt::white);
      over->setFont(QFont("DEATH",50));
      gamm->scene->addItem(over);

}
void vida::gameover(){
    qDebug()<<"de malas";
    gamme->scenes->setBackgroundBrush(Qt::black);
    gamme->scenes->removeItem(gamme->persona);
    gamme->scenes->removeItem(gamme->personita);
    gamme->alis->stop();
    gamme->raptalia->stop();
    gamme->scenes->clear();
    over->setPlainText(QString("GAME OVER"));
    over->setPos(300,100);
    over->setDefaultTextColor(Qt::white);
    over->setFont(QFont("DEATH",50));
    gamme->scenes->addItem(over);

}
void vida::vim(){
    QString valor = QString::number(gamm->vt);
        if(arduino->isWritable()){
            arduino->write(valor.toStdString().c_str());
        }
}

