#ifndef HISTO2_H
#define HISTO2_H

#include <QMainWindow>
#include <QWidget>
#include <iostream>
#include "stdlib.h"
#include <QString>

namespace Ui {
class histo2;
}

class histo2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit histo2(QWidget *parent = nullptr);
    ~histo2();

private:
    Ui::histo2 *ui;
};

#endif // HISTO2_H
