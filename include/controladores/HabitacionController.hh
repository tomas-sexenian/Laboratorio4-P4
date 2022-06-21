#ifndef HABITACIONCONTROLLER
#define HABITACIONCONTROLLER

#include <list>
#include <map>
#include <iostream>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES


#include "../interfaces/IControladorHabitacion.hh"
#include "../cabezales/Habitacion.hh"
#include "../cabezales/DTHabitacion.hh"
#include "../cabezales/DTFecha.hh"
#include "../controladores/HostalController.hh"

using namespace std;

class HabitacionController: public IControladorHabitacion {
    private:
        static HabitacionController * instancia;
        HabitacionController();
        multimap<int,Habitacion *> Habitaciones;
        Habitacion *habitacionSeleccionada;

        //Memoria
        int numero,precio,capacidad;
        Hostal* hostal;
    public:
		static HabitacionController* getInstancia();
	    virtual ~HabitacionController();
        multimap<int,Habitacion *> getHabitaciones();

        void seleccionarHabitacion(string, int);
        list<DTHabitacion> obtenerHabitacionesDisponiblesHostal(string,DTFecha,DTFecha);
        //Lo que antes era AltaHabitacion
        void ingresarDatosHabitacion(int,float,int);
        void confirmarAltaHabitacion(bool);
        void cancelarAltaHabitacion();
        void ingresarHostalHabitacion(string);

        void LiberarMemoria();
};
#endif
