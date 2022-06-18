#include "../include/controladores/UsuarioController.hh"

UsuarioController* UsuarioController:: instancia=NULL;

UsuarioController::UsuarioController() {
    
}


UsuarioController::~UsuarioController() {
}

UsuarioController * UsuarioController::getInstancia(){
    if (UsuarioController::instancia == NULL)
        UsuarioController::instancia = new UsuarioController();
    return UsuarioController::instancia;
};

map<string,Huesped *> UsuarioController::getHuespedes() {
    return Huespedes;
}

map<string,Empleado *> UsuarioController::getEmpleados() {
    return Empleados;
}

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void UsuarioController::seleccionarHuesped(string EmailHuesped) {
    Huesped* h = Huespedes.find(EmailHuesped)->second;
    huespedSeleccionado = h;
}

void UsuarioController::seleccionarEmpleado(string EmailEmpleado) {
    Empleado* e = Empleados.find(EmailEmpleado)->second;
    empleadoSeleccionado = e;
}


//Lo que antes era AltaUsuario
void UsuarioController::ingresarDatosUsuario(string UnNombre, string UnEmail, string UnaContrasenia) {
    this->nombre = UnNombre;
    this->email = UnEmail;
    this->contrasenia = UnaContrasenia;
}

void UsuarioController::ingresarTipo(TipoUsuario UnTipo) {
    this->tipo = UnTipo;
}

void UsuarioController::ingresarNuevoEmail(string UnEmail) {
    this->email = UnEmail;
}

void UsuarioController::ingresarCargo(TipoCargo cargo) {
    this->cargo = cargo;
}

void UsuarioController::ingresarEsFinger(bool finger) {
    this->esFinger = finger;
}

void UsuarioController::confirmarAltaUsuario() {
    if((Empleados.find(this->email) == Empleados.end()) && (Huespedes.find(this->email) == Huespedes.end())){
        switch(tipo){
            case empleado:
                    Empleados.insert(pair<string,Empleado*>(this->email,
                    new Empleado(
                        this->nombre,
                        this->email,
                        this->contrasenia,
                        this->cargo,
                        list<Notificacion*> {},
                        NULL,
                        list<RespuestaEmpleado*> {}
                    )));
                

                break;
            case huesped:
                    Huespedes.insert(pair<string,Huesped*>(this->email,
                    new Huesped(
                        this->nombre,
                        this->email,
                        this->contrasenia,
                        this->esFinger,
                        map<int, Reserva*> {},
                        list<Estadia*> {}
                    )));
                break;
        }
        cout << "El usuario ha sido registrado con exito" << endl;
    }
    else
        throw std::invalid_argument( "Ya existe un usuario registrado con ese correo");
}

void UsuarioController::cancelarAltaUsuario() {
    nombre = "";
    email = "";
    contrasenia = "";
    esFinger = false;
}

//Lo que antes era HuespedController
bool UsuarioController::obtenerEsFinger(){
    return huespedSeleccionado->getEsFinger();
}

list<DTHuesped> UsuarioController::obtenerTodosHuespedes(){
    list<DTHuesped> res;
    auto itr = Huespedes.begin();
    while(itr != Huespedes.end()){ //Iterar map
        Huesped *h = itr->second;
        DTHuesped dt(h->getNombre(), h->getEmail(), h->getContrasenia(), h->getEsFinger());
        res.push_back(dt);
        itr++;
    }
    return res;
}

list<DTEstadia> UsuarioController::obtenerEstadiasFinalizadasHuesped() {
    SistemaController* sis = SistemaController::getInstancia();
    DTFecha fechaSis = sis->obtenerFechaActual();

    list<DTEstadia> res;
    list<Estadia*> estadiasHuesped = huespedSeleccionado->getEstadias();

    for (auto const& itr : estadiasHuesped) { //Iterar list
        Estadia *e = itr;
        if(e->getSalida() < fechaSis){
            DTEstadia dt(huespedSeleccionado->getEmail(), 
                        huespedSeleccionado->getNombre(), 
                        e->getEntrada(), 
                        e->getSalida(), 
                        e->getReserva()->getHabitacion()->getNumero(),
                        e->getPromo());
            res.push_back(dt);
        }
    }

    return res;
}


//Lo que antes era EmpleadoController

//Esta raro, tendria que estar en calificaciones
void UsuarioController::agregarComentario(string UnComentario) {
    RespuestaEmpleado* res = new RespuestaEmpleado();
    res->setComentario(UnComentario);

    this->Empleados[this->email]->setRespuesta(res);
}

list<DTEmpleado> UsuarioController::obtenerTodosEmpleados() {
    list<DTEmpleado> res;
    auto itr = Empleados.begin();
    while(itr != Empleados.end()){ //Iterar map
        Empleado *e = itr->second;
        DTEmpleado dt(e->getNombre(), e->getEmail(), e->getContrasenia(), e->getCargo());
        res.push_back(dt);
        itr++;
    }
    return res;
}

DTInfoEmpleado UsuarioController::obtenerHostalYCargoEmpleado() {
    Empleado* e = this->Empleados[this->email];
    DTInfoEmpleado ret = DTInfoEmpleado(e);
    return ret;
}

/*list<string> UsuarioController::obtenerComentariosSinRespuestaHostalEmpleado(string EmailEmpleado) {
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
};*/


/*list<DTInfoHostal> UsuarioController::obtenerCalificacionYURespuestasEmpleados(int numero) {
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
}*/

/*list<DTNotificacion> UsuarioController::obtenerNotificacionesDelEmpleado() {
    Empleado* e = empleadoSeleccionado;
    list<DTNotificacion> lista;
    list<Notificacion*> notificaciones =  e->getNotificaciones();
    for (list<Notificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); ++it) {
        lista.push_back(DTNotificacion(DTNotificacion(e->getAutor(),getPuntaje(),getComentario())));
    }

    return lista;
	   
}*/

void UsuarioController::cancelarAsignacionEmpleado() {
    empleadoSeleccionado = NULL;
}

void UsuarioController::confirmarAsignacionEmpleado() {
    empleadoSeleccionado->setCargo(cargo);
    empleadoSeleccionado->setHostal(hostal);

}

void UsuarioController::seleccionarCargo(TipoCargo cargo) {
    this->cargo= cargo;
}

list<DTEmpleado> UsuarioController::obtenerEmpleadosNoAsignadosHostal(string NombreHostal) {
    list<DTEmpleado> lista;
    for (map<string,Empleado*>::iterator it = Empleados.begin(); it != Empleados.end(); ++it) {
        if (it->second->getHostal()->getNombre() == NombreHostal) {
            DTEmpleado dt(
                            it->second->getNombre(), 
                            it->second->getEmail(), 
                            it->second->getContrasenia(),
                            it->second->getCargo()
            );
            lista.push_back(dt);
        }
    }
    return lista;
}

void UsuarioController::ingresarHostal(string nombreHostal) {
    HostalController* controladorHostales = HostalController::getInstancia();
    hostal = controladorHostales->getHostales().find(nombreHostal)->second;
}
