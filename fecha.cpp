#include<iostream>
#include <limits>

using namespace std;
#include"rlutil.h"
#include"fecha.h"
#include "validaciones.h"

void Fecha::setDia(int d){
            if(0<d && d<=31){
                _dia=d;
            }
            else{_dia=0;}
}
void Fecha::setMes(int m){
            if(0<m && m<=12){_mes=m;}
            else{_mes=0;}
}
void Fecha::setAnio(int a){
        if(1900<a && a<= 2100){_anio=a;}
        else{_anio=0;}
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
    cargarEntero(dia);
    setDia(dia);
    cout<<"MES: ";
    cargarEntero(mes);
    setMes(mes);
    cout<<"ANIO: ";
    cargarEntero(anio);
    setAnio(anio);


    return true;
}


