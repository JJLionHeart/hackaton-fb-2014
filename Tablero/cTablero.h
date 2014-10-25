#ifndef CTABLERO_H_INCLUDED
#define CTABLERO_H_INCLUDED
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "cuadrito.h"
class tablero{
public:
    void agregar(Cuadrito c);
    void refrescar();
    void settablero(char c[][]);
private:
    unsigned char cTablero[25][80];
    char c=254;

};

void tablero::settablero(char c[][]){
    cTablero=c;
}

void refrescar(){
    system("cls");
    printf("%s", cTablero)
}

void tablero::agregar(Cuadrito c){
    int x=Cuadrito.getX();
    int y=Cuadrito.getY();
    cTablero[y][x]=c;
}


#endif // CTABLERO_H_INCLUDED
