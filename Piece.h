#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include "Point.h"

namespace Ui {
    class Piece;
}


class Piece : public QLabel
{
    Q_OBJECT
public:
    explicit Piece(QWidget *parent = nullptr, QString teamValue);
    virtual ~Piece(){};
    static const QString BLACK_TEAM;
    static const QString WHITE_TEAM;
    virtual QVector<Point> getMoves(Point& currentPosition) = 0;
private:
    Ui::Piece *ui;
    QString team{};
    bool life{true};
    QString imgPath{};
    QPixmap icon{};
};

#endif // PIECE_H
