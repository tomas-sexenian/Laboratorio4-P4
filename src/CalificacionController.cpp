#include "../include/controladores/CalificacionController.hh"

CalificacionController::CalificacionController() {
}

CalificacionController::~CalificacionController() {
}

CalificacionController* CalificacionController::instancia;
CalificacionController * CalificacionController::getInstancia(){
    if (CalificacionController::instancia == NULL)
        CalificacionController::instancia = new CalificacionController();
    return CalificacionController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void CalificacionController::ingresarComentario(string UnComentario) {
}

void CalificacionController::ingresarPuntaje(int UnPuntaje) {
}

void CalificacionController::confirmarAltaCalificacion() {
}

void CalificacionController::elegirComentario() {
}

void CalificacionController::altaComentarios() {
}