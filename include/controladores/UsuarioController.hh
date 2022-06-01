#ifndef USUARIOCONTROLLER
#define USUARIOCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Usuario.hh"
#include "../cabezales/Empleado.hh"
#include "../cabezales/DTUsuario.hh"
#include "../cabezales/DTInfoUsuario.hh"
#include "../cabezales/DTFecha.hh"

using namespace std;

class UsuarioController{
    private:
        static UsuarioController * instancia;
        UsuarioController();
        map<int,Usuario *> Usuario;
    public:
		static UsuarioController* getInstancia();
	    ~UsuarioController();

        DTInfoUsuario seleccionarUsuario(string);
        void confirmarConsulta();
        void ingresarFecha(DTFecha);
        void actualizarFecha(DTFecha);
        void ingresarEmpleado(Empleado);
};
#endif