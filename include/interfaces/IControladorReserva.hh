#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include <list>
#include <map>

#include "../cabezales/DTReserva.hh"
#include "../cabezales/DTReservaIndividual.hh"
#include "../cabezales/DTReservaGrupal.hh"
#include "../cabezales/Habitacion.hh"
#include "../cabezales/DTFecha.hh"
#include "../TipoReserva.hh"
#include "../EstadoReserva.hh"
#include "../cabezales/Huesped.hh"

class Huesped;
class Habitacion;

using namespace std;

class IControladorReserva {
    public:
        virtual DTReservaIndividual obtenerReservaIndividual() = 0;
        virtual DTReservaGrupal obtenerReservaGrupal() = 0;
        virtual void seleccionarReservaIndividual(int) = 0;
        virtual void seleccionarReservaGrupal(int) = 0;
        virtual Reserva* obtenerReserva(int) = 0;
        virtual list<DTReserva*> getListaReservasNoCanceladasHuesped(string) = 0;
        virtual void confirmarConsulta() = 0;
        virtual void ingresarDatosReservaIndividual(int, string, DTFecha, DTFecha, EstadoReserva, TipoReserva, Habitacion*) = 0;
        virtual void ingresarDatosReservaGrupal(int, string, DTFecha, DTFecha, EstadoReserva, TipoReserva, Habitacion*, list<int>) = 0;
        virtual void ingresarDatosReserva(int,DTFecha,DTFecha,EstadoReserva) = 0;
        virtual void agregarHuespedesReservaGrupal(map<string, Huesped*>) = 0;
        virtual void confirmarReserva(bool) = 0;
        virtual void cancelarReserva(int) = 0;
        virtual list<DTReserva*> obtenerReservasHostal(string) = 0;
        
        virtual void seleccionarHostal(string) = 0;
        virtual void seleccionarHabitacion(int) = 0;
        virtual void seleccionarTipo(TipoReserva) = 0;
        virtual void ingresarHuesped(string) = 0;
        virtual void ingresarInvitados(list<string>) = 0;

        virtual void LiberarMemoria() = 0;

}; 

#endif
