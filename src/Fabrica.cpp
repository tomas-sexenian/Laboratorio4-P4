#include "../include/cabezales/Fabrica.hh"
#include "../include/controladores/CalificacionController.hh"
#include "../include/controladores/EstadiaController.hh"
#include "../include/controladores/HabitacionController.hh"
#include "../include/controladores/HostalController.hh"
#include "../include/controladores/NotificacionesController.hh"
#include "../include/controladores/SistemaController.hh"
#include "../include/controladores/UsuarioController.hh"

IControladorCalificacion * Fabrica :: getCalificacionController(){
    return CalificacionController::getInstancia();
};

IControladorEstadia * Fabrica :: getEstadiaController(){
    return EstadiaController::getInstancia();
};

IControladorHabitacion * Fabrica :: getHabitacionController(){
    return HabitacionController::getInstancia();
};

IControladorHostal * Fabrica :: getHostalController(){
    return HostalController::getInstancia();
};


IControladorNotificaciones * Fabrica :: getNotificacionesController(){
    return NotificacionesController::getInstancia();
};

IControladorSistema * Fabrica :: getSistemaController(){
    return SistemaController::getInstancia();
}; 

IControladorUsuario * Fabrica :: getUsuarioController(){
    return UsuarioController::getInstancia();
};

IControladorReserva * Fabrica :: getReservaController(){
    return ReservaController::getInstancia();
};