#ifndef SERPIENTE_H_INCLUDED
#define SERPIENTE_H_INCLUDED
#include "cuadrito.h"
#include "cTablero.h"
class Vibora{
public:
    void agregarElemento(Cuadrito c);
    int getCoordenadaPrincipal();
    void dibujarVibora(tablero &t);
    Vibora();
private:
    Cuadrito elementos[100];
    int iCantidadElementos;
};
Vibora::Vibora(){
for(int i=0;i<100;i++){
    elementos[i].setActivo(false);
    elementos[i].setX(0);
    elementos[i].setY(0);
}
iCantidadElementos = 3;
elementos[0].setAvtivo(true);
elementos[0].setX(10);
elementos[0].setY(10);
elementos[1].setAvtivo(true);
elementos[1].setX(11);
elementos[1].setY(10);
elementos[2].setAvtivo(true);
elementos[2].setX(12);
elementos[2].setY(10);
}
void Vibora::dibujarVibora(tablero &t){
for(int i = 0;i<iCantidadElementos;i++){
    t.agregar(elemento[i]);
}
}
int getCoordenadaPrincipal(int &ix, int &iy){
ix=elementos[0].getX();
iy=elementos[0].getY();
}
#endif // SERPIENTE_H_INCLUDED
