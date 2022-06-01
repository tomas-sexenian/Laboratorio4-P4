#include "../include/controladores/AltaDeUsuarioController.hh"

AltaDeUsuarioController::AltaDeUsuarioController() {
}

AltaDeUsuarioController::~AltaDeUsuarioController() {
}

AltaDeUsuarioController* AltaDeUsuarioController::instancia;
AltaDeUsuarioController * AltaDeUsuarioController::getInstancia(){
    if (AltaDeUsuarioController::instancia == NULL)
        AltaDeUsuarioController::instancia = new AltaDeUsuarioController();
    return AltaDeUsuarioController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void AltaDeUsuarioController::ingresarDatosUsuario(string UnNombre, string UnEmail, string UnaContrasenia) {
}

void AltaDeUsuarioController::ingresarCargo(TipoCargo cargo) {
}

void AltaDeUsuarioController::ingresarEsFinger(bool finger) {
}

void AltaDeUsuarioController::ingresarNuevoEmail(string UnEmail) {
}

void AltaDeUsuarioController::confirmarAltaUsuario() {
}

void AltaDeUsuarioController::cancelarAltaUsuario() {
}
