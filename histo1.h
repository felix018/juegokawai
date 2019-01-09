#ifndef HISTO1_H
#define HISTO1_H

#include <QMainWindow>

namespace Ui {
class histo1;
}

class histo1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit histo1(QWidget *parent = nullptr);
    ~histo1();

private:
    Ui::histo1 *ui;
};

#endif // HISTO1_H
