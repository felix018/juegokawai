#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include<QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsPixmapItem>
#include <villanos.h>
#include "aliens.h"
#include "caida.h"
#include "fy.h"
//#include "alien2.h"
//#include "play2.h"
#define WIDTH 1000
#define HEIGHT 400

class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit personaje(QGraphicsItem *parent = nullptr);
    void settBanLeft();
    void settBanRight();
    void resettBanLeft();
    void resettBanRight();
    void setBandera();
    void resetBandera();
    int bandera=0,c=0;
     villanos * enemigo;
     villanos *tramp;
     caida *caer;
     FY *kilua;
    /*
    QPixmap *paranguti;
    float ancho=47,alto=57;
    explicit personaje(int, int, QObject *parent);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    */
private:
    int ban_left;
        int ban_right;
        int height;
        float delta = 0,delta2;
        int ban_jump=0;
        float faire=1;

signals:
public slots:

        void move_right();
        void move_left();
        void generar();
        void generar2();
        void generar3();
        void generar4();
        void jump();
        void setHeight(int);
        void set_jump(int bul);

    //void keyPressEvent(QKeyEvent *ev);
};
#endif // PERSONAJE_H
