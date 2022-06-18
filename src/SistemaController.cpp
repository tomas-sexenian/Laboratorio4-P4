#include "../include/controladores/SistemaController.hh"

SistemaController::SistemaController() {
    DTFecha *date= new DTFecha();
    FechaSistema* fecha = FechaSistema::getInstancia();
    fecha->setFecha(*date);

}

SistemaController::SistemaController(DTFecha UnaFecha) {
    FechaSistema* fecha = FechaSistema::getInstancia();
    fecha->setFecha(UnaFecha);
}

SistemaController::~SistemaController() {
}

SistemaController* SistemaController::instancia=NULL;
SistemaController * SistemaController::getInstancia(){
    if (SistemaController::instancia == NULL)
        SistemaController::instancia = new SistemaController();
    return SistemaController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

DTFecha SistemaController::obtenerFechaActual(){
    FechaSistema* fecha = FechaSistema::getInstancia();
    return fecha->getFecha();
}

void SistemaController::modificarFecha(DTFecha UnaFecha) {
    FechaSistema* fecha = FechaSistema::getInstancia();
    fecha->setFecha(UnaFecha);
}
