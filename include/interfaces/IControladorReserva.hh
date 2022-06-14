#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include <list>

#include "../cabezales/DTHuesped.hh"
#include "../cabezales/DTReserva.hh"

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
        virtual void agregarHuespedesReservaGrupal(map<string, Huesped*>) = 0;
        virtual void confirmarReserva() = 0;
        virtual void cancelarReserva() = 0;
        virtual list<DTReserva> obtenerReservasHostal(string) = 0;
        virtual void liberarReservaIndividualSeleccionada() = 0;
        virtual void liberarReservaGrupalSeleccionada() = 0;
};

#endif