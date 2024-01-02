#include<iostream>
#include <limits>

using namespace std;
#include"hora.h"
#include"rlutil.h"

void Hora::setHora(int h){
     if(8<=h && h<=22){
        _hora=h;
     }
     else{_hora=-1;}
}
void Hora::setMinuto(int m){
    if(0<=m && m<60){
        _minuto=m;
    }
    else{_minuto=-1;}
}

int Hora::getHora(){return _hora;}
int Hora::getMinuto(){return _minuto;}

bool Hora::cargarHora(){
    cout<<endl;
    int hora,minuto;

    rlutil::locate(30, 3);
    cout<<"INGRESAR HORA DEL TURNO: ";
    rlutil::locate(56, 3);
    cin>>hora;

    if(hora<8 || hora>22){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }
    int ho=4;
    rlutil::locate(30, ho);
    cout<<"INGRESAR MINUTOS: ";
    rlutil::locate(48, ho);
    cin>>minuto;
    ho++;

    

    if(minuto<0 || minuto>59){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    setHora(hora);
    setMinuto(minuto);
    return true;
}
