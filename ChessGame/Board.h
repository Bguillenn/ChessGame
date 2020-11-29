#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <iostream>

#include <QtWidgets>

#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QDropEvent>

#include "Pieza.h"
#include "Reina.h"

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
    void paintEvent(QPaintEvent *event) override; //sobreescribir este metodo

    //Posicion inicial
    void mousePressEvent(QMouseEvent *event) override;
    //gragEnterEvent y dragEnterEvent sirven como puente
    void dragEnterEvent(QDragEnterEvent *event) override;//Verificar si todo está bien
    void dragMoveEvent(QDragMoveEvent *event) override;//Verificar que no se haya perdido informacion
    //Posicion final
    void dropEvent(QDropEvent *event) override;

private:
    Ui::Board *ui;
    QPixmap BoardIcon;

    std::unique_ptr<Pieza> reina; //Utilizamos estos punteros porque vamos a utilizar polimorfismo
};

#endif // BOARD_H
