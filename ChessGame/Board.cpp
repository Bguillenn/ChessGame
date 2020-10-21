#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    BoardIcon.load("/home/denis/Workspace/Chess/Icons/tablero-marron-notacion.png");
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(), width(), BoardIcon);
}
