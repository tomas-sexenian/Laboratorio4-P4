#include "../include/controladores/EmpleadoController.hh"
#include "../include/controladores/CalificacionController.hh"
#include "../include/cabezales/DTNotificacion.hh"
#include "../include/cabezales/Empleado.hh"
#include "../include/controladores/UsuarioController.hh" 
#include "../include/cabezales/DTEmpleado.hh"
#include "../include/cabezales/DTInfoHostal.hh"

#include <list>
#include <iterator>


EmpleadoController::EmpleadoController() {
}

EmpleadoController::~EmpleadoController() {
}

EmpleadoController* EmpleadoController::instancia;
EmpleadoController* EmpleadoController::getInstancia(){
    if (EmpleadoController::instancia == NULL)
        EmpleadoController::instancia = new EmpleadoController();
    return EmpleadoController::instancia;
};

//  Implementación de SetEmail & GetEmail
/*
void EmpleadoController::setEmail(string Email){
    this->Email = Email;
}

string EmpleadoController::getEmail()
{
    return this->Email;
}
*/

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void EmpleadoController::ingresarEmailEmpleado(string EmailEmpleado) {
    this->Email = EmailEmpleado;
};

void EmpleadoController::agregarComentario(string UnComentario) {
    RespuestaEmpleado* res = new RespuestaEmpleado();
    res->setComentario(UnComentario);

    this->Empleados[this->Email]->setRespuesta(res);
};

list<DTEmpleado> EmpleadoController::obtenerTodosEmpleados() {
    UsuarioController* c = UsuarioController :: getInstancia();
    map<string,Usuario*> usuarios = c->getUsuarios();
    list<DTEmpleado> lista; 
    for (map<string,Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        Empleado* empleado= dynamic_cast<Empleado*>(it->second);
       
        if (empleado) {
            lista.insert(new DTEmpleado(empleado->getNombre(),
            empleado->getEmail(), empleado->getContrasenia(), empleado->getCargo(), empleado->getNotificaciones(),
            empleado->getHostal(), empleado->getRespuestas()));
        }
       
    }   
    return lista;
};

DTInfoEmpleado EmpleadoController::obtenerHostalYCargoEmpleado() {
    Empleado* e = this->Empleados[this->Email];

    DTInfoEmpleado ret = DTInfoEmpleado(e);
    return ret;
};

list<string> EmpleadoController::obtenerComentariosSinRespuestaHostalEmpleado(string EmailEmpleado) {
    Empleado* empleado= this->Empleados[EmailEmpleado];
    list<string> lista;
    list<RespuestaEmpleado*> comentarios;
    list<string> comentariosSeleccionados;
    Hostal * hostal = empleado->getHostal();
    map<string,Estadia*> estadias= hostal->getEstadias();
    for (map<string,Estadia*>::iterator it = estadias.begin(); it != estadias.end(); ++it) {
        if (it->second->getCalificacion()!=NULL) {
            list<RespuestaEmpleado*> comentarios = it->second->getCalificacion()->getRespuestas();
        } 
        if (comentarios==NULL) {
                lista.insert(it->second->getCalificacion()->getComentario());
                comentariosSeleccionados.insert(it->second->getCalificacion()->getComentario());
            }
        it->second;   
    }
    
    return lista;
};


list<DTInfoHostal> EmpleadoController::obtenerCalificacionYURespuestasEmpleados(int numero) {
    CalificacionController* c = CalificacionController :: getInstancia();
    map<int,Calificacion *> calificaciones = c->getCalificaciones();
    Calificacion* calificacion = calificaciones[numero];
    list<RespuestaEmpleado*> comentarios = calificacion->getRespuestas();
    if (comentarios!=NULL) {
        for (list<RespuestaEmpleado*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
            list<string> lista = lista.insert(it->second->getComentario());
        }
        list<DTInfoHostal> info = DTInfoHostal(lista, calificacion.getPuntaje());
    }
    else {
         list<DTInfoHostal> info = DTInfoHostal(NULL, calificacion.getPuntaje());
    }
    return info;
};

list<DTNotificacion> EmpleadoController::obtenerNotificacionesDelEmpleado() {
    Empleado* e = this->Empleados[this->Email];
    list<DTNotificacion> lista;
    list<Notificacion*> notificaciones =  e->getNotificaciones();
    for (list<Notificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); ++it) {
        lista = lista.insert(<DTNotificacion>(DTNotificacion(getAutor(),getPuntaje(),getComentario())));
    }

    return lista;
	   
};

Empleado* EmpleadoController :: getEmpleadoIniciar() {
    return this->EmpleadoIniciar;
};

void EmpleadoController :: setEmpleadoIniciar(Empleado* empleado) {
    this->EmpleadoIniciar = empleado;
};



void EmpleadoController::seleccionarEmpleado(string EmailEmpleado) {
    this->EmpleadoIniciar = Empleados[EmailEmpleado];
};

void EmpleadoController::cancelarAsignacionEmpleado() {
    this->EmpleadoIniciar=NULL;
};

void EmpleadoController::confirmarAsignacionEmpleado() {
    this->Empleados.insert(pair<string,Empleado*>(EmpleadoIniciar->getEmail(),new Empleado(this->EmpleadoIniciar->getNombre(),
    this->EmpleadoIniciar->getEmail(), this->EmpleadoIniciar->getContrasenia(), cargo, EmpleadoIniciar->getNotificaciones(),
    EmpleadoIniciar->getHostal(), EmpleadoIniciar->getRespuestas())));
    EmpleadoIniciar= NULL;
};

void EmpleadoController::seleccionarCargo(TipoCargo cargo) {
    this->cargo= cargo;
};

list<DTEmpleado> EmpleadoController::obtenerEmpleadosNoAsignadosHostal(string NombreHostal) {
    list<DTEmpleado> lista;
    for (map<string,Empleado*>::iterator it = Empleados.begin(); it != Empleados.end(); ++it) {
        if (it->second->getHostal()->getNombre()!=NombreHostal) {
            lista = lista.insert(<DTEmpleado>(new DTEmpleado(it->getNombre(), it->getEmail(), 
            it->getContrasenia(), it->cargo, it->getNotificaciones(), it->getHostal(), it->getRespuestas())));
        }
    }
    return lista;
};

list<string> EmpleadoController :: getComentariosSeleccionados() {
    return this->comentariosSeleccionados;
};


// falta implementar
void EmpleadoController :: elegirComentario(string c) {
}

// falta implementar
void CalificacionController::altaComentarios() {
}
