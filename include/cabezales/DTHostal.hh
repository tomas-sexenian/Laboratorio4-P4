#ifndef DTHOSTAL
#define DTHOSTAL

#include <string>

using namespace std;

class DTHostal {
    private:
        string nombre;
        string direccion;
        string telefono;
    public:
        DTHostal();
        DTHostal(string,string,string);
        ~DTHostal();
        string getNombre();
        string getDireccion();
        string getTelefono();
};

#endif