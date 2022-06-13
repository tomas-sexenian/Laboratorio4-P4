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

void HabitacionController :: ingresarDatosHabitacion(Habitacion* datosHabitacion) {
    this->habitacionIniciar = datosHabitacion;
}

void HabitacionController :: confirmarAltaHabitacion() {
    this->Habitaciones.insert(pair<int,Habitacion*>(habitacionIniciar->getNumero(),new Habitacion(
        habitacionIniciar->getNumero(), habitacionIniciar->getPrecio(), habitacionIniciar->getCapacidad(), 
        habitacionIniciar->getHostal(), habitacionIniciar->getReservas())));
    this->habitacionIniciar = NULL;
}

void HabitacionController :: cancelarAltaHabitacion() {
     this->habitacionIniciar = NULL;
};

map<int,Habitacion*> HabitacionController :: getHabitaciones() {
    return this->Habitaciones;
};


Habitacion * HabitacionController :: getHabitacionIniciar() {
    return this->habitacionIniciar; 
};



list<DTHabitacion> HabitacionController::obtenerHabitacionesDisponiblesHostal(string NombreHostal, DTFecha checkInt, DTFecha checkOut) {
}

void HabitacionController::seleccionarHabitacion(int NumeroHabitacion) {
}

