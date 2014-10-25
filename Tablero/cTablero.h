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
    void Destruir();
private:
    unsigned char **Tablero;


};
tablero::tablero(){
Tablero = (unsigned char**) malloc(sizeof(char)*25);
for(int i=0;i<25;i++){
    Tablero[i]=(unsigned char*)malloc(sizeof(char)*80);
}
}
void tablero::LimpiarTablero(){
    for(int i=0;i<25;i++){
        for(int j=0;j<80;j++)
            Tablero[i][j]=32;
    }
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
void tablero::Destruir(){
    for(int i=0;i<25;i++)
        free(Tablero[i]);
    free(Tablero);
}


#endif // CTABLERO_H_INCLUDED
