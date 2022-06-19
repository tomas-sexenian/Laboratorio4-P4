#include "../include/controladores/CalificacionController.hh"


CalificacionController::CalificacionController() {
    
}

CalificacionController::~CalificacionController() {
}

CalificacionController* CalificacionController::instancia=NULL;
CalificacionController * CalificacionController::getInstancia(){
    if (CalificacionController::instancia == NULL)
        CalificacionController::instancia = new CalificacionController();
    return CalificacionController::instancia;
};

map<int,Calificacion *> CalificacionController::getCalificaciones() {
    return Calificaciones;
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
    EstadiaController* est = EstadiaController::getInstancia();
    Estadia *e = est->obtenerEstadia(codigoReserva, emailHuesped);

    Calificacion* nueva = new Calificacion();
    nueva->setComentario(comentario);
    nueva->setPuntaje(puntaje);
    nueva->setFecha(sist->obtenerFechaActual());
    nueva->setEstadia(e);

    Calificaciones.insert((pair<int,Calificacion*>(codigoReserva,nueva)));
    e->setCalificacion(nueva);

    cout << "La calificacion ha sido registrada con exito" << endl;
}

void CalificacionController::ingresarRespuesta(string UnaRespuesta) {
    respuesta = UnaRespuesta;
}

void CalificacionController::responderCalificacion(int codigoReserva, string emailHuesped,DTFecha UnaFecha) {
    EstadiaController* est = EstadiaController::getInstancia();
    Estadia *e = est->obtenerEstadia(codigoReserva, emailHuesped);
    Calificacion *c = e->getCalificacion();

    RespuestaEmpleado* nueva = new RespuestaEmpleado(respuesta,UnaFecha,c);
    c->setRespuesta(nueva);
    RespuestasEmpleados.insert((pair<Calificacion *,RespuestaEmpleado*>(c,nueva)));
    
}

void CalificacionController::eliminarCalificaciones() {
    Calificaciones.clear();
}

void CalificacionController::eliminarRespuestasEmpleado() {
    RespuestasEmpleados.clear();
}