#ifndef PIECE_H
#define PIECE_H

#include <QLabel>

namespace Ui {
    class Piece;
}


class Piece : public QLabel
{
    Q_OBJECT
public:
    explicit Piece(QWidget *parent = nullptr);
    virtual ~Piece(){};
    static const QString BLACK_TEAM;
    static const QString WHITE_TEAM;

private:
    Ui::Piece *ui;
    QString team;
    bool life;
    QString imgPath;
};

#endif // PIECE_H
