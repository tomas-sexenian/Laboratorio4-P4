#ifndef SISTEMACONTROLLER
#define SISTEMACONTROLLER

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES


#include "../interfaces/IControladorSistema.hh"
#include "../cabezales/FechaSistema.hh"
#include "../cabezales/DTFecha.hh"

using namespace std;

class SistemaController: public IControladorSistema{
    private:
        static SistemaController * instancia;
        SistemaController();
        SistemaController(DTFecha);

       
    public:
		static SistemaController* getInstancia();
	    ~SistemaController();
        
        DTFecha obtenerFechaActual();
        void modificarFecha(DTFecha);
};
#endif
