#ifndef CTABLERO_H_INCLUDED
#define CTABLERO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "cuadrito.h"
#include "bloque.h"
class tablero{
public:
    //constructor default
    tablero();
    //funciones hechas para agregar cosas al tablero
    void agregar(Cuadrito c);//para agregar al tablero objetos de la clase cuadrito
    void agregar(bloque y);//para agregar al tablero el bloque que hace crecer la snake
    void agregar(int x, int y);//funcion para agregar un caracter 254 en una coordenada
    void bordes();//agrega en el tablero los margenes de pantalla
    //Funciones que manipulan el tablero
    void refrescar();//borra lo que está en pantalla y vuelve a dibujar el tablero
    void LimpiarTablero();//borra todos los elementos del arreglo tablero
    //Funciones de coolisiones
    bool checar(int a,int b);//revisa si la coordenada (a,b) está ocupada por un caracter 254
    bool checarcolision(int a,int b);//revisa si la coordenada (a,b) está ocupada por un caracter 254
    //las 2 funciones anteriores hay que fusionarlas en una sola


private:
    unsigned char Tablero[25][80];//el tablero es un arreglo de caracteres que se imprime en la ventana msdos
    //las dimensiones de una ventana msdos son 25 filas por 80 columnas


};
//constructor default:
tablero::tablero(){
    //Inicializa el tablero en espacios (caracter 32) y coloca el caracter nulo al final
for(int i=0;i<25;i++)
    for(int j=0;j<80;j++)
    Tablero[i][j]=32;
    Tablero[24][79]='\0';
}
//funciones que agregan cosas al tablero
void tablero::agregar(Cuadrito c){
    //agrega un objeto de la clase cuadrito al tablero en funcion de las coordenadas de este objeto
    int x=c.getX();
    int y=c.getY();
    Tablero[y][x]=c.getC();
}
void tablero::agregar(bloque y){
    //agrega un objeto bloque al tablero, el objeto bloque es el que hace crecer a la serpiente
    int x,a;
    do{

x=y.getX();
a=y.getY();
if(!checar(x,a))
    y.cambiaLugar();
    }while(!checar(x,a));//se tiene que revisar que la posicion en la que se intenta poner el bloque
                        // si la posicion ya esta ocupada se manda llamar al metodo cambiar lugar hasta que quede en una posicion sin ocupar
Tablero[a][x]=2;
}
void tablero::agregar(int x, int y){//agrega un caracter 254 en la coordenada x,y
    Tablero[y][x]=254;
}
void tablero::bordes()
{
    //dibuja los bordes (el marco) del tablero
    for(int i=0;i<80;i++)//horizontales
    {
        Tablero[0][i]=254;
        Tablero[24][i]=254;
    }
    for(int j=0;j<25;j++)//verticales
    {
        Tablero[j][0]=254;
        Tablero[j][79]=254;
    }

}
//funciones que manipulan el tablero
void tablero::LimpiarTablero(){//borra todo el contenido del tablero, poniendo en cada posicion un espacio (caracter 32)
    for(int i=0;i<25;i++){
        for(int j=0;j<80;j++)
            Tablero[i][j]=32;
    }
    Tablero[24][79]='\0';
}

void tablero::refrescar(){//borra lo que esté en pantalla y vuelve a imprimir el tablero
    system("cls");//borra pantalla
    bordes();
    Tablero[24][79]='\r';
    Tablero[25][0]='\0';
    printf("%s", Tablero);//imprime tablero

}
//funciones para colisiones
bool tablero::checar(int a,int b){
    //funcion para checar si una cierta posicion está ocupada o no
    // si no está ocupada devuelve un true
    // si está ocupada devuelve un false
if(Tablero[b][a]!= 254)
    return true;
else
    return false;
}
bool tablero::checarcolision(int a,int b){
    //esta funcion hace exactamente lo mismo que checar() pero el true false está alreves, hay que eliminarla
if(Tablero[b][a]== 254)
    return true;
else
    return false;
}











#endif // CTABLERO_H_INCLUDED
