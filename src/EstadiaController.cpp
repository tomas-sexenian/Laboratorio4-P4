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

list<Estadia*> EstadiaController::getEstadias() {
    return Estadias;
}

void EstadiaController::setEstadia() {
    this->Estadias.push_back(new Estadia(this->entrada,this->salida,this->promo,list<Observer*>,NULL,NULL,NULL));
}

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

Estadia* EstadiaController :: getEstadiaSeleccionada() {
}

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
