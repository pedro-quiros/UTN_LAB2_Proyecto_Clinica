#ifndef LISTADOSCONTROLADORES_H_INCLUDED
#define LISTADOSCONTROLADORES_H_INCLUDED

#include"archivoClassPacientess.h"
#include"paciente.h"

//funciones prototipos
void cargarCadenaPa(char *palabra, int tam);
void listaPorApellido();
void listarPorDni();
void listarMenores();

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
    cout<<"Ingresar el apellido a buscar: ";
    cargarCadenaPa(ape,19);
    cout<<endl;

    system("cls");

    const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(anchoColumna) << "DNI"
              << setw(anchoColumna) << "ESPECIALISTA"
              << setw(15) << "MATRICULA"
              << setw(anchoColumna) << "TURNO"
              << setw(anchoColumna) << "HORA"
              << "\n";

    bool banderaListaApellido=true;

    for(int i=0;i<contPa;i++){
       pa= archiPa.leerRegistro(i);

        if(pa.getEstado() && strcmp(pa.getApellido(),ape)==0){
            pa.mostrarPaciente();

            banderaListaApellido=false;
        }
    }
    if(banderaListaApellido){
        cout<<endl;

        system("cls");
        cout<<"NO EXISTE APELLIDO..."<<endl;
    }
    cout<<endl;
}

void listarPorDni(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int num;
    cout<<"Ingresar el DNI a buscar: ";
    cin>>num;
    cout<<endl;

    system("cls");

    const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(anchoColumna) << "DNI"
              << setw(anchoColumna) << "ESPECIALISTA"
              << setw(15) << "MATRICULA"
              << setw(anchoColumna) << "TURNO"
              << setw(anchoColumna) << "HORA"
              << "\n";

    bool banderaListaDni=true;

    for(int i=0;i<contPa;i++){
         pa= archiPa.leerRegistro(i);

        if(pa.getEstado() && pa.getDni()==num){
            pa.mostrarPaciente();

            banderaListaDni=false;
        }
    }
    if(banderaListaDni){
        cout<<endl;

        system("cls");
        cout<<"NO EXISTE DNI..."<<endl;
    }
    cout<<endl;
}

void listarMenores(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int num;
    cout<<"Ingresar anio actual: ";
    cin>>num;
    cout<<endl;

    system("cls");

    const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(anchoColumna) << "DNI"
              << setw(anchoColumna) << "ESPECIALISTA"
              << setw(15) << "MATRICULA"
              << setw(anchoColumna) << "TURNO"
              << setw(anchoColumna) << "HORA"
              << "\n";

    bool banderaMenores=true;

    for(int i=0;i<contPa;i++){
         pa= archiPa.leerRegistro(i);

        if(pa.getEstado() && (num - pa.getFecha().getAnio())<18){
            pa.mostrarPaciente();

            banderaMenores=false;
        }
    }
    if(banderaMenores){
        cout<<endl;

        system("cls");
        cout<<"NO EXISTE DNI..."<<endl;
    }
    cout<<endl;
}

#endif // LISTADOSCONTROLADORES_H_INCLUDED
