#include "King.h"

King::King(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/King.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool King::isValidMove(QPoint& initial, QPoint& final, const BoardData& board)
{
    int difX = final.x() - initial.x();
    int difY = final.y() - initial.y();

    if(((abs(difX) == 1) && (difY == 0) ) || ((abs(difY) == 1) && (difX == 0)) || ( (abs(difX) == 1) && (abs(difY) == 1) ))
    {
        if(board.isBlank(final.x(), final.y()))
            return true;
        else
            if(board.isWhitePiece(initial.x(), initial.y()) != board.isWhitePiece(final.x(), final.y()))
                return true;
    }


    return false;
}
