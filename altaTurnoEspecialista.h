#ifndef ALTATU_ME_H_INCLUDED
#define ALTATU_ME_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"
#include"recuadro.h"
#include"validaciones.h"

void altasTurnoEspecialista(){
    int opcion;
    char titulo[40]= "MENU ALTAS TURNO Y ESPECIALISTA";
    recuadro(titulo);

    rlutil::locate(51, 5);
    cout<<"1. ALTA Turno."<<endl;
    rlutil::locate(51, 6);
    cout<<"2. ALTA Especialista."<<endl;
    rlutil::locate(51, 7);
    cout << "0. Volver." << endl;
    rlutil::locate(51, 8);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 9);
    cout << char(175) << " OPCION: ";
    cargarEntero(opcion);

    system("cls");

    switch(opcion){

    case 1: altaTurno();
            break;
    case 2: altaEspecialista();
            break;
    default:
            break;
    }
}

#endif // ALTATU_ME_H_INCLUDED
