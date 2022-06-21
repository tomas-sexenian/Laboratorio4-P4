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

multimap<int,Estadia*> EstadiaController::getEstadias() {
    return Estadias;
}


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void EstadiaController::seleccionarEstadia(int codigoReserva, string email) {
    Estadia* res = NULL;
    for(multimap<int,Estadia*>::iterator it = this->Estadias.begin(); it != this->Estadias.end(); it++){
        if (it->second->getReserva()->getCodigo() == codigoReserva && it->second->getHuesped()->getEmail() == email)
            res =  it->second;
    }
    if(res == NULL) throw std::invalid_argument( "No se puede seleccionar una estadia que no existe");
    estadiaSeleccionada = res;
}

Estadia* EstadiaController::obtenerEstadia(int codigoReserva, string email) {
    Estadia* res = NULL;
    for(multimap<int,Estadia*>::iterator it = this->Estadias.begin(); it != this->Estadias.end(); it++){
        if (it->second->getReserva()->getCodigo() == codigoReserva && it->second->getHuesped()->getEmail() == email)
            res =  it->second;
    }
    if(res == NULL) throw std::invalid_argument( "No se puede obtener una estadia que no existe");
    return res;
}

DTInfoEstadia EstadiaController::obtenerInfoEstadia() {
    if (estadiaSeleccionada != NULL){
        DTInfoEstadia info = DTInfoEstadia(emailHuesped,estadiaSeleccionada->getHostal()->getNombre(),estadiaSeleccionada->getEntrada(),estadiaSeleccionada->getSalida(),estadiaSeleccionada->getReserva()->getHabitacion()->getNumero(),estadiaSeleccionada->getPromo(),codigoReserva);
        return info;
    }
    else{
        return DTInfoEstadia();
    }
}

Estadia* EstadiaController::finalizarEstadia() {
    if (estadiaSeleccionada == NULL)
        throw std::invalid_argument( "Debe haber una estadia seleccionada");
    
    SistemaController* sist = SistemaController::getInstancia ();
    estadiaSeleccionada->setSalida(sist->obtenerFechaActual());
    ReservaController* controladorReservas = ReservaController::getInstancia();
    Reserva* r = controladorReservas->obtenerReserva(estadiaSeleccionada->getReserva()->getCodigo());
    r->setEstadoReserva(cerrada);
    
    return estadiaSeleccionada;
}

void EstadiaController::confirmarFinEstadia() {
    codigoReserva = -1;
    emailHuesped = "";
    entrada = salida = DTFecha();
    promo = "";
    estadiaSeleccionada = NULL;
}

list<DTEstadia*> EstadiaController::obtenerTodasEstadiasHostal(string nombreHostal){
    list<DTEstadia*> res = {};
    for(multimap<int,Estadia*>::iterator it = this->Estadias.begin(); it != this->Estadias.end(); it++){
        if (it->second->getHostal()->getNombre() == nombreHostal){
            DTEstadia *item = new DTEstadia(it->second->getReserva()->getCodigo() ,it->second->getHuesped()->getEmail(),it->second->getHostal()->getNombre(),it->second->getEntrada(),it->second->getSalida(),it->second->getReserva()->getHabitacion()->getNumero(),it->second->getPromo());
            res.push_back(item);
        }
    }
    return res;
}



void EstadiaController::seleccionarReserva(int UnCodigo){
    ReservaController* controladorReservas = ReservaController::getInstancia();
    reservaSeleccionada = controladorReservas->obtenerReserva(UnCodigo);
}

void EstadiaController::seleccionarTipo(TipoReserva UnTipo){
    tipoReserva = UnTipo;
}

void EstadiaController::ingresarHuesped(string UnEmail){
    UsuarioController* controladorUsuarios = UsuarioController::getInstancia();
    huesped = controladorUsuarios->getHuespedes().find(UnEmail)->second;
}

void EstadiaController::ingresarInvitados(list<string> UnosInvitados){
    invitados = UnosInvitados;
}

void EstadiaController::ingresarEntradaEstadia(int UnDia, int UnMes, int UnAnio, int UnaHora, int UnMinuto){
    entrada = DTFecha(UnDia, UnMes, UnAnio, UnaHora, UnMinuto);
}


void EstadiaController::confirmarAltaEstadia(){
    if (tipoReserva == individual){
        Estadias.insert(pair<int,Estadia*>(reservaSeleccionada->getCodigo(), new Estadia(entrada,DTFecha(),"",reservaSeleccionada,reservaSeleccionada->getHabitacion()->getHostal(),NULL,huesped)));
    } else {
        Estadia *est = new Estadia(entrada,DTFecha(),"",reservaSeleccionada,reservaSeleccionada->getHabitacion()->getHostal(),NULL,huesped);
        Estadias.insert(pair<int,Estadia*>(reservaSeleccionada->getCodigo(), est));
        UsuarioController* controladorUsuarios = UsuarioController::getInstancia();
        for (std::list<string>::iterator it = invitados.begin(); it != invitados.end(); ++it){
            Huesped *i = controladorUsuarios->getHuespedes().find(*it)->second;
            i->setEstadia(est);
        }
    }
    cout << "La estadia ha sido registrada con exito" << endl;
}
