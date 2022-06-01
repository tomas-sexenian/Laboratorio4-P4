#include "../include/controladores/ReservaController.hh"

ReservaController::ReservaController() {
}

ReservaController::~ReservaController() {
}

ReservaController* ReservaController::instancia;
ReservaController * ReservaController::getInstancia(){
    if (ReservaController::instancia == NULL)
        ReservaController::instancia = new ReservaController();
    return ReservaController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

DTReserva ReservaController::obtenerReserva(int UnCodigo) {
}

void ReservaController::seleccionarReserva(int UnCodigo) {
}

list<DTReserva> ReservaController::getListaReservasNoCanceladasHuesped(string UnEmail) {
}

void ReservaController::confirmarAltaEstadia() {
}

void ReservaController::confirmarConsulta() {
}

void ReservaController::ingresarDatosReserva(DTReserva) {
}

void ReservaController::agregarHuespedesReserva(list<DTHuesped> UnosHuespedes) {
}

void ReservaController::confirmarReserva() {
}

void ReservaController::cancelarReserva() {
}

list<DTReserva> ReservaController::obtenerReservasHostal(string UnHostal) {
}

void ReservaController::cancelarBajaReserva() {
}

void ReservaController::liberarReserva() {
}