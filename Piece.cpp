#include "Piece.h"

const QString Piece::BLACK_TEAM = "black_pieces";
const QString Piece::WHITE_TEAM = "white_pieces";

Piece::Piece(QWidget *parent, QString teamValue) : QLabel(parent), team{teamValue}
{

}
