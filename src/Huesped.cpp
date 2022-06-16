#include "../include/cabezales/Huesped.hh"

using namespace std;

bool Huesped::getEsFinger() {
	return esFinger;
} 

void Huesped::setEsFinger(bool finger) {
	esFinger = finger;
} 

Huesped::Huesped() {
    nombre = "";
    email = "";
    contrasenia = "";
    esFinger = false;
    map<int, Reserva*> lista1;
    reservas = lista1;
    list<Estadia*> lista2;
    estadias = lista2;
}

Huesped::Huesped(string UnNombre, string UnEmail, string UnaContrasenia, bool finger, map<int, Reserva*> UnasReservas ,list<Estadia*> UnasEstadias) {
    nombre = UnNombre;
    email = UnEmail;
    contrasenia = UnaContrasenia;
    esFinger = finger;
    reservas = UnasReservas;
    estadias = UnasEstadias;
}

Huesped::~Huesped(){
    for (auto const& itr : this->reservas) { //Iterar
        Reserva *r = itr.second;
        delete &r;
    }
    for (auto const& itr : this->estadias) { //Iterar
        Estadia *e = itr;
        delete &e;
    }
};

map<int, Reserva*> Huesped::getReservas(){
    return reservas;
};

void Huesped::setReserva(Reserva* r){
    reservas.insert(pair<int,Reserva*>(r->getCodigo(),r));
};

 list<Estadia*> Huesped::getEstadias(){
    return estadias;
};

void Huesped::setEstadia(Estadia* e){
    estadias.push_back(e);
};
