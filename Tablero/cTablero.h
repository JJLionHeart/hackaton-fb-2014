#ifndef CTABLERO_H_INCLUDED
#define CTABLERO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "cuadrito.h"

class tablero{
public:
    tablero();
    void agregar(Cuadrito c);
    void refrescar();
    void LimpiarTablero();
    void depurar();

private:
    unsigned char Tablero[25][80];


};
tablero::tablero(){
for(int i=0;i<25;i++){
    for(int j=0;j<80;j++)
        Tablero[i][j]=32;
}
    Tablero[24][79]='\0';
}
void tablero::LimpiarTablero(){
    memset(Tablero,32,sizeof(tablero));

    Tablero[24][79]='\0';
    }


void tablero::refrescar(){
    system("cls");
    printf("%s", Tablero);
}

void tablero::agregar(Cuadrito c){
    int x=c.getX();
    int y=c.getY();
    Tablero[y][x]=254;
}
void tablero::depurar(){
for(int i=0;i<25;i++){
    for(int j=0;j<80;j++)
    {
        int a=Tablero[i][j];
        cout<<"tablero["<<i<<"]["<<j<<"]="<<a<<endl;
    }
}
}


#endif // CTABLERO_H_INCLUDED
