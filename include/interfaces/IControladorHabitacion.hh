#ifndef ICONTROLADORHABITACION
#define ICONTROLADORHABITACION

#include <list>
#include <string>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/DTHabitacion.hh"
#include "../cabezales/DTFecha.hh"
 

using namespace std;

class IControladorHabitacion {
    public:
        virtual void seleccionarHabitacion(string, int) = 0;
        virtual list<DTHabitacion> obtenerHabitacionesDisponiblesHostal(string,DTFecha,DTFecha) = 0;
        //Lo que antes era AltaHabitacion
        virtual void ingresarDatosHabitacion(int,float,int) = 0;
        virtual void confirmarAltaHabitacion() = 0;
        virtual void cancelarAltaHabitacion() = 0;
        virtual void ingresarHostalHabitacion(string) = 0;
       
        virtual void LiberarMemoria() = 0;
};

#endif