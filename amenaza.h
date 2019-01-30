#ifndef AMENAZA_H
#define AMENAZA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <typeinfo>

class amenaza : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit amenaza(QObject *parent = nullptr);
    QTimer * tempura = new QTimer();
    QTimer *kusoda = new QTimer();
    int cont=0;

signals:

public slots:
    void partite();
    void zepar();
};

#endif // AMENAZA_H
