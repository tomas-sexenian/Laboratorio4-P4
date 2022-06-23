#ifndef ICONTROLADORNOTIFICACIONES
#define ICONTROLADORNOTIFICACIONES

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */


#include "../cabezales/DTNotificacion.hh"
#include "../cabezales/notificacion.hh"
#include "../cabezales/calificacion.hh"

 class Calificacion;
 
using namespace std;

class IControladorNotificaciones {
    public:
        virtual Notificacion* confirmarNotificacion(int,string, Calificacion*) = 0;
        virtual void LiberarMemoria() = 0;
        virtual list<DTNotificacion> ObtenerNotificacionesEmpleado(string) = 0;
        virtual void eliminarNotificaciones(string) = 0;
};


#endif