#ifndef SANGRE_H
#define SANGRE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <typeinfo>
#include <QDebug>
#include <QMediaPlayer>
#include "personaje.h"
#include "vida.h"

class sangre : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit sangre();
    QTimer *tora = new QTimer();

signals:

public slots:
    void teteike();
};

#endif // SANGRE_H
