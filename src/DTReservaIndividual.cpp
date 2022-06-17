#include "../cabezales/DTReservaIndividual.hh"

DTReservaIndividual::DTReservaIndividual() {
    codigo = 0;
    nombreHostal = "";
    checkin = DTFecha();
    checkout = DTFecha();
    estado = abierta;
    costo = 0;
    habitacion = 0;
}

DTReservaIndividual::DTReservaIndividual(int UnCodigo,string UnNombre, DTFecha Uncheckin, DTFecha Uncheckout, EstadoReserva UnEstado, float UnCosto, int UnaHabitacion) { 
    codigo = UnCodigo;
    nombreHostal = UnNombre;
    checkin = Uncheckin;
    checkout = Uncheckout;
    estado = UnEstado;
    costo = UnCosto;
    habitacion = UnaHabitacion;
}

DTReservaIndividual::~DTReservaIndividual() {
    //FALTA IMPLEMENTAR
};