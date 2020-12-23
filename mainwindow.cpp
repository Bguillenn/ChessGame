#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

}

void MainWindow::updateBlancasCapturadas()
{

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
    for(int i = record.length() - 1 ; i >= 0 ; i--){
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
}

void MainWindow::handleUpdateGameData()
{
    updateGameData();
}
