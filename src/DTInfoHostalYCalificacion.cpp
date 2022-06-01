#include "../include/cabezales/DTInfoHostalYCalificacion.hh"

float DTInfoHostalYCalificacion::getPromedioCalificaciones() {
	return promedioCalificaciones;
}

DTHostal DTInfoHostalYCalificacion::getHostal() {
	return hostal;
}
	
DTInfoHostalYCalificacion::DTInfoHostalYCalificacion() {
    hostal = DTHostal();
    promedioCalificaciones = 0;
}

DTInfoHostalYCalificacion::DTInfoHostalYCalificacion(DTHostal UnHostal, float UnPromedio) {
    hostal = UnHostal;
    promedioCalificaciones = UnPromedio;
}

DTInfoHostalYCalificacion::~DTInfoHostalYCalificacion() {
}