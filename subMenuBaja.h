#ifndef SUBMENUBAJA_H_INCLUDED
#define SUBMENUBAJA_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

#include"recuadro.h"

void bajasTurnoEspecialista(){

    int opcion;
    char titulo[40]= "MENU BAJAS TURNO Y ESPECIALISTA";

    recuadro(titulo);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"1. BAJA Turno."<<endl;
    rlutil::locate(51, 6);
    cout<<"2. BAJA Especialista."<<endl;
    rlutil::locate(51, 7);
    cout<<"0. Volver."<<endl;
    rlutil::locate(51, 8);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 9);
    cout << char(175) << " OPCION: ";
    cargarEntero(opcion);

    system("cls");

    switch(opcion){

    case 1: bajaLogicaTurno();
            break;
    case 2: bajaLogicaEspecialista();
            break;
    default:
            break;
    }

}



#endif // SUBMENUBAJA_H_INCLUDED
