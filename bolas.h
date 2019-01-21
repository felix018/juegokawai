#ifndef BOLAS_H
#define BOLAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QGraphicsScene>
class bolas : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit bolas(QObject *parent = nullptr);
    QTimer *shikan=new QTimer();
    QTimer * plumas = new QTimer();
    QTimer *huevos = new QTimer();

    QGraphicsTextItem *winn;
    QGraphicsPixmapItem *pchente;

    int cont=0,cont1=0;
        int numplumas=0;
        int flag=0;
        int head=0;
        int vidaR=100;
        void win();
signals:

public slots:

    void huevo();
    void pluma1();
    void movereis();
};

#endif // BOLAS_H
