#ifndef ICONTROLADORNOTIFICACIONES
#define ICONTROLADORNOTIFICACIONES

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */


#include "../cabezales/DTNotificacion.hh"

using namespace std;

class IControladorNotificaciones {
    public:
        virtual void subscribirEmpleado(string) = 0;
        virtual void eliminarNotificaciones() = 0;
        virtual void eliminarSubscripcion(string) = 0;
};

#endif