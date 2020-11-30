#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QVector>

#include <QtWidgets>

#include "Piece.h"
#include "King.h"

#include <memory> //para utlilizar punteros inteligentes

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Board *ui;
    QPixmap boardImage;

    std::unique_ptr<Piece> horse;
    std::unique_ptr<Piece> queen;
    std::unique_ptr<Piece> king;

};

#endif // BOARD_H
