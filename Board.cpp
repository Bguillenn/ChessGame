#include "Board.h"
#include "ui_Board.h"
#include "Knight.h"
#include "Queen.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    boardImage.load(":/Icons/Boards/ChessBoard.jpg");

    horse = std::make_unique<Knight>(this, Piece::BLACK_TEAM);
    horse->move(5,5);
    horse->show();

    queen = std::make_unique<Queen>(this);
    queen->move(80,5);
    queen->show();

    king = std::make_unique<King>(this);
    king->move(155,5);
    king->show();
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,600,600, this->boardImage);
}
