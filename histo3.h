#ifndef HISTO3_H
#define HISTO3_H

#include <QMainWindow>
#include "menu1.h"
#include "histo2.h"
#include <QWidget>
#include <iostream>
#include "stdlib.h"
#include <QString>

namespace Ui {
class histo3;
}

class histo3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit histo3(QWidget *parent = nullptr);
    ~histo3();

private slots:
    void on_seguir_clicked();

private:
    Ui::histo3 *ui;
};

#endif // HISTO3_H
