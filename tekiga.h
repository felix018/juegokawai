#ifndef TEKIGA_H
#define TEKIGA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <typeinfo>

class tekiga : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit tekiga(QGraphicsItem *parent = nullptr);
    QTimer * chronol = new QTimer();
    QTimer *tra = new QTimer();
    int cont=0;
private:
    int contador=0;

signals:

public slots:
     void andate();
     void shooting();

};

#endif // TEKIGA_H
