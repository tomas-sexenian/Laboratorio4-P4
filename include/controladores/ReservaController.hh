#ifndef RESERVACONTROLLER
#define RESERVACONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorReserva.hh"
#include "../cabezales/Reserva.hh"
#include "../cabezales/ReservaIndividual.hh"
#include "../cabezales/ReservaGrupal.hh"
#include "../cabezales/DTReserva.hh"
#include "../cabezales/DTHuesped.hh"
#include "../../include/TipoReserva.hh"

using namespace std;

class ReservaController : public IControladorReserva {
    private:
        static ReservaController * instancia;
        ReservaController();
        map<int,Reserva*> Reservas;

        int codigo;
        DTFecha checkIn, checkOut;
        EstadoReserva estado;
        TipoReserva tipo;
    public:
		static ReservaController* getInstancia();
	    ~ReservaController();
        map<int,Reserva*> getReservas();
        void setReserva();

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