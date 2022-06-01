#include "../include/cabezales/DTInfoEmpleado.hh"

DTInfoEmpleado::~DTInfoEmpleado() {
}

DTInfoEmpleado::DTInfoEmpleado() {
    hostal = "";
    cargo = limpieza;
}

DTInfoEmpleado::DTInfoEmpleado(string UnHostal, TipoCargo UnCargo) {
    hostal = UnHostal;
    cargo = UnCargo;
}

string DTInfoEmpleado::getHostal() {
    return hostal;
}

TipoCargo DTInfoEmpleado::getCargo() {
    return cargo;
}
