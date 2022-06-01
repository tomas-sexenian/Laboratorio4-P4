#ifndef DTINFOUSUARIO
#define DTINFOUSUARIO

#include <string>

using namespace std;

class DTInfoUsuario{
    private: 
        string nombre;
        string email;
    public:
        DTInfoUsuario(string,string);
        DTInfoUsuario();
        ~DTInfoUsuario();
        string getNombre();
        string getEmail();
};

#endif