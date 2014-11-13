#ifndef CUADRITO_H_INCLUDED
#define CUADRITO_H_INCLUDED

class Cuadrito
{
public:
    Cuadrito(); //constructo default
    Cuadrito(int iX, int iY, bool iActivo, int direccion); //constructor con variables
    void setX(int iX); // sirve para cambiar la coordenada X
    void setY(int iY); // sirve para cambiar la coordenada y
    void setActivo(bool iActivo); //sirve para cambiar si el cuadrito esta "vivo" o "muerto"
    void setDireccion(int dire); //sirve para  cambiar la direccion a la cual se mueve el cuadrito
    void setCoordCambio(int a,int b); //sirve para establecer en que coordenada va a cambiar el cuadrito a otra direccion
    void setCambio(bool a); //sirve para establecer si se va a cambiar de direccion
    void setNuevaDir(int a); //sirve para establecer la nueva direccion a la que va a cambiar
    //void setC(int ca);
    int getX(); //obtiene la coordenada x
    int getY(); //obtiene la coordenada y
    bool getActivo(); //obtiene si el cuadrito esta activo
    int getDireccion(); //obtiene la dirección del cuadrito
    void Movimiento(); //mueve el cuadrito en la idreccion correspondiente y modifica su direccion en caso de ser necesario
    bool getEstadoCambio(); //obtener si necesita cambiar
    //void getCoordCambios(int &a,int&b);
    void modStack(int a,int b,int ndir); //modifica el stack de cambios del jugador y almacena la informacion del siguiente cambio
    char getC();
    void compStack(); //obtiene el siguiente cambio
private:
    int x; //cordenada x
    int y; //cordenada y
    char c; //<---????
int stacker[1000][3];
    int cantCambios;
    bool activo;
    int cx;//coordenada x del cambio
    int cy;//coordenada cy del cambio
    bool cambio;//para determinar si tiene que hacer cambio de direccion;
    int nuevadir;//la nueva direccion que tiene que adoptar
    int direccion;
};
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
    c=254;
     for(int i=0;i<1000;i++)
        for(int j=0;j<3;j++)
        stacker[i][j]=0;
    cambio = false;
    cx=-1;
    cy=-1;
    nuevadir=0;
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
int Cuadrito::getX() //obtener X
{
    return x;
}

int Cuadrito::getY() //obtener Y
{
    return y;
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
void Cuadrito::modStack(int a,int b,int ndir){
    cambio = true;
if(cantCambios==1000)
{
    cantCambios=0;
    stacker[cantCambios][0]=a;
    stacker[cantCambios][1]=b;
    stacker[cantCambios][2]=ndir;
}
if(cantCambios != 1000){
    stacker[cantCambios][0]=a;
    stacker[cantCambios][1]=b;
    stacker[cantCambios][2]=ndir;
    cantCambios++;
}/*else{
    cantCambios=0;
    stacker[cantCambios][0]=a;
    stacker[cantCambios][1]=b;
    stacker[cantCambios][2]=ndir;
}*/
    }
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












#endif // CUADRITO_H_INCLUDED
