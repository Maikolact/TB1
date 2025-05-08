#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Usuario.h"
using namespace std;

void Menu() {
    cout << "|===============================================|" << endl;
    cout << "|------SISTEMA DE GESTION DE BIBLIOTECAS--------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|    1.REGISTRAR USUARIO                        |" << endl;
    cout << "|    2.INGRESAR SECCION COMO LECTOR             |" << endl;
    cout << "|    3.INGRESAR SECCION COMO ADMINISTRADOR      |" << endl;
    cout << "|    4.SALIR                                    |" << endl;
    cout << "|===============================================|" << endl;
    cout << "Ingrese una opcion: ";
}

int main() {
    char opcion;
    string tipo;

    do {
        system("cls");
        Menu();
        cin >> opcion;
        cin.ignore();

        string nombre, contrasenia;
        Usuario* usuario = nullptr;

        switch (opcion) {
        case '1':
            cout << "Tipo de cuenta a registrar (Lector / Administrador): ";
            cin >> tipo;
            cout << "Ingrese nombre del " << tipo << ": ";
            cin >> nombre;
            cout << "Ingrese contrasenia: ";
            cin >> contrasenia;
            usuario = new Usuario(nombre, contrasenia);

            if (usuario->ComprobarUsuario(tipo)) {
                cout << "El " << tipo << " ya esta registrado." << endl;
            }
            else {
                usuario->AgregarUsuario(tipo);
            }
            break;

        case '2':
            tipo = "Lector";
            cout << "Ingrese nombre de Lector: ";
            getline(cin, nombre);
            cout << "Ingrese contrasenia: ";
            getline(cin, contrasenia);
            usuario = new Usuario(nombre, contrasenia);

            if (usuario->IniciarSesion(tipo)) {
                cout << "Bienvenido, " << nombre << "." << endl;
            }
            else {
                cout << "Nombre o contrasenia incorrectos." << endl;
            }
            break;

        case '3':
            tipo = "Administrador";
            cout << "Ingrese nombre de administrador: ";
            getline(cin, nombre);
            cout << "Ingrese contrasenia: ";
            getline(cin, contrasenia);
            usuario = new Usuario(nombre, contrasenia);

            if (usuario->IniciarSesion(tipo)) {
                cout << "Bienvenido, " << nombre << "." << endl;
            }
            else {
                cout << "Nombre o contraseña incorrectos." << endl;
            }
            break;

        case '4':
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion equivocada. Intente nuevamente...." << endl;
            break;
        }

        delete usuario;
        cout << "\nPresione cualquier tecla para continuar...";
        _getch();

    } while (opcion != '4');

    _getch();
    return 0;
}
