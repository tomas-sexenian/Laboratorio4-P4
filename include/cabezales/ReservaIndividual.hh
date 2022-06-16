#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include "./Reserva.hh"

class ReservaIndividual: public Reserva {
    private:
    public:
        ReservaIndividual();
        ReservaIndividual(int, Huesped*, DTFecha, DTFecha, EstadoReserva, Habitacion*);
        ~ReservaIndividual();
        float calcularCosto();
};

#endif

