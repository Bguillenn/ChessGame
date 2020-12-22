#include "Rook.h"

Rook::Rook(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Rook.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Rook::isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard)
{



    return true;
}
