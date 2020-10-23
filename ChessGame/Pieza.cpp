#include "Pieza.h"

Pieza::Pieza(QWidget *parent) : QLabel(parent)
{
    Icon.load(":/resources/Icons/caballo-negro.png");
    this->setPixmap(Icon);
}
