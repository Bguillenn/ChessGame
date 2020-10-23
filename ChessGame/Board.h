#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>

#include "Pieza.h"

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
    void paintEvent(QPaintEvent * event) override; //sobreescribir este metodo

private:
    Ui::Board *ui;
    QPixmap BoardIcon;

    std::unique_ptr<Pieza> pieza; //Utilizamos estos punteros porque vamos a utilizar polimorfismo
};

#endif // BOARD_H
