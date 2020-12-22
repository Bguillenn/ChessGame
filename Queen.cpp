#include "Queen.h"

Queen::Queen(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Queen.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Queen::isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard)
{



    return true;
}

