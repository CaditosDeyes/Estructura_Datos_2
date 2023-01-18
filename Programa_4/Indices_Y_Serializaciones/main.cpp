#include <iostream>
#include "data.h"
#include "hash.h"

using namespace std;

int main()
{
    Hash h;
    string op;

    while (true)
    {
        cout << endl;
        cout << "             .:Menu:.";
        cout << "\n1. Agregar Libro";
        cout << "\n2. Eliminar Libro";
        cout << "\n3. Buscar Libro";
        cout << "\n4. Mostrar Tabla (contenido)";
        cout << "\n5. Guardar Datos";
        cout << "\n6. Cargar Datos";
        cout << "\n0. Salir\n";
        cout << "R= ";
        getline(cin, op);

        if (op == "1")
        {
            data d;
            cin >> d;

            h.insertar(d.getLlave(),d);
            cout << "Libro insertado" << endl;
            cout << "--------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        else if (op == "2")
        {
            int llave;
            cout << "Inserte el codigo a eliminar (tambien se eliminara el contenido): ";
            cin >> llave;
            cin.ignore();

            h.eliminar(llave);
            cout << "--------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        else if (op == "3")
        {
            int llave;
            cout << "Ingrese el codigo del libro a buscar: ";
            cin >> llave;
            cin.ignore();

            h.buscar(llave);
            cout << "--------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        else if (op == "4")
        {
            cout << "Tabla: " << endl;
            h.mostrar_tabla();
            cout << "--------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        else if (op == "5")
        {
            h.Guardar();
            cout << "Datos Guardados" << endl;
            cout << "--------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        else if (op == "6")
        {
            h.Cargar();
            cout << "Datos Cargados" << endl;
            cout << "--------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        else if (op == "0")
        {
            break;
        }
    }
}
