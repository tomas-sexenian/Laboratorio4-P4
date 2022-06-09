#ifndef SISTEMACONTROLLER
#define SISTEMACONTROLLER

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/FechaSistema.hh"
#include "../cabezales/DTFecha.hh"

using namespace std;

class SistemaController{
    private:
        static SistemaController * instancia;
        SistemaController();
    public:
		static SistemaController* getInstancia();
	    ~SistemaController();
        
        void ingresarFecha(DTFecha);
        void actualizarFecha(DTFecha);
        void ModificarFecha(DTFecha);
};
#endif