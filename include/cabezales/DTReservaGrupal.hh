#ifndef DTRESERVAGRUPAL
#define DTRESERVAGRUPAL

#include <list>

#include "./DTReserva.hh"
#include "./DTHuesped.hh"

class DTReservaGrupal: public DTReserva {
    private: 
        list<DTHuesped> invitados;
    public:
        DTReservaGrupal();
        DTReservaGrupal(int,string,DTFecha,DTFecha,EstadoReserva,float,int,list<DTHuesped>);
        ~DTReservaGrupal();
        list<DTHuesped> getInvitados();
};

#endif
