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
    void setDireccion(int dire);
    int getX();
    int getY();
    bool getActivo();
    int getDireccion(int dire);
private:
    int x; //cordenada x
    int y; //cordenada y
    bool activo;
    int direccion;
};

Cuadrito::Cuadrito() //constructor default
{
    x=0;
    y=0;
    activo=false;
    direccion=2;
}

Cuadrito::Cuadrito(int iX, int iY, bool iActivo, int direcion) //constructor con X y Y
{
    x=iX;
    y=iY;
    activo=iActivo;
    direccion=2;
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

void Cuadrito::setDireccion(int dire)
{
    direccion=dire;
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

int Cuadrito::getDireccion()
{
    return direccion;
}
#endif // CUADRITO_H_INCLUDED
