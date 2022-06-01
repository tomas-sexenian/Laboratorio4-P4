#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include "./Reserva.hh"

class ReservaIndividual: public Reserva {
    private:
    public:
        ReservaIndividual();
        ReservaIndividual(int, DTFecha, DTFecha, EstadoReserva);
        ~ReservaIndividual() = default;
        float calcularCosto();
};

#endif

