#include "Bishop.h"

Bishop::Bishop(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Bishop.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

QVector<Point>& Bishop::getMoves(const Point& currentPosition)
{

}
