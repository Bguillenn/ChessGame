#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

namespace Ui{
    class Knight;
}

class Knight: public Piece
{
    Q_OBJECT
public:
    explicit Knight(QWidget *parent = nullptr, QString teamValue);
    QVector<Point> getMoves(Point &currentPosition);
};

#endif // KNIGHT_H
