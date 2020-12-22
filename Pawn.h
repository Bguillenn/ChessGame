#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

namespace Ui {
    class Pawn;
}

class Pawn : public Piece
{
    Q_OBJECT
public:
    explicit Pawn(QWidget *parent = nullptr, QString teamValue);
};

#endif // PAWN_H
