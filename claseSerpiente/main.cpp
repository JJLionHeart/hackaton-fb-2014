#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
#include "serpiente.h"
int main()
{
    Vibora a;
    tablero t;
   // a.dibujarVibora(t);
    char cTecla='b';

    while(cTecla!='a')
        {
           cTecla = getch();
       if(cTecla == 0)
           cTecla = getch();
       else
           switch(cTecla)
           {
            case 72:
                printf("\r\n Presiono Flecha Arriba");
            break;

            case 80:
                 printf("\r\n Presiono Flecha Abajo");
            break;

            case 75:
                 printf("\r\n Presiono Flecha izquierda");
            break;

            case 77:
                 printf("\r\n Presiono Flecha derecha");
            break;
            default:
        for(int i=0;i<200;i++){
        a.Mover();
        Sleep(10);
        t.LimpiarTablero();
        a.dibujarVibora(t);
    }
            }
    }
    return 0;
}
