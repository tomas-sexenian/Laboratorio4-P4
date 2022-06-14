#include "../include/cabezales/Hostal.hh"

using namespace std;

Hostal::Hostal() {
	nombre = "";
	direccion = "";
	telefono = 0;
	map<int, Habitacion*> lista1;
	habitaciones = lista1;
	map<string, Empleado*> lista2;
	empleados = lista2;
}

Hostal::Hostal(string UnNombre ,string UnaDireccion ,int UnTelefono ,map<int, Habitacion*> UnasHabitaciones ,map<string, Empleado*> UnosEmpleados) {
	nombre = UnNombre;
	direccion = UnaDireccion;
	telefono = UnTelefono;
	habitaciones = UnasHabitaciones;
	empleados = UnosEmpleados;
} 

Hostal::Hostal(string UnNombre ,string UnaDireccion ,int UnTelefono) {
	nombre = UnNombre;
	direccion = UnaDireccion;
	telefono = UnTelefono;
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

int Hostal::getTelefono() {
	return telefono;
}

void Hostal::setTelefono(int UnTelefono) {
	telefono = UnTelefono;
}

float Hostal::obtenerPromedioCalificaciones() {
	//FALTA IMPLEMENTAR
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

map<string, Estadia*> Hostal::getEstadias() {
	return estadias;
}

void Hostal::setEstadia(Estadia* e) {
	estadias.insert(pair<string,Estadia*>(e->getPromo(),e));
}


