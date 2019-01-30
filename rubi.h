#ifndef RUBI_H
#define RUBI_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include <QMediaPlayer>
#include "personaje.h"
#include "vida.h"

class rubi : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit rubi();
    QTimer *tel = new QTimer();
    QTimer *vil = new QTimer();
    QTimer *fil = new QTimer();

signals:

public slots:
    void mot();
};

#endif // RUBI_H
