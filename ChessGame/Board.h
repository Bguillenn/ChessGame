#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    void paintEvent(QPaintEvent *);

private:
    Ui::Board *ui;
    QPixmap BoardIcon;
};

#endif // BOARD_H
