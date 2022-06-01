#include "../include/cabezales/DTEstadia.hh"

DTEstadia::~DTEstadia() {
}

DTEstadia::DTEstadia() {
    emailHuesped = "";
    nombreHostal = "";
    entrada = DTFecha();
    salida = DTFecha();
    habitacion = 0;
    promo = "";
}

DTEstadia::DTEstadia(string UnEmail, string UnNombre, DTFecha UnaEntrada, DTFecha UnaSalida, int UnaHabitacion, string UnaPromo) {
    emailHuesped = UnEmail;
    nombreHostal = UnNombre;
    entrada = UnaEntrada;
    salida = UnaSalida;
    habitacion = UnaHabitacion;
    promo = UnaPromo;
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