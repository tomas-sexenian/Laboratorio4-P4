#include "../include/controladores/NotificacionesController.hh"

NotificacionesController::NotificacionesController() {
}

NotificacionesController::~NotificacionesController() {
    
}

NotificacionesController* NotificacionesController::instancia=NULL;
NotificacionesController * NotificacionesController::getInstancia(){
    if (NotificacionesController::instancia == NULL)
        NotificacionesController::instancia = new NotificacionesController();
    return NotificacionesController::instancia;
};

list<Notificacion *> NotificacionesController::getNotificaciones() {
    return Notificaciones;
}

void NotificacionesController::setNotificacion() {
    Notificaciones.push_back(new Notificacion(
        this->autor,
        this->puntaje,
        this->comentario
      ));
}

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void NotificacionesController::LiberarMemoria(){
    for(list<Notificacion *>::iterator it = Notificaciones.begin(); it != Notificaciones.end(); it++)
        delete *it;
    delete instancia;
    instancia = NULL;
}


Notificacion* NotificacionesController::confirmarNotificacion(int codigoReserva, string emailHuesped, Calificacion *cal) {
    Notificacion* n= new Notificacion(emailHuesped,cal->getPuntaje(),cal->getComentario());
    Notificaciones.push_back(n);
    return n;
};


list<DTNotificacion> NotificacionesController::ObtenerNotificacionesEmpleado(string email) {
    UsuarioController* controladorUsuario = UsuarioController::getInstancia();
    list<DTNotificacion> listadt;
    Empleado* empleado= controladorUsuario->obtenerEmpleado(email);
    list<Notificacion*> lista = empleado->getNotificaciones();
    for(list<Notificacion*>::iterator it = lista.begin(); it != lista.end(); it++) {
        DTNotificacion notificacion = DTNotificacion((*it)->getAutor(),(*it)->getPuntaje(),(*it)->getComentario());
        listadt.push_back(notificacion);
    }

    return listadt;
}
void NotificacionesController::eliminarNotificaciones(string email) {
    UsuarioController* controladorUsuario = UsuarioController::getInstancia();
    Empleado* empleado= controladorUsuario->obtenerEmpleado(email); 
    list<Notificacion*> notificaciones = empleado->getNotificaciones();

    auto o = notificaciones.begin();
    while(o != notificaciones.end()) {
        Notificacion *n = *o;
        o++;
        notificaciones.remove(n);
    }
}