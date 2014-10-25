#ifndef CUADRITO_H_INCLUDED
#define CUADRITO_H_INCLUDED

class Cuadrito
{
public:
    Cuadrito();
    Cuadrito(int iX, int iY, bool iActivo);
    void setX(int iX);
    void setY(int iY);
    void setActivo(bool iActivo);
    int getX();
    int getY();
    bool getActivo();
private:
    int x; //cordenada x
    int y; //cordenada y
    bool activo;
};

Cuadrito::Cuadrito() //constructor default
{
    x=0;
    y=0;
    bool=false;
}

Cuadrito::Cuadrito(int iX, int iY, bool iActivo) //constructor con X y Y
{
    x=iX;
    y=iY;
    activo=iActivo;
}

void Cuadrito::setX(int iX) //modificar X
{
    x=iX;
}

void Cuadrito::setY(int iY) //modificar Y
{
    y=iY;
}

void Cuadrito::setActivo(bool iActivo)
{
    activo=iActivo;
}

int Cuadrito::getX() //obtener X
{
    return x;
}

int Cuadrito::getY() //obtener Y
{
    return y;
}

bool Cuadrito::getActivo()
{
    return activo;
}
#endif // CUADRITO_H_INCLUDED
