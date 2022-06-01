#include "../include/cabezales/DTHabitacion.hh"
#include <iostream>
#include <string>

int DTHabitacion::getNumero() {
	return numero;
}

float DTHabitacion::getPrecio() {
	return precio;
}

int DTHabitacion::getCapacidad() {
	return capacidad;
}
	
DTHabitacion::DTHabitacion() {
    numero = 0;
    precio = 0;
    capacidad = 0;
}

DTHabitacion::DTHabitacion(int UnNumero, float UnPrecio, int UnCapacidad) {
    numero = UnNumero;
    precio = UnPrecio;
    capacidad = UnCapacidad;
}

DTHabitacion::~DTHabitacion() {
}
