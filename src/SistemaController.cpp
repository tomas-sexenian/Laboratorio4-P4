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

void SistemaController::ModificarFecha(DTFecha UnaFecha) {
}