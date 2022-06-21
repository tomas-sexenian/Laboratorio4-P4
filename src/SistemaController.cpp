#include "../include/controladores/SistemaController.hh"

SistemaController::SistemaController() {
    FechaSistema* fecha = FechaSistema::getInstancia();
    fecha->setFecha(DTFecha());

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

void SistemaController::modificarFecha(int UnDia, int UnMes, int UnAnio, int UnaHora, int UnMinuto) {
    FechaSistema* fecha = FechaSistema::getInstancia();
    fecha->setFecha(UnDia, UnMes, UnAnio, UnaHora, UnMinuto);
}
