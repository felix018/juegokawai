#ifndef PRUM_H
#define PRUM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include "personaje.h"

class prum : public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    prum();
    QTimer *chronos= new QTimer();

signals:

public slots:
     void mov();
};

#endif // PRUM_H
