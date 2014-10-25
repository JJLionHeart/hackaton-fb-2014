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
    void Mover(tablero &t);
    Vibora();
    void cambiarCuadritos();
    void Modificar(int n,tablero &t);
private:
    Cuadrito elementos[100];
    int Direccion;
    int iCantidadElementos;
};
Vibora::Vibora(){
    Direccion = 2;
for(int i=0;i<100;i++){
    elementos[i].setActivo(false);
    elementos[i].setX(0);
    elementos[i].setY(0);
    elementos[i].setDireccion(2);
}
iCantidadElementos = 3;
elementos[0].setActivo(true);
elementos[0].setX(12);
elementos[0].setY(10);
elementos[1].setActivo(true);
elementos[1].setX(11);
elementos[1].setY(10);
elementos[2].setActivo(true);
elementos[2].setX(10);
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
void Vibora::Modificar(int n,tablero &t){
    //si la direccion no es la misma o la contraria llama a la funcion cambiar cuadrito
    //all esto para modificar el estado de cada cuadrito en particular
    if(Direccion == 1){
        if(n != 1 && n != 3){
            Direccion = n;
            cambiarCuadritos();
        }
    }else if(Direccion == 2){
        if(n != 2 && n != 4){
            Direccion = n;
            cambiarCuadritos();
        }
    }else if(Direccion == 3){
        if(n != 1 && n != 3){
            Direccion = n;
            cambiarCuadritos();
        }
    }else if(Direccion == 4){
        if(n != 4 && n != 2){
            Direccion = n;
            cambiarCuadritos();
        }
    }
    t.LimpiarTablero();
    Mover(t);

}
void Vibora::cambiarCuadritos(){
    for(int j=0;j<iCantidadElementos;j++)
    elementos[j].setCoordCambio(elementos[0].getX(),elementos[0].getY());
    for(int i=0;i<iCantidadElementos;i++){
        if(!elementos[i].getEstadoCambio()){
        elementos[i].setNuevaDir(Direccion);
        elementos[i].setCambio(true);
    }
        elementos[i].incrementarCambio();
        int cam=elementos[i].getCantidadCambiosHechos();
        elementos[i].setVarios(elementos[0].getX(),elementos[0].getY(),cam,Direccion);
    }
}
void Vibora::Mover(tablero &t){
for(int i=0;i<iCantidadElementos;i++)
    elementos[i].Movimiento();
dibujarVibora(t);
}
#endif // SERPIENTE_H_INCLUDED
