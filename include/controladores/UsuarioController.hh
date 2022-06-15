#ifndef USUARIOCONTROLLER
#define USUARIOCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES


#include "../interfaces/IControladorUsuario.hh"
#include "../cabezales/Fabrica.hh"
#include "../cabezales/Usuario.hh"
#include "../cabezales/Empleado.hh"
#include "../cabezales/DTUsuario.hh"
#include "../cabezales/DTHuesped.hh"
#include "../cabezales/DTEmpleado.hh"
#include "../cabezales/DTEstadia.hh"
#include "../cabezales/DTInfoUsuario.hh"
#include "../cabezales/DTInfoEmpleado.hh"
#include "../cabezales/DTFecha.hh"
#include "../controladores/HostalController.hh"
#include "../../include/TipoUsuario.hh"
#include "../../include/TipoCargo.hh"

using namespace std;

class UsuarioController: public IControladorUsuario {
    private:
        static UsuarioController *instancia;
        UsuarioController();
        map<string,Huesped*> Huespedes;
        map<string,Empleado*> Empleados;
        Huesped *huespedSeleccionado;
        Empleado *empleadoSeleccionado;

        //Memoria
        string nombre,email,contrasenia;
        bool esFinger;
        TipoCargo cargo;
        TipoUsuario tipo;
        Hostal* hostal;
    public:
		static UsuarioController* getInstancia();
	    ~UsuarioController();
        map<string,Huesped *> getHuespedes();
        map<string,Empleado *> getEmpleados();

        void seleccionarHuesped(string);
        void seleccionarEmpleado(string);
        //void confirmarConsulta(); No tiene sentido tener esto

        //Lo que antes era AltaUsuario
        void ingresarDatosUsuario(string,string,string);
        void ingresarTipo(TipoUsuario);
        void ingresarNuevoEmail(string);
        void ingresarEsFinger(bool);
        void ingresarCargo(TipoCargo);
        void confirmarAltaUsuario();
        void cancelarAltaUsuario(); //Esto tampoco tiene sentido tenerlo aca, iria en el menu
        
        //Lo que antes era Huespedcontroller
        bool obtenerEsFinger();
        list<DTHuesped> obtenerTodosHuespedes();
        list<DTEstadia> obtenerEstadiasFinalizadasHuesped();

        //Lo que antes era UsuarioController
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
        void ingresarHostal(string);
};
#endif
