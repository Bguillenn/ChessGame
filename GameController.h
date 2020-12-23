#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QVector>
#include <QObject>
#include "Piece.h"
#include "Move.h"

class GameController: public QObject
{
    Q_OBJECT
private:
    QString turn{Piece::WHITE_TEAM}; //Turno
    QVector<Move> record{};
    QVector<int> whitesCap{};
    QVector<int> blacksCap{};
    int moves{0};
    bool end{false};
    QString winner{"NONE"};

    // PRIVATE METHODS

    void switchTurn();


    //Pseudo Singleton
    static GameController* _instance;

public:

    static GameController* getInstance();

    static const int KILL_MOVEMENT;
    static const int NORMAL_MOVEMENT;
    static const int PROMOTION_MOVEMENT;
    static const int JAQUE_MOVEMENT;


    GameController();

    // PUBLIC METHODS

    QString getTurn() const;
    void makeMove(QPoint ini, QPoint fin,QString team ,int type);
    int getMoves();
    QVector<Move> getRecord();
    QVector<int> getWhitesCaptured();
    QVector<int> getBlacksCaptured();
    bool isEnd() const;
    QString getWinner() const;


    void addToCementery(int pieceType, QString team);

signals:
    void updateGameData();
public slots:

};

#endif // GAMECONTROLLER_H
