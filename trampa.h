#ifndef TRAMPA_H
#define TRAMPA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>

class trampa : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit trampa(QObject *parent = nullptr);
    QTimer * tempo = new QTimer();
    int cont=0;
    int HEI=400;
private:
    int contador=0;

signals:

public slots:
    void move();
    //void fuego();
};

#endif // TRAMPA_H
