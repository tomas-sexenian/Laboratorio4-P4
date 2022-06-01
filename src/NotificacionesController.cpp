#include "../include/controladores/NotificacionesController.hh"

NotificacionesController::NotificacionesController() {
}

NotificacionesController::~NotificacionesController() {
}

NotificacionesController* NotificacionesController::instancia;
NotificacionesController * NotificacionesController::getInstancia(){
    if (NotificacionesController::instancia == NULL)
        NotificacionesController::instancia = new NotificacionesController();
    return NotificacionesController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void NotificacionesController::subscribirEmpleado(string EmailEmpleado) {
}

void NotificacionesController::eliminarNotificaciones() {
}

void NotificacionesController::eliminarSubscripcion(string EmailEmpleado) {
}