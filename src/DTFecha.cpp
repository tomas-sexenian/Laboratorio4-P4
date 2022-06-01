#include "../include/cabezales/DTFecha.hh"
#include <iostream>
#include <string>

DTFecha::DTFecha() {
    dia = 1;
    mes = 1;
    anio = 1901;
}

DTFecha::DTFecha(int UnDia, int UnMes, int UnAnio, int UnaHora, int UnMinuto ) {
    if (UnDia > 31 || UnMes > 12 || UnDia < 1 || UnMes < 1 || UnAnio < 1900)
      throw std::invalid_argument("Revise haber ingesado bien la fecha");
    else { 
        dia = UnDia;
        mes = UnMes;
        anio = UnAnio;
        hora = UnaHora;
        minuto = UnMinuto;
    } 
}

int DTFecha::getDia() {
    return dia;
}

int DTFecha::getMes() {
    return mes;
}

int DTFecha::getAnio() {
    return anio;
}

int DTFecha::getHora() {
    return hora;
}

int DTFecha::getMinuto() {
    return minuto;
}
