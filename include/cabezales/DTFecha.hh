#ifndef DTFECHA
#define DTFECHA

class DTFecha {
    private:
        int dia,mes,anio,hora,minuto;
    public:
        DTFecha();
        DTFecha(int,int,int,int,int);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
};

#endif
