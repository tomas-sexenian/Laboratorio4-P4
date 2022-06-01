#ifndef DTESTADIA
#define DTESTADIA

#include "./DTFecha.hh"

#include <string>

using namespace std;

class DTEstadia{
    private: 
        string emailHuesped;
        string nombreHostal;
        DTFecha entrada;
        DTFecha salida;
        int habitacion;
        string promo;
    public:
        DTEstadia(string,string,DTFecha,DTFecha,int,string);
        DTEstadia();
        ~DTEstadia();
        string getEmailHuesped();
        string getNombreHostal();
        DTFecha getEntrada();
        DTFecha getSalida();
        int getHabitacion();
        string getPromo();
};

#endif