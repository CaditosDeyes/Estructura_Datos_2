#include <iostream>
#include "grafo.h"
#include<windows.h>
using namespace std;

int main()
{
    int opc;
    string nombre;
    string origen,destino;
    int peso;
    grafo G;
    G.inicializa();

    G.insertVertice("Guadalajara");
    G.insertVertice("Puebla");
    G.insertVertice("DF");
    G.insertVertice("Zacatecas");
    G.insertVertice("Michoacan");
    G.insertVertice("Los Cabos");

    G.insertArista("Guadalajara","DF",300);
    G.insertArista("Guadalajara", "Zacatecas", 200);
    G.insertArista("Guadalajara","Los Cabos", 400);
    G.insertArista("Puebla","Michoacan", 100);
    G.insertArista("Puebla", "DF", 300);
    G.insertArista("DF","Los Cabos", 200);
    G.insertArista("Zacatecas","Puebla", 300);
    G.insertArista("Zacatecas","Los Cabos", 200);
    G.insertArista("Michoacan", "Guadalajara", 400);
    G.insertArista("Michoacan", "DF", 300);
    G.insertArista("Los Cabos", "Michoacan", 300);

    do{
            system("cls");
        cout<<"\t.:MENU:.\n";
        cout<<"1. Ingresar Vertice\n2. Ingresar Arista\n3. Lista de Adyacencia\n";
        cout<<"4. Tamano\n5. Eliminar Vertice\n6. Eliminar Arista\n7. Anular\n";
        cout<<"8. Guardar\n9. Cargar\n0. Salir\n\tR= ";
        cin>>opc;
        switch(opc)
        {

            case 1:
                cout<<"Ingresa nombre del vertice: ";
                cin>>nombre;
                G.insertVertice(nombre);
                system("pause");
                break;
            case 2:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    cout<<"\nIngrese nombre del vertice origen: ";
                    cin>>origen;
                    cout<<"\nIngrese nombre del vertice destino: ";
                    cin>>destino;
                    cout<<"Ingrese el peso: ";
                    cin>>peso;
                    if(G.getVertice(origen)==nullptr || G.getVertice(destino)==nullptr)
                    {
                        cout<<"\nUno de los vertices no es valido\n";
                        system("pause");
                    }
                    else
                    {
                        G.insertArista(origen,destino,peso);
                    }
                }
                cout<<endl;
                system("pause");
                break;
            case 3:
                {
                    if(G.vacio())
                    {
                        cout<<"\nEl grafo esta vacio\n";
                        system("pause");
                    }
                    else
                    {
                        cout<<endl;
                        G.listaAdyacencia();
                        system("pause");
                    }
                }
                break;
            case 4:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    cout<<"\nTamano: "<<G.tamano()<<endl;
                    system("pause");
                }
                break;
            case 5:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    cout<<"Ingrese el vertice a eliminar: ";
                    cin>>nombre;
                    if(G.getVertice(nombre)==nullptr)
                    {
                        cout<<"\nVertice Invalido\n";
                        system("pause");
                    }
                    else
                    {
                        G.eliminarVertice(nombre);
                    }
                }
                system("pause");
                break;
            case 6:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    cout<<"\nIngrese vertice origen: ";
                    cin>>origen;
                    cout<<"\nIngrese vertice destino: ";
                    cin>>destino;
                    if(G.getVertice(origen)==nullptr || G.getVertice(destino)==nullptr)
                    {
                        cout<<"\nUno de los vertices no es valido\n";
                        system("pause");
                    }
                    else
                    {
                        G.eliminarArista(G.getVertice(origen), G.getVertice(destino));
                    }
                }
                system("pause");
                break;
            case 7:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    G.anular();
                    cout<<"\nAnulando datos...\n";
                    Sleep(300);
                    cout<<"Datos Anulados\n";
                    system("pause");

                }
                break;
            case 8:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    G.guarVer();
                    cout<<"\Guardando datos...\n";
                    Sleep(300);
                    cout<<"Datos Guardados\n";
                    system("pause");
                }
                break;
            case 9:
                if(G.vacio())
                {
                    cout<<"\nEl grafo esta vacio\n";
                    system("pause");
                }
                else
                {
                    G.cargVer();
                    cout<<"\Cargando datos...\n";
                    Sleep(300);
                    cout<<"Datos Cargados\n";
                    system("pause");
                }
                break;
            case 0:
                break;
        }
    }while(opc!=0);
    cout<<"Cerrando programa...\n";
    return 0;
}
