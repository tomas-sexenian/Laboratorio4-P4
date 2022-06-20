#ifndef DTESTADIA
#define DTESTADIA

#include "./DTFecha.hh"

#include <string>

using namespace std;

class DTEstadia{
    private: 
        int codigoReserva;
        string emailHuesped;
        string nombreHostal;
        DTFecha entrada;
        DTFecha salida;
        int habitacion;
        string promo;
    public:
        DTEstadia(int, string,string,DTFecha,DTFecha,int,string);
        DTEstadia();
        ~DTEstadia();
        int getCodigoReserva();
        string getEmailHuesped();
        string getNombreHostal();
        DTFecha getEntrada();
        DTFecha getSalida();
        int getHabitacion();
        string getPromo();
};

#endif