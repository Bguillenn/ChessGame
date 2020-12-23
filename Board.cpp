#include "Board.h"
#include "ui_Board.h"
#include <QDebug>

#define VACIO -1
#define PEONB 11
#define PEONN 10
#define ALFILB 7
#define ALFILN 6
#define CABALLOB 9
#define CABALLON 8
#define REYB 1
#define REYN 0
#define REINAB 3
#define REINAN 2
#define TORREB 5
#define TORREN 4


Board::Board(QWidget *parent, BoardData boardD) :
    QWidget(parent),
    ui(new Ui::Board),
    boardData{boardD}
{
    ui->setupUi(this);
    boardImage.load(":/Icons/Boards/ChessBoard.jpg");

    loadPiecesOnBoard();
    //Aceptamos drops
    setAcceptDrops(true);
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
    int dat;
    Piece *aux;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            dat = boardData[i][j];
            //Validamos que no sea un casillero vacio para no pintarlo
            if(dat != VACIO){
                //Validamos de que equipo es la ficha para añadirlo al vector de su team
                aux = &createPiece(dat);
                if(aux->getTeam() == Piece::BLACK_TEAM)
                    this->black_pieces.push_back(aux);
                else
                    this->white_pieces.push_back(aux);

                //aux->move(j*75+5, i*75+5);
                aux->move(i*75+5, j*75+5);
                aux->setCursor(Qt::PointingHandCursor);
                aux->show();

            }
        }
}

Piece& Board::createPiece(int value)
{
    Piece *aux;
    switch(value){
    case TORREN:
        aux = new Rook(this, Piece::BLACK_TEAM);
        break;
    case CABALLON:
        aux = new Knight(this, Piece::BLACK_TEAM);
        break;
    case ALFILN:
        aux = new Bishop(this, Piece::BLACK_TEAM);
        break;
    case REINAN:
        aux = new Queen(this, Piece::BLACK_TEAM);
        break;
    case REYN:
        aux = new King(this, Piece::BLACK_TEAM);
        break;
    case PEONN:
        aux = new Pawn(this, Piece::BLACK_TEAM);
        break;
    case TORREB:
        aux = new Rook(this, Piece::WHITE_TEAM);
        break;
    case CABALLOB:
        aux = new Knight(this, Piece::WHITE_TEAM);
        break;
    case ALFILB:
        aux = new Bishop(this, Piece::WHITE_TEAM);
        break;
    case REINAB:
        aux = new Queen(this, Piece::WHITE_TEAM);
        break;
    case REYB:
        aux = new King(this, Piece::WHITE_TEAM);
        break;
    case PEONB:
        aux = new Pawn(this, Piece::WHITE_TEAM);
        break;
    }

    return *aux;
}


//Drag and drop
void Board::mousePressEvent(QMouseEvent *event)
{

    auto child = childAt(event->pos());
    //Validamos si clickeamos en cualquier sitio
    if(child == nullptr) return;
    Piece *piece = (Piece*) child;

    QByteArray data;
    QDataStream dataStream( &data, QIODevice::WriteOnly);

    dataStream << QPoint(piece->pos());

    QMimeData *mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);

    QDrag *drag = new QDrag( this );


    QPixmap pixmap = piece->pixmap(Qt::ReturnByValue);

    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - piece->pos());
    drag->exec( Qt::CopyAction | Qt::MoveAction, Qt::CopyAction );
}

void Board::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata")){
        if(event->source() == this){
            event->setDropAction( Qt::MoveAction );
            event->accept();
        }else
            event->acceptProposedAction();

    }else{
        event->ignore();
    }
}

void Board::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata")){
        if(event->source() == this){
            event->setDropAction( Qt::MoveAction );
            event->accept();

        }else
            event->acceptProposedAction();

    }else{
        event->ignore();
    }
}

void Board::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata")){
        QByteArray data = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&data, QIODevice::ReadOnly);

        QPoint pieceCoord;
        dataStream >> pieceCoord;

        if(event->source() == this){


            Piece *piece = (Piece *)childAt(pieceCoord);

            int xPos = (event->pos().x() / 75) * 75 + 5;
            int yPos = (event->pos().y() / 75) * 75 + 5;

            int xini = pieceCoord.x() / 75;
            int yini = pieceCoord.y() / 75;
            int xfin = event->pos().x() / 75;
            int yfin = event->pos().y() / 75;

            QPoint initial(xini, yini);
            QPoint final(xfin,yfin);

            if(piece->isValidMove(initial, final , boardData)){
                event->setDropAction(Qt::MoveAction);
                event->accept();
                QPoint destinyPoint(xPos, yPos);

                piece->move(destinyPoint);
                piece->show();


                //TODO: Validar kills tambien kill del rey
                updateBoardData(initial, final);

            }else{
                event->acceptProposedAction();
            }
        }else{
            event->acceptProposedAction();
        }
    }else{
        event->ignore();
    }
}

void Board::updateBoardData(QPoint initial, QPoint final)
{
    boardData.set(final.x(), final.y(), boardData[initial.x()][initial.y()]);
    boardData.set(initial.x(), initial.y(), VACIO);

    qDebug() << "Mostrando boardData ";
    for(int i=0; i < 8; i++){
        QString row {};
        for(int j = 0; j < 8; j++){
            row += ", " + QString::number(boardData[i][j]);
        }
        qDebug() << row;
    }
}

