#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL

#include "../include/cabezales/DTReserva.hh"

class DTReservaIndividual: public DTReserva {
    private:

    public:
        DTReservaIndividual();
        DTReservaIndividual(int,string,DTFecha,DTFecha,EstadoReserva,float,int);
        ~DTReservaIndividual();
};

#endif
