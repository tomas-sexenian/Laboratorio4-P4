#include "./ReservaGrupal.hh"

ReservaGrupal::~ReservaGrupal(){
    //FALTA IMPLEMENTAR
}; 

ReservaGrupal::ReservaGrupal(){
    codigo = 0;
    checkIn = DTFecha();
    checkOut = DTFecha();
    estado = abierta;
    std::list<int> lista({});
    cantHuespedes = lista;
};   

ReservaGrupal::ReservaGrupal(int UnCodigo, DTFecha UnCheckIn, DTFecha UnCheckOut, EstadoReserva UnEstado,list<int> cantHuespedesPorDia){
    codigo = UnCodigo;
    checkIn = UnCheckIn;
    checkOut = UnCheckOut;
    estado = UnEstado;
    cantHuespedes = cantHuespedesPorDia;
};

list<int> ReservaGrupal::getCantHuespedes(){
    return cantHuespedes;
};

void ReservaGrupal::setCantHuespedes(int cantidad){
    cantHuespedes.push_back(cantidad);
}

ReservaGrupal::~ReservaGrupal(){
    //FALTA IMPLEMENTAR EL DESTRUCTOR DE RESERVA GRUPAL
};

float ReservaGrupal::calcularCosto(){
    DTFecha ingreso = getCheckIn();
    DTFecha egreso = getCheckOut();
    int dif = (egreso.getDia() + (egreso.getMes()*31) + (egreso.getAnio()*31*12)) - (ingreso.getDia() + (ingreso.getMes()*31) + (ingreso.getAnio()*31*12));
    return 0; //FALTA TERMINAR ESTA FUNCION
};

map<string, Huesped*> ReservaGrupal::getInvitados(){
    return invitados;
};

void ReservaGrupal::setInvitado(Huesped* h){
    invitados.insert(pair<string,Huesped*>(h->getEmail(),h));
};