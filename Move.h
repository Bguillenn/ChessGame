#ifndef MOVE_H
#define MOVE_H

#include <QString>
#include <QPoint>

class Move
{
private:
    QString origin{};
    QString destiny{};
    QString team{};
    int type{};

    QString asignLetterAndNumber(QPoint n);
public:
    Move(QPoint ori, QPoint des, QString team, int type);
    QString getOrigin() const;
    QString getDestiny() const;
    QString getTeam() const;
    int getType() const;
};

#endif // MOVE_H
