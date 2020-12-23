#include "Pawn.h"
#include <QDebug>

Pawn::Pawn(QWidget *parent, QString teamValue):
    Piece(parent, teamValue)
{
    this->imgPath = ":/Icons/Pieces/"+this->team+"/Pawn.png";
    this->icon.load(this->imgPath);
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Pawn::isValidMove(QPoint& initial, QPoint& final, const BoardData& board)
{

    int difX = final.x() - initial.x();
    int difY = final.y() - initial.y();

    bool isPosible = false;

    qDebug() << " >> Validando ";
    qDebug() << "difx = "<<difX;
    qDebug() << "dify = "<<difY;

    //Validamos que se este moviendo verticalmente
    if(difX == 0)
    {
        if(abs(difY) == 1) //Si solo se mueve un casillero
        {
            //Validamos el movimiento en caso sea pieza blanca o pieza negra

            int difC = ( board.isWhitePiece(initial.x(), initial.y()) ) ? -1:1;


            if(difY == difC)
            {

                //En caso este vacio movemos la pieza, el movimiento esta permitido
                if( board.isBlank(final.x(), final.y()) )
                    isPosible = true;
            }
        }else if(abs(difY) == 2) //Movimiento largo
        {
            //Validamos que sea el primer movimiento del tablero de ajedres
            if(initial.y() == ( board.isWhitePiece(initial.x(), initial.y() ) ? 6:1 ))
            {

                if(board.isFreeWay(initial, final) && board.isBlank(final.x(), final.y()))
                    isPosible = true;
            }
        }
    } else if((abs(difX) == 1) //Si esta intentando matar al enemigo
              && (difY == (board.isWhitePiece(initial.x(), initial.y()) ? -1:1))
              && !board.isBlank(final.x(), final.y())
              && (board[initial.y()][initial.x()] != board[final.y()][final.x()]))
    {
        isPosible = true;
    }

    return isPosible;
}

