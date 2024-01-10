#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

 class Fecha{
    protected:
        int _dia,_mes,_anio;

    public:
        void setDia(int& valor);
        void setMes(int& valor);
        void setAnio(int& valor);

        int getDia();
        int getMes();
        int getAnio();

        bool cargarFecha();
};

#endif // FECHA_H_INCLUDED
