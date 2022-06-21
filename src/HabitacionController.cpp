#include "../include/controladores/HabitacionController.hh"


HabitacionController::HabitacionController() {
}

HabitacionController::~HabitacionController() {
    
}

HabitacionController* HabitacionController::instancia=NULL;
HabitacionController * HabitacionController::getInstancia(){
    if (HabitacionController::instancia == NULL)
        HabitacionController::instancia = new HabitacionController();
    return HabitacionController::instancia;
};

multimap<int,Habitacion *> HabitacionController::getHabitaciones() {
    return Habitaciones;
}


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

list<DTHabitacion> HabitacionController::obtenerHabitacionesDisponiblesHostal(string NombreHostal, DTFecha checkIn, DTFecha checkOut) {
    list<DTHabitacion> res;
    HostalController* controladorHostales = HostalController::getInstancia();
    map<int, Habitacion *> habitaciones = controladorHostales->getHostales().find(NombreHostal)->second->getHabitaciones();

    auto itrInd = habitaciones.begin();
    while(itrInd != habitaciones.end()){ //Iterar map
        Habitacion *h = itrInd->second;
        if(h->estaDisponible(checkIn, checkOut)){
            DTHabitacion dt(h->getNumero(), h->getPrecio(), h->getCapacidad());
            res.push_back(dt);
        }
        itrInd++;
    }
    return res;
}

void HabitacionController::seleccionarHabitacion(string nombreHostal, int NumeroHabitacion) {
    Habitacion *hab = NULL;
    for(multimap<int,Habitacion *>::iterator it = Habitaciones.begin(); it != Habitaciones.end(); it++)
        if(it->second->getNumero() == NumeroHabitacion && it->second->getHostal()->getNombre() == nombreHostal)
            hab = it->second;
    habitacionSeleccionada = hab;
}

//Lo que antes era altaHabitacion
void HabitacionController::ingresarDatosHabitacion(int UnNumero, float UnPrecio, int UnaCapacidad) {
    numero = UnNumero;
    precio = UnPrecio;
    capacidad = UnaCapacidad;
}

void HabitacionController::confirmarAltaHabitacion() {
    Habitacion *ins = new Habitacion(
        this->numero,
        this->precio,
        this->capacidad,
        this->hostal,
        map<int, Reserva*> {}
    );
    this->Habitaciones.insert(pair<int,Habitacion*>(this->numero, ins));
    this->hostal->setHabitacion(ins);
    cout << "La habitación ha sido registrada con exito" << endl;
}

void HabitacionController::cancelarAltaHabitacion() {
    numero = 0;
    precio = 0;
    capacidad = 0;
}

void HabitacionController::ingresarHostalHabitacion(string nombreHostal){
    HostalController* controladorHostales = HostalController::getInstancia();
    hostal = controladorHostales->getHostales().find(nombreHostal)->second;
}
    
void HabitacionController::LiberarMemoria(){
    for(multimap<int,Habitacion *>::iterator it = Habitaciones.begin(); it != Habitaciones.end(); it++)
        delete it->second;
    delete instancia;
    instancia = NULL;
}