#include "../include/controladores/UsuarioController.hh"

UsuarioController::UsuarioController() {
}

UsuarioController::~UsuarioController() {
}

UsuarioController* UsuarioController::instancia;
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

list<string> UsuarioController::obtenerComentariosSinRespuestaHostalEmpleado(string EmailEmpleado) {
}

list<DTInfoHostal> UsuarioController::obtenerCalificacionYURespuestasEmpleados(int numero) {
}

list<DTNotificacion> UsuarioController::obtenerNotificacionesDelEmpleado() {
}

void UsuarioController::cancelarAsignacionEmpleado() {
}

void UsuarioController::confirmarAsignacionEmpleado() {
}

void UsuarioController::seleccionarCargo(TipoCargo cargo) {
}

list<DTEmpleado> UsuarioController::obtenerEmpleadosNoAsignadosHostal(string NombreHostal) {
}

void UsuarioController::ingresarHostal(string nombreHostal) {
    HostalController* controladorHostales = HostalController::getInstancia();
    hostal = controladorHostales->getHostales().find(nombreHostal)->second;
}