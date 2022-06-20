#include "../include/controladores/HostalController.hh"


HostalController::HostalController() {
}

HostalController::~HostalController() {
}

HostalController* HostalController::instancia=NULL;
HostalController * HostalController::getInstancia(){
    if (HostalController::instancia == NULL)
        HostalController::instancia = new HostalController();
    return HostalController::instancia;
};

map<string,Hostal*> HostalController::getHostales() {
    return Hostales;
}


// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

list<DTHostal> HostalController::obtenerTodosHostales() {
    list<DTHostal> res;
    for(map<string,Hostal*>::iterator itr = Hostales.begin(); itr != Hostales.end(); itr++){
        Hostal *h = itr->second;
        DTHostal dt(h->getNombre(), h->getDireccion(), h->getTelefono());
        res.push_back(dt);
    }
    return res;
}

list<DTHostal> HostalController::obtenerTop3Hostales() {
    list<DTHostal> res;
    Hostal* primero = NULL;
    float calificacionPrimero = -1;
    Hostal* segundo = NULL;
    float calificacionSegundo = -1;
    Hostal* tercero = NULL;
    float calificacionTercero = -1;

    for(map<string,Hostal*>::iterator itr = Hostales.begin(); itr != Hostales.end(); itr++){
        Hostal *h = itr->second;
        float calificacionH = obtenerPromedioCalificaciones();

        if(calificacionH > calificacionPrimero){
            tercero = segundo;
            calificacionTercero = calificacionSegundo;
            segundo = primero;
            calificacionSegundo = calificacionPrimero;
            primero = h;
            calificacionPrimero = calificacionH;
        }
        else if(calificacionH > calificacionSegundo){
            tercero = segundo;
            calificacionTercero = calificacionSegundo;
            segundo = h;
            calificacionSegundo = calificacionH;
        }
        else if(calificacionH > calificacionTercero){
            tercero = h;
            calificacionTercero = calificacionH;
        }
    }

    DTHostal dtPrimero;
    DTHostal dtSegundo;
    DTHostal dtTercero;
    if(primero == NULL)
        dtPrimero = DTHostal();
    else
        dtPrimero = DTHostal(primero->getNombre(), primero->getDireccion(), primero->getTelefono());
    if(segundo == NULL)
        dtSegundo = DTHostal();
    else
        dtSegundo = DTHostal(segundo->getNombre(), segundo->getDireccion(), segundo->getTelefono());
    if(tercero == NULL)
        dtTercero = DTHostal();
    else
        dtTercero = DTHostal(tercero->getNombre(), tercero->getDireccion(), tercero->getTelefono());

    res.push_back(dtPrimero);
    res.push_back(dtSegundo);
    res.push_back(dtTercero);

    return res;
}

DTInfoBasicaHostal HostalController::obtenerInfoBasicaHostal() {
    float prom = obtenerPromedioCalificaciones();
    list<DTCalificacion> cal = obtenerCalificaciones();
    DTInfoBasicaHostal dt(
        hostalSeleccionado->getNombre(),
        hostalSeleccionado->getDireccion(),
        hostalSeleccionado->getTelefono(),
        prom,
        cal
    );
    return dt;
}

list<DTHabitacion> HostalController::obtenerHabitacionesHostal() {
    list<DTHabitacion> res;
    map<int,Habitacion*> habitaciones = hostalSeleccionado->getHabitaciones();
    for(map<int,Habitacion*>::iterator itr = habitaciones.begin(); itr != habitaciones.end(); itr++){
        Habitacion *h = itr->second;
        DTHabitacion dt(h->getNumero(), h->getPrecio(), h->getCapacidad());
        res.push_back(dt);
    }
    return res;
}


void HostalController::seleccionarHostal(string NombreHostal) {
    Hostal* h = Hostales.find(NombreHostal)->second;
    if(h == NULL) throw std::invalid_argument("No se puede seleccionar un hostal que no existe");
    hostalSeleccionado = h;
}

