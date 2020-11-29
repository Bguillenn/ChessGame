#include "Piece.h"

const QString Piece::BLACK_TEAM = "black_team";
const QString Piece::WHITE_TEAM = "white_team";

Piece::Piece(QWidget *parent, QString teamValue) : QLabel(parent), team{teamValue}
{

}
