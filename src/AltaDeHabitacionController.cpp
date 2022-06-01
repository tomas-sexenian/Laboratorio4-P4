#include "../include/controladores/AltaDeHabitacionController.hh"

AltaDeHabitacionController::AltaDeHabitacionController() {
}

AltaDeHabitacionController::~AltaDeHabitacionController() {
}

AltaDeHabitacionController* AltaDeHabitacionController::instancia;
AltaDeHabitacionController * AltaDeHabitacionController::getInstancia(){
    if (AltaDeHabitacionController::instancia == NULL)
        AltaDeHabitacionController::instancia = new AltaDeHabitacionController();
    return AltaDeHabitacionController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void AltaDeHabitacionController::ingresarDatosHabitacion(int UnNumero, float UnPrecio, int UnaCapacidad) {
}

void AltaDeHabitacionController::confirmarAltaHabitacion() {
}

void AltaDeHabitacionController::cancelarAltaHabitacion() {
}