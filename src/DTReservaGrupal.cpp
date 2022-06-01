#include "./DTReservaGrupal.hh"

DTReservaGrupal::DTReservaGrupal() {
    codigo = 0;
    nombreHostal = "";
    checkin = DTFecha();
    checkout = DTFecha();
    estado = abierta;
    costo = 0;
    habitacion = 0;
    list<DTHuesped> lista1;
    invitados = lista1;
    list<int> lista2;
    cantHuespedes = lista2;
}

DTReservaGrupal::DTReservaGrupal(int UnCodigo,string UnNombre, DTFecha UnCheckIn, DTFecha UnCheckOut, EstadoReserva UnEstado, float UnCosto, int UnHabitacion,list<DTHuesped> UnosInvitados,list<int> UnasCantidades) {
    codigo = UnCodigo;
    nombreHostal = UnNombre;
    checkin = UnCheckIn;
    checkout = UnCheckOut;
    estado = UnEstado;
    costo = UnCosto;
    habitacion = UnHabitacion;
    invitados = UnosInvitados;
    cantHuespedes = UnasCantidades;
}

list<DTHuesped> DTReservaGrupal::getInvitados() {
    return invitados;
}

list<int> DTReservaGrupal::getCantHuespedes() {
    return cantHuespedes;
}

DTReservaGrupal::~DTReservaGrupal(){
    //FALTA IMPLEMENTAR
}
