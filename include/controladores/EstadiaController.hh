#ifndef ESTADIACONTROLLER
#define ESTADIACONTROLLER

#include <list>


//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorEstadia.hh"
#include "../cabezales/Estadia.hh"
#include "../cabezales/Reserva.hh"
#include "../cabezales/Huesped.hh"
#include "../cabezales/Hostal.hh"
#include "../cabezales/calificacion.hh"
#include "../cabezales/DTEstadia.hh"
#include "../cabezales/DTInfoEstadia.hh"
#include "../cabezales/DTFecha.hh"
#include "../TipoReserva.hh"
#include "../controladores/SistemaController.hh"
#include "../controladores/ReservaController.hh"
#include "../controladores/UsuarioController.hh"


using namespace std;

class EstadiaController : public IControladorEstadia {
    private:
        static EstadiaController * instancia;
        EstadiaController();
        map<int,Estadia*> Estadias;
        Estadia* estadiaSeleccionada;
        string promo;
        int codigoReserva;
        string emailHuesped;
        
        //Memoria alta
        Reserva* reservaSeleccionada;
        Huesped* huesped;
        TipoReserva tipoReserva;
        list<string> invitados;
        DTFecha entrada, salida;
    public:
		static EstadiaController* getInstancia();
	    ~EstadiaController();
        map<int,Estadia*> getEstadias();

        void seleccionarEstadia(int,string);
        DTInfoEstadia obtenerEstadia();
        Estadia* finalizarEstadia();
        void confirmarFinEstadia();
        list<DTEstadia> obtenerTodasEstadiasHostal(string);

        void seleccionarReserva(int);
        void seleccionarTipo(TipoReserva);
        void ingresarHuesped(string);
        void ingresarInvitados(list<string>);
        void ingresarEntradaEstadia(int,int,int,int,int);
        void confirmarAltaEstadia();
};
#endif