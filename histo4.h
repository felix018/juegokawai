#ifndef HISTO4_H
#define HISTO4_H

#include <QMainWindow>
#include "histo2.h"
#include <QWidget>
#include <iostream>
#include "stdlib.h"
#include <QString>


namespace Ui {
class histo4;
}

class histo4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit histo4(QWidget *parent = nullptr);
    ~histo4();

private slots:
    void on_siguelo_clicked();

private:
    Ui::histo4 *ui;
};

#endif // HISTO4_H
