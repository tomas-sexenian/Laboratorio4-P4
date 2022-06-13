#ifndef USUARIO
#define USUARIO

#include <string>

using namespace std;

class Usuario{
    protected:
        string nombre, email, contrasenia;
    public:
        string getNombre();
        void setNombre(string);
        string getEmail();
        void setEmail(string);
        string getContrasenia();
        virtual void setContrasenia(string);
};

#endif
