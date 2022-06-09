#ifndef ICONTROLADORESTADIA
#define ICONTROLADORESTADIA

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/DTFecha.hh"
#include "../cabezales/DTInfoEstadia.hh"

using namespace std;

class IControladorEstadia {
    public:
        virtual void seleccionarEstadia(int) = 0;
        virtual DTInfoEstadia obtenerEstadia(int) = 0;
        virtual void finalizarEstadia(int) = 0;
        virtual void registrarCheckOut(int,DTFecha) = 0;
        virtual void confirmarFinEstadia() = 0;
};

#endif