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
}

void Estadia :: setPromo(string promo) {
	this->promo= promo;
}

Huesped* Estadia :: getHuesped() {
	return huesped;
}

void Estadia :: setHuesped(Huesped* UnHuesped) {
	huesped = UnHuesped;
}

Estadia::Estadia() {
	entrada = DTFecha();
	salida = DTFecha();
	reserva = NULL;
	hostal = NULL;
	calificacion = NULL;
	huesped = NULL;
}

Estadia::Estadia(DTFecha UnaEntrada, DTFecha UnaSalida, string UnaPromo,Reserva* UnaReserva, Hostal* UnHostal, Calificacion* UnaCalificacion, Huesped* UnHuesped) {
	entrada = UnaEntrada;
	salida = UnaSalida;
	reserva = UnaReserva;
	hostal = UnHostal;
	calificacion = UnaCalificacion;
	huesped = UnHuesped;
}

Estadia::~Estadia() {
	delete &this->entrada;
	delete &this->salida;
	delete &this->calificacion;
}



