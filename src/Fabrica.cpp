#include "../include/cabezales/Fabrica.hh"

AltaDeHabitacionController * Fabrica :: getAltaDeHabitacionController(){
    return AltaDeHabitacionController::getInstancia();
};

AltaDeHostalController * Fabrica :: getAltaDeHostalController(){
    return AltaDeHostalController::getInstancia();
};

AltaDeUsuarioController * Fabrica :: getAltaDeUsuarioController(){
    return AltaDeUsuarioController::getInstancia();
};

CalificacionController * Fabrica :: getCalificacionController(){
    return CalificacionController::getInstancia();
};

EmpleadoController * Fabrica :: getEmpleadoController(){
    return EmpleadoController::getInstancia();
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

HuespedController * Fabrica :: getHuespedController(){
    return HuespedController::getInstancia();
};

NotificacionesController * Fabrica :: getNotificacionesController(){
    return NotificacionesController::getInstancia();
};

RespuestaEmpleadoController * Fabrica :: getRespuestaEmpleadoController(){
    return RespuestaEmpleadoController::getInstancia();
}; 

SistemaController * Fabrica :: getSistemaController(){
    return SistemaController::getInstancia();
}; 

UsuarioController * Fabrica :: getUsuarioController(){
    return UsuarioController::getInstancia();
};