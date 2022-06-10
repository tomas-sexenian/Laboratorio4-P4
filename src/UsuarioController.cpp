#include "../include/controladores/UsuarioController.hh"

UsuarioController::UsuarioController() {
     this->usuarioIniciar = NULL;
}

UsuarioController::~UsuarioController() {
}

UsuarioController* UsuarioController::instancia;
UsuarioController * UsuarioController::getInstancia(){
    if (UsuarioController::instancia == NULL)
        UsuarioController::instancia = new UsuarioController();
    return UsuarioController::instancia;
};

map<string,Usuario *> UsuarioController::getUsuarios() {
    return Usuarios;
}

void UsuarioController::setUsuario() {
    switch(tipo){
        case empleado:
            Usuarios.insert(pair<string,Usuario*>(this->email,
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
            Usuarios.insert(pair<string,Usuario*>(this->email,
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

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

DTInfoUsuario UsuarioController::seleccionarUsuario(string EmailUsuario) {
    Usuario* user = Usuarios.find(EmailUsuario)->second;
    return DTInfoUsuario(user->getNombre(), user->getEmail());
}

void UsuarioController::confirmarConsulta() {
}


//void UsuarioController::ingresarEmpleado(Empleado e) {}


Usuario * UsuarioController::getUsuarioIniciar() {
    return this->usuarioIniciar;
    
    void UsuarioController :: ingresarDatosUsuario(Usuario* datos) {
        this->usuarioIniciar= datos; 
    }
}

void UsuarioController :: ingresarCargo(TipoCargo cargo) { 
    this->cargo= cargo;
}

void UsuarioController :: ingresarEsFinger(bool esFinger) { 
    this->esFinger= esFinger;
}

void UsuarioController :: ingresarNuevoEmail(string email) {
    this->usuarioIniciar->setEmail(email);
}

void UsuarioController :: confimarAltaUsuario() {
    DTEmpleado* empleado= dynamic_cast<DTEmpleado*>(usuarioIniciar);
    if (empleado) {
        this->usuarios.insert(pair<string,Usuario*>(empleado.getEmail(),new Empleado(usuarioIniciar.getNombre(),
        usuarioIniciar.getEmail(), usuarioIniciar.getConstrasenia(), cargo, usuarioIniciar.getNotificaciones(),
         usuarioIniciar.getHostal(), usuarioIniciar.getRespuestas())));
    }
    else {
        DTHuesped* huesped= dynamic_cast<DTHuesped*>(usuarioIniciar);
        if (huesped) {
            this->usuarios.insert(pair<string,Usuario*>(huesped.getNombre(),new Huesped(usuarioIniciar.getNombre(),
        usuarioIniciar.getEmail(), usuarioIniciar.getConstrasenia(), esFinger,  usuarioIniciar.getReservas(), usuarioIniciar.getEstadias())));
    }
        }
      
    this->usuarioIniciar = NULL;
}

void UsuarioController :: cancelarAltaUsuario() {
    this->usuarioIniciar= NULL;
}

UsuarioController :: ~UsuarioController() {   
}

Hostal * UsuarioController :: getHostalIniciar() {
    return this->hostalIniciar;
}

Habitacion * UsuarioController :: getHabitacionIniciar() {
    return this->habitacionIniciar; 
}
        
map<string,Hostal*> UsuarioController :: getHostales() {
    return this->hostales;
}
        
map<string,Habitacion*> UsuarioController :: getHabitaciones() {
    return this->habitaciones;
}

void UsuarioController :: ingresarDatosHostal(Hostal* datosHostal ) { 
    this->hostalIniciar = datosHostal;
}

void UsuarioController :: confirmarAltaHostal() {
       this->hostales.insert(pair<string,Hostal*>(hostalIniciar.getNombre(),new Hostal(hostalIniciar.getNombre(),hostalIniciar.getDireccion(
           , hostalIniciar.getTelefono(), hostalIniciar.getHabitaciones(), hostalIniciar.getEmpleados()));
    
       this->hostalIniciar = NULL;
}

void UsuarioController :: ingresarDatosHabitacion(Habitacion* datosHabitacion) {
    this->habitacionIniciar = datosHabitacion;
}

void UsuarioController :: confirmarAltaHabitacion() {
    this->habitaciones.insert(pair<string,Habitacion*>(habitacionIniciar.getNombre(),new Habitacion(
        habitacionIniciar.getNombre(), habitacionIniciar.getPrecio(), habitacionIniciar.getCapacidad(), 
        habitacionIniciar.getHostal(), habitacionIniciar.getReservas())));
    this->habitacionIniciar = NULL;
}

void UsuarioController :: cancelarAltaHabitacion() {
     this->habitacionIniciar = NULL;
};