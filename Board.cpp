#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    boardImage.load(":/Icons/Boards/ChessBoard.jpg");

    piece = std::make_unique<Piece>(this);
    piece->setText("Hola");
    piece->move(0,0);
    piece->show();
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,600,600, this->boardImage);
}
