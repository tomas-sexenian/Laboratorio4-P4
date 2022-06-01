#include "../include/cabezales/DTHostal.hh"

string DTHostal::getNombre() {
    return nombre;
}

string DTHostal::getDireccion() {
    return direccion;
}

int DTHostal::getTelefono() {
    return telefono;
}

DTHostal::DTHostal() {
    nombre = "";
    direccion = "";
    telefono = 0;
}

DTHostal::DTHostal(string UnNombre, string UnaDireccion, int UnTelefono) {
    nombre = UnNombre;
    direccion = UnaDireccion;
    telefono = UnTelefono;
}

DTHostal::~DTHostal() {
}