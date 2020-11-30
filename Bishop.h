#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
    Q_OBJECT
public:
    explicit Bishop(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
    QVector<Point> & getMoves(const Point &currentPosition) override;
};

#endif // BISHOP_H
