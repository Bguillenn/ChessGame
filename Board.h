#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QVector>

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




};

#endif // BOARD_H
