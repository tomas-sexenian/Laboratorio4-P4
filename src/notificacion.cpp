#include "../include/cabezales/notificacion.hh"

using namespace std;

string Notificacion:: getAutor() {
	return autor;
} 

void Notificacion::setAutor(string UnAutor) {
	autor = UnAutor;
}

string Notificacion::getComentario() {
	return comentario;
}

void Notificacion::setComentario(string UnComentario) {
	comentario = UnComentario;
}

int Notificacion::getPuntaje() {
	return puntaje;
}

void Notificacion::setPuntaje(int UnPuntaje) {
	puntaje = UnPuntaje;
}
Notificacion::Notificacion(){};
    
Notificacion::Notificacion(string,int,string){};
      
Notificacion::~Notificacion(){}; 