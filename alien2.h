#ifndef ALIEN2_H
#define ALIEN2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>

class alien2 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit alien2(QObject *parent = nullptr);
    QTimer * tempoi = new QTimer();
    QTimer *pumi = new QTimer();
    int cont=0;

signals:

public slots:
    void movero();
    void shootu();
};

#endif // ALIEN2_H
