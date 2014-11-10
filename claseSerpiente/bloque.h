#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



/*
Clase Bloque, Snake 2 v 2 Juan José López Jaimez y José Humberto Guevara Martinez
Esta clase es para representar el objeto cuadrito que hace crecer a la snake cuando esta choca con el
se incluyen funciones que generan numeros aleatorios para poder poner el cuadro en un lugar al azar del tablero*/
class bloque{
public:
    /* Constructores default y con parámetros*/
    bloque();
    bloque(int iX, int iY);
    /*
        Métodos de acceso y modificación
    */
    void setX(int iX);
    void setY(int iY);
    int getX();
    int getY();
    //Función para asignar coordenadas al azar al bloque
    void cambiaLugar();
private:
    int x; //cordenada x
    int y; //cordenada y
};
//Definición de los constructores
bloque::bloque()
{
    srand (time(NULL));
    x=rand()%78+1;
    y=rand()%23+1;
}
bloque::bloque(int iX, int iY){
    x=iX;
    y=iY;
}
//definicion de los métodos de acceso y modificación
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
//Definicion del metodo de cambio de coordenadas
void bloque::cambiaLugar(){

    x=rand()%78+1;
    y=rand()%23+1;

}

#endif // BLOQUE_H_INCLUDED
