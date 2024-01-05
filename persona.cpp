#include<iostream>
#include<cstring>
#include <limits>

using namespace std;
#include"rlutil.h"
#include"persona.h"
#include"fecha.h"
#include"validaciones.h"


void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

const char* Persona::getNombre(){
    return _nombre;
}
const char* Persona::getApellido(){
    return _apellido;
}
Fecha Persona::getFecha(){
    return nacimiento;
}
int Persona::getDni(){
    return _dni;
}

void Persona::setNombre(const char *n){
    strcpy(_nombre,n);
}
void Persona::setApellido(const char *a){
    strcpy(_apellido,a);
}
void Persona::setFecha(Fecha f){
    nacimiento=f;
}
void Persona::setDni(int d){
      _dni=d;
}

bool Persona::cargarPersona(){
    cout<<endl;
    rlutil::locate(30, 3);
    cout<<"INGRESAR NOMBRE: ";
    cargarCadena(_nombre,19);
    rlutil::locate(30, 4);
    cout<<"INGRESAR APELLIDO: ";
    cargarCadena(_apellido,19);
    rlutil::locate(30, 5);
    cout<<"INGRESAR DNI: ";
    rlutil::locate(44, 5);
    cargarEntero(_dni);

    system("cls");

    rlutil::locate(50, 1);
    cout<<"CARGAR FECHA DE NACIMIENTO: "<<endl;

    if(!nacimiento.cargarFecha()){
        return false;
    }
    cout<<endl;
    return true;
}





