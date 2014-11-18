#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
#include "serpiente.h"

#include "bloque.h"
int main()
{
    bloque y;
    tablero t;
    bloque *point;
    point = &y;
    tablero *tab;
    tab=&t;
    t.agregar(y);

    Vibora *serpientes[2];
    serpientes[0]=new Vibora(point,2,10,tab,10,10,1);
    //serpientes[1]= new Vibora(point,2,10,tab,10,20,2);

    while(true){
    serpientes[0]->comprobarMovimiento();


   // serpientes[1]->comprobarMovimiento();
    serpientes[0]->dibujarVibora(t);
   // serpientes[1]->dibujarVibora(t);
    t.agregar(y);
    t.refrescar();

    Sleep(100);
    }
return 0;
}
