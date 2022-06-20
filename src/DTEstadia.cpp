#include "../include/cabezales/DTEstadia.hh"

DTEstadia::~DTEstadia() {
}

DTEstadia::DTEstadia() {
    codigoReserva = 0;
    emailHuesped = "";
    nombreHostal = "";
    entrada = DTFecha();
    salida = DTFecha();
    habitacion = 0;
    promo = "";
}

DTEstadia::DTEstadia(int UnCodigo, string UnEmail, string UnNombre, DTFecha UnaEntrada, DTFecha UnaSalida, int UnaHabitacion, string UnaPromo) {
    codigoReserva = UnCodigo;
    emailHuesped = UnEmail;
    nombreHostal = UnNombre;
    entrada = UnaEntrada;
    salida = UnaSalida;
    habitacion = UnaHabitacion;
    promo = UnaPromo;
}

int DTEstadia::getCodigoReserva(){
    return codigoReserva;
}

string DTEstadia::getEmailHuesped() {
    return emailHuesped;
}

string DTEstadia::getNombreHostal() {
    return nombreHostal;
}

DTFecha DTEstadia::getEntrada() {
    return entrada;
}

DTFecha DTEstadia::getSalida() {
    return salida;
}

int DTEstadia::getHabitacion() {
    return habitacion;
}

string DTEstadia::getPromo() {
    return promo;
}