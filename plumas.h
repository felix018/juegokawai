#ifndef PLUMAS_H
#define PLUMAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include "personaje.h"

class plumas : public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
   plumas();
   QTimer *timer= new QTimer();

signals:

public slots:
   void moves();//proyectiles personajes
};

#endif // PLUMAS_H
