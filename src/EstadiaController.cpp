#include "../include/controladores/EstadiaController.hh"

EstadiaController::EstadiaController() {
}

EstadiaController::~EstadiaController() {
}

EstadiaController* EstadiaController::instancia;
EstadiaController * EstadiaController::getInstancia(){
    if (EstadiaController::instancia == NULL)
        EstadiaController::instancia = new EstadiaController();
    return EstadiaController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void EstadiaController::seleccionarEstadia(int UnCodigo) {
}

DTInfoEstadia EstadiaController::obtenerEstadia(int UnCodigo) {
}

void EstadiaController::finalizarEstadia(int UnCodigo) {
}

void EstadiaController::registrarCheckOut(int UnCodigo, DTFecha UnaFecha) {
}

void EstadiaController::confirmarFinEstadia() {
}

