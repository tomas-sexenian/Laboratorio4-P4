#include "../include/controladores/ReservaController.hh"

ReservaController::ReservaController() {
}

ReservaController::~ReservaController() {
}

ReservaController* ReservaController::instancia;
ReservaController * ReservaController::getInstancia(){
    if (ReservaController::instancia == NULL)
        ReservaController::instancia = new ReservaController();
    return ReservaController::instancia;
};

map<int,ReservaIndividual*> ReservaController::getReservasIndividuales() {
    return ReservasIndividuales;
}

map<int,ReservaGrupal*> ReservaController::getReservasGrupales() {
    return ReservasGrupales;
}


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void ReservaController::seleccionarReservaIndividual(int UnCodigo) {
    reservaIndividualSeleccionada = ReservasIndividuales.find(UnCodigo)->second;
}

void ReservaController::seleccionarReservaGrupal(int UnCodigo) {
    reservaGrupalSeleccionada = ReservasGrupales.find(UnCodigo)->second;
}


DTReserva ReservaController::obtenerReservaIndividual() { //Obtiene un DTReserva de reservaIndividualSeleccionada
    DTReserva res(
                    reservaIndividualSeleccionada->getCodigo(), 
                    reservaIndividualSeleccionada->getHabitacion()->getHostal()->getNombre(), 
                    reservaIndividualSeleccionada->getCheckIn(),
                    reservaIndividualSeleccionada->getCheckOut(),
                    reservaIndividualSeleccionada->getEstadoReserva(),
                    reservaIndividualSeleccionada->calcularCosto(), //Ojo que calcularCosto de individual y grupal son diferentes metodos, por eso estan separados
                    reservaIndividualSeleccionada->getHabitacion()->getNumero()
                );
    return res;
    
}

DTReserva ReservaController::obtenerReservaGrupal() { //Obtiene un DTReserva de reservaGrupalSeleccionada
    DTReserva res(
                    reservaGrupalSeleccionada->getCodigo(), 
                    reservaGrupalSeleccionada->getHabitacion()->getHostal()->getNombre(), 
                    reservaGrupalSeleccionada->getCheckIn(),
                    reservaGrupalSeleccionada->getCheckOut(),
                    reservaGrupalSeleccionada->getEstadoReserva(),
                    reservaGrupalSeleccionada->calcularCosto(),
                    reservaGrupalSeleccionada->getHabitacion()->getNumero()
                );
    return res;
    
}

list<DTReserva> ReservaController::getListaReservasNoCanceladasHuesped(string UnEmail) {
    list<DTReserva> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        if((r->getEmailTitular() == UnEmail) && (r->getEstadoReserva() != cancelada)){
            DTReserva dt(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero()
                    );
            res.push_back(dt);
        }
        itrInd++;
    }

    auto itrGrup = ReservasGrupales.begin();
    while(itrGrup != ReservasGrupales.end()){ //Iterar map
        ReservaGrupal *r = itrGrup->second;
        if((r->getEmailTitular() == UnEmail) && (r->getEstadoReserva() != cancelada)){
            DTReserva dt(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero()
                    );
            res.push_back(dt);
        }
        itrGrup++;
    }

    return res;
}

void ReservaController::confirmarConsulta() {
    reservaIndividualSeleccionada = NULL;
    reservaGrupalSeleccionada = NULL;
}

void ReservaController::ingresarDatosReservaIndividual(int UnCodigo, string UnEmail, DTFecha UnCheckin, DTFecha UnCheckout, EstadoReserva UnEstado, TipoReserva UnTipo, Habitacion* UnaHabitacion) {
    this->codigo = UnCodigo;
    this->email = UnEmail;
    this->checkIn = UnCheckin;
    this->checkOut = UnCheckout;
    this->estado = UnEstado;
    this->tipo = UnTipo;
    this->habitacion = UnaHabitacion;
}

void ReservaController::ingresarDatosReservaGrupal(int UnCodigo, string UnEmail, DTFecha UnCheckin, DTFecha UnCheckout, EstadoReserva UnEstado, TipoReserva UnTipo, Habitacion* UnaHabitacion, list<int> UnCantHuespedes) {
    this->codigo = UnCodigo;
    this->email = UnEmail;
    this->checkIn = UnCheckin;
    this->checkOut = UnCheckout;
    this->estado = UnEstado;
    this->tipo = UnTipo;
    this->habitacion = UnaHabitacion;
    this->cantHuespedes = UnCantHuespedes;
}


void ReservaController::agregarHuespedesReservaGrupal(map<string, Huesped*> UnosInvitados) {
    this->invitados = UnosInvitados;
}

void ReservaController::confirmarReserva() {
    if(habitacion->estaDisponible(this->checkIn, this->checkOut)){
       switch(tipo){
        case individual:
            ReservasIndividuales.insert(pair<int,ReservaIndividual*>(this->codigo,new ReservaIndividual(
                this->codigo,
                this->email,
                this->checkIn,
                this->checkOut,
                this->estado,
                this->habitacion
            )));
            break;
        case grupal:
            if((this->cantHuespedes.size() +1) <= habitacion->getCapacidad()){
                ReservasGrupales.insert(pair<int,ReservaGrupal*>(this->codigo,new ReservaGrupal(
                    this->codigo,
                    this->email,
                    this->checkIn,
                    this->checkOut,
                    this->estado,
                    this->habitacion,
                    this->cantHuespedes,
                    this->invitados
                )));
                break;
            }
            else
                throw std::invalid_argument( "No se realizó la reserva, la capacidad de la habitación no es suficiente");
        }
    }
    else
        throw std::invalid_argument( "No se realizó la reserva, la habitación se encuentra reservada en ese rango de fechas");
}
    

