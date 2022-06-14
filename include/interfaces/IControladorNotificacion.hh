#ifndef ICONTROLADORNOTIFICACION
#define ICONTROLADORNOTIFICACION

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/Empleado.hh"

using namespace std;

class IControladorNotificacion {
    public:

        virtual void subscribirEmpleado(string) = 0;
        virtual void eliminarNotificaciones() = 0;
        virtual void eliminarSubscripcion(string) = 0;

        virtual ~IControladorNotificacion() {};

};


#endif
