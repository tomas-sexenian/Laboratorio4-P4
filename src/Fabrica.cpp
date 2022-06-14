#include "../include/cabezales/Fabrica.hh"


CalificacionController * Fabrica :: getCalificacionController(){
    return CalificacionController::getInstancia();
};

EstadiaController * Fabrica :: getEstadiaController(){
    return EstadiaController::getInstancia();
};

HabitacionController * Fabrica :: getHabitacionController(){
    return HabitacionController::getInstancia();
};

HostalController * Fabrica :: getHostalController(){
    return HostalController::getInstancia();
};


NotificacionesController * Fabrica :: getNotificacionesController(){
    return NotificacionesController::getInstancia();
};

SistemaController * Fabrica :: getSistemaController(){
    return SistemaController::getInstancia();
}; 

UsuarioController * Fabrica :: getUsuarioController(){
    return UsuarioController::getInstancia();
};