void ReservaController::cancelarReserva(int UnCodigoReserva) {
    if(ReservasIndividuales.find(UnCodigoReserva) != ReservasIndividuales.end())
        delete &ReservasIndividuales.find(UnCodigoReserva);
    else if(ReservasGrupales.find(UnCodigoReserva) != ReservasGrupales.end())
        delete &ReservasGrupales.find(UnCodigoReserva);
    else
        throw std::invalid_argument( "No se puede cancelar una reserva que no existe");
}

list<DTReserva> ReservaController::obtenerReservasHostal(string UnHostal) {
    list<DTReserva> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        if(r->getHabitacion()->getHostal()->getNombre() == UnHostal){
            DTReserva dt(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero()
                    );
            res.push_back(dt);
        }
        itrInd++;
    }

    auto itrGrup = ReservasGrupales.begin();
    while(itrGrup != ReservasGrupales.end()){ //Iterar map
        ReservaGrupal *r = itrGrup->second;
        if(r->getHabitacion()->getHostal()->getNombre() == UnHostal){
            DTReserva dt(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero()
                    );
            res.push_back(dt);
        }
        itrGrup++;
    }

    return res;
}

void ReservaController::liberarReservaIndividualSeleccionada() { //Elimina la reserva individual seleccionada
    ReservasIndividuales.erase(ReservasIndividuales.find(reservaIndividualSeleccionada->getCodigo()));
    delete reservaIndividualSeleccionada;
    reservaIndividualSeleccionada = NULL;
}

void ReservaController::liberarReservaGrupalSeleccionada() { //Elimina la reserva grupal seleccionada
    ReservasGrupales.erase(ReservasGrupales.find(reservaIndividualSeleccionada->getCodigo()));
    delete reservaGrupalSeleccionada;
    reservaGrupalSeleccionada = NULL;
}

void ReservaController::ingresarDatosReserva(int UnCodigo, DTFecha UnCheckIn, DTFecha UnCheckOut, EstadoReserva UnEstado) {
    codigo = UnCodigo;
    checkIn = UnCheckIn;
    checkOut = UnCheckOut;
    estado = UnEstado;
}

void ReservaController::seleccionarHostal(string nombreHostal) {
    HostalController* controladorHostales = HostalController::getInstancia();
    hostal = controladorHostales->getHostales().find(nombreHostal)->second;
}

void ReservaController::seleccionarHabitacion(int numeroHabitacion) {
    HostalController* controladorHostales = HostalController::getInstancia();
    habitacion = controladorHostales->getHostales().find(hostal->getNombre())->second->getHabitaciones().find(numeroHabitacion)->second;
}

void ReservaController::seleccionarTipo(TipoReserva UnTipo) {
    tipo = UnTipo;
}

void ReservaController::ingresarHuesped(string emailHuesped) {
    UsuarioController* controladorUsuarios = UsuarioController::getInstancia();
    huesped = controladorUsuarios->getHuespedes().find(emailHuesped)->second;
}

void ReservaController::ingresarInvitados(list<string> UnosInvitados) {
    UsuarioController* controladorUsuarios = UsuarioController::getInstancia();
    map<string,Huesped*> huespedes = controladorUsuarios->getHuespedes();
    for (std::list<string>::iterator it = UnosInvitados.begin(); it != UnosInvitados.end(); ++it){
        for(map<string,Huesped*>::iterator i = huespedes.begin(); i != huespedes.end(); i++){
            if (it->c_str() == i->second->getEmail())
                listaInvitados.push_back(i->second);
        }
    }
}


void ReservaController::ingresarEntradaEstadia(int anio,int mes ,int dia ,int hora ,int minuto) {
    entradaEstadia = DTFecha(anio,mes ,dia ,hora ,minuto);
}

void ReservaController::ingresarEntradaEstadia(DTFecha UnaFecha) {
    entradaEstadia = UnaFecha;
}


void ReservaController::confirmarAltaEstadia(){
    EstadiaController* controladorEstadias = EstadiaController::getInstancia();
    if (tipo == individual){
        controladorEstadias->getEstadias().insert(pair<int,Estadia*>(codigo, new Estadia(entradaEstadia,DTFecha(),promo,resIndividual,hostal,NULL,huesped)));
    } else {
        controladorEstadias->getEstadias().insert(pair<int,Estadia*>(codigo, new Estadia(entradaEstadia,DTFecha(),promo,resGrupal,hostal,NULL,huesped)));
        for (std::list<Huesped*>::iterator it = listaInvitados.begin(); it != listaInvitados.end(); ++it){
            controladorEstadias->getEstadias().insert(pair<int,Estadia*>(codigo, new Estadia(entradaEstadia,DTFecha(),promo,resGrupal,hostal,NULL,(*it))));
        }
    }
    
}