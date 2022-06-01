#ifndef RESERVA
#define RESERVA

#include "./Huesped.hh"
#include "./Habitacion.hh"
#include "./DTFecha.hh"
#include "../../include/EstadoReserva.hh"

#include <string>

using namespace std;

class Reserva{
    protected:
        int codigo;
        DTFecha checkIn;
        DTFecha checkOut;
        EstadoReserva estado;
        Habitacion* habitacion;

    public:
        int getCodigo();
        void setCodigo(int);
        DTFecha getCheckIn();
        void setCheckIn(DTFecha);
        DTFecha getCheckOut();
        void setCheckOut(DTFecha);
        EstadoReserva getEstadoReserva();
        void setEstadoReserva(EstadoReserva);
        Habitacion* getHabitacion();
        void setHabitacion(Habitacion*);

        virtual ~Reserva() = default;
        virtual float calcularCosto() = 0;

};

#endif
