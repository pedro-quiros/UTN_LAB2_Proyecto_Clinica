#ifndef SUBMENUMODIFICAR_H_INCLUDED
#define SUBMENUMODIFICAR_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"

#include"recuadro.h"

void modificarTuME(){

    int num;
    char titulo4[50]= "     SUB-MENU MODIFICAR";

    recuadro(titulo4);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"   1- MODIFICAR turnos.            "<<endl;
    rlutil::locate(51, 6);
    cout<<"   2- MODIFICAR Especilista.       "<<endl;
    rlutil::locate(51, 7);
    cout<<"   0- Volver.                      "<<endl;
    rlutil::locate(51, 8);
    cin>>num;

     

    system("cls");

    switch(num){

    case 1: modificarTurno();
            break;
    case 2: modificarEspecialista();
            break;
    default:
            break;
    }

}



#endif // SUBMENUMODIFICAR_H_INCLUDED
