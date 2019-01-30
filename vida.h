#ifndef VIDA_H
#define VIDA_H

#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QtSerialPort/QSerialPort>
#include <QMediaPlayer>
#include "personaje.h"
#include "villanos.h"



class vida : public QObject
{
    Q_OBJECT
public:
    explicit vida(QObject *parent = nullptr);
    int vid1=6;
    int vid2=6;
    QTimer *tim=new QTimer();
    QTimer *vil = new QTimer();
    QTimer *will = new QTimer();
    QGraphicsTextItem *over;
    void decrece1();
    void decrece2();
    void decreceN2();
    void decrecerN2();
    void decreceJazul();
    void muerteT();
    void muerteT2();
    void GameOver();
    void gameover();
private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
private slots:
    void vim();



signals:   
public slots:
};

#endif // VIDA_H
