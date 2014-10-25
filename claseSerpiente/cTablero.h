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
    tablero();
    void agregar(Cuadrito c);
    void agregar(bloque y);
    void agregar(int x, int y);
    void refrescar();
    void LimpiarTablero();
    bool checar(int a,int b);
    bool checarcolision(int a,int b);
    void bordes();

private:
    unsigned char Tablero[26][80];


};
void tablero::bordes()
{
    for(int i=0;i<80;i++)
    {
        Tablero[0][i]=254;
        Tablero[24][i]=254;
    }
    for(int j=0;j<25;j++)
    {
        Tablero[j][0]=254;
        Tablero[j][79]=254;
    }

}

bool tablero::checar(int a,int b){
if(Tablero[b][a]!= 2)
    return true;
else
    return false;
}
bool tablero::checarcolision(int a,int b){
if(Tablero[b][a]== 254)
    return true;
else
    return false;
}

void tablero::agregar(bloque y){
    int x,a;
    do{
x=y.getX();
a=y.getY();
    }while(!checar(x,a));
Tablero[a][x]=2;
}
tablero::tablero(){
for(int i=0;i<25;i++)
    for(int j=0;j<80;j++)
    Tablero[i][j]=32;
    Tablero[24][79]='\0';
}
void tablero::LimpiarTablero(){
    for(int i=0;i<25;i++){
        for(int j=0;j<80;j++)
            Tablero[i][j]=32;
    }
    Tablero[24][79]='\0';
}

void tablero::refrescar(){
    system("cls");
    bordes();
    Tablero[24][79]='\r';
    Tablero[25][0]='\0';
    printf("%s", Tablero);

}

void tablero::agregar(Cuadrito c){
    int x=c.getX();
    int y=c.getY();
    Tablero[y][x]=c.getC();
}

void tablero::agregar(int x, int y){
    Tablero[y][x]=254;
}



#endif // CTABLERO_H_INCLUDED
