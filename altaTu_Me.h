#ifndef ALTATU_ME_H_INCLUDED
#define ALTATU_ME_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

#include"recuadro.h"

void altas(){

    int opc;
    char titulo[50]= "SUB-MENU ALTAS ";

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
    cin >> opc;


    system("cls");

    switch(opc){

    case 1: altaTurno();
            break;
    case 2: altaEspecialista();
            break;
    default:
            break;
    }

}



#endif // ALTATU_ME_H_INCLUDED
