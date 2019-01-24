#ifndef ULTIMOD_H
#define ULTIMOD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include <QMediaPlayer>
#include "personaje.h"
#include "vida.h"

class ultimoD : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     ultimoD();
     QTimer *tear = new QTimer();
     bool tipo=false;

signals:

public slots:
     void movp();//proyectiles personajes
};

#endif // ULTIMOD_H
