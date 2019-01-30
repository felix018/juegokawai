#ifndef JEFE_H
#define JEFE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QGraphicsScene>

class jefe : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit jefe();

    QTimer *telep = new QTimer();
    QTimer *vilis = new QTimer();
    QGraphicsTextItem *winni = new QGraphicsTextItem();
    int cont=0,cont1=0;
    int numplumas=0;
    int flag=0;
    int head=0;
    int c=0;
    int vidaR=100;


signals:

public slots:
    void mov();
    //void huevo();
    //void pluma1();
};

#endif // JEFE_H
