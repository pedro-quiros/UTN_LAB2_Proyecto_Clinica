#ifndef ALTATU_ME_H_INCLUDED
#define ALTATU_ME_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

#include"recuadro.h"

void altas(){

    int num;
    char titulo2[50]="    SUB-MENU ALTAS ";

    recuadro(titulo2);

    rlutil::locate(51, 5);
    cout<<"   1- ALTA turnos.            "<<endl;
    rlutil::locate(51, 6);
    cout<<"   2- ALTA Especilista        "<<endl;
    rlutil::locate(51, 7);
    cout<<"   0- Volver.                 "<<endl;
    rlutil::locate(52, 8);
    cin>>num;



    system("cls");

    switch(num){

    case 1: altaTurno();
            break;
    case 2: altaEspecialista();
            break;
    default:
            break;
    }

}



#endif // ALTATU_ME_H_INCLUDED
