#include "../include/cabezales/DTUsuario.hh"

string DTUsuario::getNombre() {
    return nombre;
}

string DTUsuario::getEmail() {
    return email;
}

string DTUsuario::getContrasenia() {
    return contrasenia;
}

DTUsuario::DTUsuario() {
    nombre = email = contrasenia = "";
}

DTUsuario::DTUsuario(string UnNombre, string UnEmail, string UnaContrasenia) {
    nombre = UnNombre;
    email = UnEmail;
    contrasenia = UnaContrasenia;
}

DTUsuario::~DTUsuario() {
}