#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>
#include <iostream>
#include "cuadrito.h"
#include "cTablero.h"

class bloque{
public:
    bloque();
    bloque(int iX, int iY);
    void setX(int iX);
    void setY(int iY);
    int getX();
    int getY();
private:
    int x; //cordenada x
    int y; //cordenada y
};


bloque::bloque()
{
    srand (time(NULL));
    x=rand()%78+1;
    y=rand()%23+1;
}


int bloque::getX()
{
    return x;
}

int bloque::getY()
{
    return y;
}

void bloque::setX(int iX)
{
    x=iX;
}

void bloque::setY(int iY)
{
    y=iY;
}

#endif // BLOQUE_H_INCLUDED
