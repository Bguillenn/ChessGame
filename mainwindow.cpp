#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //obtener instancia de game controller
    gameController = GameController::getInstance();


    initLabels();
}

void MainWindow::initLabels(){
    //Set logo
    QPixmap pixmapLogo(":/Icons/otro/logo.png");
    ui->GameTitleLbl->setPixmap(pixmapLogo.scaled(QSize(250, 47)));
    //ui->GameTitleLbl->setMask(pixmapLogo.mask());

    //Set images to labels
    QPixmap pixmapYBar(":/Icons/Boards/y-axis.png");
    ui->imgYbar->setPixmap(pixmapYBar.scaled(QSize(47,600), Qt::KeepAspectRatio));
    ui->imgYbar->setMask(pixmapYBar.mask());

    ui->imgYbar->show();

    QPixmap pixmapXBar(":/Icons/Boards/x-axis.png");
    ui->imgXbar->setPixmap(pixmapXBar.scaled(QSize(600,47), Qt::KeepAspectRatio));
    ui->imgXbar->setMask(pixmapXBar.mask());

    ui->imgXbar->show();


    //Turno y movimientos

    updateGameData();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTurnoLabel()
{
    ui->lblTurno->setText( (gameController->getTurn() == Piece::WHITE_TEAM) ? "BLANCAS" : "NEGRAS" );
}

void MainWindow::updateJugadasLabel()
{
    ui->lblJugadas->setText(QString::number(gameController->getMoves()));
}

void MainWindow::updateNegrasCapturadas()
{
    ui->negrasCap->setFlow(QListWidget::LeftToRight);
    ui->negrasCap->clear();

    QVector<int> pieces = gameController->getBlacksCaptured();

    QIcon* item;
    QPixmap *pixmap;

    for(int i = 0; i < pieces.length(); i++ ){
        item = new QIcon();
        pixmap = getPiecePixMap(pieces[i]);

        item->addPixmap(pixmap->scaled(QSize(50,50), Qt::KeepAspectRatio));

        ui->negrasCap->addItem(new QListWidgetItem(*item, ""));


    }

}

void MainWindow::updateBlancasCapturadas()
{


    ui->blancasCap->setFlow(QListWidget::LeftToRight);
    ui->blancasCap->clear();

    QVector<int> pieces = gameController->getWhitesCaptured();

    QIcon* item;
    QPixmap *pixmap;

    for(int i = 0; i < pieces.length(); i++ ){
        item = new QIcon();
        pixmap = getPiecePixMap(pieces[i]);

        item->addPixmap(pixmap->scaled(QSize(50,50), Qt::KeepAspectRatio));

        ui->blancasCap->addItem(new QListWidgetItem(*item, ""));

    }

}

QPixmap* MainWindow::getPiecePixMap(int type)
{
    QPixmap *pix = new QPixmap();
    QString path;
    switch(type){
    case PEONN: path = ":/Icons/Pieces/black_pieces/Pawn.png";
        break;
    case PEONB: path = ":/Icons/Pieces/white_pieces/Pawn.png";
        break;
    case TORREN: path = ":/Icons/Pieces/black_pieces/Rook.png";
        break;
    case TORREB: path = ":/Icons/Pieces/white_pieces/Rook.png";
        break;
    case CABALLON: path = ":/Icons/Pieces/black_pieces/Knight.png";
        break;
    case CABALLOB: path = ":/Icons/Pieces/white_pieces/Knight.png";
        break;
    case ALFILN: path = ":/Icons/Pieces/black_pieces/Bishop.png";
        break;
    case ALFILB: path = ":/Icons/Pieces/white_pieces/Bishop.png";
        break;
    case REINAN: path = ":/Icons/Pieces/black_pieces/Queen.png";
        break;
    case REINAB: path = ":/Icons/Pieces/white_pieces/Queen.png";
        break;
    case REYN: path = ":/Icons/Pieces/black_pieces/King.png";
        break;
    case REYB: path = ":/Icons/Pieces/white_pieces/King.png";
        break;
    }

    pix->load(path);
    return pix;
}

void MainWindow::updateHistorialTable()
{
    //Reseteamos el rowcount
    ui->tblHistorial->clear();

    QVector<Move> record = gameController->getRecord();
    ui->tblHistorial->setRowCount(record.length());
    ui->tblHistorial->setColumnCount(4);

    ui->tblHistorial->setHorizontalHeaderLabels(QStringList() << "Origen" << "Destino" << "Equipo" << "Tipo");

    QString type{};
    for(int i = 0 ; i < record.length() ; i++){
        ui->tblHistorial->setItem(i, 0, new QTableWidgetItem(record[i].getOrigin()));
        ui->tblHistorial->setItem(i, 1, new QTableWidgetItem(record[i].getDestiny()));
        ui->tblHistorial->setItem(i, 2, new QTableWidgetItem(record[i].getTeam()));

        /*
const int GameController::KILL_MOVEMENT = 3;
const int GameController::NORMAL_MOVEMENT = 1;
const int GameController::PROMOTION_MOVEMENT = 2;
const int GameController::JAQUE_MOVEMENT = 4;
        */

        switch(record[i].getType()){
            case 1:
            type = "NORMAL";
            break;
            case 2:
            type = "PROMOTION";
            break;
            case 3:
            type = "KILL";
            break;
            case 4:
            type = "JAQUE MATE";
            break;
        }

        ui->tblHistorial->setItem(i, 3, new QTableWidgetItem(type));

    }

}

void MainWindow::updateGameData()
{
    updateJugadasLabel();
    updateTurnoLabel();
    updateHistorialTable();
    updateBlancasCapturadas();
    updateNegrasCapturadas();
}

void MainWindow::handleUpdateGameData()
{
    updateGameData();
}
