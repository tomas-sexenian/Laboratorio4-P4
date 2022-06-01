#ifndef DTINFOESTADIA
#define DTINFOESTADIA

#include <string>
#include <list>

#include "./DTFecha.hh"

using namespace std;

class DTInfoEstadia{
    private: 
        string emailHuesped;
        string nombreHostal;
        DTFecha entrada;
        DTFecha salida;
        int habitacion;
        string promo;
        int codigoReserva;
    public:
        DTInfoEstadia(string,string,DTFecha,DTFecha,int,string,int);
        DTInfoEstadia();
        ~DTInfoEstadia();
        string getEmailHuesped();
        string getNombreHostal();
        DTFecha getEntrada();
        DTFecha getSalida();
        int getHabitacion();
        string getPromo();
        int getCodigoReserva();
};

#endif