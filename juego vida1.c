#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
unsigned char field[25][80];//array principal
unsigned char salva[25][80];//array de salvamento que evita problemas al momento de asignar al array principal
unsigned char c = 254;
int tablero(int y, int x)//funcioon encargada de preparar el tablero
//el tablero en msdos consiste en 25 filas con espacio para 80 caracteres cada una
//se crea un "cuadro de busqueda" para cada posicion donde x1,y1 pertenece a la primera esquina de ese cuadro
//y x2,y2 pertenece a la ultima esquina del cuadro (inferior derecha)
{
     int x1,y1,x2,y2,i,j,contador=0;
     switch(x)
     {
              case 0://para evitar desbordar el array del tablero, no podemos analizar la posicion -1
                   x1=0;
                   x2=x+1;
                   break;
              case 79://algo parecido, ya que la posicion 80 no existe y por lo tanto se analiza solo hasta la posicion 79 
                   x1=x-1;
                   x2=79;
                   break;
              default://si no pasa nada, se crea el cuadro de busqueda normalito
                   x1=x-1;
                   x2=x+1;
                   break;
                   }
     switch(y)//todo similar a el x
     {
              case 0:
                   y1=0;
                   y2=y+1;
                   break;
              case 25:
                   y1=y-1;
                   y2=25;
                   break;
              default:
                      y1=y-1;
                      y2=y+1;
                      break;
                      }
for(i=y1;i<=y2;i++)//un grupo de boucles que analiza el cuadro de busqueda y va contando las casillas activas
{
for(j=x1;j<=x2;j++)
{
if(!(i==y && j==x))//para evitar que se cuente el cuadro actual
{
          if(field[i][j]==c)
          contador++;
          }
}                 
}

if(contador<2 || contador >3)//primera regla del juego de la vida, si una casilla tiene alrededor menos de 2 o mas de 3 casillas la casilla muere
salva[y][x]=32;
else if(contador == 3 && field[y][x] == 32)//si hay 3 casillas activas alrededor y la casilla esta muerta, esta vuelve a la vida
salva[y][x]=c;
else if((contador== 2 || contador == 3)&& field[y][x]==c)//en cualquier otro caso la celda queda viva
salva[y][x] = c;
//printf("la posición %d,%d tiene el caracter %d:%c, y se contaron %d\n",y,x,salva[y][x],salva[y][x],contador);
return contador;//esto era para depurar y saber cuantas casillas había a un lado
              }
     

int main(){
    memset(field,32,sizeof(field));//para poner en blanco el array del archivo
    memset(salva,32,sizeof(salva));//para poner en blanco el array de salvamento
    int i,j,contador;
    field[2][24]=c;//aqui se pone el patron
    field[3][24]=c;
    field[3][22]=c;
    field[4][12]=c;
    field[4][13]=c;
    field[4][20]=c;
    field[4][21]=c;
    field[4][34]=c;
    field[4][35]=c;
    field[5][11]=c;
    field[5][15]=c;
    field[5][20]=c;
    field[5][21]=c;
    field[5][34]=c;
    field[5][35]=c;
    field[6][0]=c;
    field[6][1]=c;
    field[6][10]=c;
    field[6][16]=c;
    field[6][20]=c;
    field[6][21]=c;
    field[7][0]=c;
    field[7][1]=c;
    field[7][10]=c;
    field[7][14]=c;
    field[7][16]=c;
    field[7][17]=c;
    field[7][22]=c;
    field[7][24]=c;
    field[8][10]=c;
    field[8][16]=c;
    field[8][24]=c;
    field[9][11]=c;
    field[9][15]=c;
    field[10][12]=c;
    field[10][13]=c;
    printf("%s\n",field);//se imprime el patron especial
    system("pause");
    system("cls");
    //field[1][1]=c;
    while(true)
    {
    for(i=0;i<25;i++)
    {
    for(j=0;j<80;j++)
    {
    tablero(i,j);
    //Sleep(10);
    }
    }
    
    for(i=0;i<25;i++)
{
for(j=0;j<80;j++)//lo que se asigno a salva se reasigna a field
{
field[i][j]=salva[i][j];


}
}
    
    
    system("cls");//limpia la pantalla de msdos
    field[24][79]='\r';//para evitar un salto de linea 
    printf("%s",field);//imprime el nuevo patron
    Sleep(100);//congela todo 100 ms
}
    system("pause");//esto no se ejecuta
    return 0;
}
