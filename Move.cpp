#include "Move.h"
#include "Piece.h"

Move::Move(QPoint ori, QPoint des, QString team, int type)
{

    this->origin = asignLetterAndNumber(ori);
    this->destiny = asignLetterAndNumber(des);

    this->team = ( team == Piece::WHITE_TEAM )? "BLANCAS":"NEGRAS";

    this->type = type;

}

QString Move::asignLetterAndNumber(QPoint n)
{
    QString position = "";
    switch (n.y()) {
        case 0: position+="A";
        break;
        case 1: position+="B";
        break;
        case 2: position+="C";
        break;
        case 3: position+="D";
        break;
        case 4: position+="E";
        break;
        case 5: position+="F";
        break;
        case 6: position+="G";
        break;
        case 7: position+="H";
        break;
    }

    switch (n.x()) {
        case 0: position += QString::number(1);
        break;
         case 1: position += QString::number(2);
        break;
        case 2: position += QString::number(3);
        break;
        case 3: position += QString::number(4);
        break;
        case 4: position += QString::number(5);
        break;
        case 5: position += QString::number(6);
        break;
        case 6: position += QString::number(7);
        break;
        case 7: position += QString::number(8);
        break;
    }

    return position;
}

QString Move::getOrigin() const
{
    return origin;
}

QString Move::getDestiny() const
{
    return destiny;
}

QString Move::getTeam() const
{
    return team;
}

int Move::getType() const
{
    return type;
}
