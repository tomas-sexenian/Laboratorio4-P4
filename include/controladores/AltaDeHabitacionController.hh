#ifndef ALTADEHABITACIONCONTROLLER
#define ALTADEHABITACIONCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

using namespace std;

class AltaDeHabitacionController{
    private:
        static AltaDeHabitacionController * instancia;
        AltaDeHabitacionController();
    public:
		static AltaDeHabitacionController* getInstancia();
	    ~AltaDeHabitacionController();

        void ingresarDatosHabitacion(int,float,int);
        void confirmarAltaHabitacion();
        void cancelarAltaHabitacion();
};
#endif