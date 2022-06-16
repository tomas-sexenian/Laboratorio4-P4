#include "./DTReservaGrupal.hh"

DTReservaGrupal::DTReservaGrupal(){
    codigo = -1;
    nombreHostal = "";
    checkin = checkout = DTFecha();
    estado = abierta;
    costo = -1;
    habitacion = -1;
    invitados = list<DTHuesped>{};
}

DTReservaGrupal::DTReservaGrupal(int UnCodigo,string UnNombre, DTFecha UnCheckIn, DTFecha UnCheckOut, EstadoReserva UnEstado, float UnCosto, int UnHabitacion,list<DTHuesped> UnosInvitados) {
    codigo = UnCodigo;
    nombreHostal = UnNombre;
    checkin = UnCheckIn;
    checkout = UnCheckOut;
    estado = UnEstado;
    costo = UnCosto;
    habitacion = UnHabitacion;
    invitados = UnosInvitados;
}

list<DTHuesped> DTReservaGrupal::getInvitados() {
    return invitados;
}

DTReservaGrupal::~DTReservaGrupal(){
    //FALTA IMPLEMENTAR
}
