#include <iostream>
using namespace std;

#include "Fecha.h"

Fecha::Fecha(int d, int m, int a){
    this -> dia = d;
    this -> mes = m;
    this -> anio = a;
}

Fecha::~Fecha(){
    //dtor
}

void Fecha::mostrarFecha(){
    cout << this -> dia << " / " << this -> mes << " / " << this -> anio;
}
