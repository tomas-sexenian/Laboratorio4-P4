#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO

#include "DTUsuario.h"
#include "DTEmpleado.h"
#include "DTHabitacion.h"
#include "DTHostal.h"
#include "DTCalificacion.h"
#include "DTRespuestaEmpleado.h"
#include "DTInfoEmpleado.h"
#include "DTNotificacion.h"
#include "DTInfoHostal.h"

#include <string>
#include <list>
#include <utility>
  
using namespace std; 

class IControladorUsuario {

public:

    virtual void ingresarDatosUsuario(datos: * Usuario) = 0;
    virtual void ingresarCargo(cargo : TipoCargo) = 0;
    virtual void ingresarEsFinger(esFinger : boolean) = 0;
    virtual void ingresarNuevoEmail(email : string) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarAltaUsuario() = 0;


    virtual void ingresarDatosHostal(datosHostal : * Hostal) = 0;
    virtual void confirmarAltaHostal() = 0;


    virtual void ingresarDatosHabitacion(datosHabitacion : * Habitacion) = 0;
    virtual void confirmarAltaHabitacion() = 0;
    virtual void cancelarAltaHabitacion() = 0;


    virtual ~IControladorUsuario() {};
 

}

#endif