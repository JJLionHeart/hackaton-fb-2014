#include <iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
#include "serpiente.h"
int main()
{
    Vibora a;
    tablero t;
<<<<<<< HEAD
    a.dibujarVibora(t);
    short int u,d,r,l;
    while(true){
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
                    cout<<"up"<<endl;
                a.Modificar(1)
            }else if(r){
                cout<<"Right"<<endl;
                a.Modificar(2);
            }else if(d){
                cout<<"down"<<endl;
                a.Modificar(3);
            }else if(l){
                cout<<"left"<<endl;
                a.Modificar(4);
            }
        }else{

=======
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
>>>>>>> origin/master
        a.Mover();
        Sleep(10);
        t.LimpiarTablero();
        a.dibujarVibora(t);

        }
    }
            }
    }
    return 0;
}
