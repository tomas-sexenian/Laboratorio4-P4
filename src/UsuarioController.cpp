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