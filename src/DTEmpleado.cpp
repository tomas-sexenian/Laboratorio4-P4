#include "../include/cabezales/DTEmpleado.hh"

DTEmpleado::~DTEmpleado() {
}

DTEmpleado::DTEmpleado() {
    nombre = "";
    email = "";
    contrasenia = "";
    cargo = limpieza;
}

DTEmpleado::DTEmpleado(string UnNombre, string UnEmail, string UnaContrasenia, TipoCargo UnCargo) {
    nombre = UnNombre;
    email = UnEmail;
    contrasenia = UnaContrasenia;
    cargo = UnCargo;
}

TipoCargo DTEmpleado::getCargo() {
    return cargo;
}