#include<iostream>
#include <limits>

using namespace std;
#include"rlutil.h"
#include"fecha.h"
#include "validaciones.h"

void Fecha::setDia(int& valor){
    cargarEntero(valor);

    while (valor < 1 || valor > 31) {
        cout << "[X] Entrada no valida. Ingrese un numero entre 1 y 31: ";
        cargarEntero(valor);
    }
    _dia=valor;
}
void Fecha::setMes(int& valor) {
    cargarEntero(valor);

    while (valor < 1 || valor > 12) {
        cout << "[X] Entrada no valida. Ingrese un numero entre 1 y 12: ";
        cargarEntero(valor);
    }
    _mes = valor;
}
void Fecha::setAnio(int& valor) {
    cargarEntero(valor);

    while (valor < 1900 || valor > 2100) {
        cout << "[X] Entrada no valida. Ingrese un numero entre 1900 y 2100: ";
        cargarEntero(valor);
    }
    _anio = valor;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

bool Fecha::cargarFecha(){
    int dia,mes,anio;

    cout << endl;
    cout<<"DIA: ";
    setDia(dia);
    cout<<"MES: ";
    setMes(mes);
    cout<<"ANIO: ";
    setAnio(anio);

    return true;
}


