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
    explicit Piece(QWidget *parent = nullptr, QString teamValue = Piece::WHITE_TEAM);
    virtual ~Piece(){};
    static const QString BLACK_TEAM;
    static const QString WHITE_TEAM;
    QString getTeam() const;
    virtual bool isValidMove(QPoint& initial, QPoint& final, QVector<QVector<char>>& currentBoard) = 0;
protected:
    Ui::Piece *ui;
    QString team{};
    bool life{true};
    QString imgPath{};
    QPixmap icon{};
};

#endif // PIECE_H
