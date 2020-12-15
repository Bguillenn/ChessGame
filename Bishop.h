#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    Q_OBJECT
public:
    explicit Bishop(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
    bool isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard);
};

#endif // BISHOP_H
