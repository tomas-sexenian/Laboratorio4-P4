#include "../include/controladores/EmpleadoController.hh"

EmpleadoController::EmpleadoController() {
}

EmpleadoController::~EmpleadoController() {
}

EmpleadoController* EmpleadoController::instancia;
EmpleadoController* EmpleadoController::getInstancia(){
    if (EmpleadoController::instancia == NULL)
        EmpleadoController::instancia = new EmpleadoController();
    return EmpleadoController::instancia;
};

//  Implementación de SetEmail & GetEmail
/*
void EmpleadoController::setEmail(string Email){
    this->Email = Email;
}

string EmpleadoController::getEmail()
{
    return this->Email;
}
*/

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void EmpleadoController::ingresarEmailEmpleado(string EmailEmpleado) {
    this->Email = EmailEmpleado;
}

void EmpleadoController::agregarComentario(string UnComentario) {
    RespuestaEmpleado* res = new RespuestaEmpleado();
    res->setComentario(UnComentario);

    this->Empleados[this->Email]->setRespuesta(res);
}

list<DTEmpleado> EmpleadoController::obtenerTodosEmpleados() {
    
}

DTInfoEmpleado EmpleadoController::obtenerHostalYCargoEmpleado() {
    Empleado* e = this->Empleados[this->Email];

    DTInfoEmpleado ret = DTInfoEmpleado(e);
    return ret;
}

list<string> EmpleadoController::obtenerComentariosSinRespuestaHostalEmpleado(string EmailEmpleado) {
}

list<DTInfoHostal> EmpleadoController::obtenerCalificacionYURespuestasEmpleados(int numero) {
}

list<DTNotificacion> EmpleadoController::obtenerNotificacionesDelEmpleado() {
}

void EmpleadoController::seleccionarEmpleado(string EmailEmpleado) {
}

void EmpleadoController::cancelarAsignacionEmpleado() {
}

void EmpleadoController::confirmarAsignacionEmpleado() {
}

void EmpleadoController::seleccionarCargo(TipoCargo cargo) {
}

list<DTEmpleado> EmpleadoController::obtenerEmpleadosNoAsignadosHostal(string NombreHostal) {
}