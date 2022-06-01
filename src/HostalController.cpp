#include "../include/controladores/HostalController.hh"

HostalController::HostalController() {
}

HostalController::~HostalController() {
}

HostalController* HostalController::instancia;
HostalController * HostalController::getInstancia(){
    if (HostalController::instancia == NULL)
        HostalController::instancia = new HostalController();
    return HostalController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

list<DTHostal> HostalController::obtenerTodosHostales() {
}

list<DTHostal> HostalController::obtenerTop3Hostales() {
}

DTInfoBasicaHostal HostalController::obtenerInfoBasicaHostal(string NombreHostal) {
}

list<DTHabitacion> HostalController::obtenerHabitacionesHostal(string NombreHostal) {
}

list<DTReserva> HostalController::obtenerReservasHostal(string NombreHostal) {
}

void HostalController::seleccionarHostal(string NombreHostal) {
}

DTInfoHostal HostalController::verDetalles(string NombreHostal) {
}

void HostalController::confirmarConsulta() {
}

list<DTInfoHostalYCalificacion> HostalController::obtenerTodosHostalesYPromCalificacion() {
}