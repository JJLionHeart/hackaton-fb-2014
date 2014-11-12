#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
public:
    Fecha();
    Fecha(int iDia, int iMes, int iAnio);
    int getDia();
    int getMes();
    int getAnio();
    void getMuestra();
    void setFecha(int iDia, int iMes, int iAnio);
    Fecha operator + (int iDias);
    bool operator < (Fecha f);
    bool operator > (Fecha f);
    bool operator <= (Fecha f);
    bool operator >= (Fecha f);
    bool operator == (Fecha f);
    //Fecha operator << (); //incorrecto
    //Fecha operator >>(); //incorrecto
private:
    int iDd;
    int iMm;
    int iAa;
};

Fecha::Fecha()
{
    iDd=0;
    iMm=0;
    iAa=0;
}
Fecha::Fecha(int iDia, int iMes, int iAnio)
{
    iDd=iDia;
    iMm=iMes;
    iAa=iAnio;
}
int Fecha::getDia()
{
    return iDd;
}
int Fecha::getMes()
{
    return iMm;
}
int Fecha::getAnio()
{
    return iAa;
}
void Fecha::setFecha(int iDia, int iMes, int iAnio)
{
    iDd=iDia;
    iMm=iMes;
    iAa=iAnio;
}
Fecha Fecha::operator + (int iDias)
{
    int iDia=iDd+iDias;
    int iMes=iMm;
    int iAnio=iAa;
    bool continuar=1;

    if(iMes==2)
    {
        if((iAnio%4==0&&!(iAnio%100==0))||iAnio%400==0)
        {
            if(iDia>29){
            while(continuar){
            iDia-=29;
            iMes++;
            if(iDia<=29)
            {
                continuar=0;
            }
            }
            continuar=1; // para utilizarlo en el if siguiente
        }
    }
    }
   else if(iMes==4||iMes==6||iMes==9||iMes==11)
   {
            if(iDia>30){
            while(continuar){
            iDia-=30;
            iMes++;
            if(iDia<=30)
            {
                continuar=0;
            }
            }
            continuar=1; //para utilizarlo en el siguiente
        }
   }
   else
   {
             if(iDia>31){
            while(continuar){
            iDia-=31;
            iMes++;
            if(iDia<=31)
            {
                continuar=0;
            }
            }
        }
   }

   if(iMes>12)
   {
       iMes-=12;
       iAnio++;
   }

   Fecha f(iDia,iMes,iAnio);

    return f;

}
bool Fecha::operator < (Fecha f)
{
  if(iAa<f.getAnio())
  {
      return true;
  }
  else if(iMm<f.getMes())
  {
      return true;
  }
  else if(iDd<f.getDia())
  {
      return true;
  }
  else
    return false;
}
bool Fecha::operator > (Fecha f)
{
  if(iAa>f.getAnio())
  {
      return true;
  }
  else if(iMm>f.getMes())
  {
      return true;
  }
  else if(iDd>f.getDia())
  {
      return true;
  }
  else
    return false;
}
bool Fecha::operator <= (Fecha f)
{
if(iAa<f.getAnio())
  {
      return true;
  }
  else if(iMm<f.getMes())
  {
      return true;
  }
  else if(iDd<=f.getDia())
  {
      return true;
  }
  else
    return false;
}
bool Fecha::operator >= (Fecha f)
{
  if(iAa>f.getAnio())
  {
      return true;
  }
  else if(iMm>f.getMes())
  {
      return true;
  }
  else if(iDd>=f.getDia())
  {
      return true;
  }
  else
    return false;
}
bool Fecha::operator == (Fecha f)
{
  if(iAa==f.getAnio())
  {
      return true;
  }
  else if(iMm==f.getMes())
  {
      return true;
  }
  else if(iDd==f.getDia())
  {
      return true;
  }
  else
    return false;
}
/*Fecha Fecha::operator << () //incorrecto
{

}
Fecha Fecha::operator >>() //incorrecto
{

}*/

void Fecha::getMuestra()
{
    cout<<"Dia: "<<iDd<<"Mes: "<<iMm<<"Año: "<<iAa;
}

#endif // FECHA_H_INCLUDED
