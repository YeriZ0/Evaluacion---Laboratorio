#include <iostream>
#include <stdlib.h>

using namespace std;

#include "Cuenta.h"
#include "Abono.h"
#include "Cliente.h"
#include "Fecha.h"

#define TAM 5

#include <string>

//FREDY ALEXANDER CAMPOS FIGUEROA - PROGRAMACION II

int menu(){
    int op = 0;
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Agregar cliente a la lista" << endl;
    cout << "2. Crear cuenta al cliente" << endl;
    cout << "3. Hacer abonos" << endl;
    cout << "4. Mostrar lista de clientes"  << endl;
    cout << "5. Mostrar lista de cuentas" << endl;
    cout << "6. Mostrar detalles de la cuenta" << endl;
    cout << "7. Salir\n";
    cin >> op;
    return op;
}

Cliente *agregarCliente(){
    Cliente *cli;
    int idC = 0;
    string n, a;
    cout << "Escriba el ID de Cliente: "; cin >> idC;
    cout << "Escriba el Nombre del Cliente: "; cin >> n;
    cout << "Escriba el Apellido del Cliente: "; cin >> a;
    cli = new Cliente(idC, n, a);
    return cli;
}

Cliente *buscarCliente(Cliente *lst[], int id, int cont){
    bool encontrado = false;
    int contador = 0;
    Cliente *cli = NULL;
    while (contador < cont && !encontrado){
        if (lst[contador] -> getIdCliente() == id){
            encontrado = true;
            cli = lst[contador];
        }else{
            contador++;
        }
    }
    return cli;
}

Cuenta *agregarCuenta(Cliente *cli){
    int nc = 0;
    Cuenta *cta = NULL;
    cout << "Digite el numero de cuenta : "; cin >> nc;
    cta = new Cuenta(nc, cli);
    return cta;
}

Cuenta *buscarCuenta(Cuenta *lst[], int id, int cont){
    Cuenta *cuenta = NULL;
    bool resultado = false;
    int contadorCuenta = 0;
    while(contadorCuenta < cont && !resultado){
        if(lst[contadorCuenta] -> getNumeroCuenta() == id){
            cuenta = lst[contadorCuenta];
            resultado = true;
        }
        contadorCuenta++;
    }
    return cuenta;
}

void hacerAbono(Cuenta *cta){
    int d, m, a;
    Fecha *fa;
    float ma;
    Abono *ab;
    cout << "Digite la fecha del abono (dd/mm/aa) : " << endl;
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "Digite el monto del abono : "; cin >> ma;
    fa = new Fecha(d, m, a);
    ab = new Abono(fa, ma);
    //ab -> getFechaAbono() -> mostrarFecha();
    cta -> agregarAbono(ab);
}

void verDetalles(Cuenta *cta){
    cout << "\nNumero de cuenta : " << cta -> getNumeroCuenta() << endl;
    cout << "Cliente : " << cta -> getCliente() -> getNombre() << " " << cta -> getCliente() -> getApellido() << endl;
    cout << "Saldo : " << cta -> getSaldo() << endl;
    if (cta -> getContadorAbonos() == 0){
        cout << "No hay abonos." << endl;
    }else{
        cout << "No\t     Fecha     \t Monto" << endl;
        Abono **lst = cta -> getlstAbonos();
        for (int i = 0; i < cta -> getContadorAbonos(); i++){
            cout << (i+1) << "\t";
            lst[i] -> getFechaAbono() -> mostrarFecha();
            cout << "\t" << lst[i] -> getMontoAbono() << endl;
        }
    }
}

int main(){
    int op = 0;
    Cliente *lstCliente[TAM];
    Cliente *cliente;
    Cuenta *lstCuenta[TAM];
    Cuenta *cuenta;
    Abono *lstAbono[TAM];
    Abono *abono;
    int contClientes=0, contCuentas=0, idCliente=0, contAbono=0, idCuenta=0;
    do{
        system("cls");
        op = menu();
        switch(op){
            case 1:
                //Agregar Cliente
                if(contClientes < TAM){
                    lstCliente[contClientes] = agregarCliente();
                    contClientes++;
                    cout << "Cliente agregado exitosamente" << endl;
                }else{
                    cout << "La lista de clientes esta llena." << endl;
                }
                break;
            case 2:
                //Agregar Cuenta
                if(contCuentas < TAM){
                    cout << "Ingrese ID de Cliente\n";
                    cin >> idCliente;
                    if(contClientes == 0){
                        cout << "La lista de clientes esta vacia, no hay cuentas."  << endl;
                    }else{
                        cliente=buscarCliente(lstCliente, idCliente, contClientes);
                        if(cliente){
                            lstCuenta[contCuentas]= agregarCuenta(cliente);
                            cout << "Cuenta agregada con exito\n";
                            contCuentas++;
                        }else{
                            cout << "El cliente no se encontro\n";
                        }
                    }
                }else{
                    cout << "La lista esta llena." << endl;
                }
                break;
            case 3:
                //Hacer Abono
                if(contCuentas == 0){
                    cout << "No existen cuentas." << endl;
                }else{
                    cout << "Ingrese el numero de cuenta que desea abonar: "; cin >> idCuenta;
                    cuenta = buscarCuenta(lstCuenta, idCuenta, contCuentas);
                    if(cuenta){
                        hacerAbono(cuenta);
                        cout << "El abono se agrego con exito."  << endl;
                        contAbono++;
                    }else if (!cuenta){
                        cout << "No se encontro la cuenta." << endl;
                    }else{
                        cout << "La lista esta llena no se pueden agregar mas cuentas. " << endl;
                    }
                }
                break;
            case 4:
                //Mostrar clientes
                if(contClientes == 0){
                    cout << "No existen clientes registrados, lista vacia. " << endl;
                }else{
                    cout << "Id\tNombre\tApellido\n";
                    for(int i=0; i<contClientes; i++){
                    cout << lstCliente[i] -> getIdCliente() << "\t";
                    cout << lstCliente[i] -> getNombre() << "\t";
                    cout << lstCliente[i] -> getApellido() << "\n";
                    }
                }
                break;
            case 5:
                //Mostras cuentas
                if(contCuentas==0){
                    cout << "Todavia no se ha creado una cuenta." << endl;
                }else{
                    cout << "No\tNombre\tApellido    \tsaldo" << endl;
                    for(int i=0;i<contCuentas;i++){
                        cout << lstCuenta[i] -> getNumeroCuenta() << "\t";
                        cout << lstCuenta[i] -> getCliente() -> getNombre() << "\t";
                        cout << lstCuenta[i] -> getCliente() -> getApellido() << "\t";
                        cout << lstCuenta[i] -> getSaldo() << endl;
                    }
                }
                break;
            case 6:
                //Mostrar detalles de cuentas
                cout << "Digite el numero de cuenta: "; cin >> idCuenta;
                cuenta = buscarCuenta(lstCuenta, idCuenta, contCuentas);
                if(cuenta){
                    verDetalles(cuenta);
                    cout << endl;
                }else{
                    cout << "La cuenta no se encontro. ";
                }
                break;
            case 7:
                //Salir del sistema
                cout << "Saliendo del sistema\n";
                break;
            default:
                cout << "Opcion no valida ingrese un numero dentro del rango de opciones habilitadas\n";
                break;
        }
        system("pause");
    }while(op!=7);
    return 0;
}
