#include "../include/controladores/AltaDeHostalController.hh"

AltaDeHostalController::AltaDeHostalController() {
}

AltaDeHostalController::~AltaDeHostalController() {
}

AltaDeHostalController* AltaDeHostalController::instancia;
AltaDeHostalController * AltaDeHostalController::getInstancia(){
    if (AltaDeHostalController::instancia == NULL)
        AltaDeHostalController::instancia = new AltaDeHostalController();
    return AltaDeHostalController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void AltaDeHostalController::ingresarDatosHabitacion(int UnNumero, float UnPrecio, int UnaCapacidad) {
}

void AltaDeHostalController::confirmarAltaHabitacion() {
}

void AltaDeHostalController::cancelarAltaHabitacion() {
}