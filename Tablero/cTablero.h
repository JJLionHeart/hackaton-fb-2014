#ifndef CTABLERO_H_INCLUDED
#define CTABLERO_H_INCLUDED

class tablero{
public:
    void agregar(Cuadrito c);
    void refrescar();
private:
    unsigned char cTablero[25][80];
    char c=254;

};



void tablero::agregar(Cuadrito c){
    int x=Cuadrito.getX();
    int y=Cuadrito.getY();
    cTablero[y][x]=c;
}


#endif // CTABLERO_H_INCLUDED
