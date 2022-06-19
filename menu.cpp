#include <iostream>
#include <stdexcept>

#include "include/cabezales/Fabrica.hh"
#include "include/TipoUsuario.hh"
#include "include/TipoReserva.hh"
#include "include/cabezales/DTReservaIndividual.hh"
#include "include/cabezales/DTReservaGrupal.hh"
#include "include/interfaces/IControladorCalificacion.hh"
#include "include/interfaces/IControladorEstadia.hh"
#include "include/interfaces/IControladorHabitacion.hh"
#include "include/interfaces/IControladorHostal.hh"
#include "include/interfaces/IControladorNotificaciones.hh"
#include "include/interfaces/IControladorReserva.hh"
#include "include/interfaces/IControladorSistema.hh"
#include "include/interfaces/IControladorUsuario.hh"

IControladorCalificacion* controladorCalificaciones = Fabrica::getCalificacionController();
IControladorEstadia* controladorEstadias = Fabrica::getEstadiaController();
IControladorHabitacion* controladorHabitaciones = Fabrica::getHabitacionController();
IControladorHostal* controladorHostales = Fabrica::getHostalController();
IControladorNotificaciones* controladorNotificaciones = Fabrica::getNotificacionesController();
IControladorReserva* controladorReservas = Fabrica::getReservaController();
IControladorSistema* controladorSistema = Fabrica::getSistemaController();
IControladorUsuario* controladorUsuarios = Fabrica::getUsuarioController();
 

