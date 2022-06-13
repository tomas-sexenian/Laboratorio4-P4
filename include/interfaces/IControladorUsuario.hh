#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include "../include/cabezales/DTUsuario.hh"
#include "../include/cabezales/DTEmpleado.hh"
#include "../include/cabezales/DTHabitacion.hh"
#include "../include/cabezales/DTHostal.hh"
#include "../include/cabezales/DTCalificacion.hh"
#include "../include/cabezales/DTRespuestaEmpleado.hh"
#include "../include/cabezales/DTInfoEmpleado.hh"
#include "../include/cabezales/DTNotificacion.hh"
#include "../include/cabezales/DTInfoHostal.hh"

#include <string>
#include <list>
#include <utility>
  
using namespace std; 

class IControladorUsuario {
public:

    virtual void ingresarDatosUsuario(Usuario*) = 0;
    virtual void ingresarCargo(TipoCargo) = 0;
    virtual void ingresarEsFinger(bool) = 0;
    virtual void ingresarNuevoEmail(string) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarAltaUsuario() = 0;

    virtual ~IControladorUsuario() {};
 

};

#endif
