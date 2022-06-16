#include "ReservaIndividual.hh"

ReservaIndividual::ReservaIndividual() {
    codigo = 0;
    checkIn = DTFecha();
    checkOut = DTFecha();
    estado = abierta;
    habitacion = NULL;
}

ReservaIndividual::ReservaIndividual(int UnCodigo, Huesped* UnTitular, DTFecha UnCheckin, DTFecha UnCheckout, EstadoReserva UnEstado, Habitacion* UnaHabitacion){
    codigo = UnCodigo;
    titular = UnTitular;
    checkIn = UnCheckin;
    checkOut = UnCheckout;
    estado = UnEstado;
    habitacion = UnaHabitacion;
}

float ReservaIndividual::calcularCosto() {
    DTFecha ingreso = getCheckIn();
    DTFecha egreso = getCheckOut();
    int dif = (egreso.getDia() + (egreso.getMes()*31) + (egreso.getAnio()*31*12)) - (ingreso.getDia() + (ingreso.getMes()*31) + (ingreso.getAnio()*31*12));
    return 0; //(dif * habitacion->getPrecio());

}

ReservaIndividual::~ReservaIndividual(){
    delete &this->getCheckIn();
    delete &this->getCheckOut();
}
