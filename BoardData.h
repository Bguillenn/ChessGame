#ifndef BOARDDATA_H
#define BOARDDATA_H

#include <QVector>
#include <QPoint>

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


class BoardData
{
private:
    QVector<QVector<int>> data{};
public:

    //STATIC
    static BoardData getInitialBoardData() {

      /*  QVector<QVector<int>>  data=
        {
            {TORREN,CABALLON,ALFILN,REINAN,REYN,ALFILN,CABALLON,TORREN},
            {PEONN,PEONN,PEONN,PEONN,PEONN,PEONN,PEONN,PEONN},
            {VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO},
            {VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO},
            {VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO},
            {VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO,VACIO},
            {PEONB,PEONB,PEONB,PEONB,PEONB,PEONB,PEONB,PEONB},
            {TORREB,CABALLOB,ALFILB,REYB,REINAB,ALFILB,CABALLOB,TORREB}
        }; */

        QVector<QVector<int>> data =
        {
            {TORREN,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,TORREB},
            {CABALLON,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,CABALLOB},
            {ALFILN,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,ALFILB},
            {REINAN,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,REYB},
            {REYN,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,REINAB},
            {ALFILN,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,ALFILB},
            {CABALLON,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,CABALLOB},
            {TORREN,PEONN,VACIO,VACIO,VACIO,VACIO,PEONB,TORREB}
        };

        return BoardData(data);
    }
    //CONSTRUCTOR
    BoardData(QVector<QVector<int>> dataM): data{dataM} {}

    bool isWhitePiece(int x, int y) const;
    bool isBlank(int x, int y) const;
    bool isFreeWay(QPoint initial, QPoint final) const;

    void set(int x, int y, int v);
    int get(int x, int y);


    QVector<int> operator[](unsigned index) const{
        return data[index];
    }
};

#endif // BOARDDATA_H
