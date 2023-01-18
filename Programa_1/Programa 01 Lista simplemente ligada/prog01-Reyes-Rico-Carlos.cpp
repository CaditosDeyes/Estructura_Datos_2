#include <iostream>
#include <string>
#include "lista.h"
using namespace std;

void push(lista&);
void pop(lista& listaReferencia);
void deleteAll(lista& listaReferencia);
void showAll(lista& listaReferencia);
void writeToDisk(lista& listaReferencia);
void readFromDisk(lista& listaReferencia);

int main(){
    lista listaReferencia;
    char opcion;
    do{
        system("cls");
        cout << "\tLista Simplemente Ligada " <<endl << endl;
        cout << "1.- Agregar un dato a la lista" <<endl;
        cout << "2.- Eliminar un dato de la lista" <<endl;
        cout << "3.- Eliminar todos los datos de la lista" <<endl;
        cout << "4.- Mostrar Todos los datos de la lista" <<endl;
        cout << "5.- Cargar los datos" <<endl;
        cout << "6.- Guardar los datos" <<endl;
        cout << "7.- Cerrar del sistema" <<endl <<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case '1':
            push(listaReferencia);
            break;
        case '2':
            pop(listaReferencia);
            break;
        case '3':
            deleteAll(listaReferencia);
            break;
        case '4':
            showAll(listaReferencia);
            break;
        case '5':
            readFromDisk(listaReferencia);
            break;
        case '6':
            writeToDisk(listaReferencia);
            break;
        case '7':
            cout << endl << "Hasta luego.." <<endl;
            break;
        default:
            cout << "Opcion invalida, intente de nuevo" <<endl;
            system("pause");
        }
    }while(opcion != '7');

    return 0;
}
void push(lista& listaReferencia)
{
    string myStr;
    int myCode,mySem;
    Dato myData;
    system("cls");   
    cout << " ****Agregar un dato****" <<endl << endl;
    cout << "Ingresa el codigo del personaje: ";
    cin >> myCode;
    myData.setCodigo(myCode);
    cin.ignore();
    cout << "Ingresa el tipo del personaje: ";
    getline(cin, myStr, '\n');
    myData.setTipo(myStr);
    cout << "Ingresa la fuerza del personaje: ";
    cin >> mySem;
    myData.setFuerza(mySem);

    try {
        listaReferencia.push(listaReferencia.getLastPosition(),myData);
    }  catch (exception) {
        cout << "Ha ocurrido un problema al registrar el dato" << endl;
        return;
    }

    cout << endl << "****Dato ingresado correctamente!****" <<endl <<endl;
    system("pause");
}
void pop(lista& listaReferencia)
{
    int myCode;
    Dato myData;
    nodo* pos;
    system("cls");
    cout << "\t ****Eliminar Dato****" << endl << endl;
    cout << "Listado de Datos " << endl << endl;
    cout << "Codigo |Tipo|Fuerza" << endl << endl;
    listaReferencia.show();
    cout << "Ingresa el codigo del dato a eliminar: ";
    cin >> myCode;
    myData.setCodigo(myCode);
    pos=listaReferencia.find(myData);
    listaReferencia.pop(pos);
    cout <<endl;
    cout << "Dato eliminado correctamente!" <<endl << endl;
    system("pause");



}
void deleteAll(lista& listaReferencia)
{
    system("cls");
    cout << "Todas los datos han sido eliminados!"<<endl << endl;
    listaReferencia.popAll();
    system("pause");
}
void showAll(lista& listaReferencia)
{
    system("cls");
    cout << "\t\t**** Lista de datos****" << endl;
    cout << "Codigo |Tipo |Fuerza" << endl <<endl;
    listaReferencia.show();
    system("pause");
}

void writeToDisk(lista& listaReferencia){
    system("cls");
    cout << "Escribiendo informacion..." <<endl << endl;
    listaReferencia.writeToDisk();

   cout << "Escritura hecha correctamente!" << endl << endl;
   system("pause");
}
void readFromDisk(lista& listaReferencia){
    system("cls");
    cout << "****Leer informacion al disco****" <<endl << endl;
    listaReferencia.readFromDisk();
    cout << "La lectura finalizo exitosamente!" <<endl << endl;
    system("pause");
}