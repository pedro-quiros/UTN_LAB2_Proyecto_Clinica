#ifndef SUBMENUBAJA_H_INCLUDED
#define SUBMENUBAJA_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

#include"recuadro.h"

void bajasTuME(){

    int num;
    char titulo3[50]= "     SUB-MENU BAJAS";

    recuadro(titulo3);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"   1- BAJA turnos.            "<<endl;
    rlutil::locate(51, 6);
    cout<<"   2- BAJA Especialista.      "<<endl;
    rlutil::locate(51, 7);
    cout<<"   0- Volver.                 "<<endl;
    rlutil::locate(51, 8);
    cin>>num;



    system("cls");

    switch(num){

    case 1: bajaLogicaTurno();
            break;
    case 2: bajaLogicaEspecialista();
            break;
    default:
            break;
    }

}



#endif // SUBMENUBAJA_H_INCLUDED
