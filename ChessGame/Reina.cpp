#include "Reina.h"

Reina::Reina(QWidget *parent) : Pieza(parent)
{
    Icon.load(":/resources/Icons/reina-negra.png");
    this->setPixmap(Icon.scaled(QSize(50,50), Qt::KeepAspectRatio));
}

void Reina::MoverPieza()
{

}
