#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO


#include "../include/cabezales/DTHuesped.hh"
#include "../include/cabezales/DTEstadia.hh"
#include "../include/cabezales/DTEmpleado.hh"
#include "../include/cabezales/DTInfoEmpleado.hh"
#include "../include/cabezales/DTInfoHostal.hh"
#include "../include/cabezales/DTNotificacion.hh"

#include <string>
#include <list>
#include <utility>
  
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
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarAltaUsuario() = 0; 
        
    //Lo que antes era Huespedcontroller
    virtual bool obtenerEsFinger() = 0;
    virtual list<DTHuesped> obtenerTodosHuespedes() = 0;
    virtual list<DTEstadia> obtenerEstadiasFinalizadasHuesped() = 0;

    //Lo que antes era UsuarioController
    virtual void agregarComentario(string) = 0;
    virtual list<DTEmpleado> obtenerTodosEmpleados() = 0;
    virtual DTInfoEmpleado obtenerHostalYCargoEmpleado() = 0;
    virtual list<string> obtenerComentariosSinRespuestaHostalEmpleado(string) = 0;
    virtual list<DTInfoHostal> obtenerCalificacionYURespuestasEmpleados(int) = 0;
    virtual list<DTNotificacion> obtenerNotificacionesDelEmpleado() = 0;
    virtual void seleccionarEmpleado(string) = 0;
    virtual void cancelarAsignacionEmpleado() = 0;
    virtual void confirmarAsignacionEmpleado() = 0;
    virtual void seleccionarCargo(TipoCargo) = 0;
    virtual list<DTEmpleado> obtenerEmpleadosNoAsignadosHostal(string) = 0;
    virtual void ingresarHostal(string) = 0;

};

#endif
