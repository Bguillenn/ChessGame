#include "Reina.h"

Reina::Reina(QWidget *parent) : Pieza(parent)
{
    Icon.load(":/resources/Icons/reina-blanca.png");
    this->setPixmap(Icon.scaled(QSize(45,45), Qt::KeepAspectRatio));
}

void Reina::MoverPieza()
{

}
