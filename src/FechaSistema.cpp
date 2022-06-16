#include "../include/cabezales/FechaSistema.hh"

DTFecha FechaSistema::getFecha() {
	return fecha;
} 

void FechaSistema::setFecha(DTFecha UnaFecha) {
	fecha = UnaFecha;
} 

FechaSistema::FechaSistema() {
}

FechaSistema::~FechaSistema() {
    delete &this->fecha;
}

FechaSistema* FechaSistema::instancia;
FechaSistema * FechaSistema::getInstancia(){
    if (FechaSistema::instancia == NULL)
        FechaSistema::instancia = new FechaSistema();
    return FechaSistema::instancia;
};
