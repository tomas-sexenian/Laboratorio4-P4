#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include <list>
#include <map>

#include "../cabezales/DTReserva.hh"
#include "../cabezales/Habitacion.hh"
#include "../cabezales/DTFecha.hh"
#include "../TipoReserva.hh"
#include "../EstadoReserva.hh"



using namespace std;

class IControladorReserva {
    public:
        virtual DTReserva obtenerReservaIndividual() = 0;
        virtual DTReserva obtenerReservaGrupal() = 0;
        virtual void seleccionarReservaIndividual(int) = 0;
        virtual void seleccionarReservaGrupal(int) = 0;
        virtual list<DTReserva> getListaReservasNoCanceladasHuesped(string) = 0;
        virtual void confirmarConsulta() = 0;
        virtual void ingresarDatosReservaIndividual(int, string, DTFecha, DTFecha, EstadoReserva, TipoReserva, Habitacion*) = 0;
        virtual void ingresarDatosReservaGrupal(int, string, DTFecha, DTFecha, EstadoReserva, TipoReserva, Habitacion*, list<int>) = 0;
        virtual void ingresarDatosReserva(int,DTFecha,DTFecha,EstadoReserva) = 0;
        virtual void agregarHuespedesReservaGrupal(map<string, Huesped*>) = 0;
        virtual void confirmarReserva() = 0;
        virtual void cancelarReserva(int) = 0;
        virtual list<DTReserva> obtenerReservasHostal(string) = 0;
        virtual void liberarReservaIndividualSeleccionada() = 0;
        virtual void liberarReservaGrupalSeleccionada() = 0;
        
        virtual void seleccionarHostal(string) = 0;
        virtual void seleccionarHabitacion(int) = 0;
        virtual void seleccionarTipo(TipoReserva) = 0;
        virtual void ingresarHuesped(string) = 0;
        virtual void ingresarInvitados(list<string>) = 0;
        virtual void ingresarPromo(string) = 0;

        virtual void ingresarEntradaEstadia(int,int,int,int,int) = 0;
        virtual void confirmarAltaEstadia() = 0;

        virtual void ingresarEntradaEstadia(DTFecha) = 0;
}; 

#endif
