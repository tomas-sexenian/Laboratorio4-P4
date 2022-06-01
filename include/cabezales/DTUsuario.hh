#ifndef USUARIO
#define USUARIO

#include "./DTFecha.hh"

#include <string>

using namespace std;

class DTUsuario {
    protected:
        string nombre;
        string email;
        string contrasenia;
    public:
        string getNombre();
        string getEmail();
        string getContrasenia();

        DTUsuario();
        DTUsuario(string,string,string);
        ~DTUsuario();
};

#endif