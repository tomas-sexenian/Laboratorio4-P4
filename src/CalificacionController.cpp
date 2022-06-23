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



void CalificacionController::responderCalificacion(int codigoReserva, string emailHuesped,DTFecha UnaFecha,bool conRetorno) {
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
        if (conRetorno)
            cout << "La respuesta ha sido insertada con exito" << endl;
    }
}


list<IObserver*> CalificacionController::getObservadores(){
    return observadores;
}

void CalificacionController::ingresarRespuesta(string UnaRespuesta) {
    respuesta = UnaRespuesta;
}

void CalificacionController::confirmarAltaCalificacion(int codigoReserva, string emailHuesped, bool conRetorno) {
    EstadiaController* est = EstadiaController::getInstancia();
    Estadia *e = est->obtenerEstadia(codigoReserva, emailHuesped);

    Calificacion* nueva = new Calificacion(puntaje, comentario, fecha, e, {});
    Calificaciones.insert((pair<int,Calificacion*>(codigoReserva,nueva)));
    e->setCalificacion(nueva);

    NotificacionesController* notifController = NotificacionesController::getInstancia();
    Notificacion *n = notifController->confirmarNotificacion(codigoReserva, emailHuesped, e->getCalificacion());
    for(list<IObserver*>::iterator it = observadores.begin(); it != observadores.end(); it++){
        Empleado* i = dynamic_cast<Empleado*>(*it);
        if(i->getHostal() == e->getHostal())
            i->notificar(n);
    }

    if (conRetorno)
        cout << "La calificacion ha sido registrada con exito" << endl;
}


void CalificacionController::agregarObservador(string email){
    UsuarioController* controladorEmpleado = UsuarioController::getInstancia();
    Empleado* empleado = controladorEmpleado->obtenerEmpleado(email);
    IObserver *i = empleado;
    observadores.push_back(i);
}




void CalificacionController::eliminarObservador(string email) {
    auto o = observadores.begin();
    Empleado *i = dynamic_cast<Empleado*>(*o);
    while(o != observadores.end() && email != i->getEmail()) {
        i = dynamic_cast<Empleado*>(*o);
        o++;
    }
    if(o != observadores.end()) observadores.remove(i);
    else throw invalid_argument("No se desuscribir un empleado que no existe");
}



void CalificacionController::LiberarMemoria(){
    for(map<int,Calificacion *>::iterator it = Calificaciones.begin(); it != Calificaciones.end(); it++)
        delete it->second;
    for(multimap<Calificacion *,RespuestaEmpleado *>::iterator it = RespuestasEmpleados.begin(); it != RespuestasEmpleados.end(); it++)
        delete it->second;
    for(list<IObserver*>::iterator it = observadores.begin(); it != observadores.end(); it++)
        delete *it;
    delete instancia;
    instancia = NULL;
}