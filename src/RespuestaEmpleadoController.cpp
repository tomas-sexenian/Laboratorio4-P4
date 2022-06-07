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

map<string,RespuestaEmpleado*> RespuestaEmpleadoController::getRespuestas() {
    return respuestas;
}

void RespuestaEmpleadoController::setRespuesta() {
    this->respuestas.insert(pair<string,RespuestaEmpleado*>(this->emailEmpleado,new RespuestaEmpleado(
        this->comentario,
        this->fecha,
        NULL
    )));
}
