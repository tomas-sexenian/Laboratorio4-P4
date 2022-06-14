#include "../include/controladores/UsuarioController.hh"
#include "../include/cabezales/Empleado.hh"
#include "../include/cabezales/DTHuesped.hh"

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
}
    
void UsuarioController :: ingresarDatosUsuario(Usuario* datos) {
    this->usuarioIniciar= datos; 
};


void UsuarioController :: ingresarCargo(TipoCargo cargo) { 
    this->cargo= cargo;
}

void UsuarioController :: ingresarEsFinger(bool esFinger) { 
    this->esFinger= esFinger;
}

void UsuarioController :: ingresarNuevoEmail(string email) {
    this->usuarioIniciar->setEmail(email);
}

void UsuarioController :: confirmarAltaUsuario() {
    Empleado* empleado= dynamic_cast<Empleado*>(this->usuarioIniciar);
    if (empleado) {
        Empleado* emp = new Empleado(this->usuarioIniciar->getNombre(),this->usuarioIniciar->getEmail(), this->usuarioIniciar->getContrasenia());
        emp->setCargo(cargo);
        this->Usuarios.insert(pair<string,Usuario*>(empleado->getEmail(),emp));
    }
    else {
        Huesped* huesped= dynamic_cast<Huesped*>(usuarioIniciar);
        if (huesped) {
            Huesped* hues = new Huesped(this->usuarioIniciar->getNombre(), this->usuarioIniciar->getEmail(), this->usuarioIniciar->getContrasenia());
            hues->setEsFinger(esFinger);
            this->Usuarios.insert(pair<string,Usuario*>(huesped->getNombre(),hues));
        }
    }
      
    this->usuarioIniciar = NULL;
}

void UsuarioController :: cancelarAltaUsuario() {
    this->usuarioIniciar= NULL;
}

UsuarioController :: ~UsuarioController() {   
}
