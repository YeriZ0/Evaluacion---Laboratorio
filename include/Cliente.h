#ifndef CLIENTE_H
#define CLIENTE_H

#include <string.h>

class Cliente
{
    public:
        Cliente(int, string, string);
        virtual ~Cliente();
        int getIdCliente();
        string getNombre();
        string getApellido();

    protected:

    private:
        int idCliente;
        string nombre;
        string apellido;
};

#endif // CLIENTE_H
