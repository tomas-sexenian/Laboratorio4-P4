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

map<int,Habitacion *> HabitacionController::getHabitaciones() {
    return Habitaciones;
}

void HabitacionController::setHabitacion() {
    this->Habitaciones.insert(pair<int,Habitacion*>(this->numero,new Habitacion(
        this->numero,
        this->precio,
        this->capacidad,
        NULL,
        map<int, Reserva*> {}
    )));
}

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

list<DTHabitacion> HabitacionController::obtenerHabitacionesDisponiblesHostal(string NombreHostal, DTFecha checkInt, DTFecha checkOut) {
}

void HabitacionController::seleccionarHabitacion(int NumeroHabitacion) {
}

