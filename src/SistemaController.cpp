#include "../include/controladores/SistemaController.hh"

SistemaController::SistemaController() {
    DTFecha date;
    this->fechaActual->setFecha(date);
}

SistemaController::SistemaController(DTFecha UnaFecha) {
    this->fechaActual->setFecha(UnaFecha);
}

SistemaController::~SistemaController() {
    delete this->fechaActual;
}

SistemaController* SistemaController::instancia;
SistemaController * SistemaController::getInstancia(){
    if (SistemaController::instancia == NULL)
        SistemaController::instancia = new SistemaController();
    return SistemaController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

DTFecha SistemaController::obtenerFechaActual(){
    return this->fechaActual->getFecha();
}

void SistemaController::modificarFecha(DTFecha UnaFecha) {
    this->fechaActual->setFecha(UnaFecha);
}
