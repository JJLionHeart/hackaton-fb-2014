#ifndef CUADRITO_H_INCLUDED
#define CUADRITO_H_INCLUDED

class Cuadrito
{
public:
    Cuadrito();
    Cuadrito(int iX, int iY, bool iActivo, int direccion);
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
    int getCantidadCambiosHechos();
    void setVarios(int a,int b,int cam,int n);
private:
    int x; //cordenada x
    int y; //cordenada y
    int cantidadCambios;
    int cambiosHechos;
    int coords[20][2];
    int direcciones[20];
    bool activo;
    int cx;//coordenada x del cambio
    int cy;//coordenada cy del cambio
    bool cambio;//para determinar si tiene que hacer cambio de direccion;
    int nuevadir;//la nueva direccion que tiene que adoptar
    int direccion;
};
void Cuadrito::setVarios(int a,int b,int cam, int n){
coords[cam][0]=a;
coords[cam][1]=b;
direcciones[cam]=n;
}
int Cuadrito::getCantidadCambiosHechos(){
return cambiosHechos;
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
Cuadrito::Cuadrito() //constructor default
{
    x=0;
    y=0;
    activo=false;
    direccion=2;
    cambio = false;
    cx=-1;
    cy=-1;
    nuevadir=0;
    cantidadCambios=0;
    cambiosHechos=0;
    for(int i=0;i<20;i++)
        for(int j=0;j<2;j++)
            coords[i][j]=-1;
    for(int i=0;i<20;i++)
        direcciones[i]=0;
}

Cuadrito::Cuadrito(int iX, int iY, bool iActivo, int direccion) //constructor con X y Y
{
    x=iX;
    y=iY;
    activo=iActivo;
    direccion=2;
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
    if((x==cx&&y==cy)&&cambio){

        if(cantidadCambios==cambiosHechos){
        cambio=false;
        cantidadCambios=0;
        cambiosHechos=0;
        cx=-1;
        cy=-1;
        }
        else{
            cx=coords[cambiosHechos][0];
            cy=coords[cambiosHechos][1];
            direccion = direcciones[cambiosHechos];
            cambiosHechos++;
        }

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
void Cuadrito::incrementarCambio(){
cantidadCambios++;
}
#endif // CUADRITO_H_INCLUDED
