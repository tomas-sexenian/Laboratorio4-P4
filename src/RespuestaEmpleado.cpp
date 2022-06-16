#include "../include/cabezales/RespuestaEmpleado.hh"

using namespace std;

string RespuestaEmpleado:: getComentario() {
	return comentario;
} 

void RespuestaEmpleado:: setComentario(string UnComentario) {
	comentario = UnComentario;
} 

DTFecha RespuestaEmpleado:: getFecha() {
	return fecha;
} 

void RespuestaEmpleado:: setFecha(DTFecha UnaFecha) {
	fecha = UnaFecha;
} 

RespuestaEmpleado::RespuestaEmpleado(string UnComentario, DTFecha UnaFecha, Calificacion* UnaCalificacion) {
	comentario = UnComentario;
	fecha = UnaFecha;
	calificacion = UnaCalificacion;
} 

RespuestaEmpleado::RespuestaEmpleado() {
	comentario = "";
	fecha = DTFecha();
	calificacion = NULL;
} 

RespuestaEmpleado::~RespuestaEmpleado() {
	delete &this->fecha;
} 

Calificacion* RespuestaEmpleado::getCalificacion() {
	return calificacion;
} 
void RespuestaEmpleado::setCalificacion(Calificacion* c) {
	calificacion = c;
}