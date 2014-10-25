#include <iostream>
#include <windows.h>
using namespace std;
#include "serpiente.h"
int main()
{
    Vibora a;
    tablero t;
    a.dibujarVibora(t);
    for(int i=0;i<200;i++){
        a.Mover();
        Sleep(10);
        t.LimpiarTablero();
        a.dibujarVibora(t);
    }
    return 0;
}
