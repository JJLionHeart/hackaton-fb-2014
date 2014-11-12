#include <iostream>
using namespace std;

#include "Fecha.h"

int main()
{
    /**Fechas de prueba*/
    Fecha f1(30,4,2012), f2(30,5,2012), f3(28,2,2011), f4(28, 2, 2012), f5(31, 10, 2012), f6(31, 12, 2012), f7(30,4,2012);

    /**Fechas cambiadas*/
    Fecha f11(1,5,2012), f22(31,5,2012), f33(1,3,2011), f44(29,2,2012), f55(1,11,2012), f66(1,1,2013);

    Fecha aux;

    if(f1 == f7)
        cout<<"Comparacion de == correcta"<<endl;
    else
        cout<<"Comparacion de == incorrecta"<<endl;

    if(f1 >= f7)
        cout<<"Comparacion de >= correcta cuando son iguales"<<endl;
    else
        cout<<"Comparacion de >= incorrecta cuando son iguales"<<endl;

    if(f1 <= f7)
        cout<<"Comparacion de <= correcta cuando son iguales"<<endl;
    else
        cout<<"Comparacion de <= incorrecta cuando son iguales"<<endl;

    aux=f1+1;

    if(aux == f11)
    {   f1.getMuestra();
        cout<< " + 1 correcta. De ";
        f1.getMuestra();
        cout<<" cambia a ";
        f11.getMuestra();
        cout<<endl;
    }
    else
        {f1.getMuestra();
        cout<<" + 1 no cambia correctamente. De" ;
        f1.getMuestra();
        cout<<" a ";
        f11.getMuestra();
        cout<<endl;}

    aux = f2 + 1;
    if(aux == f22){
        f2.getMuestra();
        cout<< " + 1 correcta. De ";
        f2.getMuestra();
        cout<<" cambia a ";
        f22.getMuestra();
        cout<<endl;}
    else
        {f2.getMuestra();
        cout<< " + 1 no cambia correctamente. De ";
        f2.getMuestra();
        cout<<" a ";
        f22.getMuestra();
        cout<<endl;}

    aux = f3 + 1;
    if(aux == f33)
        {f3.getMuestra();
        cout<< " + 1 correcta. De ";
        f3.getMuestra();
        cout<<" cambia a ";
        f33.getMuestra();
        cout<<endl;}
    else
        {f3.getMuestra();
        cout<< " + 1 no cambia correctamente. De ";
        f3.getMuestra();
        cout<<" a ";
        f33.getMuestra();
        cout<<endl;}

    aux = f4 + 1;
    if(aux == f44)
        {f4.getMuestra();
         cout<< " + 1 correcta. De ";
         f4.getMuestra();
         cout<<" cambia a ";
         f44.getMuestra();
         cout<<endl;}
    else
        {f4.getMuestra();
         cout<< " + 1 no cambia correctamente. De ";
         f4.getMuestra();
         cout<<" a ";
         f44.getMuestra();
         cout<<endl;}

    aux = f5 + 1;
    if(aux == f55)
        {f5.getMuestra();
        cout<< " + 1 correcta. De ";
        f5.getMuestra();
        cout<<" cambia a ";
        f55.getMuestra();
        cout<<endl;}
    else
        {f5.getMuestra();
         cout<< " + 1 no cambia correctamente. De ";
         f5.getMuestra();
         cout<<" a ";
         f55.getMuestra();
         cout<<endl;}

    aux = f6 + 1;
    if(aux == f66)
        {f6.getMuestra();
         cout<< " + 1 correcta. De ";
         f6.getMuestra();
         cout<<" cambia a ";
         f66.getMuestra();
         cout<<endl;}
    else
        {f6.getMuestra();
         cout<< " + 1 no cambia correctamente. De ";
         f6.getMuestra();
         cout<<" a ";
         f66.getMuestra();
         cout<<endl;}

    Fecha f9(20,5,2014), f99(25,5,2014);
    aux = f9 + 5;
    if(aux == f99)
        {f9.getMuestra();
         cout<< " + 5 correcta. De ";
         f9.getMuestra();
         cout<<" cambia a ";
         f99.getMuestra();
         cout<<endl;}
    else
        {f9.getMuestra();
         cout<< " + 5 no cambia correctamente. De ";
         f9.getMuestra();
         cout<<" a ";
         f99.getMuestra();
         cout<<endl;}

    Fecha fa(20,5,2014), fb(20,5,2015);
    if (fa < fb)
        {cout<<" < correcta para ";
         fa.getMuestra();
         cout<<" y ";
         fb.getMuestra();
         cout<<endl;}
    else
        {cout<<" < incorrecta para ";
         fa.getMuestra();
         cout<<" y ";
         fb.getMuestra();
         cout<<endl;}

    if (fb > fa)
        {cout<<" > correcta para ";
         fb.getMuestra();
         cout<<" y ";
         fa.getMuestra();
         cout<<endl;}
    else
        {cout<<" > incorrecta para ";
         fb.getMuestra();
         cout<<" y ";
         fa.getMuestra();
         cout<<endl;}

    if (fa <= fb)
        {cout<<" <= correcta para ";
         fa.getMuestra();
         cout<<" y ";
         fb.getMuestra();
         cout<<endl;}
    else
        {cout<<" <= incorrecta para ";
         fa.getMuestra();
         cout<<" y ";
         fb.getMuestra();
         cout<<endl;}

    if (fb >= fa)
        {cout<<" >= correcta para ";
         fb.getMuestra();
         cout<<" y ";
         fa.getMuestra();
         cout<<endl;}
    else
        {cout<<" >= incorrecta para ";
         fb.getMuestra();
         cout<<" y ";
         fa.getMuestra();
         cout<<endl;}

    Fecha fc(20,2,2015), fd(20,5,2015);
    if (fc < fd)
        {cout<<" < correcta para ";
         fc.getMuestra();
         cout<<" y ";
         fd.getMuestra();
         cout<<endl;}
    else
        {cout<<" < incorrecta para ";
         fc.getMuestra();
         cout<<" y ";
         fd.getMuestra();
         cout<<endl;}

    if (fd > fc)
        {cout<<" > correcta para ";
         fd.getMuestra();
         cout<<" y ";
         fc.getMuestra();
         cout<<endl;}
    else
        {cout<<" > incorrecta para ";
         fd.getMuestra();
         cout<<" y ";
         fc.getMuestra();
         cout<<endl;}

    if (fc <= fd)
        {cout<<" <= correcta para ";
         fc.getMuestra();
         cout<<" y ";
         fd.getMuestra();
         cout<<endl;}
    else
        {cout<<" <= incorrecta para ";
         fc.getMuestra();
         cout<<" y ";
         fd.getMuestra();
         cout<<endl;}

    if (fd >= fc)
        {cout<<" >= correcta para ";
         fd.getMuestra();
         cout<<" y ";
         fc.getMuestra();
         cout<<endl;}
    else
        {cout<<" >= incorrecta para ";
         fd.getMuestra();
         cout<<" y ";
         fc.getMuestra();
         cout<<endl;}

    Fecha fe(12,5,2015), ff(20,5,2015);
    if (fe < ff)
        {cout<<" < correcta para ";
         fe.getMuestra();
         cout<<" y ";
         ff.getMuestra();
         cout<<endl;}
    else
        {cout<<" < incorrecta para ";
         fe.getMuestra();
         cout<<" y ";
         ff.getMuestra();
         cout<<endl;}

    if (ff > fe)
        {cout<<" > correcta para ";
         ff.getMuestra();
         cout<<" y ";
         fe.getMuestra();
         cout<<endl;}
    else
        {cout<<" > incorrecta para ";
         ff.getMuestra();
         cout<<" y ";
         fe.getMuestra();
         cout<<endl;}

    if (fe <= ff)
        {cout<<" <= correcta para ";
         fe.getMuestra();
         cout<<" y ";
         ff.getMuestra();
         cout<<endl;}
    else
        {cout<<" <= incorrecta para ";
         fe.getMuestra();
         cout<<" y ";
         ff.getMuestra();
         cout<<endl;}

    if (ff >= fe)
        {cout<<" >= correcta para ";
         ff.getMuestra();
         cout<<" y ";
         fe.getMuestra();
         cout<<endl;}
    else
        {cout<<" >= incorrecta para ";
         ff.getMuestra();
         cout<<" y ";
         fe.getMuestra();
         cout<<endl;}

    return 0;
}
