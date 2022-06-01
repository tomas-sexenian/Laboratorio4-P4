#include "ReservaIndividual.hh"

ReservaIndividual::ReservaIndividual() {
    codigo = 0;
    checkIn = DTFecha();
    checkOut = DTFecha();
    estado = abierta;
}

ReservaIndividual::ReservaIndividual(int UnCodigo, DTFecha UnCheckin, DTFecha UnCheckout, EstadoReserva UnEstado){
    codigo = UnCodigo;
    checkIn = UnCheckin;
    checkOut = UnCheckout;
    estado = UnEstado;
}

float ReservaIndividual::calcularCosto() {
    DTFecha ingreso = getCheckIn();
    DTFecha egreso = getCheckOut();
    int dif = (egreso.getDia() + (egreso.getMes()*31) + (egreso.getAnio()*31*12)) - (ingreso.getDia() + (ingreso.getMes()*31) + (ingreso.getAnio()*31*12));
    return 0; //(dif * habitacion->getPrecio());

}
