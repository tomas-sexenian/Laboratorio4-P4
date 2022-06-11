#include "../include/controladores/SistemaController.hh"

SistemaController::SistemaController() {
    DTFecha date;
    this->fechaActual->setFecha(date);
}

SistemaController::SistemaController(DTFecha UnaFecha) {
    fechaActual->setFecha(UnaFecha);
}

SistemaController::~SistemaController() {
}

SistemaController* SistemaController::instancia;
SistemaController * SistemaController::getInstancia(){
    if (SistemaController::instancia == NULL)
        SistemaController::instancia = new SistemaController();
    return SistemaController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void SistemaController::modificarFecha(DTFecha UnaFecha) {
    this->fechaActual->setFecha(UnaFecha);
}
