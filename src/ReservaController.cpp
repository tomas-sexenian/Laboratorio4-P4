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
    reservaIndividualSeleccionada = ReservasIndividuales.find(UnCodigo)->second;
}

void ReservaController::seleccionarReservaGrupal(int UnCodigo) {
    reservaGrupalSeleccionada = ReservasGrupales.find(UnCodigo)->second;
}

Reserva* ReservaController::seleccionarReserva(int UnCodigo) {
    Reserva *res = NULL;
    if (ReservasGrupales.count(UnCodigo) != 0)
        res = ReservasGrupales.find(UnCodigo)->second;
    else if(ReservasIndividuales.count(UnCodigo) != 0)
        res = ReservasIndividuales.find(UnCodigo)->second;
    return  res;
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

list<DTReserva> ReservaController::getListaReservasNoCanceladasHuesped(string UnEmail) {
    list<DTReserva> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        
        if((r->getTitular()->getEmail() == UnEmail) && (r->getEstadoReserva() != cancelada)){
            DTReservaIndividual dt(
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
            for(map<string,Huesped*>::iterator it = r->getInvitados().begin(); it != r->getInvitados().end(); it++){
                DTHuesped invitado_i = DTHuesped(it->second->getNombre(),it->second->getEmail(),it->second->getContrasenia(),it->second->getEsFinger());
                lstInvitados.push_back(invitado_i);
            }
            DTReservaGrupal dt(
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

void ReservaController::confirmarReserva() {
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
                    cout << "La reserva ha sido registrada con exito" << endl;
                    break;
                }
                else
                    throw std::invalid_argument( "No se realizó la reserva, la capacidad de la habitación no es suficiente");
            }
        }
        else
            throw std::invalid_argument( "No se realizó la reserva, la habitación se encuentra reservada en ese rango de fechas");
    }
    else
        throw std::invalid_argument("Las fechas de check-in y check-out no son válidas");
}
    

void ReservaController::cancelarReserva(int UnCodigoReserva) {
    if(ReservasIndividuales.find(UnCodigoReserva) != ReservasIndividuales.end()){
        delete ReservasIndividuales.find(UnCodigoReserva)->second;
        ReservasIndividuales.erase(UnCodigoReserva);
        ReservasIndividuales.find(UnCodigoReserva)->second->getTitular()->getReservas().erase(UnCodigoReserva);

        cout << "La reserva ha sido cancelada con exito" << endl;
    }
    else if(ReservasGrupales.find(UnCodigoReserva) != ReservasGrupales.end()){
        delete ReservasGrupales.find(UnCodigoReserva)->second;
        ReservasGrupales.erase(UnCodigoReserva);
        ReservasGrupales.find(UnCodigoReserva)->second->getTitular()->getReservas().erase(UnCodigoReserva);

        cout << "La reserva ha sido cancelada con exito" << endl;
    }
    else
        throw std::invalid_argument( "No se puede cancelar una reserva que no existe");
}

list<DTReserva> ReservaController::obtenerReservasHostal(string UnHostal) {
    list<DTReserva> res;

    auto itrInd = ReservasIndividuales.begin();
    while(itrInd != ReservasIndividuales.end()){ //Iterar map
        ReservaIndividual *r = itrInd->second;
        if(r->getHabitacion()->getHostal()->getNombre() == UnHostal){
            DTReservaIndividual dt(
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
            for(map<string,Huesped*>::iterator it = r->getInvitados().begin(); it != r->getInvitados().end(); it++){
                DTHuesped invitado_i = DTHuesped(it->second->getNombre(),it->second->getEmail(),it->second->getContrasenia(),it->second->getEsFinger());
                lstInvitados.push_back(invitado_i);
            }
            DTReservaGrupal dt(
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
    cout << "La estadía ha sido registrada con exito" << endl;
}
