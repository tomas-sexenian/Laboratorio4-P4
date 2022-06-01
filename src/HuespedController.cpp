#include "../include/controladores/HuespedController.hh"

HuespedController::HuespedController() {
}

HuespedController::~HuespedController() {
}

HuespedController* HuespedController::instancia;
HuespedController * HuespedController::getInstancia(){
    if (HuespedController::instancia == NULL)
        HuespedController::instancia = new HuespedController();
    return HuespedController::instancia;
};

// DE ACA HACIA ABAJO IMPLEMENTAN LAS OPERACIONES

void HuespedController::ingresarEmailHuesped(string UnEmail) {
}

bool HuespedController::obtenerEsFinger() {
}

list<DTHuesped> HuespedController::obtenerTodosHuespedes() {
}

list<DTEstadia> HuespedController::obtenerEstadiasFinalizadasHuesped() {
}

void HuespedController::seleccionarHuesped(string UnEmail) {
}