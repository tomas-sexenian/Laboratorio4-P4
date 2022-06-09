#ifndef EMPLEADOCONTROLLER
#define EMPLEADOCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorEmpleado.hh"
#include "../cabezales/Empleado.hh"
#include "../cabezales/DTEmpleado.hh"
#include "../cabezales/DTInfoEmpleado.hh"
#include "../cabezales/DTInfoHostal.hh"
#include "../cabezales/DTNotificacion.hh"


using namespace std;

class EmpleadoController{
    private:
        static EmpleadoController* instancia;
        EmpleadoController();
        map<string, Empleado*> Empleados;
        string Email;
    public:
		static EmpleadoController* getInstancia();
	    ~EmpleadoController();

        /*
        void setEmail(string Email);
        string getEmail();
        */

        void ingresarEmailEmpleado(string);
        void agregarComentario(string);
        list<DTEmpleado> obtenerTodosEmpleados();
        DTInfoEmpleado obtenerHostalYCargoEmpleado();
        list<string> obtenerComentariosSinRespuestaHostalEmpleado(string);
        list<DTInfoHostal> obtenerCalificacionYURespuestasEmpleados(int);
        list<DTNotificacion> obtenerNotificacionesDelEmpleado();
        void seleccionarEmpleado(string);
        void cancelarAsignacionEmpleado();
        void confirmarAsignacionEmpleado();
        void seleccionarCargo(TipoCargo);
        list<DTEmpleado> obtenerEmpleadosNoAsignadosHostal(string);
};
#endif