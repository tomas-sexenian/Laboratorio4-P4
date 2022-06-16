#ifndef DTUSUARIO
#define DTUSUARIO

#include "./Usuario.hh"
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

        ~DTUsuario();
};

#endif