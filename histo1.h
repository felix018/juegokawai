#ifndef HISTO1_H
#define HISTO1_H

#include <QMainWindow>
#include "menu1.h"
#include "histo2.h"
#include <QWidget>
#include <iostream>
#include "stdlib.h"
#include <QString>


namespace Ui {
class histo1;
}

class histo1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit histo1(QWidget *parent = nullptr);
    ~histo1();

private slots:
    void on_siguiente_clicked();

private:
    Ui::histo1 *ui;
};

#endif // HISTO1_H
