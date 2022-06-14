#ifndef ICONTROLADORHOSTAL
#define ICONTROLADORHOSTAL

#include <list>

/*DEJO HECHA SOLO ESTA INTERFAZ PORQUE EN EL LAB3 NOS OLVIDAMOS 
DE HACERLAS Y NO SE CUANTAS VAMOS A PRECISAR. USEN ESTA DE EJEMPLO
PARA CREAR LAS OTRAS*/

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES
//EN LAS INTERFACES NO SE HACE INCLUDE DE CLASES, SOLO DATA TYPES

#include "../cabezales/DTHostal.hh"
#include "../cabezales/DTHabitacion.hh"
#include "../cabezales/DTReserva.hh"
#include "../cabezales/DTInfoHostal.hh"
#include "../cabezales/DTInfoBasicaHostal.hh"
#include "../cabezales/DTInfoHostalYCalificacion.hh"

using namespace std;

class IControladorHostal {
    public:
        virtual list<DTHostal> obtenerTodosHostales() = 0;
        virtual list<DTHostal> obtenerTop3Hostales() = 0;
        virtual DTInfoBasicaHostal obtenerInfoBasicaHostal() = 0;
        virtual list<DTHabitacion> obtenerHabitacionesHostal() = 0;
        virtual void seleccionarHostal(string) = 0;
        virtual DTInfoHostal verDetalles() = 0;
        virtual void confirmarConsulta() = 0;
        virtual list<DTInfoHostalYCalificacion> obtenerTodosHostalesYPromCalificacion() = 0;
};

#endif