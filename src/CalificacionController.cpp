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

Calificacion* CalificacionController::getCalificacionRecordada() {
    return calificacionRecordada;
}

void CalificacionController::setCalificacionRecordada(int codigoReserva, string emailHuesped) {
    Calificacion* res = NULL;
    for(map<int,Calificacion*>::iterator it = this->Calificaciones.begin(); it != this->Calificaciones.end(); it++){
        if (it->second->getEstadia()->getReserva()->getCodigo() == codigoReserva && it->second->getEstadia()->getHuesped()->getEmail() == emailHuesped)
            res =  it->second;
    }
    calificacionRecordada = res;
}


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void CalificacionController::ingresarComentario(string UnComentario) {
    comentario = UnComentario;
}

void CalificacionController::ingresarPuntaje(int UnPuntaje) {
    puntaje = UnPuntaje;
}

void CalificacionController::ingresarFecha(DTFecha UnaFecha) {
    fecha = UnaFecha;
}

void CalificacionController::confirmarAltaCalificacion(int codigoReserva, string emailHuesped) {
    SistemaController* sist = SistemaController::getInstancia();
    Calificacion* nueva = new Calificacion();
    nueva->setComentario(comentario);
    nueva->setPuntaje(puntaje);
    nueva->setFecha(sist->obtenerFechaActual());
    Estadia* res = NULL;
    for(map<int,Calificacion*>::iterator it = this->Calificaciones.begin(); it != this->Calificaciones.end(); it++){
        if (it->second->getEstadia()->getReserva()->getCodigo() == codigoReserva && it->second->getEstadia()->getHuesped()->getEmail() == emailHuesped)
            res =  it->second->getEstadia();
    }
    nueva->setEstadia(res);
    nueva->setRespuesta(NULL);
    Calificaciones.insert((pair<int,Calificacion*>(codigoReserva,nueva)));

    puntaje = codigoReserva = -1;
    comentario = "";
    fecha = DTFecha();
    calificacionRecordada = NULL;
}

void CalificacionController::ingresarRespuesta(string UnaRespuesta) {
    respuesta = UnaRespuesta;
}

void CalificacionController::responderCalificacion(int codigoReserva, string emailHuesped,DTFecha UnaFecha) {
    Calificacion* res = NULL;
    for(map<int,Calificacion*>::iterator it = this->Calificaciones.begin(); it != this->Calificaciones.end(); it++){
        if (it->second->getEstadia()->getReserva()->getCodigo() == codigoReserva && it->second->getEstadia()->getHuesped()->getEmail() == emailHuesped)
            res =  it->second;
    }
    if (res != NULL){
        RespuestaEmpleado* nueva = new RespuestaEmpleado(respuesta,UnaFecha,res);
        res->setRespuesta(nueva);
        RespuestasEmpleados.insert((pair<Calificacion *,RespuestaEmpleado*>(res,nueva)));
    }
}