//Ver detalles del Hostal seleccionado
DTInfoHostal HostalController::verDetalles() {
    float prom = obtenerPromedioCalificaciones();
    list<string> lista = obtenerComentarios();
    DTInfoHostal res(lista, prom);
    return res;
}

void HostalController::confirmarConsulta() {
    hostalSeleccionado = NULL;
    //HACER
}

//Medio al pedo, borralo si queres y hacelo desde el menu
list<DTInfoHostalYCalificacion> HostalController::obtenerTodosHostalesYPromCalificacion() {
    list<DTInfoHostalYCalificacion> res;
    for(map<string,Hostal*>::iterator itr = Hostales.begin(); itr != Hostales.end(); itr++){
        Hostal *h = itr->second;
        DTHostal dtHostal(h->getNombre(), h->getDireccion(), h->getTelefono());
        float prom = obtenerPromedioCalificaciones();
        DTInfoHostalYCalificacion dtInfo(dtHostal, prom);
        res.push_back(dtInfo);
    }
    return res;
}

//Obtiene calificaciones del hostal seleccionado
list<DTCalificacion> HostalController::obtenerCalificaciones() {
	EstadiaController* controladorEstadia = EstadiaController::getInstancia();
	list<DTCalificacion> res;
    map<int,Estadia*> estadias = controladorEstadia->getEstadias();

    for(map<int,Estadia*>::iterator itr = estadias.begin(); itr != estadias.end(); itr++){
        Estadia *e = itr->second;
		if(e->getHostal()->getNombre() == hostalSeleccionado->getNombre()){
			if(e->getCalificacion() != NULL){
				DTCalificacion dt(
								e->getCalificacion()->getPuntaje(), 
								e->getCalificacion()->getComentario(),
								e->getCalificacion()->getFecha()
				);
				res.push_back(dt);
			}
		}
    }
	
	return res;
}

//Obtiene comentarios del hostal seleccionado
list<string> HostalController::obtenerComentarios() {
	EstadiaController* controladorEstadia = EstadiaController::getInstancia();
	list<string> res;
    map<int,Estadia*> estadias = controladorEstadia->getEstadias();

	for(map<int,Estadia*>::iterator itr = estadias.begin(); itr != estadias.end(); itr++){
        Estadia *e = itr->second;
		if(e->getHostal()->getNombre() == hostalSeleccionado->getNombre()){
			if(e->getCalificacion() != NULL)
				res.push_back(e->getCalificacion()->getComentario());
		}
        itr++;
    }
	
	return res;
}

//Obtiene el promedio de calificaciones del hostal seleccionado
float HostalController::obtenerPromedioCalificaciones() {
	EstadiaController* controladorEstadia = EstadiaController::getInstancia();
	float res = 0;
	int cantCalificaciones = 0;
    map<int,Estadia*> estadias = controladorEstadia->getEstadias();

    for(map<int,Estadia*>::iterator itr = estadias.begin(); itr != estadias.end(); itr++){
        Estadia *e = itr->second;
		if(e->getHostal()->getNombre() == hostalSeleccionado->getNombre()){
			if(e->getCalificacion() != NULL){
				res += e->getCalificacion()->getPuntaje();
				cantCalificaciones++; 
			}
		}
    }
	if(cantCalificaciones==0) return 0;
	else
		return res/cantCalificaciones;
}

//LO QUE ANTES ERA ALTAHOSTAL

void HostalController::ingresarDatosHostal(string UnNombre, string UnaDireccion, string UnTelefono) {
    nombre = UnNombre;
    direccion = UnaDireccion;
    telefono = UnTelefono;
}

void HostalController::confirmarAltaHostal() {
    this->Hostales.insert(pair<string,Hostal*>(this->nombre,new Hostal(
        this->nombre,
        this->direccion,
        this->telefono,
        map<int, Habitacion*> {},
        map<string, Empleado*> {}
    )));
}

void HostalController::cancelarAltaHostal() {
    nombre = "";
    direccion = "";
    telefono = "";
}