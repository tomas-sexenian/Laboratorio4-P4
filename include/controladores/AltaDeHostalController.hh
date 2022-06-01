#ifndef ALTADEHOSTALCONTROLLER
#define ALTADEHOSTALCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Hostal.hh"

using namespace std;

class AltaDeHostalController{
    private:
        static AltaDeHostalController * instancia;
        AltaDeHostalController();
    public:
		static AltaDeHostalController* getInstancia();
	    ~AltaDeHostalController();

        void ingresarDatosHabitacion(int,float,int);
        void confirmarAltaHabitacion();
        void cancelarAltaHabitacion();
};
#endif