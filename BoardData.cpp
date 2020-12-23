#include "BoardData.h"


bool BoardData::isWhitePiece(int x, int y) const
{
     return data[x][y] % 2 == 1;
}

bool BoardData::isBlank(int x, int y) const
{
    return data[x][y] == -1;
}

bool BoardData::isFreeWay(QPoint initial, QPoint final) const
{
    int difX = final.x() - initial.x();
    int difY = final.y() - initial.y();

    bool ok = true;

    //Tenemos que validar un movimiento vertical
    if(difX == 0)
    {
        //Recorremos verticalmente en caso de que haya alguna obstruccion
        for(int i = 1; i < abs(difY); i++)
            if(data[initial.x()][initial.y() + ((difY < 0) ? -i:i)]  != VACIO)
                ok = false;
    }else if(difY == 0) //Movimiento horizontal
    {
        for(int i = 1; i < abs(difY); i++)
            if(data[initial.x() + ((difX < 0 )? -i:i)][initial.y()] != VACIO)
                ok = false;
    }else if(abs(difX) == abs(difY)) //Movimiento horizontal
    {
        for(int i = 1; i < abs(difY); i++)
            if(data[initial.x() + ((difX < 0) ? -i:i)][initial.y() + ((difY < 0) ? -i:i)] != VACIO)
                ok = false;
    }

    return ok;
}

void BoardData::set(int x, int y, int v)
{
    data[x][y] = v;
}
int BoardData::get(int x, int y)
{
    return data[x][y];
}
