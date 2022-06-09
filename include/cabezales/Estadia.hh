#ifndef ESTADIA
#define ESTADIA

#include "./DTFecha.hh"
#include "./Hostal.hh"
#include "./Reserva.hh"
#include "./Calificacion.hh"

#include <string>
#include <list>
#include <map>

using namespace std;

class Estadia{
    private:
        DTFecha entrada, salida;
        string promo;
        list<Observer*> observers;
        Reserva* reserva;
        Hostal* hostal;
        Calificacion* calificacion;

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


        Estadia();
        ~Estadia();
        Estadia(DTFecha,DTFecha,string,list<Observer*>,Reserva*,Hostal*,Calificacion*);

        void agregar(Observer*);
        void eliminar(Observer*);
        void notificar()

};


#endif
