#include <iostream>
#include <windows.h>
using namespace std;
#include "serpiente.h"
int main()
{
    Vibora a;
    tablero t;
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

        a.Mover();
        Sleep(10);
        t.LimpiarTablero();
        a.dibujarVibora(t);

        }
    }
    return 0;
}
