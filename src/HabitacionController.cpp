#include "../include/controladores/HabitacionController.hh"

HabitacionController::HabitacionController() {
}

HabitacionController::~HabitacionController() {
}

HabitacionController* HabitacionController::instancia;
HabitacionController * HabitacionController::getInstancia(){
    if (HabitacionController::instancia == NULL)
        HabitacionController::instancia = new HabitacionController();
    return HabitacionController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

list<DTHabitacion> HabitacionController::obtenerHabitacionesDisponiblesHostal(string NombreHostal, DTFecha checkInt, DTFecha checkOut) {
}

void HabitacionController::seleccionarHabitacion(int NumeroHabitacion) {
}

