#ifndef CUENTA_H
#define CUENTA_H

#include "Abono.h"
#include "Cliente.h"

#define LISTA 5

class Cuenta
{
    public:
        Cuenta();
        Cuenta(int, Cliente*);
        virtual ~Cuenta();
        int getNumeroCuenta();
        void setNumeroCuenta(int);
        Cliente *getCliente();
        void setCliente(Cliente*);
        bool agregarAbono(Abono*);
        Abono **getlstAbonos();
        float getSaldo();
        int getContadorAbonos();

    protected:

    private:
        int numeroCuenta;
        Cliente *cliente;
        Abono *lstAbonos[LISTA];
        float saldo;
        int contadorAbono;
};

#endif // CUENTA_H
