#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QVector>

#include <QtWidgets>

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

#include "BoardData.h"
#include "GameController.h"


#include <memory> //para utlilizar punteros inteligentes

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr,const BoardData boardD = BoardData::getInitialBoardData());
    ~Board();

    void paintEvent(QPaintEvent *event) override;
private:
    Ui::Board *ui;
    QPixmap boardImage{};
    BoardData boardData;

    QVector<Piece*> black_pieces{};
    QVector<Piece*> white_pieces{};

    GameController* gameController;

    //METODOS
    void loadPiecesOnBoard();
    Piece& createPiece(int value);
    void updateBoardData(QPoint initial, QPoint final);
    Piece* mostrarMenuPromotion(QString team);



    //Drag and drop functions
    void mousePressEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // BOARD_H
