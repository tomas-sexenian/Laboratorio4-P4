#include "../include/controladores/SistemaController.hh"

SistemaController::SistemaController() {
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

void SistemaController::ingresarFecha(DTFecha UnaFecha) {
}

void SistemaController::actualizarFecha(DTFecha UnaFecha) {
}

void SistemaController::ModificarFecha(DTFecha UnaFecha) {
}