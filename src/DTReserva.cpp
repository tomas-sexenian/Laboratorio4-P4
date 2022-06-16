#include "../include/cabezales/DTReserva.hh"

int DTReserva::getCodigo() { 
    return codigo;
}

string DTReserva::getNombreHostal() { 
    return nombreHostal;
}

DTFecha DTReserva::getCheckin() {
    return checkin;
}

DTFecha DTReserva::getCheckout() {
    return checkout;
}

EstadoReserva DTReserva::getEstado() {
    return estado;
}

float DTReserva::getCosto() {
    return costo;
}

int DTReserva::getHabitacion() {
    return habitacion;
}

DTReserva::~DTReserva(){
    delete &this->checkin;
    delete &this->checkout;
};