#ifndef PLAY2_H
#define PLAY2_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QImage>
#include <QMediaPlayer>
#include <QFile>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <personaje.h>
#include "vida.h"
#include "disparos.h"
#include "trampa.h"
#include "caida.h"
#include "joyas.h"
#define WIDTH 1000
#define HEIGHT 400

namespace Ui {
class play2;
}

class play2 : public QWidget
{
    Q_OBJECT

public:
    explicit play2(QWidget *parent = nullptr);
    QGraphicsScene *scenes;
    ~play2();
    personaje *persona;
    personaje *personita;
    QTimer *interaccion;

    //void keyPressEvent(QKeyEvent * event);
    //void keyReleaseEvent(QKeyEvent * event);
    void setHeight(int w);
    int cont=0;
    int vt;
    int p1=0, p2=0;
    int cambio=0;
    int flag=0;
    bool player=false;
    int huevos=10;
    QGraphicsTextItem *tex;
    disparos *baline;
    disparos *balin1;
    //parte de las vidas
    vida *vida1;
    vida *vida2;
    bool playe=false;

    QTimer *Jtimen=new QTimer();
    QTimer *TGamen = new QTimer();
    QTimer *TGame2n = new QTimer();

    void inicia(int juego);

private:
    Ui::play2 *ui;
};

#endif // PLAY2_H
