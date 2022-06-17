#ifndef HUESPED
#define HUESPED

#include "./Usuario.hh"
#include "./Reserva.hh"
#include "./Estadia.hh"
#include <string>
#include <map>
#include <list>

//Forward declarations
class Reserva;
class Estadia;

using namespace std;

class Huesped: public Usuario {
    private:
        bool esFinger;
        map<int, Reserva*> reservas;
        list<Estadia*> estadias;
    public:
        bool getEsFinger();
        void setEsFinger(bool);
        Huesped();
        Huesped(string,string,string,bool,map<int, Reserva*>,list<Estadia*>);
        ~Huesped();
        map<int, Reserva*> getReservas();
        void setReserva(Reserva*);
         list<Estadia*> getEstadias();
        void setEstadia(Estadia*);
};

#endif