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

DTInfoEmpleado::DTInfoEmpleado(Empleado* e){
    Hostal* h = e->getHostal();

    hostal = h->getNombre();
    cargo = e->getCargo();
}

string DTInfoEmpleado::getHostal() {
    return hostal;
}

TipoCargo DTInfoEmpleado::getCargo() {
    return cargo;
}
