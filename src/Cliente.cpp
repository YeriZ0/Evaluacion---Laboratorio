#include <iostream>
using namespace std;

#include "Cliente.h"

Cliente::Cliente(int id, string nom, string ape){
    this -> idCliente = id;
    this -> nombre = nom;
    this -> apellido = ape;
}

Cliente::~Cliente(){
    //dtor
}

int Cliente::getIdCliente(){
    return this -> idCliente;
}

string Cliente::getNombre(){
    return this -> nombre;
}

string Cliente::getApellido(){
    return this -> apellido;
}
