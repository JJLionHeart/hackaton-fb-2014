#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
#include "serpiente.h"
#include "bloque.h"
int main()
{
    bloque y;
    Vibora a;
    tablero t;
    int contador=0;
    short int u,d,r,l;
    while(true){
        if(contador==0){
        if((u=GetAsyncKeyState(VK_UP))||(d=GetAsyncKeyState(VK_DOWN))||(r=GetAsyncKeyState(VK_RIGHT))||(l=GetAsyncKeyState(VK_LEFT))){
            u=u>>16;
            u=u&0x1;
            d=d>>16;
            d=d&0x1;
            r=r>>16;
            r=r&0x1;
            l=l>>16;
            l=l&0x1;
            if(u){

                a.Modificar(1,t);

            }else if(r){

                a.Modificar(2,t);
            }else if(d){

                a.Modificar(3,t);
            }else if(l){

                a.Modificar(4,t);
            }

        }else{
        t.LimpiarTablero();
        a.Mover(t);

}
        }else{
        contador--;
        t.LimpiarTablero();
        a.Mover(t);
        }
    Sleep(100);
    }
return 0;
}
