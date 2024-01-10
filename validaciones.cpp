#include "validacion.h"
#include <limits>
#include <iostream>
#include <iomanip>
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



void imprimirEncabezadoPaciente() {
    const int anchoColumna = 20;
    cout << left << setw(anchoColumna) << "NOMBRE"
        << setw(anchoColumna) << "APELLIDO"
        << setw(anchoColumna) << "DNI"
        << setw(anchoColumna) << "ESPECIALISTA"
        << setw(15) << "MATRICULA"
        << setw(anchoColumna) << "TURNO"
        << setw(anchoColumna) << "HORA"
        << "\n";
}