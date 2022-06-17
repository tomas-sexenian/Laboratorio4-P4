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

void NotificacionesController::subscribirEmpleado(string EmailEmpleado) {
    list<string>::iterator pos = this->Suscripciones.begin();
    while ((pos != this->Suscripciones.end()) && (*pos != EmailEmpleado))
    {
        pos++;
    }

    if ((pos == this->Suscripciones.end()) && (*pos != EmailEmpleado))
    {
        this->Suscripciones.push_back(EmailEmpleado);
    }
    
}

void NotificacionesController::eliminarNotificaciones() {
    while (!this->Notificaciones.empty())
    {
        Notificacion* del = this->Notificaciones.front();

        del->~Notificacion();
        this->Notificaciones.remove(del);
    }
    
}

void NotificacionesController::eliminarSubscripcion(string EmailEmpleado) {
    list<string>::iterator pos = this->Suscripciones.begin();
    while ((pos != this->Suscripciones.end()) && (*pos != EmailEmpleado))
    {
        pos++;
    }
    
    if (*pos == EmailEmpleado)
    {
        this->Suscripciones.erase(pos);
    }
}