#ifndef DTRESERVAGRUPAL
#define DTRESERVAGRUPAL

#include <list>

#include "./DTReserva.hh"
#include "./DTHuesped.hh"

class DTReservaGrupal: public DTReserva {
    private: 
        list<DTHuesped> invitados;
        list<int> cantHuespedes;
    public:
        DTReservaGrupal();
        DTReservaGrupal(int,string,DTFecha,DTFecha,EstadoReserva,float,int,list<DTHuesped>,list<int>);
        ~DTReservaGrupal();
        list<DTHuesped> getInvitados();
        list<int> getCantHuespedes();
};

#endif
