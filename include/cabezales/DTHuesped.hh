#ifndef DTHUESPED
#define DTHUESPED

#include "./DTUsuario.hh"

class DTHuesped: public DTUsuario {
    private: 
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(string,string,string,bool);
        ~DTHuesped();
        int getEsFinger();
};

#endif