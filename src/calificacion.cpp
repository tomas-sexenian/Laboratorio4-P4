#include "../include/cabezales/calificacion.hh"

using namespace std;

int Calificacion:: getPuntaje() {
	return puntaje;
} 

void Calificacion:: setPuntaje(int UnPuntaje) {
	puntaje = UnPuntaje;
} 

string Calificacion:: getComentario() {
	return comentario;
} 

void Calificacion:: setComentario(string UnComentario) {
	comentario = UnComentario;
} 

DTFecha Calificacion:: getFecha() {
	return fecha;
} 

void Calificacion:: setFecha(DTFecha UnaFecha) {
	fecha = UnaFecha;
} 

void Calificacion:: setFecha(DTFecha UnaFecha) {
	fecha = UnaFecha;
} 

Calificacion:: Calificacion(int UnPuntaje, string UnComentario, DTFecha UnaFecha, Estadia* UnaEstadia,list<RespuestaEmpleado*> UnasRespuestas) {
	puntaje = UnPuntaje;
	comentario = UnComentario;
	fecha = UnaFecha;
	estadia = UnaEstadia;
	respuestas = UnasRespuestas;
} 

Calificacion:: Calificacion() {
	puntaje = 0;
	comentario = "";
	fecha = DTFecha();
	estadia = NULL;
	list<RespuestaEmpleado*> lista;
	respuestas = lista;
} 

Calificacion::~Calificacion() {
	delete &this->fecha;
	for (auto const& itr : this->respuestas) { //Iterar list
        RespuestaEmpleado *r = itr;
        delete &r;
    }
} 

Estadia* Calificacion::getEstadia() {
	return estadia;
} 

void Calificacion::setEstadia(Estadia* e) {
	estadia = e;
}

list<RespuestaEmpleado*> Calificacion::getRespuestas() {
	return respuestas;
}

void Calificacion::setRespuesta(RespuestaEmpleado* r) {
	respuestas.push_back(r);
}