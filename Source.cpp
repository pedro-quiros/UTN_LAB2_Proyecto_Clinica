//Proyecto: Sistema Clinica
///Autor: Pedro Quiros
///Grupo 7
///Laboratorio de Computacion II -  UTN FRGP

#include <iostream>
#include<cstring>
#include <limits>
using namespace std;

#include"rlutil.h"
#include"altaTurnoEspecialista.h"
#include"subListas.h"
#include"subMenuBaja.h"
#include"subMenuModificar.h"
#include"consulta.h"
#include"subMenuReporte.h"
#include"recuadro.h"
#include "validaciones.h"

#include <chrono>
#include <ctime>

int main() {
    rlutil::setColor(rlutil::YELLOW);
    rlutil::setBackgroundColor(rlutil::BLUE);

    char titulo[40] = "MENU CLINICA UTN";
    int opc;
    while (true) {
        system("cls");
        recuadro(titulo);

        // Obtener el tiempo actual
        auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
        // Mostrar hora con minutos en el formato dd/mm/yyyy HH:MM
        rlutil::locate(85, 4);
        cout << put_time(localtime(&now), "%d/%m/%Y - %H:%Mhs") << endl;

        rlutil::locate(51, 5);
        cout << "1. ALTAS TURNO/ESP." << endl;
        rlutil::locate(51, 6);
        cout << "2. BAJA LOGICA TURNO/ESP." << endl;
        rlutil::locate(51, 7);
        cout << "3. MODIFICAR TURNO/ESP." << endl;
        rlutil::locate(51, 8);
        cout << "4. LISTAS DE TURNOS/ESP." << endl;
        rlutil::locate(51, 9);
        cout << "5. CONSULTAS." << endl;
        rlutil::locate(51, 10);
        cout << "6. REPORTES." << endl;
        rlutil::locate(51, 11);
        cout << "0. SALIR DEL PROGRAMA." << endl;
        rlutil::locate(51, 12);
        cout << "-------------------------------" << endl;
        rlutil::locate(51, 13);
        cout << char(175)<<" OPCION: ";
        cargarEntero(opc);

        system("cls");

        switch (opc) {

        case 1: altasTurnoEspecialista();
            break;
        case 2: bajasTurnoEspecialista();
            break;
        case 3: modificarTurnoEspecialista();
            break;
        case 4: subMenuLista();
            break;
        case 5: consulta();
            break;
        case 6: reporte();
            break;

        case 0:
            cout << "[X] Saliendo del programa. Muchas gracias." << endl;
            return 0;
            break;
        default:
            cout << "[X] Opcion no valida. Intente nuevamente." << endl;
            cout << endl;
        }
        system("pause");
    }
    return 0;
}
