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


void CalificacionController::setCalificacionRecordada(int codigoReserva, string emailHuesped) {
    Calificacion* res = NULL;
    for(map<int,Calificacion*>::iterator it = this->Calificaciones.begin(); it != this->Calificaciones.end(); it++){
        if (it->second->getEstadia()->getReserva()->getCodigo() == codigoReserva && it->second->getEstadia()->getHuesped()->getEmail() == emailHuesped)
            res =  it->second;
    }
    calificacionRecordada = res;
}


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

//Obtiene una lista de DTCalificacion de la calificacion recordada
DTCalificacion CalificacionController::obtenerDTCalificacionRecordada() {
    DTCalificacion res(calificacionRecordada->getPuntaje(), calificacionRecordada->getComentario(), calificacionRecordada->getFecha());
    return res;
}

//Obtiene una lista de DTRespuestaEmpleado de la calificacion recordada
list<DTRespuestaEmpleado> CalificacionController::obtenerDTRespuestas(){
    list<DTRespuestaEmpleado> res;
    list<RespuestaEmpleado*> respuestas = calificacionRecordada->getRespuestas();
    for(list<RespuestaEmpleado*>::iterator it = respuestas.begin(); it != respuestas.end(); it++){
        DTRespuestaEmpleado ins((*it)->getComentario(), (*it)->getFecha());
        res.push_back(ins);
    }
    return res;
}

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
    EstadiaController* est = EstadiaController::getInstancia();
    Estadia *e = est->obtenerEstadia(codigoReserva, emailHuesped);

    Calificacion* nueva = new Calificacion(puntaje, comentario, fecha, e, {});

    Calificaciones.insert((pair<int,Calificacion*>(codigoReserva,nueva)));
    e->setCalificacion(nueva);

    cout << "La calificacion ha sido registrada con exito" << endl;
}

void CalificacionController::ingresarRespuesta(string UnaRespuesta) {
    respuesta = UnaRespuesta;
}

void CalificacionController::responderCalificacion(int codigoReserva, string emailHuesped,DTFecha UnaFecha) {
    Calificacion* c = NULL;
    for(map<int,Calificacion*>::iterator it = this->Calificaciones.begin(); it != this->Calificaciones.end(); it++){
        if (it->second->getEstadia()->getReserva()->getCodigo() == codigoReserva && it->second->getEstadia()->getHuesped()->getEmail() == emailHuesped)
            c =  it->second;
    }
    if(c == NULL) throw invalid_argument("No se puede responder a una calificacion que no existe");
    else{
        RespuestaEmpleado* nueva = new RespuestaEmpleado(respuesta,UnaFecha,c);
        c->setRespuesta(nueva);
        RespuestasEmpleados.insert((pair<Calificacion *,RespuestaEmpleado*>(c,nueva)));
        cout << "La respuesta ha sido insertada con exito" << endl;
    }  
}