#include "Knight.h"
#include <QDebug>

Knight::Knight(QWidget* parent, QString teamValue):
    Piece(parent, teamValue)
{
    //El atributo "life" por defecto esta en true, por lo que aqui no es necesario inicializarlo
    //Para determinar de que color pintara la ficha
    this->imgPath = ":/Icons/Pieces/"+ this->team +"/Knight.png";
    //Cargamos el icono en el QPixmap
    this->icon.load(this->imgPath);
    //Ahora cargamos el pixmap al label
    this->setPixmap(this->icon.scaled(QSize(65,65), Qt::KeepAspectRatio));
}

bool Knight::isValidMove(QPoint& initial, QPoint& final, const BoardData& board)
{
    int difX = final.x() - initial.x();
    int difY = final.y() - initial.y();

    if(((abs(difX) == 2) && (abs(difY) == 1)) || ((abs(difX) == 1) && (abs(difY) == 2)))
    {
        qDebug() << "Cumplio con el movimiento de caballo";
        qDebug() << "Initial: " << board[initial.y()][initial.x()];
        qDebug() << "Final: " << board[final.y()][final.x()];
      //  if(board[initial.x()][initial.y()] != board[final.x()][final.y()])
       // {
        //   return true;
       // }

        if(board.isBlank(final.x(), final.y())){
            return true;
        }else{
            if(board.isWhitePiece(initial.x(), initial.y()) != board.isWhitePiece(final.x(), final.y()))
                return true;
        }
    }
    return false;
}
