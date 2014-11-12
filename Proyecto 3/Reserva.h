#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED
#include "Fecha.h"
class Reserva
{
public:
    Reserva();
    Reserva(int idM, int idC, Fecha f);
    Fecha calculaFechaFinReserva(int incantDias);
    int getIdMaterial();
    int getIdCliente();
    Fecha getFechaReservacion();
    void setIdMaterial(int idM);
    void setIdCliente(int idC);
    void setFechaReservacion(Fecha f);
private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
};

Reserva::Reserva()
{
    Fecha f;
    idMaterial=0;
    idCliente=0;
    fechaReservacion=f;
}


#endif // RESERVA_H_INCLUDED
