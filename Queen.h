#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen: public Piece
{
    Q_OBJECT
public:
    explicit Queen(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
    bool isValidMove(QPoint& initial, QPoint& final, const BoardData& board);
};

#endif // QUEEN_H
