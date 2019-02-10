#ifndef VIVAMOS_H
#define VIVAMOS_H

#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QtSerialPort/QSerialPort>
#include <QMediaPlayer>
#include "personaje.h"
#include "villanos.h"

class vivamos : public QObject
{
    Q_OBJECT
public:
    explicit vivamos(QObject *parent = nullptr);
    int vida1=6;
    int vida2=6;
    QTimer *timoti=new QTimer();
    QTimer *vileno = new QTimer();
    QTimer *william = new QTimer();
    QGraphicsTextItem *overlord;

    void decreceraN2();
    void decrecereN2();
    void muerteT();
    void muerteT2();

    void condenaros();

signals:

public slots:
};

#endif // VIVAMOS_H
