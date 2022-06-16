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

    DTFecha checkIn = DTFecha(1,5,22,14,0);
    DTFecha checkOut = DTFecha(10,5,22,10,0);
    controladorReservas->ingresarDatosReserva(1,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("La posada del finger");
    controladorReservas->seleccionarHabitacion(1);
    controladorReservas->seleccionarTipo(individual);
    controladorReservas->ingresarHuesped("sofia@mail.com");
    controladorReservas->confirmarReserva();

    checkIn = DTFecha(4,1,1,20,0);
    checkOut = DTFecha(5,1,1,2,0);
    controladorReservas->ingresarDatosReserva(2,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("El Pony Pisador");
    controladorReservas->seleccionarHabitacion(1);
    controladorReservas->seleccionarTipo(grupal);
    controladorReservas->ingresarHuesped("frodo@mail.com");
    list<string> invitados = {"sam@mail.com","merry@mail.com","pippin@mail.com"};
    controladorReservas->ingresarInvitados(invitados);
    controladorReservas->confirmarReserva();

    checkIn = DTFecha(7,6,22,14,0);
    checkOut = DTFecha(30,6,22,11,0);
    controladorReservas->ingresarDatosReserva(3,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("La posada del finger");
    controladorReservas->seleccionarHabitacion(3);
    controladorReservas->seleccionarTipo(individual);
    controladorReservas->ingresarHuesped("sofia@mail.com");
    controladorReservas->confirmarReserva();

    checkIn = DTFecha(10,6,22,14,0);
    checkOut = DTFecha(30,6,22,11,0);
    controladorReservas->ingresarDatosReserva(4,checkIn,checkOut,abierta);
    controladorReservas->seleccionarHostal("Caverna Lujosa");
    controladorReservas->seleccionarHabitacion(1);
    controladorReservas->seleccionarTipo(individual);
    controladorReservas->ingresarHuesped("seba@mail.com");
    controladorReservas->confirmarReserva();

    // CARGA DE ESTADIAS PARA RESERVAS DE HUESPEDES

    controladorReservas->seleccionarTipo(individual);
    controladorReservas->seleccionarReservaIndividual(1);
    controladorReservas->ingresarHuesped("sofia@mail.com");
    controladorReservas->ingresarEntradaEstadia(1,5,22,18,0);
    controladorReservas->confirmarAltaEstadia();

    controladorReservas->seleccionarTipo(grupal);
    controladorReservas->seleccionarReservaGrupal(2);
    controladorReservas->ingresarHuesped("frodo@mail.com");
    invitados = {"sam@mail.com","merry@mail.com","pippin@mail.com"};
    controladorReservas->ingresarInvitados(invitados);
    controladorReservas->ingresarEntradaEstadia(4,1,1,21,0);
    controladorReservas->confirmarAltaEstadia();

    controladorReservas->seleccionarTipo(individual);
    controladorReservas->seleccionarReservaIndividual(4);
    controladorReservas->ingresarHuesped("seba@mail.com");
    controladorReservas->ingresarEntradaEstadia(7,6,22,18,0);
    controladorReservas->confirmarAltaEstadia();

    // FINALIZACION DE ESTADIAS

    Estadia* e;

    controladorEstadias->seleccionarEstadia(1,"sofia@mail.com");
    e = controladorEstadias->finalizarEstadia();
    e->setSalida(DTFecha(10,5,22,9,0));

    controladorEstadias->seleccionarEstadia(2,"frodo@mail.com");
    e = controladorEstadias->finalizarEstadia();
    e->setSalida(DTFecha(5,1,1,2,0));

    controladorEstadias->seleccionarEstadia(4,"seba@mail.com");
    e = controladorEstadias->finalizarEstadia();
    e->setSalida(DTFecha(15,6,22,22,0));

    // CALIFICACIONES DE ESTADIAS

    controladorCalificaciones->ingresarComentario("Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacia tremendo ruido) y 2 pesas, la piscina parecia el lago del Parque Rodo y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuevlo");
    controladorCalificaciones->ingresarPuntaje(3);
    controladorCalificaciones->ingresarFecha(DTFecha(11,5,22,18,0));
    controladorCalificaciones->confirmarAltaCalificacion(1,"sofia@mail.com");

    controladorCalificaciones->ingresarComentario("Se pone peligroso de noche, no recomiendo. Ademas no hay caja fuerte para guardar los anillos");
    controladorCalificaciones->ingresarPuntaje(2);
    controladorCalificaciones->ingresarFecha(DTFecha(5,1,1,3,0));
    controladorCalificaciones->confirmarAltaCalificacion(2,"frodo@mail.com");

    controladorCalificaciones->ingresarComentario("Habia pulgas en la habitacion. Que lugar mas mamarracho!!");
    controladorCalificaciones->ingresarPuntaje(1);
    controladorCalificaciones->ingresarFecha(DTFecha(15,6,22,11,0));
    controladorCalificaciones->confirmarAltaCalificacion(4,"seba@mail.com");

    // COMENTARIOS A CALIFICACIONES

    controladorCalificaciones->ingresarRespuesta("Desaparecio y se fue sin pagar");
    controladorCalificaciones->responderCalificacion(2,"frodo@mail.com",DTFecha(15,6,22,23,0));
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

int main(){
    cargarDatosPrueba();
    int autoNumberCodigoReserva = 5;
    cout << "Ingrese la fecha del sistema\n";

    cout << "Anio:";
    int AnioSistema;
    cin >> AnioSistema;
    cout << "\n";

    cout << "Mes:";
    int MesSistema;
    cin >> MesSistema;
    cout << "\n";

    cout << "Dia:";
    int DiaSistema;
    cin >> DiaSistema;
    cout << "\n";

    cout << "Hora:";
    int HoraSistema;
    cin >> HoraSistema;
    cout << "\n";

    cout << "Minuto:";
    int MinutoSistema;
    cin >> MinutoSistema;
    cout << "\n";

    controladorSistema->modificarFecha(DTFecha(AnioSistema,MesSistema,DiaSistema,HoraSistema,HoraSistema));

    bool elegirOpcionUsuario = true;
    int opcionUsuario;
    while (elegirOpcionUsuario) {
         try{
            cout << "Seleccione el tipo de usuario que se encuentra utilizando el sistema\n";
            cout << "1: Administrador\n";
            cout << "2: Empleado\n";
            cout << "3: Huesped\n";
            cout << "4: Quiero salir del sistema\n";
            cout << "Ingrese una opcion: ";
            cin >> opcionUsuario;
            cin.ignore(256,'\n');
            cout << "\n";
            if ((opcionUsuario > 4) || (opcionUsuario < 1))
                throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
        }
        
        // PARA ALTA DE USUARIO
        int eleccionTipoUsuario_CUsuario;
        string eleccionNombreUsuario_CUsuario;
        string eleccionMailUsuario_CUsuario;
        string eleccionContraseniaUsuario_CUsuario;
        int eleccionCargoUsuario_CUsuario;
        int eleccionEsFingerUsuario_CUsuario;

        // PARA ALTA DE HOSTAL
        string eleccionNombreHostal_CUsuario, eleccionDireccionHostal_CUsuario, eleccionTelefonoHostal_CUsuario;

        // PARA ALTA DE HABITACION
        int eleccionNumeroHabitacion_CUsuario, eleccionCapacidadHabitacion_CUsuario, eleccionCostoHabitacion_CUsuario;
                        
        // PARA ASIGNAR EMPLEADO A HOSTAL
        string eleccionEmailEmpleado_CUsuario;
        
        // PARA REGISTRAR ESTADIA
        int eleccionTipoEstadia_CEmpleado, eleccionCodigoReserva_CEmpleado;
        string eleccionEmailHuespedEstadia_CEmpleado;

        // PARA REGISTRAR ESTADIA
        int eleccionTipoEstadia_CEmpleado, eleccionCodigoReserva_CEmpleado;
        string eleccionEmailHuespedEstadia_CEmpleado;

        // PARA FINALIZAR ESTADIA
        string eleccionComentarioEstadia_CEmpleado;
        int eleccionPuntajeEstadia_CEmpleado;

        // PARA COMENTAR CALIFICACION
        string eleccionComentarioCalificacion_CEmpleado;

        // PARA REALIZAR RESERVA
        string eleccionHostalReserva_CHuesped,eleccionEmailInvitado_CHuesped;
        int eleccionHabitacionReserva_CHuesped,eleccionTipoReserva_CHuesped,eleccionSeguiraAgregando_CHuesped;
        list<string> eleccionEmailInvitadosReserva_CHuesped;
        bool continuarArgegando_CHuesped;

        // PARA CALIFICAR ESTADIA
        string eleccionComentarioEstadia_CHuesped;
        int eleccionPuntajeEstadia_CHuesped;
        
        // PARA CONSULTA DE USUARIO
        int eleccionTipoUsuario_CHuesped;
        string eleccionEmailEmpleado_CHuesped, eleccionEmailHuesped_CHuesped,eleccionHostal_CHuesped;
        

        // PARA CONSULTA DE HOSTAL
        int cantCalificaciones_CHuesped;
        DTInfoBasicaHostal infoBasicaHostal_CHuesped;

        // PARA CONSULTA DE RESERVA
        int eleccionReserva_CHuesped;

        // PARA CONSULTA DE ESTADIA
        string eleccionHuesped_CHuesped;

        // PARA BAJA DE RESERVA
        int eleccionCancelar_CHuesped;
        
        switch (opcionUsuario){
            case 1:
                //COMIENZO CASOS DE USO ADMINISTRADOR
                bool elegirOpcionAdministrador = true;
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
                        cin.ignore(256,'\n');
                        cout << "\n";
                        if ((opcionAdministrador > 6) || (opcionAdministrador < 1))
                            throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
                    }
                    catch(invalid_argument& e){
                        cout << e.what() << endl;
                    }

                        switch (opcionAdministrador){
                            case 1:

                                cout << "Ingrese el tipo de usuario: 1 = Empleado / 2 = Huesped\n";
                                cin >> eleccionTipoUsuario_CUsuario;
                                cout << "\n";
                                if (eleccionTipoUsuario_CUsuario = 1){
                                    controladorUsuarios->ingresarTipo(empleado);
                                    cout << "Ingrese el cargo del empleado: 1 = Administracion / 2 = Limpieza / 3 = Recepcion / 4 = Infraestructura\n";
                                    cin >> eleccionCargoUsuario_CUsuario;
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
                                else if (eleccionTipoUsuario_CUsuario = 2){
                                    controladorUsuarios->ingresarTipo(huesped);
                                    cout << "Indique si el huesped es finger o no: 1 = Si / 2 = No\n";
                                    cin >> eleccionCargoUsuario_CUsuario;
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
                                cin >> eleccionNombreUsuario_CUsuario;
                                cout << "\n";    
                                cout << "Ingrese el mail del usuario\n";
                                cin >> eleccionMailUsuario_CUsuario;
                                cout << "\n";  
                                cout << "Ingrese la contrasenia del usuario\n";
                                cin >> eleccionContraseniaUsuario_CUsuario;
                                cout << "\n";  
                                controladorUsuarios->ingresarDatosUsuario(eleccionNombreUsuario_CUsuario,eleccionMailUsuario_CUsuario,eleccionContraseniaUsuario_CUsuario);

                                controladorUsuarios->confirmarAltaUsuario();
                                break;
                            case 2:
                                cout << "Ingrese el nombre del hostal\n";
                                cin >> eleccionNombreHostal_CUsuario;
                                cout << "\n";   

                                cout << "Ingrese la direccion del hostal\n";
                                cin >> eleccionDireccionHostal_CUsuario;
                                cout << "\n"; 

                                cout << "Ingrese el telefono del hostal\n";
                                cin >> eleccionTelefonoHostal_CUsuario;
                                cout << "\n";   

                                controladorHostales->ingresarDatosHostal(eleccionNombreHostal_CUsuario,eleccionDireccionHostal_CUsuario,eleccionTelefonoHostal_CUsuario);
                                controladorHostales->confirmarAltaHostal();
                                break;
                            case 3:
                                cout << "Ingrese el numero de habitacion\n";
                                cin >> eleccionNumeroHabitacion_CUsuario;
                                cout << "\n";

                                cout << "Ingrese el costo de la habitacion\n";
                                cin >> eleccionCostoHabitacion_CUsuario;
                                cout << "\n";

                                cout << "Ingrese la capacidad de la habitacion\n";
                                cin >> eleccionCapacidadHabitacion_CUsuario;
                                cout << "\n";

                                controladorHabitaciones->ingresarDatosHabitacion(eleccionNumeroHabitacion_CUsuario,eleccionCostoHabitacion_CUsuario,eleccionCapacidadHabitacion_CUsuario);

                                cout << "Ingrese el nombre del hostal al cual pertenece la habitacion\n";
                                cin >> eleccionNombreHostal_CUsuario;
                                cout << "\n";

                                controladorHabitaciones->ingresarHostalHabitacion(eleccionNombreHostal_CUsuario);
                                controladorHabitaciones->confirmarAltaHabitacion();
                                break;
                            case 4:
                                imprimirTodosEmailHuespedes();
                                cout << "Ingrese el email del empleado\n";
                                cin >> eleccionEmailEmpleado_CUsuario;
                                cout << "\n";
                                controladorUsuarios->seleccionarEmpleado(eleccionEmailEmpleado_CUsuario);

                                cout << "Ingrese el cargo del empleado: 1 = Administracion / 2 = Limpieza / 3 = Recepcion / 4 = Infraestructura\n";
                                    cin >> eleccionCargoUsuario_CUsuario;
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
                                cin >> eleccionNombreHostal_CUsuario;
                                cout << "\n";
                                controladorUsuarios->ingresarHostal(eleccionNombreHostal_CUsuario);

                                controladorUsuarios->confirmarAsignacionEmpleado();
                                break;
                            case 5:
                                    cout << "Ingrese la fecha del sistema\n";

                                    cout << "Anio:";
                                    cin >> AnioSistema;
                                    cout << "\n";

                                    cout << "Mes:";
                                    cin >> MesSistema;
                                    cout << "\n";

                                    cout << "Dia:";
                                    cin >> DiaSistema;
                                    cout << "\n";

                                    cout << "Hora:";
                                    cin >> HoraSistema;
                                    cout << "\n";

                                    cout << "Minuto:";
                                    cin >> MinutoSistema;
                                    cout << "\n";

                                    controladorSistema->modificarFecha(DTFecha(AnioSistema,MesSistema,DiaSistema,HoraSistema,HoraSistema));
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
                //COMIENZO CASOS DE USO EMPLEADO

                bool elegirOpcionEmpleado = true;
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
                        cin.ignore(256,'\n');
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
                                cout << "Indique si la estadia corresponde a una reserva individual o grupal: 1 = Individual / 2 = Grupal\n";
                                cin >> eleccionTipoEstadia_CEmpleado;
                                cout << "\n";

                                cout << "Indique el codigo de la reserva asociada a la estadia\n";
                                cin >> eleccionCodigoReserva_CEmpleado;
                                cout << "\n";
                                
                                switch(eleccionTipoEstadia_CEmpleado){
                                    case 1:
                                        controladorReservas->seleccionarTipo(individual);
                                        controladorReservas->seleccionarReservaIndividual(eleccionCodigoReserva_CEmpleado);

                                        break;
                                    case 2:
                                        controladorReservas->seleccionarTipo(grupal);
                                        controladorReservas->seleccionarReservaGrupal(eleccionCodigoReserva_CEmpleado);

                                        break;
                                }


                                imprimirTodosEmailHuespedes();
                                cout << "Indique el email del huesped asociado a la estadia\n";
                                cin >> eleccionEmailHuespedEstadia_CEmpleado;
                                cout << "\n";
                                controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);


                                controladorReservas->ingresarEntradaEstadia(controladorSistema->obtenerFechaActual());
                                controladorReservas->confirmarAltaEstadia();
                                break;
                            case 2:
                                //Finalizar estadia
                                cout << "Indique el comentario asociado a la estadia\n";
                                cin >> eleccionComentarioEstadia_CEmpleado;
                                cout << "\n";
                                controladorCalificaciones->ingresarComentario(eleccionComentarioEstadia_CEmpleado);

                                cout << "Indique el puntaje asociado a la estadia\n";
                                cin >> eleccionPuntajeEstadia_CEmpleado;
                                cout << "\n";
                                controladorCalificaciones->ingresarPuntaje(eleccionPuntajeEstadia_CEmpleado);

                                controladorCalificaciones->ingresarFecha(controladorSistema->obtenerFechaActual());

                                cout << "Indique el codigo de la reserva asociada a la estadia\n";
                                cin >> eleccionCodigoReserva_CEmpleado;
                                cout << "\n";

                                imprimirTodosEmailHuespedes();
                                cout << "Indique el email del huesped asociado a la estadia\n";
                                cin >> eleccionEmailHuespedEstadia_CEmpleado;
                                cout << "\n";
                                controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);
                                
                                controladorCalificaciones->confirmarAltaCalificacion(eleccionCodigoReserva_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado);
                                break;
                            case 3:
                                //Comentar calificacion
                                cout << "Indique el comentario asociado a la calificacion\n";
                                cin >> eleccionComentarioCalificacion_CEmpleado;
                                cout << "\n";
                                controladorCalificaciones->ingresarRespuesta(eleccionComentarioCalificacion_CEmpleado);
                                
                                cout << "Indique el codigo de la reserva asociada a la estadia\n";
                                cin >> eleccionCodigoReserva_CEmpleado;
                                cout << "\n";

                                cout << "Indique el email del huesped asociado a la estadia\n";
                                cin >> eleccionEmailHuespedEstadia_CEmpleado;
                                cout << "\n";
                                controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);

                                controladorCalificaciones->responderCalificacion(eleccionCodigoReserva_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado,controladorSistema->obtenerFechaActual());
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
                bool elegirOpcionHuesped = true;
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
                        cin >> elegirOpcionHuesped;
                        cin.ignore(256,'\n');
                        cout << "\n";
                        if ((elegirOpcionHuesped > 10) || (elegirOpcionHuesped < 1))
                            throw invalid_argument("Opcion invalida, por favor ingrese una opcion valida");
                    }
                    catch(invalid_argument& e){
                        cout << e.what() << endl;
                    }
                        switch (elegirOpcionHuesped){
                            case 1:
                                //Realizar reserva

                                /*

                                    NOTA (borrar)
                                    checkeate que checkin < checkout, porque
                                    si no falla el algoritmo de estaDisponible
                                    también no tiene sentido de que el dia de
                                    checkin sea igual a checkout
                                    Para DTFecha operator< ya está implementado


                                */

                                cout << "Ingrese la fecha de check in\n";

                                cout << "Anio:";
                                cin >> AnioSistema;
                                cout << "\n";

                                cout << "Mes:";
                                cin >> MesSistema;
                                cout << "\n";

                                cout << "Dia:";
                                cin >> DiaSistema;
                                cout << "\n";

                                cout << "Hora:";
                                cin >> HoraSistema;
                                cout << "\n";

                                cout << "Minuto:";
                                cin >> MinutoSistema;
                                cout << "\n";

                                DTFecha checkIn = DTFecha(AnioSistema,MesSistema,DiaSistema,HoraSistema,MinutoSistema);

                                cout << "Ingrese la fecha de check out\n";

                                cout << "Anio:";
                                cin >> AnioSistema;
                                cout << "\n";

                                cout << "Mes:";
                                cin >> MesSistema;
                                cout << "\n";

                                cout << "Dia:";
                                cin >> DiaSistema;
                                cout << "\n";

                                cout << "Hora:";
                                cin >> HoraSistema;
                                cout << "\n";

                                cout << "Minuto:";
                                cin >> MinutoSistema;
                                cout << "\n";

                                DTFecha checkOut = DTFecha(AnioSistema,MesSistema,DiaSistema,HoraSistema,MinutoSistema);

                                controladorReservas->ingresarDatosReserva(autoNumberCodigoReserva,checkIn,checkOut,abierta);
                                autoNumberCodigoReserva++;

                                imprimirTodosNombreHostal();
                                cout << "Indique el nombre del hostal donde realizara la reserva\n";
                                cin >> eleccionHostalReserva_CHuesped;
                                cout << "\n";
                                controladorReservas->seleccionarHostal(eleccionHostalReserva_CHuesped);
                                
                                imprimirTodosNumeroHabitacion(eleccionHostalReserva_CHuesped,checkIn,checkOut);
                                cout << "Indique el numero de habitacion\n";
                                cin >> eleccionHabitacionReserva_CHuesped;
                                cout << "\n";
                                controladorReservas->seleccionarHabitacion(eleccionHabitacionReserva_CHuesped);

                                cout << "Indique el tipo de reserva: 1 = Individual / 2 = Grupal\n";
                                cin >> eleccionTipoReserva_CHuesped;
                                cout << "\n";
                                switch(eleccionTipoReserva_CHuesped){
                                    case 1:
                                        controladorReservas->seleccionarTipo(individual);
                                        cout << "Por favor indique su email\n";
                                        cin >> eleccionEmailHuespedEstadia_CEmpleado;
                                        cout << "\n";
                                        controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);
                                        break;
                                    case 2:
                                        controladorReservas->seleccionarTipo(grupal);
                                        cout << "Por favor indique su email\n";
                                        cin >> eleccionEmailHuespedEstadia_CEmpleado;
                                        cout << "\n";
                                        controladorReservas->ingresarHuesped(eleccionEmailHuespedEstadia_CEmpleado);
                                        cout << "Por favor indique sus huespedes invitados\n";
                                        eleccionEmailInvitadosReserva_CHuesped = {};
                                        continuarArgegando_CHuesped = true;
                                        while (continuarArgegando_CHuesped){
                                            cout << "Por favor indique el email del huesped:";
                                            cin >> eleccionEmailInvitado_CHuesped;
                                            eleccionEmailInvitadosReserva_CHuesped.push_back(eleccionEmailInvitado_CHuesped);
                                            cout << "Si desea detenerse, ingrese 1 de lo contrario ingrese cualquier numero:";
                                            cin >> eleccionSeguiraAgregando_CHuesped;
                                            if (eleccionSeguiraAgregando_CHuesped = 1)
                                                continuarArgegando_CHuesped = false;
                                        }
                                        controladorReservas->ingresarInvitados(eleccionEmailInvitadosReserva_CHuesped);
                                        break;
                                }
                                controladorReservas->confirmarReserva();
                                break;
                            case 2:
                                //Consultar top 3 hostales
                                break;
                            case 3:
                                //Calificar estadia
                                cout << "Por ingrese el comentario\n";
                                cin >> eleccionComentarioEstadia_CHuesped;
                                cout << "\n";
                                controladorCalificaciones->ingresarComentario(eleccionComentarioEstadia_CHuesped);

                                cout << "Por favor ingrese el puntaje\n";
                                cin >> eleccionPuntajeEstadia_CHuesped;
                                cout << "\n";
                                controladorCalificaciones->ingresarPuntaje(eleccionPuntajeEstadia_CHuesped);

                                controladorCalificaciones->ingresarFecha(controladorSistema->obtenerFechaActual());

                                cout << "Indique el codigo de la reserva asociada a la estadia\n";
                                cin >> eleccionCodigoReserva_CEmpleado;
                                cout << "\n";
                                cout << "Por favor indique su email\n";
                                cin >> eleccionEmailHuespedEstadia_CEmpleado;
                                cout << "\n";
                                controladorCalificaciones->confirmarAltaCalificacion(eleccionCodigoReserva_CEmpleado,eleccionEmailHuespedEstadia_CEmpleado);

                                break;
                            case 4:
                                //Consulta de usuario
                                cout << "Indique si desea consultar por empleados o huespedes: 1 = Huespedes / 2 = Empleados" << endl;
                                cin >> eleccionTipoUsuario_CHuesped;
                                cout << "\n";
                                if (eleccionTipoUsuario_CHuesped = 1){
                                    imprimirTodosEmailHuespedes();
                                    cout << "Ingrese el mail del empleado que desea visualizar" << endl;
                                    cin >> eleccionEmailEmpleado_CHuesped;
                                    cout << "\n";
                                    imprimirDetalleEmpleado(eleccionEmailEmpleado_CHuesped);
                                }
                                else if (eleccionTipoUsuario_CHuesped = 2){
                                    imprimirTodosEmailEmpleados();
                                    cout << "Ingrese el mail del huesped que desea visualizar" << endl;
                                    cin >> eleccionEmailEmpleado_CHuesped;
                                    cout << "\n";
                                    imprimirDetalleHuesped(eleccionEmailEmpleado_CHuesped);
                                }
                                break;
                            case 5:
                                //Consulta de hostal
                                imprimirTodosNombreHostal();
                                cout << "Ingrese el nombre del hostal que desea consultar" << endl;
                                cin >> eleccionHostal_CHuesped;
                                cout << "\n";
                                imprimirDetalleHostal(eleccionHostal_CHuesped);
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
                                break;
                            case 6:
                                //Consulta de reserva
                                imprimirTodosNombreHostal();
                                cout << "Ingrese el nombre del hostal cuya reserva desea consultar" << endl;
                                cin >> eleccionHostal_CHuesped;
                                cout << "\n";
                                imprimirTodasReservas(eleccionHostal_CHuesped);
                                cout << "Ingrese el numero de la reserva que desea consultar" << endl;
                                cin >> eleccionReserva_CHuesped;
                                cout << "\n";
                                imprimirDetalleReserva(eleccionReserva_CHuesped,eleccionHostal_CHuesped);
                                break;
                            case 7:
                                //Consulta de estadia
                                imprimirTodosNombreHostal();
                                cout << "Ingrese el nombre del hostal en el que se realizo la estadia" << endl;
                                cin >> eleccionHostal_CHuesped;
                                cout << "\n";
                                imprimirTodasEstadias(eleccionHostal_CHuesped);
                                cout << "Ingrese el email del huesped cuya estadia desea consultar" << endl;
                                cin >> eleccionHuesped_CHuesped;
                                cout << "\n";
                                imprimirDetalleEstadia(eleccionHostal_CHuesped,eleccionHuesped_CHuesped);
                                break;
                            case 8:
                                //Baja de reserva
                                imprimirTodosNombreHostal();
                                cout << "Ingrese el nombre del hostal cuya reserva desea cancelar" << endl;
                                cin >> eleccionHostal_CHuesped;
                                cout << "\n";
                                imprimirTodasReservas(eleccionHostal_CHuesped);
                                cout << "Ingrese el numero de la reserva que desea cancelar" << endl;
                                cin >> eleccionReserva_CHuesped;
                                cout << "\n";
                                cout << "Indique si esta seguro de su cancelacion: 1 = Si / 2 = No" << endl;
                                cin >> eleccionCancelar_CHuesped;
                                cout << "\n";
                                if (eleccionCancelar_CHuesped = 1){
                                    controladorReservas->cancelarReserva(eleccionReserva_CHuesped);
                                    cout << "La reserva ha sido cancelada con exito" << endl;
                                } else if (eleccionCancelar_CHuesped = 2)
                                    cout << "Se ha cancelado el proceso de baja de reserva" << endl;
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
}
