#include "./ReservaGrupal.hh"

ReservaGrupal::~ReservaGrupal(){
    //FALTA IMPLEMENTAR
}; 

ReservaGrupal::ReservaGrupal(){
    codigo = 0;
    titular = NULL;
    checkIn = DTFecha();
    checkOut = DTFecha();
    estado = abierta;
    habitacion = NULL;
    invitados =  map<string, Huesped*>{};
};   

ReservaGrupal::ReservaGrupal(int UnCodigo, Huesped* UnTitular, DTFecha UnCheckIn, DTFecha UnCheckOut, EstadoReserva UnEstado, Habitacion *UnaHabitacion, map<string, Huesped*> UnosInvitados){
    codigo = UnCodigo;
    titular = UnTitular;
    checkIn = UnCheckIn;
    checkOut = UnCheckOut;
    estado = UnEstado;
    habitacion = UnaHabitacion;
    invitados = UnosInvitados;
};

int ReservaGrupal::getCantHuespedes(){
    int res = 0;
    for(map<string,Huesped*>::iterator it = this->invitados.begin(); it != this->invitados.end(); it++)
        res++;
    return res + 1;
};

ReservaGrupal::~ReservaGrupal(){
    delete &this->getCheckIn();
    delete &this->getCheckOut();
};

float ReservaGrupal::calcularCosto(){
    DTFecha ingreso = getCheckIn();
    DTFecha egreso = getCheckOut();
    int dif = (egreso.getDia() + (egreso.getMes()*31) + (egreso.getAnio()*31*12)) - (ingreso.getDia() + (ingreso.getMes()*31) + (ingreso.getAnio()*31*12));
    int cantFingers = 0;
    for(map<string,Huesped*>::iterator it = this->invitados.begin(); it != this->invitados.end(); it++)
        if (it->second->getEsFinger())
            cantFingers++;
    if ((cantFingers = 1 && this->getTitular()->getEsFinger()) || (cantFingers > 2))
        return dif * this->calcularCosto() * 0.7;
    return dif * this->calcularCosto();
};

map<string, Huesped*> ReservaGrupal::getInvitados(){
    return invitados;
};

void ReservaGrupal::setInvitado(Huesped* h){
    invitados.insert(pair<string,Huesped*>(h->getEmail(),h));
};
