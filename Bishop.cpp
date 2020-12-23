#include "Bishop.h"

Bishop::Bishop(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Bishop.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Bishop::isValidMove(QPoint& initial, QPoint& final, const BoardData& board)
{
    int difX = final.x() - initial.x();
    int difY = final.y() - initial.y();

    if(abs(difX) == abs(difY))
    {
        if(board.isFreeWay(initial, final))
        {
            if(board.isBlank(final.x(), final.y())){
                return true;
            }else{
                if(board.isWhitePiece(initial.x(), initial.y()) != board.isWhitePiece(final.x(), final.y()) )
                    return true;
            }
        }
    }

    return false;
}

