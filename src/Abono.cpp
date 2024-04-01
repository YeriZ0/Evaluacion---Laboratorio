#include <iostream>
using namespace std;

#include "Abono.h"
#include "Fecha.h"

Abono::Abono(Fecha *fec, float mAb){
    this -> fecha = fec;
    this -> montoAbono = mAb;
}

Abono::~Abono(){
    //dtor
}

Fecha *Abono::getFechaAbono(){
    return this -> fecha;
}

float Abono::getMontoAbono(){
    return this -> montoAbono;
}
