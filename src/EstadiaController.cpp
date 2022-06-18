#include "../include/controladores/EstadiaController.hh"


EstadiaController::EstadiaController() {
}

EstadiaController::~EstadiaController() {
}

EstadiaController* EstadiaController::instancia=NULL;
EstadiaController * EstadiaController::getInstancia(){
    if (EstadiaController::instancia == NULL)
        EstadiaController::instancia = new EstadiaController();
    return EstadiaController::instancia;
};

map<int,Estadia*> EstadiaController::getEstadias() {
    return Estadias;
}

void EstadiaController::setEstadia() {
    this->Estadias.insert(pair<int,Estadia*>(this->codigoReserva ,new Estadia(this->entrada,this->salida,this->promo,NULL,NULL,NULL,NULL)));
}

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void EstadiaController::seleccionarEstadia(int codigoReserva, string emailHuesped) {
    Estadia* res = NULL;
    for(map<int,Estadia*>::iterator it = this->Estadias.begin(); it != this->Estadias.end(); it++){
        if (it->second->getReserva()->getCodigo() == codigoReserva && it->second->getHuesped()->getEmail() == emailHuesped)
            res =  it->second;
    }
    estadiaSeleccionada = res;
}

DTInfoEstadia EstadiaController::obtenerEstadia() {
    if (estadiaSeleccionada != NULL){
        DTInfoEstadia info = DTInfoEstadia(emailHuesped,estadiaSeleccionada->getHostal()->getNombre(),estadiaSeleccionada->getEntrada(),estadiaSeleccionada->getSalida(),estadiaSeleccionada->getReserva()->getHabitacion()->getNumero(),estadiaSeleccionada->getPromo(),codigoReserva);
        return info;
    }
    else{
        return DTInfoEstadia();
    }
}

Estadia* EstadiaController::finalizarEstadia() {
    if (estadiaSeleccionada != NULL){
        SistemaController* sist = SistemaController::getInstancia();
        estadiaSeleccionada->setSalida(sist->obtenerFechaActual());
    }
    ReservaController* controladorReservas = ReservaController::getInstancia();
    Reserva* r = controladorReservas->seleccionarReserva(codigoReserva);
    if(dynamic_cast<ReservaIndividual*>(r)){
         ReservaIndividual* r_individual = dynamic_cast<ReservaIndividual*>(r);
         r_individual->setEstadoReserva(cerrada);
    } else if (dynamic_cast<ReservaGrupal*>(r)){
        ReservaGrupal* r_grupal = dynamic_cast<ReservaGrupal*>(r);
        for(map<string,Huesped*>::iterator it = r_grupal->getInvitados().begin(); it != r_grupal->getInvitados().end(); it++){
            if (it->second->getEmail() == this->emailHuesped)
                r_grupal->getInvitados().erase(emailHuesped);

        }
    }
    return estadiaSeleccionada;
}

void EstadiaController::confirmarFinEstadia() {
    codigoReserva = -1;
    emailHuesped = "";
    entrada = salida = DTFecha();
    promo = "";
    estadiaSeleccionada = NULL;
}

list<DTEstadia> EstadiaController::obtenerTodasEstadiasHostal(string nombreHostal){
    list<DTEstadia> res = {};
    for(map<int,Estadia*>::iterator it = this->Estadias.begin(); it != this->Estadias.end(); it++){
        if (it->second->getHostal()->getNombre() == nombreHostal){
            DTEstadia item = DTEstadia(it->second->getHuesped()->getNombre(),it->second->getHostal()->getNombre(),it->second->getEntrada(),it->second->getSalida(),it->second->getReserva()->getHabitacion()->getNumero(),it->second->getPromo());
            res.push_back(item);
        }
    }
    return res;
}
