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
    explicit Knight(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
};

#endif // KNIGHT_H
