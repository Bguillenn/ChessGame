#ifndef KING_H
#define KING_H

#include "Piece.h"

class King:public Piece
{
    Q_OBJECT
public:
    explicit King(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
    bool isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard);
};

#endif // KING_H
