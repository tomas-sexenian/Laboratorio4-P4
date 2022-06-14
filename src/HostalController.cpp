#include "../include/controladores/HostalController.hh"

HostalController::HostalController() {
}

HostalController::~HostalController() {
}

HostalController* HostalController::instancia;
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
    auto itr = Hostales.begin();
    while(itr != Hostales.end()){ //Iterar map
        Hostal *h = itr->second;
        DTHostal dt(h->getNombre(), h->getDireccion(), h->getTelefono());
        res.push_back(dt);
        itr++;
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

    auto itr = Hostales.begin();
    while(itr != Hostales.end()){ //Iterar map
        Hostal *h = itr->second;
        float calificacionH = h->obtenerPromedioCalificaciones();

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
        itr++;
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
    DTInfoBasicaHostal dt(
        hostalSeleccionado->getNombre(),
        hostalSeleccionado->getDireccion(),
        hostalSeleccionado->getTelefono(),
        hostalSeleccionado->obtenerPromedioCalificaciones(),
        hostalSeleccionado->obtenerCalificaciones()
    );
    return dt;
}

list<DTHabitacion> HostalController::obtenerHabitacionesHostal() {
    list<DTHabitacion> res;
    auto itr = hostalSeleccionado->getHabitaciones().begin();
    while(itr != hostalSeleccionado->getHabitaciones().begin()){ //Iterar map
        Habitacion *h = itr->second;
        DTHabitacion dt(h->getNumero(), h->getPrecio(), h->getCapacidad());
        res.push_back(dt);
        itr++;
    }
    return res;
}


void HostalController::seleccionarHostal(string NombreHostal) {
    Hostal* h = Hostales.find(NombreHostal)->second;
    hostalSeleccionado = h;
}

//Ver detalles del Hostal seleccionado
DTInfoHostal HostalController::verDetalles() {
    DTInfoHostal res(hostalSeleccionado->obtenerComentarios(), hostalSeleccionado->obtenerPromedioCalificaciones());
    return res;
}

void HostalController::confirmarConsulta() {
    hostalSeleccionado = NULL;
    //HACER
}

//Medio al pedo, borralo si queres y hacelo desde el menu
list<DTInfoHostalYCalificacion> HostalController::obtenerTodosHostalesYPromCalificacion() {
    list<DTInfoHostalYCalificacion> res;
    auto itr = Hostales.begin();
    while(itr != Hostales.end()){ //Iterar map
        Hostal *h = itr->second;
        DTHostal dtHostal(h->getNombre(), h->getDireccion(), h->getTelefono());
        DTInfoHostalYCalificacion dtInfo(dtHostal, h->obtenerPromedioCalificaciones());
        res.push_back(dtInfo);
        itr++;
    }
    return res;
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