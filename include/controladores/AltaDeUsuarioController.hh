#ifndef ALTADEUSUARIOCONTROLLER
#define ALTADEUSUARIOCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Usuario.hh"
#include "../cabezales/Empleado.hh"
#include "../cabezales/Huesped.hh"

using namespace std;

class AltaDeUsuarioController{
    private:
        static AltaDeUsuarioController * instancia;
        AltaDeUsuarioController();
    public:
		static AltaDeUsuarioController* getInstancia();
	    ~AltaDeUsuarioController();

        void ingresarDatosUsuario(string,string,string);
        void ingresarCargo(TipoCargo);
        void ingresarEsFinger(bool);
        void ingresarNuevoEmail(string);
        void confirmarAltaUsuario();
        void cancelarAltaUsuario();
};
#endif