#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    boardImage.load(":/Icons/Boards/ChessBoard.jpg");

    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *){

    QPainter painter(this);
    painter.drawPixmap(0,0,600,600, this->boardImage);
}
