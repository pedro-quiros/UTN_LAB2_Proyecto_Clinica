///Proyecto: Sistema clinica
///Autor: Hugo Orlando Benitez
///Grupo 7.
///Laboratorio de Computacion II -> UTN G.Pacheco.

#include <iostream>
#include<cstring>
//#include<windows.h>
#include <limits>

using namespace std;

#include"rlutil.h"
#include"altaTu_Me.h"
#include"subListas.h"
#include"subMenuBaja.h"
#include"subMenuModificar.h"
#include"consulta.h"
#include"subMenuReporte.h"
#include"recuadro.h"

int main(){

    rlutil::setColor(rlutil::YELLOW);
    rlutil::setBackgroundColor(rlutil::BLUE);

    char tit[40]="MENU CLINICA MARIA AUXILIADORA";

    int opc;
    while(true){
        system("cls");

        recuadro(tit);

        cout<<endl;
        rlutil::locate(51, 5);
        cout<<"1. ALTAS TURNO/ESP."<<endl;
        rlutil::locate(51,6);
        cout<<"2. BAJA LOGICA TURNO/ESP."<<endl;
        rlutil::locate(51,7);
        cout<<"3. MODIFICAR TURNO/ESP "<<endl;
        rlutil::locate(51,8);
        cout<<"4. LISTAS DE TURNOS/ESP."<<endl;
        rlutil::locate(51,9);
        cout<<"5. CONSULTAS.           "<<endl;
        rlutil::locate(51,10);
        cout<<"6. REPORTES.           "<<endl;
        rlutil::locate(51,11);
        cout<<"0. SALIR DEL PROGRAMA "<<endl;
        rlutil::locate(51, 12);
        cout<<"-------------------------------"<<endl;
        rlutil::locate(51, 13);
        cout<<"OPCION "<<endl;
        rlutil::locate(51, 14);
        cin>>opc;

        int sum=15;
        while(cin.fail()) {
             rlutil::locate(51, sum);
             cout << "Entrada no valida. Por favor, ingrese un numero entero: ";
             // Limpiar el buffer de entrada
             cin.clear();
             // Descartar el contenido no v�lido en el buffer
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Volver a intentar leer
            cin >> opc;
            sum++;
        }
        system("cls");

        switch(opc){

            case 1: altas();
                    break;
            case 2: bajasTuME();
                    break;
            case 3: modificarTuME();
                    break;
            case 4: subMenuLista();
                    break;
            case 5: consulta();
                    break;
            case 6: reporte();
                    break;

            case 0:
                    cout<<endl;
                    cout << "Saliendo del programa..." << endl;
                    cout<<endl;
                    return 0;
                    break;
            default:
                    cout<<endl;
                    cout << "Opcion no valida. Ociones validas 1,2,3,4,5,6 o 0-Salir." << endl;
                    cout<<endl;
        }
    system("pause");
    }

    return 0;
}