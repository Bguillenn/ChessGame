#include "GameController.h"

const int GameController::KILL_MOVEMENT = 3;
const int GameController::NORMAL_MOVEMENT = 1;
const int GameController::PROMOTION_MOVEMENT = 2;
const int GameController::JAQUE_MOVEMENT = 4;

GameController* GameController::_instance = nullptr;

GameController* GameController::getInstance(){
    //Verificamos si ya inicializamos el objeto, en caso no lo inicializamos
    if(_instance == nullptr){
        _instance = new GameController();
    }
    return _instance;
}


GameController::GameController()
{

}

void GameController::switchTurn(){
    if(this->turn == Piece::WHITE_TEAM){
        this->turn = Piece::BLACK_TEAM;
    }else{
        this->turn = Piece::WHITE_TEAM;
    }
}

QString GameController::getTurn() const{
    return this->turn;
}


void GameController::makeMove(QPoint ini, QPoint fin,QString team ,int type){

    record.push_back(Move(ini, fin, team, type));
    switchTurn();
    moves++;

    if(type == JAQUE_MOVEMENT){
        winner = (team == Piece::WHITE_TEAM) ? "BLANCAS": "NEGRAS";
        end = true;
    }

    emit updateGameData();
}

void GameController::addToCementery(int pieceType, QString team)
{
    if(team == Piece::WHITE_TEAM)
        whitesCap.push_back(pieceType);
    else
        blacksCap.push_back(pieceType);
}

int GameController::getMoves(){
    return moves;
}

QVector<Move> GameController::getRecord()
{
    return record;
}

QVector<int> GameController::getWhitesCaptured()
{
    return whitesCap;
}

QVector<int> GameController::getBlacksCaptured()
{
    return blacksCap;
}

bool GameController::isEnd() const{
    return end;
}

QString GameController::getWinner() const{
    return winner;
}

void GameController::reset() {
    turn = Piece::WHITE_TEAM;
    record = {};
    whitesCap = {};
    blacksCap = {};
    moves = 0;
    end = false;
    winner = "NONE";

    emit updateGameData();
}
