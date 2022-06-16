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

list<DTCalificacion> Hostal::obtenerCalificaciones() {
	EstadiaController* controladorEstadia = EstadiaController::getInstancia();
	list<DTCalificacion> res;

	auto itr = controladorEstadia->getEstadias().begin();
    while(itr != controladorEstadia->getEstadias().end()){ //Iterar map
        Estadia *e = itr->second;
		if(e->getHostal()->getNombre() == nombre){
			if(e->getCalificacion() != NULL){
				DTCalificacion dt(
								e->getCalificacion()->getPuntaje(), 
								e->getCalificacion()->getComentario(),
								e->getCalificacion()->getFecha()
				);
				res.push_back(dt);
			}
		}
        itr++;
    }
	
	return res;
}

list<string> Hostal::obtenerComentarios() {
	EstadiaController* controladorEstadia = EstadiaController::getInstancia();
	list<string> res;

	auto itr = controladorEstadia->getEstadias().begin();
    while(itr != controladorEstadia->getEstadias().end()){ //Iterar map
        Estadia *e = itr->second;
		if(e->getHostal()->getNombre() == nombre){
			if(e->getCalificacion() != NULL)
				res.push_back(e->getCalificacion()->getComentario());
		}
        itr++;
    }
	
	return res;
}

float Hostal::obtenerPromedioCalificaciones() {
	EstadiaController* controladorEstadia = EstadiaController::getInstancia();
	float res = 0;
	int cantCalificaciones = 0;

	auto itr = controladorEstadia->getEstadias().begin();
    while(itr != controladorEstadia->getEstadias().end()){ //Iterar map
        Estadia *e = itr->second;
		if(e->getHostal()->getNombre() == nombre){
			if(e->getCalificacion() != NULL){
				res += e->getCalificacion()->getPuntaje();
				cantCalificaciones++; 
			}
		}
        itr++;
    }
	if(cantCalificaciones==0) return 0;
	else
		return res/cantCalificaciones;
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
