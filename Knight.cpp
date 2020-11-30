#include "Knight.h"


Knight::Knight(QWidget* parent, QString teamValue):
    Piece(parent, teamValue)
{
    //El atributo "life" por defecto esta en true, por lo que aqui no es necesario inicializarlo
    //Para determinar de que color pintara la ficha
    this->imgPath = ":/Icons/Pieces/"+ this->team +"/Knight.png";
    //Cargamos el icono en el QPixmap
    this->icon.load(this->imgPath);
    //Ahora cargamos el pixmap al label
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

QVector<Point>& Knight::getMoves(const Point &currentPosition) {
}
