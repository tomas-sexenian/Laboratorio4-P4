#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO


#include "../cabezales/DTHuesped.hh"
#include "../cabezales/DTEstadia.hh"
#include "../cabezales/DTEmpleado.hh"

#include "../cabezales/Empleado.hh"
#include "../cabezales/DTInfoEmpleado.hh"
#include "../cabezales/DTInfoHostal.hh"
#include "../cabezales/DTNotificacion.hh"
#include "../TipoCargo.hh"
#include "../TipoUsuario.hh"

#include <string>
#include <list>
#include <utility>
  
class DTInfoEmpleado;
class Empleado;

using namespace std; 

class IControladorUsuario {
public:

    virtual void seleccionarHuesped(string) = 0;
    virtual void seleccionarEmpleado(string) = 0;

    //Lo que antes era AltaUsuario
    virtual void ingresarDatosUsuario(string,string,string) = 0;
    virtual void ingresarTipo(TipoUsuario) = 0;
    virtual void ingresarNuevoEmail(string) = 0;
    virtual void ingresarEsFinger(bool) = 0;
    virtual void ingresarCargo(TipoCargo) = 0;
    virtual void confirmarAltaUsuario(bool) = 0;
    virtual void cancelarAltaUsuario() = 0; 
        
    //Lo que antes era Huespedcontroller
    virtual bool obtenerEsFinger() = 0;
    virtual list<DTHuesped> obtenerTodosHuespedes() = 0;
    virtual list<DTEstadia*> obtenerEstadiasFinalizadasHuesped() = 0;

    //Lo que antes era UsuarioController
    virtual void agregarComentario(string) = 0;
    virtual list<DTEmpleado> obtenerTodosEmpleados() = 0;
    virtual DTInfoEmpleado obtenerHostalYCargoEmpleado() = 0;
    // virtual list<string> obtenerComentariosSinRespuestaHostalEmpleado(string) = 0;
    // virtual list<DTInfoHostal> obtenerCalificacionYURespuestasEmpleados(int) = 0;
    // virtual list<DTNotificacion> obtenerNotificacionesDelEmpleado() = 0;
    virtual void cancelarAsignacionEmpleado() = 0;
    virtual void confirmarAsignacionEmpleado() = 0;
    virtual void seleccionarCargo(TipoCargo) = 0;
    virtual list<DTEmpleado> obtenerEmpleadosNoAsignadosHostal(string) = 0;
    virtual void ingresarHostal(string) = 0;



    virtual Empleado* obtenerEmpleado(string) = 0;


    virtual void LiberarMemoria() = 0;
};

#endif
