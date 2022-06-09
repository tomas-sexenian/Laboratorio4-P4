#ifndef ICONTROLADOREMPLEADO
#define ICONTROLADOREMPLEADO

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../../include/TipoCargo.hh"
#include "../cabezales/DTEmpleado.hh"
#include "../cabezales/DTInfoEmpleado.hh"
#include "../cabezales/DTInfoHostal.hh"
#include "../cabezales/DTNotificacion.hh"

using namespace std;

class IControladorEmpleado {
    public:
        /*
        virtual void setEmail(string Email) = 0;
        virtual string getEmail() = 0;
        */

        virtual void ingresarEmailEmpleado(string) = 0;
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
};

#endif