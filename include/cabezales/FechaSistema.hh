#ifndef FECHASISTEMA
#define FECHASISTEMA

#include "./DTFecha.hh"

#include <string>

using namespace std;

class FechaSistema{
    private:
        DTFecha fecha;
        static FechaSistema * instancia;
        FechaSistema();
    public:
		static FechaSistema* getInstancia();
        DTFecha getFecha();
        void setFecha(DTFecha);
        void setFecha(int, int, int, int, int);
	    ~FechaSistema();
};


#endif