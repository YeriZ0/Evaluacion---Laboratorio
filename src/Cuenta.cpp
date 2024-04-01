#include <iostream>
using namespace std;

#include "Cuenta.h"
#include "Cliente.h"
#include "Abono.h"

#define LISTA 5

Cuenta::Cuenta(int nC, Cliente *cli){
    this -> numeroCuenta = nC;
    this -> cliente = cli;
    this -> saldo = 0.0;
    this -> contadorAbono = 0;
}

Cuenta::~Cuenta(){
    //dtor
}

int Cuenta::getNumeroCuenta(){
    return this -> numeroCuenta;
}

void Cuenta::setNumeroCuenta(int num){
    this -> numeroCuenta = num;
}

Cliente *Cuenta::getCliente(){
    return this -> cliente;
}

void Cuenta::setCliente(Cliente *cli){
    this -> cliente = cli;
}

bool Cuenta::agregarAbono(Abono *abo){
    bool resultado = false;
    if(this -> contadorAbono < LISTA){
        this -> lstAbonos[this -> contadorAbono] = abo;
        this -> saldo += abo -> getMontoAbono();
        this -> contadorAbono++;
        resultado = true;
    }else{
        cout << "Se alcanzo el limite de abonos." << endl;
    }
    return resultado;
}

Abono **Cuenta::getlstAbonos(){
    return this -> lstAbonos;
}

float Cuenta::getSaldo(){
    return this -> saldo;
}

int Cuenta::getContadorAbonos(){
    return this -> contadorAbono;
}
