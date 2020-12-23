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

    gameController = GameController::getInstance();

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

    //Si es el fin del juego entonces no permite movimientos
    if(gameController->isEnd()) return;

    auto child = childAt(event->pos());
    //Validamos si clickeamos en cualquier sitio
    if(child == nullptr) return;
    //Validamos que sea el turno del personaje con el controlador de juego
    Piece *piece = (Piece*) child;
    if(piece->getTeam() != gameController->getTurn())
    {
        //No es turno mostrar mensaje
        return;
    }


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
        //PARA IR MOSTRANDO SI EL MOVIMIENTO ES VALIDO O NO
        /*QByteArray data = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&data, QIODevice::ReadOnly);

        QPoint pieceCoord;
        dataStream >> pieceCoord;

        int xini = pieceCoord.x() / 75;
        int yini = pieceCoord.y() / 75;
        int xfin = event->pos().x() / 75;
        int yfin = event->pos().y() / 75;

        QPoint initial(xini, yini);
        QPoint final(xfin,yfin);

        Piece *piece = (Piece *)childAt(pieceCoord);

        qDebug() << "Valido movimiento? " << piece->isValidMove(initial, final, boardData); */


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


                bool jaque = false;
                int type = GameController::NORMAL_MOVEMENT;
                //Si esque el casillero no esta vacio es que hay una pieza enemiga
                if(boardData[xfin][yfin] != VACIO){
                    type = GameController::KILL_MOVEMENT;
                    //JAQUE MATE
                    if( (boardData[xfin][yfin] == REYN) || (boardData[xfin][yfin] == REYB) ){
                        type = GameController::JAQUE_MOVEMENT;
                        //JAQUE MATE REALIZADO
                        qDebug() << "JAQUE MATE!!";
                        jaque = true;
                    }
                    //END JAQUE MATE


                    Piece *pieceE = (Piece *)childAt(event->pos());

                    gameController->addToCementery(boardData[xfin][yfin] , pieceE->getTeam());
                    //pieceE->hide();
                    delete pieceE;
                }

                //PROMOTION
                if( ((boardData[xini][yini] == PEONB) || (boardData[xini][yini] == PEONN)) && !jaque ){
                    int extreme = (boardData[xini][yini] == PEONB) ? 0:7;
                    if(yfin == extreme)
                    {
                        type = GameController::PROMOTION_MOVEMENT;
                        qDebug() << "PROMOTION mostrando opciones!!";
                       //HACER PROMOTION
                        QString team = piece->getTeam();
                        delete piece;
                        piece = mostrarMenuPromotion(piece->getTeam());
                    }
                }
                //END PROMOTION

                updateBoardData(initial, final);

                gameController->makeMove(initial, final, piece->getTeam(), type);
                piece->move(destinyPoint);
                piece->show();



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

Piece* Board::mostrarMenuPromotion(QString team)
{
    QMessageBox msgBox(QMessageBox::Information, "PROMOTION", "Elige una de las siguientes opciones para promover a tu peon");
    QPushButton* caballoBtn = msgBox.addButton(tr("Caballo"), QMessageBox::ActionRole);
    QPushButton* alfilBtn = msgBox.addButton(tr("Alfil"), QMessageBox::ActionRole);
    QPushButton* reynaBtn = msgBox.addButton(tr("Reyna"), QMessageBox::ActionRole);
    QPushButton* torreBtn = msgBox.addButton(tr("Torre"), QMessageBox::ActionRole);

    msgBox.exec();

    Piece* newPiece;

    if(msgBox.clickedButton() == caballoBtn)
        newPiece = new Knight(this, team);
    if(msgBox.clickedButton() == alfilBtn)
        newPiece = new Bishop(this, team);
    if(msgBox.clickedButton() == reynaBtn)
        newPiece = new Queen(this, team);
    if(msgBox.clickedButton() == torreBtn)
        newPiece = new Rook(this, team);



    newPiece->setCursor(Qt::PointingHandCursor);
    return newPiece;
}

void Board::resetBoard(){
    Piece* aux;

    for(int i=0; i < 8; i++){
        for(int j=0; j < 8 ; j++){
            aux = (Piece *) childAt(QPoint(i*75+6,j*75+6));
            qDebug() << "Borrando pieza "<<aux;
            if(aux != nullptr) delete aux;
        }
    }

    boardData = BoardData::getInitialBoardData();
    loadPiecesOnBoard();
}

