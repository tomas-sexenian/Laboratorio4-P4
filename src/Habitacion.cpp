#include "../include/cabezales/Habitacion.hh"

void Habitacion::setNumero (int val) {
	numero = val;
} 

int Habitacion::getNumero () {
	return numero;
}

void Habitacion::setPrecio (float val) {
	precio = val;
} 

float Habitacion::getPrecio () {
	return precio;
}

void Habitacion::setCapacidad (int val) {
	capacidad = val;
} 

int Habitacion::getCapacidad () {
	return capacidad;
}

Hostal* Habitacion::getHostal () {
	return hostal;
}

void Habitacion::setHostal (Hostal* h) {
	hostal = h;
}

map<int, Reserva*> Habitacion::getReservas () {
	return reservas;
}

void Habitacion::setReserva (Reserva* nuevaReserva) {
	reservas.insert(pair<int,Reserva*>(nuevaReserva->getCodigo(),nuevaReserva));
}

Habitacion::Habitacion() {
    numero = 0;
    precio = 0;
    capacidad = 0;
    hostal = NULL;
    map<int, Reserva*> lista;
    reservas = lista;
}

Habitacion::Habitacion(int UnNumero, float UnPrecio, int UnCapacidad,Hostal* UnHostal, map<int, Reserva*> UnasReservas) {
    numero = UnNumero;
    precio = UnPrecio;
    capacidad = UnCapacidad;
    hostal = UnHostal;
    reservas= UnasReservas;
}  

Habitacion::~Habitacion() {
    for (auto const& itr : this->reservas) { //Iterar list
        Reserva *r = itr.second;
        delete &r;
    }
}

bool Habitacion::estaDisponible(DTFecha checkIn, DTFecha checkOut) {
    auto itr = this->reservas.begin();
    bool res = true;
    while(res && (itr != this->reservas.end())){ //Iterar map
        Reserva *r = itr->second;
        if((r->getCheckIn() <= checkOut) && (checkIn <= r->getCheckOut()))
            res = false;
        itr++;
    }
    return res;
}


