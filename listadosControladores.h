#ifndef LISTADOSCONTROLADORES_H_INCLUDED
#define LISTADOSCONTROLADORES_H_INCLUDED

#include"archivoClassPacientess.h"
#include"paciente.h"
#include "validacion.h"
//funciones prototipos
void cargarCadenaPa(char *palabra, int tam);
void listaPorApellido();
void listarPorDni();
void listarMenores();

//funciones
void cargarCadenaPa(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void listaPorApellido(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    char ape[20];
    cout<<"Ingresar el Apellido de paciente a buscar: ";
    cargarCadenaPa(ape,19);
    system("cls");
    imprimirEncabezadoPaciente();
    bool banderaListaApellido=true;

    for(int i=0;i<contPa;i++){
       pa= archiPa.leerRegistro(i);

        if(pa.getEstado() && strcmp(pa.getApellido(),ape)==0){
            pa.mostrarPaciente();
            banderaListaApellido=false;
        }
    }
    if(banderaListaApellido){
        system("cls");
        cout << "[X] Error Apellido, No se encontraron registros.";
        cout << endl;
    }
    cout<<endl;
}

void listarPorDni(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int num;
    cout<<"Ingresar el DNI a buscar: ";
    cargarEntero(num);

    system("cls");
    imprimirEncabezadoPaciente();
    bool banderaListaDni=true;

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);

        if(pa.getEstado() && pa.getDni()==num){
            pa.mostrarPaciente();
            banderaListaDni=false;
        }
    }
    if(banderaListaDni){
        system("cls");
        cout << "[X] Error DNI, No se encontraron registros.";
        cout << endl;
    }
    cout<<endl;
}

void listarMenores(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int num;
    cout<<"Ingresar anio actual: ";
    cargarEntero(num);

    system("cls");
    imprimirEncabezadoPaciente();
    bool banderaMenores=true;

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);

        if(pa.getEstado() && (num - pa.getFecha().getAnio())<18){
            pa.mostrarPaciente();
            banderaMenores=false;
        }
    }
    if(banderaMenores){
        system("cls");
        cout << "[X] Error DNI, No se encontraron registros.";
        cout<<endl;
    }
    cout<<endl;
}

#endif // LISTADOSCONTROLADORES_H_INCLUDED
