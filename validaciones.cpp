#include "validacion.h"
#include <limits>
#include <iostream>
using namespace std;
#undef max

void cargarEntero(int& valor) {
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "[X] Entrada no valida. Por favor, ingrese un numero entero: ";
    }
    cin.ignore();
}


void cargarDia(int& valor) {
    cargarEntero(valor);

    while (valor < 1 || valor > 31) {
        cout << "[X] El dia ingresado está fuera del rango. Ingrese un numero entre 1 y 31: ";
        cargarEntero(valor);
    }
}

void cargarMes(int& valor) {
	cargarEntero(valor);

    while (valor < 1 || valor > 12) {
		cout << "[X] El mes ingresado esta fuera del rango. Ingrese un numero entre 1 y 12: ";
		cargarEntero(valor);
	}
}

void cargarAnio(int& valor) {
	cargarEntero(valor);

    while (valor < 1900 || valor > 2100) {
		cout << "[X] El anio ingresado esta fuera del rango. Ingrese un numero entre 1900 y 2100: ";
		cargarEntero(valor);
	}
}