#include "../include/cabezales/Hostal.hh"

using namespace std;

Hostal::Hostal() {
	nombre = "";
	direccion = "";
	telefono = "";
	map<int, Habitacion*> lista1;
	habitaciones = lista1;
	map<string, Empleado*> lista2;
	empleados = lista2;
}

Hostal::Hostal(string UnNombre ,string UnaDireccion ,string UnTelefono ,map<int, Habitacion*> UnasHabitaciones ,map<string, Empleado*> UnosEmpleados) {
	nombre = UnNombre;
	direccion = UnaDireccion;
	telefono = UnTelefono;
	habitaciones = UnasHabitaciones;
	empleados = UnosEmpleados;
} 

Hostal::~Hostal() {
	//FALTA IMPLEMENTAR
} 

string Hostal::getNombre() {
	return nombre;
} 

void Hostal::setNombre(string UnNombre) {
	nombre = UnNombre;
}

string Hostal::getDireccion() {
	return direccion;
}

void Hostal::setDireccion(string UnaDireccion) {
	direccion = UnaDireccion;
}

string Hostal::getTelefono() {
	return telefono;
}

void Hostal::setTelefono(string UnTelefono) {
	telefono = UnTelefono;
}

map<int, Habitacion*> Hostal::getHabitaciones() {
	return habitaciones;
}

void Hostal::setHabitacion(Habitacion* h) {
	habitaciones.insert(pair<int,Habitacion*>(h->getNumero(),h));
}

map<string, Empleado*> Hostal::getEmpleados() {
	return empleados;
}

void Hostal::setEmpleado(Empleado* e) {
	empleados.insert(pair<string,Empleado*>(e->getEmail(),e));
}
