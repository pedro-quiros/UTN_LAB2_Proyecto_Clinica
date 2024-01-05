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