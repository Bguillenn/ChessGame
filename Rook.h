#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
    Q_OBJECT
public:
    explicit Rook(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
};

#endif // ROOK_H
