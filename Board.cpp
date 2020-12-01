#include "Board.h"
#include "ui_Board.h"

const QVector<QVector<char>> Board::INITIAL_BOARD_DATA =
{
    {'R','H','B','Q','K','B','H','R'},
    {'P','P','P','P','P','P','P','P'},
    {'x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x'},
    {'p','p','p','p','p','p','p','p'},
    {'r','h','b','k','q','b','h','r'}
};

Board::Board(QWidget *parent, const QVector<QVector<char>>& boardData) :
    QWidget(parent),
    ui(new Ui::Board),
    BoardData{boardData}
{
    ui->setupUi(this);
    boardImage.load(":/Icons/Boards/ChessBoard.jpg");

    loadPiecesOnBoard();
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.drawPixmap(0,0,600,600, this->boardImage);
}

void Board::loadPiecesOnBoard()
{
    char dat;
    Piece *aux;
    for(int i = 0; i < BoardData.size(); i++)
        for(int j = 0; j < BoardData[i].size(); j++){
            dat = BoardData[i][j];
            //Validamos que no sea un casillero vacio para no pintarlo
            if(dat != 'x'){
                //Validamos de que equipo es la ficha para añadirlo al vector de su team
                aux = &createPiece(dat);
                if(aux->getTeam() == Piece::BLACK_TEAM)
                    this->black_pieces.push_back(aux);
                else
                    this->white_pieces.push_back(aux);

                aux->move(j*75+5, i*75+5);
                aux->show();

            }
        }

}

Piece& Board::createPiece(char value)
{
    Piece *aux;
    switch(value){
    case 'R':
        aux = new Rook(this, Piece::BLACK_TEAM);
        break;
    case 'H':
        aux = new Knight(this, Piece::BLACK_TEAM);
        break;
    case 'B':
        aux = new Bishop(this, Piece::BLACK_TEAM);
        break;
    case 'Q':
        aux = new Queen(this, Piece::BLACK_TEAM);
        break;
    case 'K':
        aux = new King(this, Piece::BLACK_TEAM);
        break;
    case 'P':
        aux = new Pawn(this, Piece::BLACK_TEAM);
        break;
    case 'r':
        aux = new Rook(this, Piece::WHITE_TEAM);
        break;
    case 'h':
        aux = new Knight(this, Piece::WHITE_TEAM);
        break;
    case 'b':
        aux = new Bishop(this, Piece::WHITE_TEAM);
        break;
    case 'q':
        aux = new Queen(this, Piece::WHITE_TEAM);
        break;
    case 'k':
        aux = new King(this, Piece::WHITE_TEAM);
        break;
    case 'p':
        aux = new Pawn(this, Piece::WHITE_TEAM);
        break;
    }

    return *aux;
}


