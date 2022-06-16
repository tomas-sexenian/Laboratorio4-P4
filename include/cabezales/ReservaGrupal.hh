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
        map<string, Huesped*> invitados;
    public:
        ReservaGrupal();
        ReservaGrupal(int, Huesped*, DTFecha, DTFecha, EstadoReserva, Habitacion*, map<string, Huesped*>);
        ~ReservaGrupal();
        int getCantHuespedes();
        float calcularCosto();
        map<string, Huesped*> getInvitados();
        void setInvitado(Huesped*);
};

#endif
