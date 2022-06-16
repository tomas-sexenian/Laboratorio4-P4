#include "../include/cabezales/Empleado.hh"

using namespace std;

TipoCargo Empleado::getCargo() {
	return cargo;
} 

void Empleado::setCargo(TipoCargo UnCargo) {
	cargo = UnCargo;
} 

Empleado::Empleado() {
    nombre = "";
    email = "";
    contrasenia = "";
    cargo = limpieza;
    list<Notificacion*> lista1;
    notificaciones = lista1;
    hostal = NULL;
    list<RespuestaEmpleado*> lista2;
    respuestas = lista2;
}

Empleado::Empleado(string UnNombre, string UnEmail, string UnaContrasenia, TipoCargo UnCargo, list<Notificacion*> UnasNotificaciones ,Hostal* UnHostal ,list<RespuestaEmpleado*> UnasRespuestas) {
    nombre = UnNombre;
    email = UnEmail;
    contrasenia = UnaContrasenia;
    cargo = UnCargo;
    notificaciones = UnasNotificaciones;
    hostal = UnHostal;
    respuestas = UnasRespuestas;
}

Empleado::~Empleado(){
    /*for (auto const& itr : this->notificaciones) { //Iterar list
        Notificacion *n = itr;
        delete &n;
    }*/
	for (auto const& itr : this->respuestas) { //Iterar list
        RespuestaEmpleado *r = itr;
        delete &r;
    }
};

void Empleado::notificar(){
    //HAY QUE IMPLEMENTAR 
};

bool Empleado::EsEmpleado(){
    //HAY QUE IMPLEMENTAR 
};

list<Notificacion*> Empleado::getNotificaciones(){
    return notificaciones;
};

void Empleado::setNotificacion(Notificacion* n){
    notificaciones.push_back(n);
};

Hostal* Empleado::getHostal(){
    return hostal;
};

void Empleado::setHostal(Hostal* h){
    hostal = h;
};

list<RespuestaEmpleado*> Empleado::getRespuestas(){
    return respuestas;
};

void Empleado::setRespuesta(RespuestaEmpleado* r){
    respuestas.push_back(r);
};



