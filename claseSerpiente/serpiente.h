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
    void depurar();
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
iCantidadElementos = 20;
elementos[0].setActivo(true);
elementos[0].setX(12);
elementos[0].setY(10);
for(int i=1;i<20;i++)
{
    elementos[i].setActivo(true);
    elementos[i].setX(12-i);
    elementos[i].setY(10);
}
}
void Vibora::depurar(){
    system("cls");
    int a,b;
for(int i=0;i<iCantidadElementos;i++){
        elementos[i].getCoordCambios(a,b);
    cout<<"Elemento "<<i+1<<": "<<elementos[i].getEstadoCambio()<<" x: "<<a<<" y: "<<b<<endl;

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

/*void Vibora::agregarElemento(Cuadrito c)
{
	int d = c.getDireccion();
	elemento[n].setActivo(true);
	switch(d)
	{
		case 1: {
			elemento[n].setY(c.getY+1);
			elemento[n].setX(c.getX);
			elemento[n].setDireccion(d);
			break;
		}
		case 2: {
			elemento[n].setY(c.getY);
			elemento[n].setX(c.getX-1);
			elemento[n].setDireccion(d);
			break;
		}
		case 3: {
			elemento[n].setY(c.getY+1);
			elemento[n].setX(c.getX);
			elemento[n].setDireccion(d);
			break;
		}
		case 4: {
			elemento[n].setX(c.getX+1);
			elemento[n].setY(c.getY);
			elemento[n].setDireccion(d);
			break;
		}
	}
}
*/
void Vibora::Mover(tablero &t){
for(int i=0;i<iCantidadElementos;i++)
    elementos[i].Movimiento();
dibujarVibora(t);
//depurar();
//Sleep(1000);
}
#endif // SERPIENTE_H_INCLUDED
