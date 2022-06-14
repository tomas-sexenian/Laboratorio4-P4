#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

#include "./Reserva.hh"
#include "./Huesped.hh"

#include <list>
#include <string>
#include <map>

using namespace std;

class ReservaGrupal: public Reserva {
    private: 
        list<int> cantHuespedes;
        map<string, Huesped*> invitados;
    public:
        ReservaGrupal();
        ReservaGrupal(int, string, DTFecha, DTFecha, EstadoReserva, Habitacion*, list<int>, map<string, Huesped*>);
        ~ReservaGrupal();
        list<int> getCantHuespedes();
        void setCantHuespedes(int);
        float calcularCosto();
        map<string, Huesped*> getInvitados();
        void setInvitado(Huesped*);
};

#endif
