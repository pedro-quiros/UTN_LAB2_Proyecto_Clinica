#ifndef SUBLISTAS_H_INCLUDED
#define SUBLISTAS_H_INCLUDED

#include"listadosControladores.h"
#include"listadosControlaTurno2.h"

#include"recuadro.h"

void subMenuLista(){

    int num;
    char titulo5[50]= "     SUB-MENU LISTAS";

    recuadro(titulo5);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"   1- Mostrar todos.          "<<endl;
    rlutil::locate(51, 6);
    cout<<"   2- Lista por Apellidos.    "<<endl;
    rlutil::locate(51, 7);
    cout<<"   3- Lista por DNI.          "<<endl;
    rlutil::locate(51, 8);
    cout<<"   4- Lista Menores Edad.     "<<endl;
    rlutil::locate(51, 9);
    cout<<"   5- Lista de Medico.        "<<endl;
    rlutil::locate(51, 10);
    cout<<"   0- Volver.                 "<<endl;
    rlutil::locate(51, 11);
    cin>>num;


    system("cls");

    switch(num){

    case 1: mostrarTodosPacientes();
            break;
    case 2: listaPorApellido();
            break;
    case 3: listarPorDni();
            break;
    case 4: listarMenores();
            break;
    case 5: listaDeMedico();
            break;
    default:
            break;
    }
}

#endif // SUBLISTAS_H_INCLUDED
