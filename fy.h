#ifndef FY_H
#define FY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <typeinfo>
#include "caida.h"

class FY : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit FY(QGraphicsItem *parent = nullptr);
    QTimer * firolai = new QTimer();
    QTimer *nevermind = new QTimer();
    int cont=0;

signals:

public slots:
    void satesate();
    void samaland();
};

#endif // FY_H
