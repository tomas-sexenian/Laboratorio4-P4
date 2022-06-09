#ifndef RESERVACONTROLLER
#define RESERVACONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorReserva.hh"
#include "../cabezales/Reserva.hh"
#include "../cabezales/DTReserva.hh"
#include "../cabezales/DTHuesped.hh"

using namespace std;

class ReservaController : public IControladorReserva {
    private:
        static ReservaController * instancia;
        ReservaController();
        map<int,Reserva*> Reservas;
    public:
		static ReservaController* getInstancia();
	    ~ReservaController();

        DTReserva obtenerReserva(int);
        void seleccionarReserva(int);
        list<DTReserva> getListaReservasNoCanceladasHuesped(string);
        void confirmarAltaEstadia();
        void confirmarConsulta();
        void ingresarDatosReserva(DTReserva);
        void agregarHuespedesReserva(list<DTHuesped>);
        void confirmarReserva();
        void cancelarReserva();
        list<DTReserva> obtenerReservasHostal(string);
        void cancelarBajaReserva();
        void liberarReserva();
        
};

#endif