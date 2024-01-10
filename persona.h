#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include"fecha.h"

class Persona{
    protected:
        char _nombre[20];
        char _apellido[20];
        Fecha nacimiento;
        int _dni;

    public:
        const char *getNombre();
        const char *getApellido();
        Fecha getFecha();
        int getDni();

        void setNombre(const char*);
        void setApellido(const char*);
        void setFecha(Fecha);
        void setDni(int);

        bool cargarPersona();
};

#endif // PERSONA_H_INCLUDED
