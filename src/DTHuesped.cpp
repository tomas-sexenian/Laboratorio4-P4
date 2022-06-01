#include "../include/cabezales/DTHuesped.hh"

DTHuesped::~DTHuesped() {
}

DTHuesped::DTHuesped() {
    nombre = "";
    email = "";
    contrasenia = "";
    esFinger = false;
}

DTHuesped::DTHuesped(string UnNombre, string UnEmail, string UnaContrasenia, bool finger) {
    nombre = UnNombre;
    email = UnEmail;
    contrasenia = UnaContrasenia;
    esFinger = finger;
}

int DTHuesped::getEsFinger() {
    return esFinger;
}



