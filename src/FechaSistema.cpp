#include "../include/cabezales/FechaSistema.hh"

DTFecha FechaSistema::getFecha() {
	return fecha;
} 
void FechaSistema::setFecha(DTFecha UnaFecha) {
	fecha = UnaFecha;
} 

void FechaSistema::setFecha(int UnDia, int UnMes, int UnAnio, int UnaHora, int UnMinuto) {
	DTFecha ins(UnDia, UnMes, UnAnio, UnaHora, UnMinuto);
    fecha = ins;
} 

FechaSistema::FechaSistema() {
}

FechaSistema::~FechaSistema() {
}

FechaSistema* FechaSistema::instancia=NULL;
FechaSistema * FechaSistema::getInstancia(){
    if (FechaSistema::instancia == NULL)
        FechaSistema::instancia = new FechaSistema();
    return FechaSistema::instancia;
};
