#ifndef CUADRITO_H_INCLUDED
#define CUADRITO_H_INCLUDED

class Cuadrito
{
public:
    Cuadrito();
    Cuadrito(int iX, int iY);
    void setX(int iX);
    void setY(int iY);
    int getX();
    int getY();
private:
    int x; //cordenada x
    int y; //cordenada y;
};

Cuadrito::Cuadrito() //constructor default
{
    x=0;
    y=0;
}

Cuadrito::Cuadrito(int iX, int iY) //constructor con X y Y
{
    x=iX;
    y=iY;
}

void Cuadrito::setX(int iX) //modificar X
{
    x=iX;
}

void Cuadrito::setY(int iY) //modificar Y
{
    y=iY;
}

int Cuadrito::getX() //obtener X
{
    return x;
}

int Cuadrito::getY() //obtener Y
{
    return y;
}

#endif // CUADRITO_H_INCLUDED
