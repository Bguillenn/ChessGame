#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

namespace Ui {
    class Bishop;
}

class Bishop : public Piece
{
    Q_OBJECT
public:
    explicit Bishop(QWidget *parent = nullptr, QString teamValue);
};

#endif // BISHOP_H
