#include "King.h"

King::King(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/King.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool King::isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard)
{



    return true;
}
