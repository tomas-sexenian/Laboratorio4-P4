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

map<int,Calificacion *> CalificacionController::getCalificaciones() {
    return Calificaciones;
}

void CalificacionController::setCalificacion() {
    this->Calificaciones.insert(pair<int,Calificacion*>(this->codigoReserva,new Calificacion(
        this->puntaje,
        this->comentario,
        this->fecha,
        NULL,
        list<RespuestaEmpleado*> {}
    )));
}

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