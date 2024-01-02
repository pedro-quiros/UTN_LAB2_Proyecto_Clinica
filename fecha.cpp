#include<iostream>
#include <limits>

using namespace std;
#include"rlutil.h"
#include"fecha.h"

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
        if(1920<a){_anio=a;}
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
    cout<<endl;
    int dia,mes,anio;

    rlutil::locate(30, 3);
    cout<<"INGRESAR DIA: ";
    rlutil::locate(45, 3);
    cin>>dia;

    int di=4;



     if(dia<=0 || dia>31){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    di++;
    rlutil::locate(30, di);
    cout<<"INGRESAR MES: ";
    rlutil::locate(45, di);
    cin>>mes;
    di++;



     if(mes<=0 || mes>12){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    di++;
    rlutil::locate(30, di);
    cout<<"INGRESAR ANIO: ";
    rlutil::locate(45, di);
    cin>>anio;
    di++;


     if(anio<=1930 || anio>2300){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    setDia(dia);
    setMes(mes);
    setAnio(anio);

    return true;
}


