#ifndef KAITA_H
#define KAITA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include <QMediaPlayer>
#include "personaje.h"
#include "vida.h"

class kaita : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit kaita();
    QTimer *kief = new QTimer();
    QTimer *hik = new QTimer();
    QGraphicsTextItem *winner = new QGraphicsTextItem();

signals:

public slots:
    void vamp();
};

#endif // KAITA_H
