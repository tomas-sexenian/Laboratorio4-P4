#ifndef ESTADIA
#define ESTADIA

#include "./DTFecha.hh"
#include "./Hostal.hh"
#include "./Huesped.hh"
#include "./Reserva.hh"
#include "./calificacion.hh"

#include <string>
#include <list>
#include <map>

//Forward declarations
class Calificacion;
class Huesped;
class Hostal;
class Reserva;

using namespace std;

class Estadia{
    private:
        DTFecha entrada, salida;
        string promo;
        Reserva* reserva;
        Hostal* hostal;
        Calificacion* calificacion;
        Huesped* huesped;
        list<string> invitados;
    public:
        DTFecha getEntrada();
        void setEntrada(DTFecha);
        DTFecha getSalida();
        void setSalida(DTFecha);
        Reserva* getReserva();
        void setReserva(Reserva*);
        Hostal* getHostal();
        void setHostal(Hostal*);
        Calificacion* getCalificacion();
        void setCalificacion(Calificacion*);
        string getPromo();
        void setPromo(string);
        Huesped* getHuesped();
        void setHuesped(Huesped*);
        list<string> getInvitados();
        void setInvitados(list<string>);

        Estadia();
        ~Estadia();
        Estadia(DTFecha,DTFecha,string,Reserva*,Hostal*,Calificacion*,Huesped*, list<string>);

};


#endif
