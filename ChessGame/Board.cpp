#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    BoardIcon.load(":/resources/Icons/tablero-verde.png"); //Cargar el icono del tablero


    pieza = std::make_unique<Pieza>(this);
    pieza->move(0,0);
    //pieza->setText("Peon");

    pieza->show();

}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *) //Para visualizar
{
    QPainter painter(this); //El que sabe pintar
    painter.drawPixmap(0,0,360,360, BoardIcon); //Entregar a painter donde va a dibujar el tablero
}
