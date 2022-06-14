#ifndef ESTADIACONTROLLER
#define ESTADIACONTROLLER

#include <list>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorEstadia.hh"
#include "../cabezales/Estadia.hh"
#include "../cabezales/DTEstadia.hh"
#include "../cabezales/DTInfoEstadia.hh"
#include "../cabezales/DTFecha.hh"
#include "../controladores/SistemaController.hh"


using namespace std;

class EstadiaController : public IControladorEstadia {
    private:
        static EstadiaController * instancia;
        EstadiaController();
        map<int,Estadia*> Estadias;

        int codigoReserva;
        string emailHuesped;
        DTFecha entrada, salida;
        string promo;
        Estadia* estadiaSeleccionada;
    public:
		static EstadiaController* getInstancia();
	    ~EstadiaController();
        map<int,Estadia*> getEstadias();
        void setEstadia();

        void seleccionarEstadia(int,string);
        DTInfoEstadia obtenerEstadia();
        Estadia* finalizarEstadia();
        void confirmarFinEstadia();
        list<DTEstadia> obtenerTodasEstadiasHostal(string);
};
#endif