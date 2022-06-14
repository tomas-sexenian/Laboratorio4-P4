#include "../include/cabezales/DTReserva.hh"

DTReserva::DTReserva(int UnCodigo, string UnNombreHostal, DTFecha UnCheckin, DTFecha UnCheckout, EstadoReserva UnEstado, float UnCosto, int UnaHabitacion){
    codigo = UnCodigo;
    nombreHostal = UnNombreHostal;
    checkin = UnCheckin;
    checkout = UnCheckout;
    estado = UnEstado;
    costo = UnCosto;
    habitacion = UnaHabitacion;
}


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
};