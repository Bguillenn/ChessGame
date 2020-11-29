#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

namespace Ui {
    class Rook;
}

class Rook : public Piece
{
    Q_OBJECT
public:
    explicit Bishop(QWidget *parent = nullptr, QString teamValue);
};

#endif // ROOK_H
