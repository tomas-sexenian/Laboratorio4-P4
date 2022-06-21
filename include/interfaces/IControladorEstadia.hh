#ifndef ICONTROLADORESTADIA
#define ICONTROLADORESTADIA

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/DTInfoEstadia.hh"
#include "../cabezales/Estadia.hh"
#include "../TipoReserva.hh"
#include "../cabezales/DTEstadia.hh"

using namespace std;

class IControladorEstadia {
    public:
       virtual void seleccionarEstadia(int,string) = 0;
       virtual DTInfoEstadia obtenerInfoEstadia() = 0;
       virtual Estadia* obtenerEstadia(int, string) = 0;
       virtual Estadia* finalizarEstadia() = 0;
       virtual void confirmarFinEstadia() = 0;
       virtual list<DTEstadia*> obtenerTodasEstadiasHostal(string) = 0;

    virtual void seleccionarTipo(TipoReserva) = 0;
    virtual void seleccionarReserva(int) = 0;
    virtual void ingresarHuesped(string) = 0;
    virtual void ingresarInvitados(list<string>) = 0;
    virtual void ingresarEntradaEstadia(int,int,int,int,int) = 0;
    virtual void confirmarAltaEstadia(bool) = 0;

    virtual void LiberarMemoria() = 0;
};

#endif