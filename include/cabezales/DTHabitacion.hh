#ifndef DTHABITACION
#define DTHABITACION


class DTHabitacion {
    private:
        int numero,capacidad;
        float precio;
    public:
        int getNumero ();
	    float getPrecio ();
	    int getCapacidad ();
        DTHabitacion();
        DTHabitacion(int, float, int);
        ~DTHabitacion();
};

#endif