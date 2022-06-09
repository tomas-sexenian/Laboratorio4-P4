#include "../include/cabezales/Estadia.hh"

DTFecha Estadia::getEntrada() {
	return entrada;
} 

void Estadia::setEntrada(DTFecha UnaEntrada) {
	entrada = UnaEntrada;
} 

DTFecha Estadia::getSalida() {
	return salida;
} 

void Estadia::setSalida(DTFecha UnaSalida) {
	salida = UnaSalida;
} 

void Estadia::agregar(Observer* o) {
	observers.push_back(o);
} 

void Estadia::eliminar(Observer* o) {
	observers.remove(o);
} 

void Estadia::notificar() {
	//FALTA IMPLEMENTAR
} 

Reserva* Estadia::getReserva() {
	return reserva;
} 

void Estadia::setReserva(Reserva* r) {
	reserva = r;
} 

Hostal* Estadia::getHostal() {
	return hostal;
} 

void Estadia::setHostal(Hostal* h) {
	hostal = h;
}

Calificacion* Estadia::getCalificacion() {
	return calificacion;
}

void Estadia::setCalificacion(Calificacion* c) {
	calificacion = c;
}

string Estadia :: getPromo() {
	return promo;
        
void Estadia :: setPromo(string promo) {
	this->promo= promo;


Estadia::Estadia() {
	entrada = DTFecha();
	salida = DTFecha();
	list<Observer*> lista;
	observers = lista;
	reserva = NULL;
	hostal = NULL;
	calificacion = NULL;
}

Estadia::Estadia(DTFecha UnaEntrada, DTFecha UnaSalida, string UnaPromo, list<Observer*> UnosObservers,Reserva* UnaReserva, Hostal* UnHostal, Calificacion* UnaCalificacion) {
	entrada = UnaEntrada;
	salida = UnaSalida;
	observers = UnosObservers;
	reserva = UnaReserva;
	hostal = UnHostal;
	calificacion = UnaCalificacion;
}

Estadia::~Estadia() {
	//FALTA IMPLEMENTAR EL DESTRCUTOR
}

