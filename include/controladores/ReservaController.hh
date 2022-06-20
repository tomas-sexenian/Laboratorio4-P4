#ifndef RESERVACONTROLLER
#define RESERVACONTROLLER

#include <list>
#include <map>
#include <iostream>
#include <stdexcept>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorReserva.hh"
#include "../cabezales/Reserva.hh"
#include "../cabezales/ReservaIndividual.hh"
#include "../cabezales/ReservaGrupal.hh"
#include "../cabezales/DTReserva.hh"
#include "../cabezales/DTReservaIndividual.hh"
#include "../cabezales/DTReservaGrupal.hh"
#include "../cabezales/DTHuesped.hh"
#include "../cabezales/Estadia.hh"
#include "../../include/TipoReserva.hh"
#include "../controladores/HostalController.hh"
#include "../controladores/UsuarioController.hh"
#include "../controladores/EstadiaController.hh"

using namespace std;

class ReservaController : public IControladorReserva {
    private:
        static ReservaController * instancia;
        ReservaController();
        map<int,ReservaIndividual*> ReservasIndividuales;
        map<int,ReservaGrupal*> ReservasGrupales;
        ReservaIndividual* reservaIndividualSeleccionada;
        ReservaGrupal* reservaGrupalSeleccionada;

        int codigo;
        string email;
        DTFecha checkIn, checkOut;
        EstadoReserva estado;
        TipoReserva tipo;
        Habitacion* habitacion;
        list<int> cantHuespedes;
        map<string, Huesped*> invitados;
        Hostal* hostal;
        Huesped* huesped;
        list<Huesped*> listaInvitados;
        ReservaIndividual* resIndividual;
        ReservaGrupal* resGrupal;
        DTFecha entradaEstadia;
        string promo;
    public:
		static ReservaController* getInstancia();
	    ~ReservaController();
        map<int,ReservaIndividual*> getReservasIndividuales();
        map<int,ReservaGrupal*> getReservasGrupales();

        DTReservaIndividual obtenerReservaIndividual();
        DTReservaGrupal obtenerReservaGrupal();
        void seleccionarReservaIndividual(int);
        void seleccionarReservaGrupal(int);
        list<DTReserva> getListaReservasNoCanceladasHuesped(string);
        void confirmarConsulta();
        void ingresarDatosReservaIndividual(int, string, DTFecha, DTFecha, EstadoReserva, TipoReserva, Habitacion*);
        void ingresarDatosReservaGrupal(int, string, DTFecha, DTFecha, EstadoReserva, TipoReserva, Habitacion*, list<int>);
        void ingresarDatosReserva(int,DTFecha,DTFecha,EstadoReserva);
        void agregarHuespedesReservaGrupal(map<string, Huesped*>);
        void confirmarReserva();
        void cancelarReserva(int);
        Reserva* obtenerReserva(int);
        list<DTReserva*> obtenerReservasHostal(string);
        
        void seleccionarHostal(string);
        void seleccionarHabitacion(int);
        void seleccionarTipo(TipoReserva);
        void ingresarHuesped(string);
        void ingresarInvitados(list<string>);
};

#endif