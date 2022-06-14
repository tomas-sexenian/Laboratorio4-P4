#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include "./Reserva.hh"

class ReservaIndividual: public Reserva {
    private:
    public:
        ReservaIndividual();
        ReservaIndividual(int, string, DTFecha, DTFecha, EstadoReserva, Habitacion*);
        ~ReservaIndividual();
        float calcularCosto();
};

#endif

