#ifndef HABITACIONCONTROLLER
#define HABITACIONCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Habitacion.hh"
#include "../cabezales/DTHabitacion.hh"
#include "../cabezales/DTFecha.hh"

using namespace std;

class HabitacionController{
    private:
        static HabitacionController * instancia;
        HabitacionController();
        Habitacion* habitacionIniciar;
        map<int,Habitacion *> Habitaciones;

        int numero,precio,capacidad;
    public:
		static HabitacionController* getInstancia();
	    ~HabitacionController();
        map<int,Habitacion *> getHabitaciones();
        void setHabitacion();

        list<DTHabitacion> obtenerHabitacionesDisponiblesHostal(string,DTFecha,DTFecha);
        void seleccionarHabitacion(int);

        map<int,Habitacion*> getHabitaciones();

        void ingresarDatosHabitacion(Habitacion*);
        void confirmarAltaHabitacion();
        void cancelarAltaHabitacion();
        Habitacion * getHabitacionIniciar();
};
#endif
