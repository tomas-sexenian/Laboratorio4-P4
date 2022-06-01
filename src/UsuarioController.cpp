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

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

DTInfoUsuario UsuarioController::seleccionarUsuario(string EmailUsuario) {
}

void UsuarioController::confirmarConsulta() {
}

void UsuarioController::ingresarFecha(DTFecha UnaFecha) {
}

void UsuarioController::actualizarFecha(DTFecha UnaFecha) {
}

void UsuarioController::ingresarEmpleado(Empleado e) {
}