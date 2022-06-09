#ifndef ICONTROLADORRESERVA
#define ICONTROLADORRESERVA

#include <list>

#include "../cabezales/DTHuesped.hh"
#include "../cabezales/DTReserva.hh"

using namespace std;

class IControladorReserva {
    public:
        virtual DTReserva obtenerReserva(int) = 0;
        virtual void seleccionarReserva(int) = 0;
        virtual list<DTReserva> getListaReservasNoCanceladasHuesped(string) = 0;
        virtual void confirmarAltaEstadia() = 0;
        virtual void confirmarConsulta() = 0;
        virtual void ingresarDatosReserva(DTReserva) = 0;
        virtual void agregarHuespedesReserva(list<DTHuesped>) = 0;
        virtual void confirmarReserva() = 0;
        virtual void cancelarReserva() = 0;
        virtual list<DTReserva> obtenerReservasHostal(string) = 0;
        virtual void cancelarBajaReserva() = 0;
        virtual void liberarReserva() = 0;
};

#endif