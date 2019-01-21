#ifndef ESPADA_H
#define ESPADA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <typeinfo>
#include "personaje.h"
#include "play2.h"

class espada : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   espada();
   QTimer *toma=new QTimer();
   int yokai; //#malos
   int angel;

signals:

public slots:
   void mueve();
};

#endif // ESPADA_H
