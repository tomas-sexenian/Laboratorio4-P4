#include "../include/controladores/RespuestaEmpleadoController.hh"

RespuestaEmpleadoController::RespuestaEmpleadoController() {
}

RespuestaEmpleadoController::~RespuestaEmpleadoController() {
}

RespuestaEmpleadoController* RespuestaEmpleadoController::instancia;
RespuestaEmpleadoController * RespuestaEmpleadoController::getInstancia(){
    if (RespuestaEmpleadoController::instancia == NULL)
        RespuestaEmpleadoController::instancia = new RespuestaEmpleadoController();
    return RespuestaEmpleadoController::instancia;
};

