#ifndef ESTADIACONTROLLER
#define ESTADIACONTROLLER

#include <list>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorEstadia.hh"
#include "../cabezales/Estadia.hh"
#include "../cabezales/DTInfoEstadia.hh"
#include "../cabezales/DTFecha.hh"


using namespace std;

class EstadiaController : public IControladorEstadia {
    private:
        static EstadiaController * instancia;
        EstadiaController();
        list<Estadia*> Estadias;
    public:
		static EstadiaController* getInstancia();
	    ~EstadiaController();

        void seleccionarEstadia(int);
        DTInfoEstadia obtenerEstadia(int);
        void finalizarEstadia(int);
        void registrarCheckOut(int,DTFecha);
        void confirmarFinEstadia();
};
#endif