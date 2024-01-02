#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED


class Hora{
    private:
        int _hora,_minuto;

    public:
        void setHora(int h);
        void setMinuto(int m);

        int getHora();
        int getMinuto();

        bool cargarHora();
};



#endif // HORA_H_INCLUDED
