#include "../include/cabezales/DTInfoBasicaHostal.hh"

DTInfoBasicaHostal::~DTInfoBasicaHostal() {
}

DTInfoBasicaHostal::DTInfoBasicaHostal() {
    nombre = "";
    direccion = "";
    telefono = 0;
    promedioCalificaciones = 0;
    list<DTCalificacion> lista;
    calificaciones = lista;
}

DTInfoBasicaHostal::DTInfoBasicaHostal(string UnNombre, string UnaDireccion, int UnTelefono, float UnPromedio, list<DTCalificacion> UnasCalificaciones) {
    nombre = UnNombre;
    direccion = UnaDireccion;
    telefono = UnTelefono;
    promedioCalificaciones = UnPromedio;
    calificaciones = UnasCalificaciones;
}

string DTInfoBasicaHostal::getNombre() {
    return nombre;
}

string DTInfoBasicaHostal::getDireccion() {
    return direccion;
}

int DTInfoBasicaHostal::getTelefono() {
    return telefono;
}

float DTInfoBasicaHostal::getPromedioCalificaciones() {
    return promedioCalificaciones;
}

list<DTCalificacion> DTInfoBasicaHostal::getCalificaciones() {
    return calificaciones;
}