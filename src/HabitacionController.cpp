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


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

list<DTHabitacion> HabitacionController::obtenerHabitacionesDisponiblesHostal(string NombreHostal, DTFecha checkInt, DTFecha checkOut) {
    //HACER
}

void HabitacionController::seleccionarHabitacion(int NumeroHabitacion) {
    Habitacion *hab = Habitaciones.find(NumeroHabitacion)->second;
    habitacionSeleccionada = hab;
}

//Lo que antes era altaHabitacion
void HabitacionController::ingresarDatosHabitacion(int UnNumero, float UnPrecio, int UnaCapacidad) {
    numero = UnNumero;
    precio = UnPrecio;
    capacidad = UnaCapacidad;
}

void HabitacionController::confirmarAltaHabitacion() {
    this->Habitaciones.insert(pair<int,Habitacion*>(this->numero,new Habitacion(
        this->numero,
        this->precio,
        this->capacidad,
        NULL,
        map<int, Reserva*> {}
    )));
}

void HabitacionController::cancelarAltaHabitacion() {
    numero = 0;
    precio = 0;
    capacidad = 0;
}

void HabitacionController::ingresarDatosHabitacion(int UnNumero, float UnPrecio, int UnaCapacidad) {
    numero = UnNumero;
    precio = UnPrecio;
    capacidad = UnaCapacidad;
}

void HabitacionController::ingresarHostalHabitacion(string nombreHostal){
    HostalController* controladorHostales = HostalController::getInstancia();
    hostal = controladorHostales->getHostales().find(nombreHostal)->second;
}
    