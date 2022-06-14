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
        string emailTitular;
        DTFecha checkIn;
        DTFecha checkOut;
        EstadoReserva estado;
        Habitacion* habitacion;

    public:
        int getCodigo();
        void setCodigo(int);
        string getEmailTitular();
        void setEmailTitular(string);
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
