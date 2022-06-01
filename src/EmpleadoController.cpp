#include "../include/controladores/EmpleadoController.hh"

EmpleadoController::EmpleadoController() {
}

EmpleadoController::~EmpleadoController() {
}

EmpleadoController* EmpleadoController::instancia;
EmpleadoController * EmpleadoController::getInstancia(){
    if (EmpleadoController::instancia == NULL)
        EmpleadoController::instancia = new EmpleadoController();
    return EmpleadoController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void EmpleadoController::ingresarEmailEmpleado(string EmailEmpleado) {
}

void EmpleadoController::agregarComentario(string UnComentario) {
}

list<DTEmpleado> EmpleadoController::obtenerTodosEmpleados() {
}

DTInfoEmpleado EmpleadoController::obtenerHostalYCargoEmpleado() {
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