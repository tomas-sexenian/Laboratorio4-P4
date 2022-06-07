#ifndef ESTADIACONTROLLER
#define ESTADIACONTROLLER

#include <list>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Estadia.hh"
#include "../cabezales/DTInfoEstadia.hh"
#include "../cabezales/DTFecha.hh"


using namespace std;

class EstadiaController{
    private:
        static EstadiaController * instancia;
        EstadiaController();
        list<Estadia*> Estadias;

        DTFecha entrada, salida;
        string promo;
    public:
		static EstadiaController* getInstancia();
	    ~EstadiaController();
        list<Estadia*> getEstadias();
        void setEstadia();

        void seleccionarEstadia(int);
        DTInfoEstadia obtenerEstadia(int);
        void finalizarEstadia(int);
        void registrarCheckOut(int,DTFecha);
        void confirmarFinEstadia();
};
#endif