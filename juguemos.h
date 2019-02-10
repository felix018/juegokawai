#ifndef JUGUEMOS_H
#define JUGUEMOS_H

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
#include "trampa.h"
#include "caida.h"
#include "joyas.h"
#include "jefe.h"
#include "vivamos.h"

#define WIDTH 1000
#define HEIGHT 400

namespace Ui {
class juguemos;
}

class juguemos : public QWidget
{
    Q_OBJECT

public:
    explicit juguemos(QWidget *parent = nullptr);
    ~juguemos();
    QGraphicsScene *scenas;
    personaje *link;
    personaje *zelda;
    QTimer *interacciones;
    jefe *part;
    //void keyPressEvent(QKeyEvent * evento);
    //void keyReleaseEvent(QKeyEvent * evento);
    void setHeight(int o);
    int cont=0;
    int outside=0;
    int vtoi;
    int p1e=0, p2e=0;
    int cambio=0;
    int flago=0;
    bool player=false;
    int amano=0;
    int yora=0;
    int huevose=10;
    QGraphicsTextItem *texto;
    //disparos *espada;
    //disparos *espada1;
    //parte de las vidas
    vida *vidas1e;
    vivamos *vivire1;
    vivamos *vivire2;
    vida *vidas2e;
    bool playe=false;

    QTimer *interare;



    QTimer *Jasmin=new QTimer();
    QTimer *alisae = new QTimer();
    QTimer *raptalias = new QTimer();

    void socrates(int u);

private:
    Ui::juguemos *ui;
};

#endif // JUGUEMOS_H
