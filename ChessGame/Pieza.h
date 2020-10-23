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
    explicit Pieza(QWidget *parent = nullptr);
    Pieza();
    //mover


protected:
    QPixmap Icon{};
};

#endif // PIEZA_H
