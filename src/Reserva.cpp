#include "../include/cabezales/Reserva.hh"


int Reserva::getCodigo() {
	return codigo;
} 

string Reserva::getEmailTitular(){
    return emailTitular;
}

void Reserva::setEmailTitular(string email){
    emailTitular = email;
}

void Reserva::setCodigo(int val) {
	codigo = val;
}

DTFecha Reserva::getCheckIn(){
    DTFecha res;
    res = checkIn;
    return res;
}

void Reserva::setCheckIn(DTFecha UnFecha){
    checkIn = UnFecha;
}

DTFecha Reserva::getCheckOut(){
    return checkOut;
}

void Reserva::setCheckOut(DTFecha UnFecha){
    checkOut = UnFecha;
}

EstadoReserva Reserva::getEstadoReserva(){
    return estado;
}

void Reserva::setEstadoReserva(EstadoReserva Unestado){
    estado = Unestado;
}

Habitacion* Reserva::getHabitacion(){
    return habitacion;
}

void Reserva::setHabitacion(Habitacion* h){
    habitacion = h;
}