void cargarDatosPrueba() {

    // CARGA DE EMPLEADOS

    controladorUsuarios->ingresarTipo(empleado);
    controladorUsuarios->ingresarDatosUsuario("Emilia","emilia@mail.com","123");
    controladorUsuarios->ingresarCargo(recepcion);
    controladorUsuarios->confirmarAltaUsuario();

    controladorUsuarios->ingresarTipo(empleado);
    controladorUsuarios->ingresarDatosUsuario("Leonardo","leo@mail.com","123");
    controladorUsuarios->ingresarCargo(recepcion);
    controladorUsuarios->confirmarAltaUsuario(); 

    controladorUsuarios->ingresarTipo(empleado);
    controladorUsuarios->ingresarDatosUsuario("Alina","alina@mail.com","123");
    controladorUsuarios->ingresarCargo(administracion);
    controladorUsuarios->confirmarAltaUsuario();

    controladorUsuarios->ingresarTipo(empleado);
    controladorUsuarios->ingresarDatosUsuario("Barliman","barli@mail.com","123");
    controladorUsuarios->ingresarCargo(recepcion);
    controladorUsuarios->confirmarAltaUsuario();


    // CARGA DE HUESPEDES

    controladorUsuarios->ingresarTipo(huesped);
    controladorUsuarios->ingresarDatosUsuario("Sofia","sofia@mail.com","123");
    controladorUsuarios->ingresarEsFinger(true);
    controladorUsuarios->confirmarAltaUsuario();
    
    controladorUsuarios->ingresarTipo(huesped);
    controladorUsuarios->ingresarDatosUsuario("Frodo","frodo@mail.com","123");
    controladorUsuarios->ingresarEsFinger(true);
    controladorUsuarios->confirmarAltaUsuario();

    controladorUsuarios->ingresarTipo(huesped);
    controladorUsuarios->ingresarDatosUsuario("Sam","sam@mail.com","123");
    controladorUsuarios->ingresarEsFinger(false);
    controladorUsuarios->confirmarAltaUsuario();

    controladorUsuarios->ingresarTipo(huesped);
    controladorUsuarios->ingresarDatosUsuario("Merry","merry@mail.com","123");
    controladorUsuarios->ingresarEsFinger(false);
    controladorUsuarios->confirmarAltaUsuario();

    controladorUsuarios->ingresarTipo(huesped);
    controladorUsuarios->ingresarDatosUsuario("Pippin","pippin@mail.com","123");
    controladorUsuarios->ingresarEsFinger(false);
    controladorUsuarios->confirmarAltaUsuario();

    controladorUsuarios->ingresarTipo(huesped);
    controladorUsuarios->ingresarDatosUsuario("Seba","seba@mail.com","123");
    controladorUsuarios->ingresarEsFinger(true);
    controladorUsuarios->confirmarAltaUsuario();

    // CARGA DE HOSTALES

    controladorHostales->ingresarDatosHostal("La posada del finger","Av de la playa 123, Maldonado","099111111");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->ingresarDatosHostal("Mochileros","Rambla Costanera 333, Rocha","42579512");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->ingresarDatosHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->ingresarDatosHostal("Altos de Fing","Altos de Fing","099892992");
    controladorHostales->confirmarAltaHostal();

    controladorHostales->ingresarDatosHostal("Caverna Lujosa","Amaya 2515","233233235");
    controladorHostales->confirmarAltaHostal();

    // CARGA DE HABITACIONES EN HOSTALES

    controladorHabitaciones->ingresarDatosHabitacion(1,40,2);
    controladorHabitaciones->ingresarHostalHabitacion("La posada del finger");
    controladorHabitaciones->confirmarAltaHabitacion();

    controladorHabitaciones->ingresarDatosHabitacion(2,10,7);
    controladorHabitaciones->ingresarHostalHabitacion("La posada del finger");
    controladorHabitaciones->confirmarAltaHabitacion();

    controladorHabitaciones->ingresarDatosHabitacion(3,30,3);
    controladorHabitaciones->ingresarHostalHabitacion("La posada del finger");
    controladorHabitaciones->confirmarAltaHabitacion();

    controladorHabitaciones->ingresarDatosHabitacion(4,5,12);
    controladorHabitaciones->ingresarHostalHabitacion("La posada del finger");
    controladorHabitaciones->confirmarAltaHabitacion();

    controladorHabitaciones->ingresarDatosHabitacion(1,3,2);
    controladorHabitaciones->ingresarHostalHabitacion("Caverna Lujosa");
    controladorHabitaciones->confirmarAltaHabitacion();

    controladorHabitaciones->ingresarDatosHabitacion(1,9,5);
    controladorHabitaciones->ingresarHostalHabitacion("El Pony Pisador");
    controladorHabitaciones->confirmarAltaHabitacion();

    // CARGA DE EMPLEADOS EN HOSTALES

    controladorUsuarios->seleccionarEmpleado("emilia@mail.com");
    controladorUsuarios->seleccionarCargo(recepcion);
    controladorUsuarios->ingresarHostal("La posada del finger");
    controladorUsuarios->confirmarAsignacionEmpleado();

    controladorUsuarios->seleccionarEmpleado("leo@mail.com");
    controladorUsuarios->seleccionarCargo(recepcion);
    controladorUsuarios->ingresarHostal("Mochileros");
    controladorUsuarios->confirmarAsignacionEmpleado();

    controladorUsuarios->seleccionarEmpleado("alina@mail.com");
    controladorUsuarios->seleccionarCargo(administracion);
    controladorUsuarios->ingresarHostal("Mochileros");
    controladorUsuarios->confirmarAsignacionEmpleado();

    controladorUsuarios->seleccionarEmpleado("barli@mail.com");
    controladorUsuarios->seleccionarCargo(recepcion);
    controladorUsuarios->ingresarHostal("El Pony Pisador");
    controladorUsuarios->confirmarAsignacionEmpleado();

    // CARGA DE RESEVAS DE HUESPEDES EN HOSTALES

    DTFecha checkIn = DTFecha(1,5,2022,14,0);
    DTFecha checkOut = DTFecha(10,5,2022,10,0);
    controladorReservas->ingresarDatosReserva(1,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("La posada del finger");
    controladorReservas->seleccionarHabitacion(1);
    controladorReservas->seleccionarTipo(individual);
    controladorReservas->ingresarHuesped("sofia@mail.com");
    controladorReservas->confirmarReserva();

    checkIn = DTFecha(4,1,2001,20,0);
    checkOut = DTFecha(5,1,2001,2,0);
    controladorReservas->ingresarDatosReserva(2,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("El Pony Pisador");
    controladorReservas->seleccionarHabitacion(1);
    controladorReservas->seleccionarTipo(grupal);
    controladorReservas->ingresarHuesped("frodo@mail.com");
    list<string> invitados = {"sam@mail.com","merry@mail.com","pippin@mail.com"};
    controladorReservas->ingresarInvitados(invitados);
    controladorReservas->confirmarReserva();

    checkIn = DTFecha(7,6,2022,14,0);
    checkOut = DTFecha(30,6,2022,11,0);
    controladorReservas->ingresarDatosReserva(3,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("La posada del finger");
    controladorReservas->seleccionarHabitacion(3);
    controladorReservas->seleccionarTipo(individual);
    controladorReservas->ingresarHuesped("sofia@mail.com");
    controladorReservas->confirmarReserva();

    checkIn = DTFecha(10,6,2022,14,0);
    checkOut = DTFecha(30,6,2022,11,0);
    controladorReservas->ingresarDatosReserva(4,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("Caverna Lujosa");
    controladorReservas->seleccionarHabitacion(1);
    controladorReservas->seleccionarTipo(individual);
    controladorReservas->ingresarHuesped("seba@mail.com");
    controladorReservas->confirmarReserva();

    // CARGA DE ESTADIAS PARA RESERVAS DE HUESPEDES

    controladorEstadias->seleccionarTipo(individual);
    controladorEstadias->seleccionarReserva(1);
    controladorEstadias->ingresarHuesped("sofia@mail.com");
    controladorEstadias->ingresarEntradaEstadia(1,5,2022,18,0);
    controladorEstadias->confirmarAltaEstadia();

    controladorEstadias->seleccionarTipo(grupal);
    controladorEstadias->seleccionarReserva(2);
    controladorEstadias->ingresarHuesped("frodo@mail.com");
    invitados = {"sam@mail.com","merry@mail.com","pippin@mail.com"};
    controladorEstadias->ingresarInvitados(invitados);
    controladorEstadias->ingresarEntradaEstadia(4,1,2001,21,0);
    controladorEstadias->confirmarAltaEstadia();

    controladorEstadias->seleccionarTipo(individual);
    controladorEstadias->seleccionarReserva(4);
    controladorEstadias->ingresarHuesped("seba@mail.com");
    controladorEstadias->ingresarEntradaEstadia(7,6,2022,18,0);
    controladorEstadias->confirmarAltaEstadia();

    // FINALIZACION DE ESTADIAS

    Estadia* e;

    controladorEstadias->seleccionarEstadia(1,"sofia@mail.com");
    e = controladorEstadias->finalizarEstadia();
    e->setSalida(DTFecha(10,5,2022,9,0));

    controladorEstadias->seleccionarEstadia(2,"frodo@mail.com");
    e = controladorEstadias->finalizarEstadia();
    e->setSalida(DTFecha(5,1,2001,2,0));

    controladorEstadias->seleccionarEstadia(4,"seba@mail.com");
    e = controladorEstadias->finalizarEstadia();
    e->setSalida(DTFecha(15,6,2022,22,0));

    // CALIFICACIONES DE ESTADIAS

    controladorCalificaciones->ingresarComentario("Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacia tremendo ruido) y 2 pesas, la piscina parecia el lago del Parque Rodo y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuevlo");
    controladorCalificaciones->ingresarPuntaje(3);
    controladorCalificaciones->ingresarFecha(DTFecha(11,5,2022,18,0));
    controladorCalificaciones->confirmarAltaCalificacion(1,"sofia@mail.com");

    controladorCalificaciones->ingresarComentario("Se pone peligroso de noche, no recomiendo. Ademas no hay caja fuerte para guardar los anillos");
    controladorCalificaciones->ingresarPuntaje(2);
    controladorCalificaciones->ingresarFecha(DTFecha(5,1,2001,3,0));
    controladorCalificaciones->confirmarAltaCalificacion(2,"frodo@mail.com");

    controladorCalificaciones->ingresarComentario("Habia pulgas en la habitacion. Que lugar mas mamarracho!!");
    controladorCalificaciones->ingresarPuntaje(1);
    controladorCalificaciones->ingresarFecha(DTFecha(15,6,2022,11,0));
    controladorCalificaciones->confirmarAltaCalificacion(4,"seba@mail.com");

    // COMENTARIOS A CALIFICACIONES

    controladorCalificaciones->ingresarRespuesta("Desaparecio y se fue sin pagar");
    controladorCalificaciones->responderCalificacion(2,"frodo@mail.com",DTFecha(15,6,2022,23,0));
}



void imprimirTodosEmailEmpleados(){
    std::cout << "TODOS LOS EMPLEADOS DEL SISTEMA"<< endl;
    list<DTEmpleado> empleados = controladorUsuarios->obtenerTodosEmpleados();
    for (std::list<DTEmpleado>::iterator it = empleados.begin(); it != empleados.end(); ++it){
        std::cout << it->getEmail() << " \n";
    }
}

void imprimirTodosEmailHuespedes(){
    std::cout << "TODOS LOS HUESPEDES DEL SISTEMA"<< endl;
    list<DTHuesped> huespedes = controladorUsuarios->obtenerTodosHuespedes();
    for (std::list<DTHuesped>::iterator it = huespedes.begin(); it != huespedes.end(); ++it){
        std::cout << it->getEmail() << " \n";
    }
}

void imprimirDetalleEmpleado(string emailEmpleado){
    std::cout << "DETALLE DE EMPLEADO:"<< endl;
    list<DTEmpleado> empleados = controladorUsuarios->obtenerTodosEmpleados();
    for (std::list<DTEmpleado>::iterator it = empleados.begin(); it != empleados.end(); ++it){
        if (it->getEmail() == emailEmpleado){
            std::cout << "Nombre: " << it->getNombre() << " \n";
            std::cout << "Email: " << it->getEmail() << " \n";
            string cargoEmpleado;
            switch(it->getCargo()){
                case administracion:
                    cargoEmpleado = "Administracion";
                    break;
                case limpieza:
                    cargoEmpleado = "Limpieza";
                    break;
                case recepcion:
                    cargoEmpleado = "Recepcion";
                    break;
                case infraestructura:
                    cargoEmpleado = "Infraestructura";
                    break;
            }
            std::cout << "Cargo: " << cargoEmpleado << " \n";
        }
    }
}

void imprimirDetalleHuesped(string emailHuesped){
    std::cout << "DETALLE DE HUESPED:"<< endl;
    list<DTHuesped> huespedes = controladorUsuarios->obtenerTodosHuespedes();
    for (std::list<DTHuesped>::iterator it = huespedes.begin(); it != huespedes.end(); ++it){
        if (it->getEmail() == emailHuesped){
            std::cout << "Nombre: " << it->getNombre() << " \n";
            std::cout << "Email: " << it->getEmail() << " \n";
            if (it->getEsFinger())
                cout << "Es finger" << it->getEmail() << " \n";
            else
                cout << "No es finger" << it->getEmail() << " \n";
        }
    }
}

void imprimirTodosNombreHostal(){
    std::cout << "TODAS LOS HOSTALES DEL SISTEMA" << endl;
    list<DTHostal> hostales = controladorHostales->obtenerTodosHostales();
    for (std::list<DTHostal>::iterator it = hostales.begin(); it != hostales.end(); ++it){
        std::cout << it->getNombre() << " \n";
    }
}

void imprimirDetalleHostal(string nombreHostal){
    std::cout << "DETALLE DEL HOSTAL: " << nombreHostal << endl;
    list<DTHostal> hostales = controladorHostales->obtenerTodosHostales();
    for (std::list<DTHostal>::iterator it = hostales.begin(); it != hostales.end(); ++it){
        if (it->getNombre() == nombreHostal){
            std::cout << "Nombre: " << it->getNombre() << " \n";
            std::cout << "Direccion: " << it->getDireccion() << " \n";
            std::cout << "Telefono: " << it->getTelefono() << " \n";
        }
    }
}

void imprimirTodasReservas(string nombreHostal){
    std::cout << "TODAS LAS RESERVAS DEL HOSTAL: " << nombreHostal << endl;
    list<DTReserva> reservas = controladorReservas->obtenerReservasHostal(nombreHostal);
    for (std::list<DTReserva>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        if(dynamic_cast<DTReservaIndividual*>(&(*it))){
            DTReservaIndividual* res_individual = dynamic_cast<DTReservaIndividual*>(&(*it));
            std::cout << "Tipo Reserva: Individual" << endl;
            std::cout << "Codigo Reserva: " << res_individual->getCodigo() << endl;
        }
        if (dynamic_cast<DTReservaGrupal*>(&(*it))){
            DTReservaGrupal* res_grupal = dynamic_cast<DTReservaGrupal*>(&(*it));
            std::cout << "Tipo Reserva: Grupal" << endl;
            std::cout << "Codigo Reserva: " << res_grupal->getCodigo() << endl;
        }
    }
}

void imprimirDetalleReserva(int codigoReserva, string nombreHostal){
    std::cout << "DETALLE DE LA RESERVA: " << codigoReserva << endl;
    list<DTReserva> reservas = controladorReservas->obtenerReservasHostal(nombreHostal);
    for (std::list<DTReserva>::iterator it = reservas.begin(); it != reservas.end(); ++it){
        if(dynamic_cast<DTReservaIndividual*>(&(*it))){
            DTReservaIndividual* res_individual = dynamic_cast<DTReservaIndividual*>(&(*it));
            if (res_individual->getCodigo() == codigoReserva){
                std::cout << "Tipo Reserva: Individual" << endl;
                std::cout << "Codigo Reserva: " << res_individual->getCodigo() << endl;
                std::cout << "Fecha CheckIn: " << res_individual->getCheckin().getDia() << "/" << res_individual->getCheckin().getMes() << res_individual->getCheckin().getDia() << endl;
                std::cout << "Fecha CheckOut: " << res_individual->getCheckout().getDia() << "/" << res_individual->getCheckout().getMes() << res_individual->getCheckout().getDia() << endl;
                std::cout << "Habitacion: " << res_individual->getHabitacion() << endl;
                std::cout << "Costo: " << res_individual->getCosto() << endl;
                switch(res_individual->getEstado()){
                    case abierta:
                        std::cout << "Estado Reserva: Abierta"<< endl;
                        break;
                    case cerrada:
                        std::cout << "Estado Reserva: Cerrada"<< endl;
                        break;
                    case cancelada:
                        std::cout << "Estado Reserva: Cancelada"<< endl;
                        break;
                }
            }
        }
        if (dynamic_cast<DTReservaGrupal*>(&(*it))){
            DTReservaGrupal* res_grupal = dynamic_cast<DTReservaGrupal*>(&(*it));
            if (res_grupal->getCodigo() == codigoReserva){
                std::cout << "Tipo Reserva: Grupal" << endl;
                std::cout << "Codigo Reserva: " << res_grupal->getCodigo() << endl;
                std::cout << "Fecha CheckIn: " << res_grupal->getCheckin().getDia() << "/" << res_grupal->getCheckin().getMes() << res_grupal->getCheckin().getDia() << endl;
                std::cout << "Fecha CheckOut: " << res_grupal->getCheckout().getDia() << "/" << res_grupal->getCheckout().getMes() << res_grupal->getCheckout().getDia() << endl;
                std::cout << "Habitacion: " << res_grupal->getHabitacion() << endl;
                std::cout << "Costo: " << res_grupal->getCosto() << endl;
                switch(it->getEstado()){
                    case abierta:
                        std::cout << "Estado Reserva: Abierta"<< endl;
                        break;
                    case cerrada:
                        std::cout << "Estado Reserva: Cerrada"<< endl;
                        break;
                    case cancelada:
                        std::cout << "Estado Reserva: Cancelada"<< endl;
                        break;
                }
                list<DTHuesped> lst_huespedes = res_grupal->getInvitados();
                for (std::list<DTHuesped>::iterator iter = lst_huespedes.begin(); iter != lst_huespedes.end(); ++it){
                    std::cout << "Email:" << iter->getEmail() << endl;
                }
            }
        }
    }
}

void imprimirTodosNumeroHabitacion(string nombreHostal, DTFecha checkIn, DTFecha checkOut){
    std::cout << "TODAS LAS HABITACIONES DISPONIBLES DEL HOSTAL: " << nombreHostal << endl;
    list<DTHabitacion> habitaciones = controladorHabitaciones->obtenerHabitacionesDisponiblesHostal(nombreHostal, checkIn, checkOut);
    for (std::list<DTHabitacion>::iterator it = habitaciones.begin(); it != habitaciones.end(); ++it){
        std::cout << "Numero: " << it->getNumero() << endl;
        std::cout << "Capacidad: " << it->getCapacidad() << endl;
        std::cout << "Costo: " << it->getPrecio() << endl;
    }
}

void imprimirTodasEstadias(string nombreHostal){
    std::cout << "TODAS LAS ESTADIAS DEL HOSTAL: " << nombreHostal << endl;
    list<DTEstadia> estadias = controladorEstadias->obtenerTodasEstadiasHostal(nombreHostal);
    for (std::list<DTEstadia>::iterator it = estadias.begin(); it != estadias.end(); ++it){
        std::cout << "Email del huesped:" << it->getEmailHuesped() << endl;
        std::cout << "Habitacion: " << it->getHabitacion() << endl;
    }
}

void imprimirDetalleEstadia(string nombreHostal,string emailHuesped){
    std::cout << "TODAS LAS ESTADIAS DEL HUESPED " << emailHuesped << " EN EL HOSTAL " << nombreHostal << endl;
    list<DTEstadia> estadias = controladorEstadias->obtenerTodasEstadiasHostal(nombreHostal);
    for (std::list<DTEstadia>::iterator it = estadias.begin(); it != estadias.end(); ++it){
        if (it->getEmailHuesped() == emailHuesped ){
            std::cout << "Habitacion: " << it->getHabitacion() << endl;
            std::cout << "Promo: " << it->getPromo() << endl;
            std::cout << "Entrada: " << it->getEntrada().getDia() << "/" << it->getEntrada().getMes() << "/" << it->getEntrada().getAnio() << endl;
            std::cout << "Salida: " << it->getSalida().getDia() << "/" << it->getSalida().getMes() << "/" << it->getSalida().getAnio() << endl;
        }
    }
}

void imprimirTop3Hostales(){
    std::cout << "TOP 3 HOSTALES DEL SISTEMA SEGUN SUS CALIFICACIONES" << endl;
    list<DTHostal> hostales = controladorHostales->obtenerTop3Hostales();
    for (std::list<DTHostal>::iterator it = hostales.begin(); it != hostales.end(); ++it){
        std::cout << it->getNombre() << " \n";
    }
}

// ----------------------------------------------------------------- //
// ----------------------------------------------------------------- //
// FUNCIONES DE LOS CASOS DE USO

//Alta de usuario
void altaDeUsuario(){

    // PARA ALTA DE USUARIO
    int eleccionTipoUsuario_CUsuario;
    string eleccionNombreUsuario_CUsuario;
    string eleccionMailUsuario_CUsuario;
    string eleccionContraseniaUsuario_CUsuario;
    int eleccionCargoUsuario_CUsuario;
    int eleccionEsFingerUsuario_CUsuario;

    cout << "Ingrese el tipo de usuario: 1 = Empleado / 2 = Huesped\n";
    cin >> eleccionTipoUsuario_CUsuario;
    cin.ignore(256, '\n');
    cout << "\n";

    if (eleccionTipoUsuario_CUsuario == 1){
        controladorUsuarios->ingresarTipo(empleado);
        cout << "Ingrese el cargo del empleado: 1 = Administracion / 2 = Limpieza / 3 = Recepcion / 4 = Infraestructura\n";
        cin >> eleccionCargoUsuario_CUsuario;
	cin.ignore(256, '\n');
        cout << "\n";
        switch(eleccionCargoUsuario_CUsuario){
            case 1:
                controladorUsuarios->ingresarCargo(administracion);
                break;
            case 2:
                controladorUsuarios->ingresarCargo(limpieza);
                break;
            case 3:
                controladorUsuarios->ingresarCargo(recepcion);
                break;
            case 4:
                controladorUsuarios->ingresarCargo(infraestructura);
                break;
        }
    }
    else if (eleccionTipoUsuario_CUsuario == 2){
        controladorUsuarios->ingresarTipo(huesped);

        cout << "Indique si el huesped es finger o no: 1 = Si / 2 = No\n";
        cin >> eleccionEsFingerUsuario_CUsuario;
        cin.ignore(256, '\n');
        cout << "\n";

        switch(eleccionEsFingerUsuario_CUsuario){
        case 1:
            controladorUsuarios->ingresarEsFinger(true);
            break;
        case 2:
            controladorUsuarios->ingresarEsFinger(false);
            break;
        }
    }
        
    cout << "Ingrese el nombre del usuario\n";
    getline(cin, eleccionNombreUsuario_CUsuario);
    cout << "\n";    

    cout << "Ingrese el mail del usuario\n";
    getline(cin, eleccionMailUsuario_CUsuario);
    cout << "\n";  

    cout << "Ingrese la contrasenia del usuario\n";
    getline(cin, eleccionContraseniaUsuario_CUsuario);
    cout << "\n";  

    controladorUsuarios->ingresarDatosUsuario(eleccionNombreUsuario_CUsuario,eleccionMailUsuario_CUsuario,eleccionContraseniaUsuario_CUsuario);

    controladorUsuarios->confirmarAltaUsuario();
}

//Alta de hostal
void altaDeHostal(){
    // PARA ALTA DE HOSTAL
    cin.ignore(256, '\n');
    string eleccionNombreHostal_CUsuario, eleccionDireccionHostal_CUsuario, eleccionTelefonoHostal_CUsuario;
    cout << "Ingrese el nombre del hostal\n";
    getline(cin, eleccionNombreHostal_CUsuario);
    cout << "\n";   

    cout << "Ingrese la direccion del hostal\n";
    getline(cin, eleccionDireccionHostal_CUsuario);
    cout << "\n"; 

    cout << "Ingrese el telefono del hostal\n";
    getline(cin, eleccionTelefonoHostal_CUsuario);
    cout << "\n";   

    controladorHostales->ingresarDatosHostal(eleccionNombreHostal_CUsuario,eleccionDireccionHostal_CUsuario,eleccionTelefonoHostal_CUsuario);
    controladorHostales->confirmarAltaHostal();
}
//Alta de habitacion
void altaDeHabitacion(){
    // PARA ALTA DE HABITACION
    int eleccionNumeroHabitacion_CUsuario, eleccionCapacidadHabitacion_CUsuario, eleccionCostoHabitacion_CUsuario;
    string eleccionNombreHostal_CUsuario;

    cout << "Ingrese el numero de habitacion\n";
    cin >> eleccionNumeroHabitacion_CUsuario;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Ingrese el costo de la habitacion\n";
    cin >> eleccionCostoHabitacion_CUsuario;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Ingrese la capacidad de la habitacion\n";
    cin >> eleccionCapacidadHabitacion_CUsuario;
    cin.ignore(256, '\n');
    cout << "\n";

    controladorHabitaciones->ingresarDatosHabitacion(eleccionNumeroHabitacion_CUsuario,eleccionCostoHabitacion_CUsuario,eleccionCapacidadHabitacion_CUsuario);

    cout << "Ingrese el nombre del hostal al cual pertenece la habitacion\n";
    getline(cin, eleccionNombreHostal_CUsuario);
    cout << "\n";

    controladorHabitaciones->ingresarHostalHabitacion(eleccionNombreHostal_CUsuario);
    controladorHabitaciones->confirmarAltaHabitacion();
}
//Asignar empleado a hostal
void asignarEmpleadoAHostal(){
    // PARA ASIGNAR EMPLEADO A HOSTAL
    string eleccionEmailEmpleado_CUsuario,eleccionNombreHostal_CUsuario;
    int eleccionCargoUsuario_CUsuario;

    imprimirTodosEmailHuespedes();

    cout << "Ingrese el email del empleado\n";
    getline(cin, eleccionEmailEmpleado_CUsuario);
    cout << "\n";

    controladorUsuarios->seleccionarEmpleado(eleccionEmailEmpleado_CUsuario);

    cout << "Ingrese el cargo del empleado: 1 = Administracion / 2 = Limpieza / 3 = Recepcion / 4 = Infraestructura\n";
    cin >> eleccionCargoUsuario_CUsuario;
    cin.ignore(256, '\n');
    cout << "\n";

    switch(eleccionCargoUsuario_CUsuario){
        case 1:
            controladorUsuarios->ingresarCargo(administracion);
            break;
        case 2:
            controladorUsuarios->ingresarCargo(limpieza);
            break;
        case 3:
            controladorUsuarios->ingresarCargo(recepcion);
            break;
        case 4:
            controladorUsuarios->ingresarCargo(infraestructura);
            break;
        }
        imprimirTodosNombreHostal();

        cout << "Ingrese el nombre del hostal en el cual trabajara el empleado\n";
        getline(cin, eleccionNombreHostal_CUsuario);
        cout << "\n";
        controladorUsuarios->ingresarHostal(eleccionNombreHostal_CUsuario);

        controladorUsuarios->confirmarAsignacionEmpleado();
}
//Modificar fecha del sistema
void modificarFechaDelSistema(){
    int AnioSistema,MesSistema,DiaSistema,HoraSistema,MinutoSistema;

    cout << "Ingrese la fecha del sistema\n";

    cout << "Anio:";
    cin >> AnioSistema;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Mes:";
    cin >> MesSistema;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Dia:";
    cin >> DiaSistema;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Hora:";
    cin >> HoraSistema;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Minuto:";
    cin >> MinutoSistema;
    cin.ignore(256, '\n');
    cout << "\n";

    controladorSistema->modificarFecha(DTFecha(DiaSistema,MesSistema,AnioSistema,HoraSistema,MinutoSistema));

}

//Registrar estadia
void registrarEstadia(string eleccionHostalEmpleado_CEmpleado){
    // PARA REGISTRAR ESTADIA
    int eleccionTipoEstadia_CEmpleado, eleccionCodigoReserva_CEmpleado;
    string eleccionEmailHuespedEstadia_CEmpleado;

    cout << "Indique si la estadia corresponde a una reserva individual o grupal: 1 = Individual / 2 = Grupal\n";
    cin >> eleccionTipoEstadia_CEmpleado;
    cin.ignore(256, '\n');
    cout << "\n";
                                
    imprimirTodasReservas(eleccionHostalEmpleado_CEmpleado);

    cout << "Indique el codigo de la reserva asociada a la estadia\n";
    cin >> eleccionCodigoReserva_CEmpleado;
    cin.ignore(256, '\n');
    cout << "\n";
                                
    switch(eleccionTipoEstadia_CEmpleado){
    case 1:
        controladorEstadias->seleccionarTipo(individual);
        break;
    case 2:
        controladorEstadias->seleccionarTipo(grupal);
        break;
    }
    controladorEstadias->seleccionarReserva(eleccionCodigoReserva_CEmpleado);

    imprimirTodosEmailHuespedes();

    cout << "Indique el email del huesped asociado a la estadia\n";
    getline(cin, eleccionEmailHuespedEstadia_CEmpleado);
    cout << "\n";

    controladorEstadias->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);

    DTFecha fechaSis = controladorSistema->obtenerFechaActual();

    /*cout << "Por favor indique sus huespedes invitados\n";
    eleccionEmailInvitadosReserva_CHuesped = {};
    continuarArgegando_CHuesped = true;
    while (continuarArgegando_CHuesped){
        cout << "Por favor indique el email del invitado:";
        getline(cin, eleccionEmailInvitado_CHuesped);
        eleccionEmailInvitadosReserva_CHuesped.push_back(eleccionEmailInvitado_CHuesped);
        cout << "Si desea detenerse, ingrese 1 de lo contrario ingrese cualquier numero:";
        cin >> eleccionSeguiraAgregando_CHuesped;
        if (eleccionSeguiraAgregando_CHuesped == 1)
            continuarArgegando_CHuesped = false;
    }
    controladorReservas->ingresarInvitados(eleccionEmailInvitadosReserva_CHuesped);
*/

    //mal, habria que pedir la fecha de la estadia
    controladorEstadias->ingresarEntradaEstadia(fechaSis.getDia(), fechaSis.getMes(), fechaSis.getAnio(), fechaSis.getHora(), fechaSis.getMinuto());
    controladorEstadias->confirmarAltaEstadia();
}

//Finalizar estadia
void finalizarEstadia(){
    // PARA FINALIZAR ESTADIA
    string eleccionComentarioEstadia_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado;
    int eleccionPuntajeEstadia_CEmpleado,eleccionCodigoReserva_CEmpleado;

    cout << "Indique el comentario asociado a la estadia\n";
    getline(cin, eleccionComentarioEstadia_CEmpleado);
    cout << "\n";
    controladorCalificaciones->ingresarComentario(eleccionComentarioEstadia_CEmpleado);

    cout << "Indique el puntaje asociado a la estadia\n";
    cin >> eleccionPuntajeEstadia_CEmpleado;
    cin.ignore(256, '\n');
    cout << "\n";
    controladorCalificaciones->ingresarPuntaje(eleccionPuntajeEstadia_CEmpleado);

    controladorCalificaciones->ingresarFecha(controladorSistema->obtenerFechaActual());

    cout << "Indique el codigo de la reserva asociada a la estadia\n";
    cin >> eleccionCodigoReserva_CEmpleado;
    cin.ignore(256, '\n');
    cout << "\n";

    imprimirTodosEmailHuespedes();
    cout << "Indique el email del huesped asociado a la estadia\n";
    getline(cin, eleccionEmailHuespedEstadia_CEmpleado);
    cout << "\n";
    controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);
                                
    controladorCalificaciones->confirmarAltaCalificacion(eleccionCodigoReserva_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado);
}
//Comentar calificacion
void comentarCalificacion(){
    // PARA COMENTAR CALIFICACION
    string eleccionComentarioCalificacion_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado;
    int eleccionCodigoReserva_CEmpleado;

    cout << "Indique el comentario asociado a la calificacion\n";
    getline(cin, eleccionComentarioCalificacion_CEmpleado);
    cout << "\n";
    controladorCalificaciones->ingresarRespuesta(eleccionComentarioCalificacion_CEmpleado);
                                
    cout << "Indique el codigo de la reserva asociada a la estadia\n";
    cin >> eleccionCodigoReserva_CEmpleado;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Indique el email del huesped asociado a la estadia\n";
    getline(cin, eleccionEmailHuespedEstadia_CEmpleado);
    cout << "\n";
    controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);

    controladorCalificaciones->responderCalificacion(eleccionCodigoReserva_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado,controladorSistema->obtenerFechaActual());
}

//Suscribirse a notificaciones
void suscribirseANotificaciones(){}
//Consulta de notificaciones
void consultaDeNotificaciones(){}
//Eliminar suscripcion
void eliminarSUscripcion(){}

//Realizar reserva
int realizarReserva(int codigoReserva){
    // PARA REALIZAR RESERVA
    string eleccionHostalReserva_CHuesped,eleccionEmailInvitado_CHuesped,eleccionEmailHuespedEstadia_CEmpleado;
    int eleccionHabitacionReserva_CHuesped,eleccionTipoReserva_CHuesped,eleccionSeguiraAgregando_CHuesped;
    list<string> eleccionEmailInvitadosReserva_CHuesped;
    bool continuarArgegando_CHuesped;
    int AnioReserva, MesReserva, DiaReserva, HoraReserva, MinutoReserva;
    
    cout << "Ingrese la fecha de check in\n";

    cout << "Anio:";
    cin >> AnioReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Mes:";
    cin >> MesReserva;
    cout << "\n";

    cout << "Dia:";
    cin >> DiaReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Hora:";
    cin >> HoraReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Minuto:";
    cin >> MinutoReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    DTFecha checkIn = DTFecha(DiaReserva,MesReserva,AnioReserva,HoraReserva,MinutoReserva);

    cout << "Ingrese la fecha de check out\n";

    cout << "Anio:";
    cin >> AnioReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Mes:";
    cin >> MesReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Dia:";
    cin >> DiaReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Hora:";
    cin >> HoraReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    cout << "Minuto:";
    cin >> MinutoReserva;
    cin.ignore(256, '\n');
    cout << "\n";

    DTFecha checkOut = DTFecha(DiaReserva,MesReserva,AnioReserva,HoraReserva,MinutoReserva);

    controladorReservas->ingresarDatosReserva(codigoReserva,checkIn,checkOut,abierta);

    imprimirTodosNombreHostal();

    cout << "Indique el nombre del hostal donde realizara la reserva\n";
    getline(cin, eleccionHostalReserva_CHuesped);
    cout << "\n";

    controladorReservas->seleccionarHostal(eleccionHostalReserva_CHuesped);
                                
    imprimirTodosNumeroHabitacion(eleccionHostalReserva_CHuesped,checkIn,checkOut);

    cout << "Indique el numero de habitacion\n";
    cin >> eleccionHabitacionReserva_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";

    controladorReservas->seleccionarHabitacion(eleccionHabitacionReserva_CHuesped);

    cout << "Indique el tipo de reserva: 1 = Individual / 2 = Grupal\n";
    cin >> eleccionTipoReserva_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";
    switch(eleccionTipoReserva_CHuesped){
        case 1:
            controladorReservas->seleccionarTipo(individual);
            cout << "Por favor indique su email\n";
            getline(cin, eleccionEmailHuespedEstadia_CEmpleado);
            cout << "\n";
            controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);
            break;
        case 2:
            controladorReservas->seleccionarTipo(grupal);
            cout << "Por favor indique su email\n";
            getline(cin, eleccionEmailHuespedEstadia_CEmpleado);
            cout << "\n";
            controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);
            cout << "Por favor indique sus huespedes invitados\n";
            eleccionEmailInvitadosReserva_CHuesped = {};
            continuarArgegando_CHuesped = true;
            while (continuarArgegando_CHuesped){
                cout << "Por favor indique el email del huesped:";
                getline(cin, eleccionEmailInvitado_CHuesped);
                eleccionEmailInvitadosReserva_CHuesped.push_back(eleccionEmailInvitado_CHuesped);
                cout << "Si desea detenerse, ingrese 1 de lo contrario ingrese cualquier numero:";
                cin >> eleccionSeguiraAgregando_CHuesped;
                cin.ignore(256, '\n');
                if (eleccionSeguiraAgregando_CHuesped == 1)
                    continuarArgegando_CHuesped = false;
            }
            controladorReservas->ingresarInvitados(eleccionEmailInvitadosReserva_CHuesped);
            break;
    }
    controladorReservas->confirmarReserva();
    return codigoReserva + 1;
}
//Consultar top 3 hostales
void consultarTop3Hostales(){
    string eleccionHostal_CHuesped;

    void imprimirTop3Hostales();
    cout << "Si desea ver detalles sobre algun hostal en particular, ingrese su nombre" << endl;
    getline(cin, eleccionHostal_CHuesped);
    cout << "\n";
    imprimirDetalleHostal(eleccionHostal_CHuesped);
}
//Calificar estadia
void calificarEstadia(){
    string eleccionComentarioEstadia_CHuesped,eleccionEmailHuespedEstadia_CEmpleado;
    int eleccionPuntajeEstadia_CHuesped,eleccionCodigoReserva_CEmpleado;

    cout << "Por ingrese el comentario\n";
    getline(cin, eleccionComentarioEstadia_CHuesped);
    cout << "\n";
    controladorCalificaciones->ingresarComentario(eleccionComentarioEstadia_CHuesped);

    cout << "Por favor ingrese el puntaje\n";
    cin >> eleccionPuntajeEstadia_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";
    controladorCalificaciones->ingresarPuntaje(eleccionPuntajeEstadia_CHuesped);

    controladorCalificaciones->ingresarFecha(controladorSistema->obtenerFechaActual());

    cout << "Indique el codigo de la reserva asociada a la estadia\n";
    cin >> eleccionCodigoReserva_CEmpleado;
    cin.ignore(256, '\n');
    cout << "\n";
    cout << "Por favor indique su email\n";
    getline(cin, eleccionEmailHuespedEstadia_CEmpleado);
    cout << "\n";
    controladorCalificaciones->confirmarAltaCalificacion(eleccionCodigoReserva_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado);
}
//Consulta de usuario
void consultaDeUsuario(){
    int eleccionTipoUsuario_CHuesped;
    string eleccionEmailEmpleado_CHuesped, eleccionEmailHuesped_CHuesped,eleccionHostal_CHuesped;

    cout << "Indique si desea consultar por empleados o huespedes: 1 = Huespedes / 2 = Empleados" << endl;
    cin >> eleccionTipoUsuario_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";
    if (eleccionTipoUsuario_CHuesped == 1){
        imprimirTodosEmailHuespedes();
        cout << "Ingrese el mail del empleado que desea visualizar" << endl;
        getline(cin, eleccionEmailEmpleado_CHuesped);
        cout << "\n";
        imprimirDetalleEmpleado(eleccionEmailEmpleado_CHuesped);
    }
    else if (eleccionTipoUsuario_CHuesped == 2){
        imprimirTodosEmailEmpleados();
        cout << "Ingrese el mail del huesped que desea visualizar" << endl;
        getline(cin, eleccionEmailEmpleado_CHuesped);
        cout << "\n";
        imprimirDetalleHuesped(eleccionEmailEmpleado_CHuesped);
    }
}
//Consulta de hostal
void consultaDeHostal(){
    int cantCalificaciones_CHuesped;
    DTInfoBasicaHostal infoBasicaHostal_CHuesped;
    string eleccionHostal_CHuesped;

    imprimirTodosNombreHostal();
    cout << "Ingrese el nombre del hostal que desea consultar" << endl;
    getline(cin, eleccionHostal_CHuesped);
    cout << "\n";
    imprimirDetalleHostal(eleccionHostal_CHuesped);
    controladorHostales->seleccionarHostal(eleccionHostal_CHuesped);
    infoBasicaHostal_CHuesped = controladorHostales->obtenerInfoBasicaHostal();
    cout << "Promedio de calificaciones del hostal: " << infoBasicaHostal_CHuesped.getPromedioCalificaciones() << endl;
    cantCalificaciones_CHuesped = 0;
    for (std::list<DTCalificacion>::iterator it = infoBasicaHostal_CHuesped.getCalificaciones().begin(); it != infoBasicaHostal_CHuesped.getCalificaciones().end(); ++it){
        cout << "Calificacion numero " << cantCalificaciones_CHuesped << endl;
        cout << "Comentario: " << it->getComentario() << endl;
        cout << "Puntaje: " << it->getPuntaje() << endl;
        cout << "Fecha: " << it->getFecha().getDia() << it->getFecha().getMes() << it->getFecha().getAnio()  << endl;
        cout << "" << endl;
    }
}
//Consulta de reserva
void consultaDeReserva(){
    int eleccionReserva_CHuesped;
    string eleccionHostal_CHuesped;
    imprimirTodosNombreHostal();
    cout << "Ingrese el nombre del hostal cuya reserva desea consultar" << endl;
    getline(cin, eleccionHostal_CHuesped);
    cout << "\n";
    imprimirTodasReservas(eleccionHostal_CHuesped);
    cout << "Ingrese el numero de la reserva que desea consultar" << endl;
    cin >> eleccionReserva_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";
    imprimirDetalleReserva(eleccionReserva_CHuesped,eleccionHostal_CHuesped);
}
//Consulta de estadia
void consultaDeEstadia(){
    string eleccionHuesped_CHuesped,eleccionHostal_CHuesped;
    imprimirTodosNombreHostal();
    cout << "Ingrese el nombre del hostal en el que se realizo la estadia" << endl;
    getline(cin, eleccionHostal_CHuesped);
    cout << "\n";
    imprimirTodasEstadias(eleccionHostal_CHuesped);
    cout << "Ingrese el email del huesped cuya estadia desea consultar" << endl;
    getline(cin, eleccionHuesped_CHuesped);
    cout << "\n";
    imprimirDetalleEstadia(eleccionHostal_CHuesped,eleccionHuesped_CHuesped);
}

