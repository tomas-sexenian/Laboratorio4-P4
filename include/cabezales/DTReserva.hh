#ifndef DTRESERVA
#define DTRESERVA

#include <string>

#include "./DTFecha.hh"
#include "../../include/EstadoReserva.hh"

using namespace std;

class DTReserva {
    protected:
        int codigo;
        string nombreHostal;
        DTFecha checkin, checkout;
        EstadoReserva estado;
        float costo;
        int habitacion;
    public:
        virtual ~DTReserva();

        int getCodigo();
        string getNombreHostal();
        DTFecha getCheckin();
        DTFecha getCheckout();
        EstadoReserva getEstado();
        float getCosto();
        int getHabitacion();
};

#endif