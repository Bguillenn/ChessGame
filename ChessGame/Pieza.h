#ifndef PIEZA_H
#define PIEZA_H

#include <QLabel>
#include <QPixmap>

namespace Ui {
    class Pieza;
}

class Pieza : public QLabel
{

Q_OBJECT

public:
    //Pieza();
    explicit Pieza(QWidget *parent = nullptr);
    virtual ~Pieza(){};
    virtual void MoverPieza() = 0;


protected:
    QPixmap Icon{};
};

#endif // PIEZA_H
