#include "King.h"

King::King(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/King.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}


QVector<Point>& King::getMoves(const Point &currentPosition){

}
