#include<iostream>
#include <limits>
using namespace std;
#include"hora.h"
#include"rlutil.h"
#include "validaciones.h"

void Hora::setHora(int& valor) {
	cargarEntero(valor);

	while (valor < 8 || valor > 22) {
        cout << "[X] Entrada no valida. Ingrese un numero entre 8 y 22: ";
		cargarEntero(valor);
	}
    _hora = valor;
}

void Hora::setMinuto(int& valor) {
    cargarEntero(valor);

    while (valor < 0 || valor > 60) {
        cout << "[X] Entrada no valida. Ingrese un numero entre 0 y 60: ";
        cargarEntero(valor);
    }
    _minuto = valor;
}

int Hora::getHora(){return _hora;}
int Hora::getMinuto(){return _minuto;}

bool Hora::cargarHora(){
    int hora,minuto;
    cout<<"INGRESAR HORA DEL TURNO: ";
    setHora(hora);
    cout<<"INGRESAR MINUTOS: ";
    setMinuto(minuto);
    return true;
}
