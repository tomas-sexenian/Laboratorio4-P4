#ifndef HUESPEDCONTROLLER
#define HUESPEDCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Huesped.hh"
#include "../cabezales/DTHuesped.hh"
#include "../cabezales/DTEstadia.hh"


using namespace std;

class HuespedController{
    private:
        static HuespedController * instancia;
        HuespedController();
        map<string,Huesped *> Huesped;
    public:
		static HuespedController* getInstancia();
	    ~HuespedController();

        void ingresarEmailHuesped(string);
        bool obtenerEsFinger();
        list<DTHuesped> obtenerTodosHuespedes();
        list<DTEstadia> obtenerEstadiasFinalizadasHuesped();
        void seleccionarHuesped(string);
};
#endif