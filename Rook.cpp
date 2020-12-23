#include "Rook.h"
#include <QDebug>

Rook::Rook(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Rook.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Rook::isValidMove(QPoint& initial, QPoint& final, const BoardData& board)
{
    int difX = final.x() - initial.x();
    int difY = final.y() - initial.y();

    if( (difX == 0) || (difY == 0) )
    {
        qDebug() << "Tiene camino libre?" << board.isFreeWay(initial, final);
        if(board.isFreeWay(initial, final)){
            if(board.isBlank(final.x(), final.y()))
                return true;
            else{
                if(board.isWhitePiece(initial.x(), initial.y()) != board.isWhitePiece(final.x(), final.y()))
                    return true;
            }
        }
    }

    return false;
}
