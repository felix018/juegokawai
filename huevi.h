#ifndef HUEVI_H
#define HUEVI_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>
#include "QTimer"

class huevi : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit huevi(QObject *parent = nullptr);
    QTimer *vel = new QTimer();
    int mover=0;
    QTimer *tras = new QTimer();
    int cont=0;

signals:

public slots:
    void anda();
    void muera();
};

#endif // HUEVI_H
