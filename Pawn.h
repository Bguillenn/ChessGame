#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
    Q_OBJECT
public:
    explicit Pawn(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
    QVector<Point> & getMoves(const Point &currentPosition) override;
};

#endif // PAWN_H
