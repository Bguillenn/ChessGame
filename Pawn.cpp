#include "Pawn.h"

Pawn::Pawn(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Pawn.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Pawn::isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard)
{



    return true;
}

