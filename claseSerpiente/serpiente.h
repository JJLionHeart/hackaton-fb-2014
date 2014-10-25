#ifndef SERPIENTE_H_INCLUDED
#define SERPIENTE_H_INCLUDED
#include <windows.h>
#include <iostream>
#include "cuadrito.h"
#include "cTablero.h"
class Vibora{
public:
    void agregarElemento(Cuadrito c);
    void getCoordenadaPrincipal(int &ix, int &iy);
    void dibujarVibora(tablero t);
    void Mover();
    Vibora();
private:
    Cuadrito elementos[100];
    int iCantidadElementos;
};
Vibora::Vibora(){
for(int i=0;i<100;i++){
    elementos[i].setActivo(false);
    elementos[i].setX(0);
    elementos[i].setY(0);
    elementos[i].setDireccion(2);
}
iCantidadElementos = 3;
elementos[0].setActivo(true);
elementos[0].setX(10);
elementos[0].setY(10);
elementos[1].setActivo(true);
elementos[1].setX(11);
elementos[1].setY(10);
elementos[2].setActivo(true);
elementos[2].setX(12);
elementos[2].setY(10);
}
void Vibora::dibujarVibora(tablero t){
for(int ic = 0;ic<iCantidadElementos;ic++){
    t.agregar(elementos[ic]);
}
t.refrescar();
}
void Vibora::getCoordenadaPrincipal(int &ix, int &iy){
ix=elementos[0].getX();
iy=elementos[0].getY();
}
void Vibora::Mover()
{
    int n=0;
    for(int a=0;a<iCantidadElementos;a++)
    {
        n=elementos[a].getX();
        n++;
        elementos[a].setX(n);

    }
}

#endif // SERPIENTE_H_INCLUDED
