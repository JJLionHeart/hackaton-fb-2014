#ifndef SERPIENTE_H_INCLUDED
#define SERPIENTE_H_INCLUDED
#include <windows.h>
#include <iostream>
#include "cuadrito.h"
#include "cTablero.h"
#include "bloque.h"
class Vibora{
public:
    //constructor default
    Vibora();
    //-----------------------------------
    //Funciones que modifican a la serpiente
    //------------------------------------
    void agregarElemento();
    void dibujarVibora(tablero t);
    void Mover(tablero &t);
    void Modificar(int n,tablero &t);
    void cambiarCuadritos();
    void setBloque(bloque *a);
    void reiniciar();
    //otras funciones
    void getCoordenadaPrincipal(int &ix, int &iy);
    bool comprobarchoque(tablero &t);

private:
    bloque *b;//un puntero al objeto bloque que hace crecer a la vibora
    Cuadrito elementos[100];//la vibora se compone de muchos cuadritos
    int Direccion;//direccion en el que se mueve la cabeza
    int iCantidadElementos;//cuantos elementos tiene hasta el momento
};
bool Vibora::comprobarchoque(tablero &t){
    bool choque=false;
if(Direccion==1)
    choque = t.checarcolision(elementos[0].getX(),elementos[0].getY()-1);
else if(Direccion==2)
    choque = t.checarcolision(elementos[0].getX()+1,elementos[0].getY());
else if(Direccion==3)
    choque = t.checarcolision(elementos[0].getX(),elementos[0].getY()+1);
else if(Direccion==4)
    choque = t.checarcolision(elementos[0].getX()-1,elementos[0].getY());
return choque;
}
void Vibora::reiniciar(){

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
for(int i=1;i<3;i++)
{
    elementos[i].setActivo(true);
    elementos[i].setX(12-i);
    elementos[i].setY(10);
}
}
void Vibora::setBloque(bloque *a){
b=a;
}
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
for(int i=1;i<3;i++)
{
    elementos[i].setActivo(true);
    elementos[i].setX(12-i);
    elementos[i].setY(10);
}
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
    t.agregar(*b);
    Mover(t);

}
void Vibora::cambiarCuadritos(){

    for(int i=0;i<iCantidadElementos;i++){
        if(!elementos[i].getEstadoCambio())
        {
            elementos[i].setCambio(true);
            elementos[i].setCoordCambio(elementos[0].getX(),elementos[0].getY());
            elementos[i].setNuevaDir(Direccion);
        }else
        elementos[i].modStack(elementos[0].getX(),elementos[0].getY(),Direccion);
        }

    }

void Vibora::agregarElemento()
{
    elementos[iCantidadElementos]=elementos[iCantidadElementos-1];
	int d = elementos[iCantidadElementos-1].getDireccion();
	//elemento[iCantidadElementos].setActivo(true);*/
	switch(d)
	{
		case 1: {
			elementos[iCantidadElementos].setY(elementos[iCantidadElementos-1].getY()+1);
			elementos[iCantidadElementos].setX(elementos[iCantidadElementos-1].getX());

			break;
		}
		case 2: {
			elementos[iCantidadElementos].setY(elementos[iCantidadElementos-1].getY());
			elementos[iCantidadElementos].setX(elementos[iCantidadElementos-1].getX()-1);

			break;
		}
		case 3: {
			elementos[iCantidadElementos].setY(elementos[iCantidadElementos-1].getY()-1);
			elementos[iCantidadElementos].setX(elementos[iCantidadElementos-1].getX());

			break;
		}
		case 4: {
			elementos[iCantidadElementos].setX(elementos[iCantidadElementos-1].getX()+1);
			elementos[iCantidadElementos].setY(elementos[iCantidadElementos-1].getY());

			break;
		}
	}
	iCantidadElementos++;
}

void Vibora::Mover(tablero &t){

if(comprobarchoque(t))
    reiniciar();
else{
for(int i=0;i<iCantidadElementos;i++)
    elementos[i].Movimiento();
if(elementos[0].getX()==b->getX()&&elementos[0].getY()==b->getY()){
    t.LimpiarTablero();
    agregarElemento();
    b->cambiaLugar();
    t.agregar(*b);
}
}
dibujarVibora(t);
//depurar();
//Sleep(1000);
}

#endif // SERPIENTE_H_INCLUDED
