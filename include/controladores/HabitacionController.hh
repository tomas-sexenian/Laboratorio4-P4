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
        map<int,Habitacion *> Habitacion;
    public:
		static HabitacionController* getInstancia();
	    ~HabitacionController();

        list<DTHabitacion> obtenerHabitacionesDisponiblesHostal(string,DTFecha,DTFecha);
        void seleccionarHabitacion(int);
};
#endif