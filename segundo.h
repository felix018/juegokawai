#ifndef SEGUNDO_H
#define SEGUNDO_H

#include <QWidget>
#include <iostream>
#include "stdlib.h"
#include <QString>

namespace Ui {
class segundo;
}

class segundo : public QWidget
{
    Q_OBJECT

public:
    explicit segundo(QWidget *parent = nullptr);
    ~segundo();
    int u=0;

private slots:
    void on_holi_clicked();

private:
    Ui::segundo *ui;
};

#endif // SEGUNDO_H
