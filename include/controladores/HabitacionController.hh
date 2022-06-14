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
#include "../controladores/HostalController.hh"

using namespace std;

class HabitacionController{
    private:
        static HabitacionController * instancia;
        HabitacionController();
        map<int,Habitacion *> Habitaciones;
        Habitacion *habitacionSeleccionada;

        //Memoria
        int numero,precio,capacidad;
        Hostal* hostal;
    public:
		static HabitacionController* getInstancia();
	    ~HabitacionController();
        map<int,Habitacion *> getHabitaciones();

        void seleccionarHabitacion(int);
        list<DTHabitacion> obtenerHabitacionesDisponiblesHostal(string,DTFecha,DTFecha);
        //Lo que antes era AltaHabitacion
        void ingresarDatosHabitacion(int,float,int);
        void confirmarAltaHabitacion();
        void cancelarAltaHabitacion();
        void ingresarHostalHabitacion(string);
};
#endif