//Baja de reserva
void bajaDeReserva(){
    int eleccionCancelar_CHuesped,eleccionReserva_CHuesped;
    string eleccionHostal_CHuesped;
    imprimirTodosNombreHostal();
    cout << "Ingrese el nombre del hostal cuya reserva desea cancelar" << endl;
    getline(cin, eleccionHostal_CHuesped);
    cout << "\n";
    imprimirTodasReservas(eleccionHostal_CHuesped);
    cout << "Ingrese el numero de la reserva que desea cancelar" << endl;
    cin >> eleccionReserva_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";
    cout << "Indique si esta seguro de su cancelacion: 1 = Si / 2 = No" << endl;
    cin >> eleccionCancelar_CHuesped;
    cin.ignore(256, '\n');
    cout << "\n";
    if (eleccionCancelar_CHuesped == 1){
        controladorReservas->cancelarReserva(eleccionReserva_CHuesped);
    } else if (eleccionCancelar_CHuesped == 2)
        cout << "Se ha cancelado el proceso de baja de reserva" << endl;
}


// ----------------------------------------------------------------- //
// ----------------------------------------------------------------- //

int main(){
    cargarDatosPrueba();
    int autoNumberCodigoReserva = 5;
    int AnioMain, MesMain, DiaMain, HoraMain, MinutoMain;

    cout << "Ingrese la fecha del sistema\n";

    cout << "Anio:";
    cin >> AnioMain;
    cin.ignore(256, '\n');

    cout << "Mes:";
    cin >> MesMain;
    cin.ignore(256, '\n');

    cout << "Dia:";
    cin >> DiaMain;
    cin.ignore(256, '\n');

    cout << "Hora:";
    cin >> HoraMain;
    cin.ignore(256, '\n');

    cout << "Minuto:";
    cin >> MinutoMain;
    cin.ignore(256, '\n');


    controladorSistema->modificarFecha(DTFecha(DiaMain,MesMain,AnioMain,HoraMain,MinutoMain));

    bool elegirOpcionUsuario = true;
    int opcionUsuario;
    bool elegirOpcionHuesped;

    bool elegirOpcionEmpleado;
    while (elegirOpcionUsuario) {
         try{
            cout << "Seleccione el tipo de usuario que se encuentra utilizando el sistema\n";
            cout << "1: Administrador\n";
            cout << "2: Empleado\n";
            cout << "3: Huesped\n";
            cout << "4: Quiero salir del sistema\n";
            cout << "Ingrese una opcion: ";
            cin >> opcionUsuario;
            cout << "\n";
            if ((opcionUsuario > 4) || (opcionUsuario < 1))
                throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }
        
        string eleccionHostalEmpleado_CEmpleado;
        bool elegirOpcionAdministrador;


        switch (opcionUsuario){
            case 1:
                //COMIENZO CASOS DE USO ADMINISTRADOR
                elegirOpcionAdministrador = true;
                int opcionAdministrador;
                while (elegirOpcionAdministrador) {
                    try{
                        cout << "Seleccione una opcion\n";
                        cout << "1: Alta de usuario\n";
                        cout << "2: Alta de hostal\n";
                        cout << "3: Alta de habitacion\n";
                        cout << "4: Asignar empleado a hostal\n";
                        cout << "5: Modificar fecha del sistema\n";
                        cout << "6: Salir\n";
                        cout << "Ingrese una opcion: ";
                        cin >> opcionAdministrador;
                        cout << "\n";
                        if ((opcionAdministrador > 6) || (opcionAdministrador < 1))
                            throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
                    }
                    catch(invalid_argument& e){
                        cout << e.what() << endl;
                    }

                        switch (opcionAdministrador){
                            case 1:
                                altaDeUsuario();
                                break;
                            case 2:
                                altaDeHostal();
                                break;
                            case 3:
                                altaDeHabitacion();
                                break;
                            case 4:
                                asignarEmpleadoAHostal();
                                break;
                            case 5:
                                modificarFechaDelSistema();
                                break;
                            case 6:
                                elegirOpcionAdministrador = false;
                            default:
                                break;
                        }
                }
                //FIN CASOS DE USO ADMINISTRADOR
                break;
            case 2:
                imprimirTodosNombreHostal();
                cout << "Indique el nombre del hostal en el cual trabaja\n";
                getline(cin, eleccionHostalEmpleado_CEmpleado);
                cout << "\n";

                //COMIENZO CASOS DE USO EMPLEADO

                elegirOpcionEmpleado = true;
                int opcionEmpleado;

                while (elegirOpcionEmpleado) {
                    try{
                        cout << "Seleccione una opcion\n";
                        cout << "1: Registrar estadia\n";
                        cout << "2: Finalizar estadia\n";
                        cout << "3: Comentar calificacion\n";
                        cout << "4: Suscribirse a notificaciones\n";
                        cout << "5: Consulta de notificaciones\n";
                        cout << "6: Eliminar suscripcion\n";
                        cout << "7: Salir\n";
                        cout << "Ingrese una opcion: ";
                        cin >> opcionEmpleado;
                        cout << "\n";
                        if ((opcionEmpleado > 7) || (opcionEmpleado < 1))
                            throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
                    }
                    catch(invalid_argument& e){
                        cout << e.what() << endl;
                    }
                        switch (opcionEmpleado){
                            case 1:
                                //Registrar estadia
                                registrarEstadia(eleccionHostalEmpleado_CEmpleado);
                                break;
                            case 2:
                                //Finalizar estadia
                                finalizarEstadia();
                                break;
                            case 3:
                                //Comentar calificacion
                                comentarCalificacion();
                                break;
                            case 4:
                                cout << "Lamentamos informarle que esta funcionalidad todavia no se encuentra disponible\n";
                                break;
                            case 5:
                                cout << "Lamentamos informarle que esta funcionalidad todavia no se encuentra disponible\n";
                            case 6:
                                cout << "Lamentamos informarle que esta funcionalidad todavia no se encuentra disponible\n";
                            case 7:
                                elegirOpcionEmpleado = false;
                                break;
                            default:
                                break;
                        }
                }
                //FIN CASOS DE USO ADMINISTRADOR
                break;

            case 3:
		
                //COMIENZO CASOS DE USO HUESPED
                elegirOpcionHuesped = true;
                int opcionHuesped;
                while (elegirOpcionHuesped) {
                    try{
                        cout << "1: Realizar reserva\n";
                        cout << "2: Consultar top 3 hostales\n";
                        cout << "3: Calificar estadia\n";
                        cout << "4: Consulta de usuario\n";
                        cout << "5: Consulta de hostal\n";
                        cout << "6: Consulta de reserva\n";
                        cout << "7: Consulta de estadia\n";
                        cout << "8: Baja de reserva\n";
                        cout << "9: Salir\n";
                        cin >> opcionHuesped;
                        cout << "\n";
                        if ((opcionHuesped > 10) || (opcionHuesped < 1))
                            throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
                    }
                    catch(invalid_argument& e){
                        cout << e.what() << endl;
                    }
                        switch (opcionHuesped){
                            case 1:
                                autoNumberCodigoReserva = realizarReserva(autoNumberCodigoReserva);
                                break;
                            case 2:
                                consultarTop3Hostales();
                                break;
                            case 3:
                                calificarEstadia();
                                break;
                            case 4:
                                //Consulta de usuario
                                consultaDeUsuario();
                                break;
                            case 5:
                                //Consulta de hostal
                                consultaDeHostal();
                                break;
                            case 6:
                                //Consulta de reserva
                                consultaDeReserva();
                                break;
                            case 7:
                                consultaDeEstadia();
                                break;
                            case 8:
                                bajaDeReserva();
                                break;
                            case 9:
                                elegirOpcionHuesped = false;
                                break;
                            default:
                                break;
                        }
                }
                //FIN CASOS DE USO HUESPED
                break;
            case 4:
                elegirOpcionUsuario = false;
                break;
            default:
                break;
        }  
    }
    controladorCalificaciones->eliminarCalificaciones();
    controladorEstadias->eliminarEstadias();
    controladorHabitaciones->eliminarHabitaciones();
    controladorHostales->eliminarHostales();
    controladorNotificaciones->eliminarNotificaciones();
    controladorReservas->eliminarReservas();
    controladorUsuarios->eliminarUsuarios();
}
