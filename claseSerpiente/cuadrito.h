#ifndef CUADRITO_H_INCLUDED
#define CUADRITO_H_INCLUDED

class Cuadrito
{
public:
    Cuadrito();
    Cuadrito(int iX, int iY, bool iActivo, int direccion);
    Cuadrito(int iX, int iY);
    void setX(int iX);
    void setY(int iY);
    void setActivo(bool iActivo);
    void setDireccion(int dire);
    int getX();
    int getY();
    bool getActivo();
    int getDireccion();
    void setCoordCambio(int a,int b);
    void setCambio(bool a);
    void setNuevaDir(int a);
    void Movimiento();
    bool getEstadoCambio();
    void incrementarCambio();
    void getCoordCambios(int &a,int&b);
    void modStack(int a,int b,int ndir);
    void setC(int ca);
    char getC();
    void compStack();
private:
    int x; //cordenada x
    int y; //cordenada y
    char c;
int stacker[1000][3];
    int cantCambios;
    bool activo;
    int cx;//coordenada x del cambio
    int cy;//coordenada cy del cambio
    bool cambio;//para determinar si tiene que hacer cambio de direccion;
    int nuevadir;//la nueva direccion que tiene que adoptar
    int direccion;
};
char Cuadrito::getC(){
    return c;
}
void Cuadrito::compStack(){
if(cambio){
    bool encontrado=false;
    for(int i=0;!encontrado&&i<1000;i++){
    if(stacker[i][2]!=0){
        encontrado = true;
        cx=stacker[i][0];
        cy=stacker[i][1];
        nuevadir=stacker[i][2];
        stacker[i][0]=0;
        stacker[i][1]=0;
        stacker[i][2]=0;

    }
    if(i==999)
        cambio = false;
    }
}
}
void Cuadrito::modStack(int a,int b,int ndir){
    cambio = true;

if(cantCambios != 1000){
    stacker[cantCambios][0]=a;
    stacker[cantCambios][1]=b;
    stacker[cantCambios][2]=ndir;
    cantCambios++;
}else{
    cantCambios=0;
    stacker[cantCambios][0]=a;
    stacker[cantCambios][1]=b;
    stacker[cantCambios][2]=ndir;
}
    }

void Cuadrito::getCoordCambios(int &a,int&b){
a=cx;
b=cy;
}

void Cuadrito::setCoordCambio(int a, int b){
cx = a;
cy = b;
}
void Cuadrito::setCambio(bool a){
cambio = a;
}
void Cuadrito::setNuevaDir(int a){
nuevadir=a;
}
void Cuadrito::setC(int ca){
c=ca;
}
Cuadrito::Cuadrito() //constructor default
{
    c=254;
    x=0;
    y=0;
    cantCambios=0;
    for(int i=0;i<1000;i++)
        for(int j=0;j<3;j++)
        stacker[i][j]=0;
    activo=false;
    direccion=2;
    cambio = false;
    cx=-1;
    cy=-1;
    nuevadir=0;

}

Cuadrito::Cuadrito(int iX, int iY, bool iActivo, int direccion) //constructor con X y Y
{
    x=iX;
    y=iY;
    activo=iActivo;
    direccion=2;
}

Cuadrito::Cuadrito(int iX, int iY)
{
    x=iX;
    y=iY;
}

void Cuadrito::setX(int iX) //modificar X
{
    x=iX;
}

void Cuadrito::setY(int iY) //modificar Y
{
    y=iY;
}

void Cuadrito::setActivo(bool iActivo)
{
    activo=iActivo;
}

void Cuadrito::setDireccion(int dire)
{
    direccion=dire;
}

int Cuadrito::getX() //obtener X
{
    return x;
}

int Cuadrito::getY() //obtener Y
{
    return y;
}

bool Cuadrito::getActivo()
{
    return activo;
}

int Cuadrito::getDireccion()
{
    return direccion;
}
void Cuadrito::Movimiento(){

    if(x==cx&&y==cy&&cambio)
    {

        direccion = nuevadir;
        compStack();
    }
    if(direccion==1)
            y-=1;
        if(direccion==2)
            x+=1;
        if(direccion==3)
            y+=1;
        if(direccion==4)
            x-=1;
}
bool Cuadrito::getEstadoCambio(){
return cambio;
}

#endif // CUADRITO_H_INCLUDED
