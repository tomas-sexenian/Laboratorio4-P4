#include "../include/controladores/ReservaController.hh"



ReservaController::ReservaController() {
}

ReservaController::~ReservaController() {

}

ReservaController* ReservaController::instancia=NULL;
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
    if(ReservasIndividuales.count(UnCodigo) == 0) throw std::invalid_argument( "No se puede seleccionar una reserva que no existe");
    else reservaIndividualSeleccionada = ReservasIndividuales.find(UnCodigo)->second;
}

void ReservaController::seleccionarReservaGrupal(int UnCodigo) {
    if(ReservasGrupales.count(UnCodigo) == 0) throw std::invalid_argument( "No se puede seleccionar una reserva que no existe");
    else reservaGrupalSeleccionada = ReservasGrupales.find(UnCodigo)->second;
}

Reserva* ReservaController::obtenerReserva(int UnCodigo) {
    Reserva *res = NULL;
    if (ReservasGrupales.count(UnCodigo) != 0)
        res = ReservasGrupales.find(UnCodigo)->second;
    else if(ReservasIndividuales.count(UnCodigo) != 0)
        res = ReservasIndividuales.find(UnCodigo)->second;
    else throw std::invalid_argument( "No se puede seleccionar una reserva que no existe");
    return res;
}


DTReservaIndividual ReservaController::obtenerReservaIndividual() { //Obtiene un DTReserva de reservaIndividualSeleccionada
    DTReservaIndividual res(
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

//(int,string,DTFecha,DTFecha,EstadoReserva,float,int,list<DTHuesped>
DTReservaGrupal ReservaController::obtenerReservaGrupal() { //Obtiene un DTReserva de reservaGrupalSeleccionada
    map<std::string, Huesped *> invitados = reservaGrupalSeleccionada->getInvitados();
    list<DTHuesped> lstInvitados = {};
    for(map<string,Huesped*>::iterator it = invitados.begin(); it != invitados.end(); it++){
        DTHuesped invitado_i = DTHuesped(it->second->getNombre(),it->second->getEmail(),it->second->getContrasenia(),it->second->getEsFinger());
        lstInvitados.push_back(invitado_i);
    }

    DTReservaGrupal res = DTReservaGrupal(
                    reservaGrupalSeleccionada->getCodigo(), 
                    reservaGrupalSeleccionada->getHabitacion()->getHostal()->getNombre(), 
                    reservaGrupalSeleccionada->getCheckIn(),
                    reservaGrupalSeleccionada->getCheckOut(),
                    reservaGrupalSeleccionada->getEstadoReserva(),
                    reservaGrupalSeleccionada->calcularCosto(),
                    reservaGrupalSeleccionada->getHabitacion()->getNumero(),
                    lstInvitados
                );
    return res;
    
}

list<DTReserva*> ReservaController::getListaReservasNoCanceladasHostal(string nombreHostal) {
    list<DTReserva*> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        
        if((r->getHabitacion()->getHostal()->getNombre() == nombreHostal) && (r->getEstadoReserva() != cancelada)){
            DTReservaIndividual *dt = new DTReservaIndividual(
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
        if((r->getHabitacion()->getHostal()->getNombre() == nombreHostal) && (r->getEstadoReserva() != cancelada)){
            list<DTHuesped> lstInvitados = {};
            map<string,Huesped*> invitados = r->getInvitados();
            for(map<string,Huesped*>::iterator it = invitados.begin(); it != invitados.end(); it++){
                DTHuesped invitado_i = DTHuesped(it->second->getNombre(),it->second->getEmail(),it->second->getContrasenia(),it->second->getEsFinger());
                lstInvitados.push_back(invitado_i);
            }
            DTReservaGrupal *dt = new DTReservaGrupal(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero(),
                        lstInvitados
                    );
            res.push_back(dt);
        }
        itrGrup++;
    }

    return res;
}


list<DTReserva*> ReservaController::getListaReservasNoCanceladasHuesped(string UnEmail) {
    list<DTReserva*> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        
        if((r->getTitular()->getEmail() == UnEmail) && (r->getEstadoReserva() != cancelada)){
            DTReservaIndividual *dt = new DTReservaIndividual(
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
        if((r->getTitular()->getEmail() == UnEmail) && (r->getEstadoReserva() != cancelada)){
            list<DTHuesped> lstInvitados = {};
            map<string,Huesped*> invitados = r->getInvitados();
            for(map<string,Huesped*>::iterator it = invitados.begin(); it != invitados.end(); it++){
                DTHuesped invitado_i = DTHuesped(it->second->getNombre(),it->second->getEmail(),it->second->getContrasenia(),it->second->getEsFinger());
                lstInvitados.push_back(invitado_i);
            }
            DTReservaGrupal *dt = new DTReservaGrupal(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero(),
                        lstInvitados
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

void ReservaController::confirmarReserva(bool conRetorno) {
    if(this->checkIn < this->checkOut){
        if(habitacion->estaDisponible(this->checkIn, this->checkOut)){
        switch(tipo){
            case individual:
                ReservaIndividual *ins;
                ins = new ReservaIndividual(
                    this->codigo,
                    this->huesped,
                    this->checkIn,
                    this->checkOut,
                    this->estado,
                    this->habitacion
                );
                ReservasIndividuales.insert(pair<int,ReservaIndividual*>(this->codigo, ins));
                this->huesped->getReservas().insert(pair<int,ReservaIndividual*>(this->codigo, ins));
                if (conRetorno)
                    cout << "La reserva ha sido registrada con exito" << endl;
                break;
            case grupal:
                int cantInvi = this->invitados.size();
                if((cantInvi+1) <= habitacion->getCapacidad()){
                    ReservaGrupal *ins;
                    ins = new ReservaGrupal(
                        this->codigo,
                        this->huesped,
                        this->checkIn,
                        this->checkOut,
                        this->estado,
                        this->habitacion,
                        this->invitados
                    );
                    ReservasGrupales.insert(pair<int,ReservaGrupal*>(this->codigo,ins));
                    this->huesped->getReservas().insert(pair<int,ReservaGrupal*>(this->codigo,ins));
                    if (conRetorno)
                        cout << "La reserva ha sido registrada con exito" << endl;
                    break;
                }
                else
                    throw std::invalid_argument( "No se realiz?? la reserva, la capacidad de la habitaci??n no es suficiente");
            }
        }
        else
            throw std::invalid_argument( "No se realiz?? la reserva, la habitaci??n se encuentra reservada en ese rango de fechas");
    }
    else
        throw std::invalid_argument("Las fechas de check-in y check-out no son v??lidas");
}
    

void ReservaController::cancelarReserva(int UnCodigoReserva) {
    if(ReservasIndividuales.find(UnCodigoReserva) != ReservasIndividuales.end()){
        ReservasIndividuales.find(UnCodigoReserva)->second->setEstadoReserva(cancelada);
        cout << "La reserva ha sido cancelada con exito" << endl;
    }
    else if(ReservasGrupales.find(UnCodigoReserva) != ReservasGrupales.end()){
        ReservasGrupales.find(UnCodigoReserva)->second->setEstadoReserva(cancelada);
        cout << "La reserva ha sido cancelada con exito" << endl;
    }
    else
        throw std::invalid_argument( "No se puede cancelar una reserva que no existe");
}

list<DTReserva*> ReservaController::obtenerReservasHostal(string UnHostal) {
    list<DTReserva*> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        if(r->getHabitacion()->getHostal()->getNombre() == UnHostal){
            DTReservaIndividual *dt = new DTReservaIndividual(
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
            list<DTHuesped> lstInvitados = {};
            map<string,Huesped*> invitados = r->getInvitados();
            for(map<string,Huesped*>::iterator it = invitados.begin(); it != invitados.end(); it++){
                DTHuesped invitado_i = DTHuesped(it->second->getNombre(),it->second->getEmail(),it->second->getContrasenia(),it->second->getEsFinger());
                lstInvitados.push_back(invitado_i);
            }
            DTReservaGrupal *dt = new DTReservaGrupal(
                        r->getCodigo(), 
                        r->getHabitacion()->getHostal()->getNombre(), 
                        r->getCheckIn(),
                        r->getCheckOut(),
                        r->getEstadoReserva(),
                        r->calcularCosto(),
                        r->getHabitacion()->getNumero(),
                        lstInvitados
                    );
            res.push_back(dt);
        }
        itrGrup++;
    }

    return res;
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

int ReservaController::capacidadHabitacionSeleccionada(){
    return habitacion->getCapacidad();
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

void ReservaController::LiberarMemoria(){
    for(map<int,ReservaIndividual*>::iterator it = ReservasIndividuales.begin(); it != ReservasIndividuales.end(); it++)
        delete it->second;
    for(map<int,ReservaGrupal*>::iterator it = ReservasGrupales.begin(); it != ReservasGrupales.end(); it++)
        delete it->second;   
    delete instancia;
    instancia = NULL; 
}