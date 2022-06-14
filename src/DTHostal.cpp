#include "../include/cabezales/DTHostal.hh"

string DTHostal::getNombre() {
    return nombre;
}

string DTHostal::getDireccion() {
    return direccion;
}

string DTHostal::getTelefono() {
    return telefono;
}

DTHostal::DTHostal() {
    nombre = "";
    direccion = "";
    telefono = "";
}

DTHostal::DTHostal(string UnNombre, string UnaDireccion, string UnTelefono) {
    nombre = UnNombre;
    direccion = UnaDireccion;
    telefono = UnTelefono;
}

DTHostal::~DTHostal() {
}