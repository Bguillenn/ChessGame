#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QVector>

#include <QtWidgets>

#include "Piece.h"
#include "Pawn.h"
#include <QtWidgets>

#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"



#include <memory> //para utlilizar punteros inteligentes

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr, const QVector<QVector<char>>& boardData = Board::INITIAL_BOARD_DATA);
    ~Board();

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Board *ui;
    QPixmap boardImage{};
    const static QVector<QVector<char>> INITIAL_BOARD_DATA;
    QVector<QVector<char>> BoardData;

    QVector<Piece*> black_pieces{};
    QVector<Piece*> white_pieces{};

    void loadPiecesOnBoard();
    Piece& createPiece(char value);

    //Drag and drop functions
    void mousePressEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // BOARD_H
