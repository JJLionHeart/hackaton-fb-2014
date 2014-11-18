#ifndef SERPIENTE_H_INCLUDED
#define SERPIENTE_H_INCLUDED
#include <windows.h>
#include <iostream>
#include "cuadrito.h"
#include "cTablero.h"
#include "bloque.h"
class Vibora{
public:
    //constructores

    Vibora(bloque *blo,int D,int cant,tablero *ta,int xi,int yi,int config);
    //-----------------------------------
    //Funciones que modifican a la serpiente
    //------------------------------------
    void comprobarMovimiento();
    void agregarElemento();//activa un cuadrito en la serpiente
    void dibujarVibora(tablero &t);//muestra la serpiente en el tablero
    void Mover(tablero &t);//mueve la serpiente en el tablero
    void Modificar(int n,tablero &t);//modifica la direccion de la serpiente en si se presiona una tecla
    void cambiarCuadritos();//actualiza el stacker de todos los cuadritos
    void setBloque(bloque *a);//le indica a la serpiente cual es el blque que va a hacer que crezca
    void reiniciar();//renicia la serpiente a su estado original
    //otras funciones
    void getCoordenadaPrincipal(int &ix, int &iy);//regresa las coordenadas del cuadro 0
    bool comprobarchoque(tablero &t);//comprueba si hubo una colision

private:
    bloque *b;//un puntero al objeto bloque que hace crecer a la vibora
    Cuadrito elementos[100];//la vibora se compone de muchos cuadritos
    int Direccion;//direccion en el que se mueve la cabeza
    int iCantidadElementos;//cuantos elementos tiene hasta el momento
    tablero *tab;
    int up,down,right,left;
};

Vibora::Vibora(bloque *blo,int D,int cant,tablero *ta,int xi,int yi,int config){
    Direccion=D;
for(int i=0;i<100;i++){
    elementos[i].setActivo(false);
    elementos[i].setX(0);
    elementos[i].setY(0);
    elementos[i].setDireccion(D);
}
b=blo;
tab=ta;
iCantidadElementos = cant;
elementos[0].setActivo(true);
elementos[0].setX(xi);
elementos[0].setY(yi);
for(int i=1;i<iCantidadElementos;i++)
{
    elementos[i].setActivo(true);
    elementos[i].setX(xi-i);
    elementos[i].setY(yi);
}
if(config == 1)
{
    up = 0x26;
    left = 0x25;
    down = 0x28;
    right= 0x27;

}else if (config == 2){
    up = 0x57;
    left = 0x41;
    down= 0x53;
    right = 0x44;
}
}
void Vibora::comprobarMovimiento(){
    short int u,d,r,l;
if((u=GetAsyncKeyState(up))||(d=GetAsyncKeyState(down))||(r=GetAsyncKeyState(right))||(l=GetAsyncKeyState(left))){
            u=u>>16;
            u=u&0x1;
            d=(d&0x800||d&0x1);
            r=r>>16;
            r=r&0x1;
            l=l>>16;
            l=l&0x1;
            if(u){

                Modificar(1,*tab);

            }else if(r){

                Modificar(2,*tab);
            }else if(d){

                Modificar(3,*tab);

            }else if(l){

                Modificar(4,*tab);
            }

        }else{
        tab->LimpiarTablero();
        Mover(*tab);

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
void Vibora::dibujarVibora(tablero &t){
for(int ic = 0;ic<iCantidadElementos;ic++){
    t.agregar(elementos[ic]);
}
}
void Vibora::Mover(tablero &t){


for(int i=0;i<iCantidadElementos;i++)
    elementos[i].Movimiento();
if(elementos[0].getX()==b->getX()&&elementos[0].getY()==b->getY()){
    t.LimpiarTablero();
    agregarElemento();
    b->cambiaLugar();
    t.agregar(*b);
}

if(comprobarchoque(*tab)){
    reiniciar();
}
//depurar();
//Sleep(1000);
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
    void Vibora::setBloque(bloque *a){
b=a;
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
void Vibora::getCoordenadaPrincipal(int &ix, int &iy){
ix=elementos[0].getX();
iy=elementos[0].getY();
}
bool Vibora::comprobarchoque(tablero &t){
    bool choque=false;
    if(elementos[0].getX()==0||elementos[0].getX()==79||elementos[0].getY()==0||elementos[0].getY()==24)
        choque=true;
    for(int i=1;i<iCantidadElementos;i++){
        if(elementos[i].getX()==elementos[0].getX()&&elementos[i].getY()==elementos[0].getY())
            choque=true;
    }
return choque;
}












#endif // SERPIENTE_H_INCLUDED
