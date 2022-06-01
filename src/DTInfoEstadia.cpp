#include "../include/cabezales/DTInfoEstadia.hh"

DTInfoEstadia::~DTInfoEstadia() {
}

DTInfoEstadia::DTInfoEstadia() {
    emailHuesped = "";
    nombreHostal = "";
    entrada = DTFecha();
    salida = DTFecha();
    habitacion = 0;
    promo = "";
}

DTInfoEstadia::DTInfoEstadia(string UnEmail, string UnNombre, DTFecha UnaEntrada, DTFecha UnaSalida, int UnaHabitacion, string UnaPromo, int UnCodigo) {
    emailHuesped = UnEmail;
    nombreHostal = UnNombre;
    entrada = UnaEntrada;
    salida = UnaSalida;
    habitacion = UnaHabitacion;
    promo = UnaPromo;
    codigoReserva = UnCodigo;
}

string DTInfoEstadia::getEmailHuesped() {
    return emailHuesped;
}

string DTInfoEstadia::getNombreHostal() {
    return nombreHostal;
}

DTFecha DTInfoEstadia::getEntrada() {
    return entrada;
}

DTFecha DTInfoEstadia::getSalida() {
    return salida;
}

int DTInfoEstadia::getHabitacion() {
    return habitacion;
}

string DTInfoEstadia::getPromo() {
    return promo;
}

int DTInfoEstadia::getCodigoReserva() {
    return codigoReserva;
}