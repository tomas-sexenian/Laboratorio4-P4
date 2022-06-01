#include "../include/cabezales/Usuario.hh"

using namespace std;

string Usuario::getNombre() {
	return nombre;
} 

void Usuario::setNombre(string UnNombre) {
	nombre = UnNombre;
} 

string Usuario::getEmail() {
	return email;
} 

void Usuario::setEmail(string UnEmail) {
	email = UnEmail;
} 

string Usuario::getContrasenia() {
	return contrasenia;
} 

void Usuario::setContrasenia(string UnaContrasenia) {
	contrasenia = UnaContrasenia;
} 
