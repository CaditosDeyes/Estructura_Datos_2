#include "abb.h"
#include<iostream>
using namespace std;

abb::abb()
{
    //ctor
}

void abb::Inicializa()
{
    h=nullptr;
}

nodo *abb::crearNodo(int n,nodo *padre)
{
    nodo *nuevo= new nodo();
    nuevo->dato=n;
    nuevo->der=nullptr;
    nuevo->izq=nullptr;
    nuevo->padre=padre;
    return nuevo;
}

void abb::insertar(nodo *&arbol,int n,nodo *padre)
{
    if(arbol==nullptr)
    {
        nodo *nuevo=crearNodo(n,padre);
        arbol=nuevo;
    }
    else
    {
        int raiz=arbol->dato;
        if(n<raiz)
        {
            insertar(arbol->izq,n,arbol);
        }
        else
        {
            insertar(arbol->der,n,arbol);
        }
    }
}

void abb::mostrar(nodo *arbol,int cont)
{
    if(arbol==nullptr)
    {
        return;
    }
    else
    {
        mostrar(arbol->der,cont+1);
        for(int i=0; i<cont; i++)
        {
            cout<<"  ";
        }
        cout<<arbol->dato<<endl;
        mostrar(arbol->izq,cont+1);
    }
}

void abb::inOrden(nodo *arbol)
{
    if(arbol==nullptr)
    {
        return;
    }
    else
    {
        inOrden(arbol->izq);
        cout<<arbol->dato<<"-";
        inOrden(arbol->der);
    }
}

void abb::preoden(nodo *arbol)
{
    if(arbol==nullptr)
    {
        return;
    }
    else
    {
        cout<<arbol->dato<<"-";
        inOrden(arbol->izq);
        inOrden(arbol->der);
    }
}

void abb::eliminar(nodo *arbol,int n)
{
    if(arbol==nullptr)
    {
        return;
    }
    else if(n<arbol->dato)
    {
        eliminar(arbol->izq,n);
    }
    else if(n>arbol->dato)
    {
        eliminar(arbol->der,n);
    }
    else
    {
        eliminarNodo(arbol);
    }
}

void abb::destruir(nodo *nodo)
{
    nodo->izq = nullptr;
    nodo->der = nullptr;

    delete nodo;
}

void abb::eliminarNodo(nodo *nodoEliminar)
{
    if(nodoEliminar->izq && nodoEliminar->der)
    {
        nodo *menor=minimo(nodoEliminar->der);
        nodoEliminar->dato=menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq)
    {
        remplazar(nodoEliminar,nodoEliminar->izq);
        destruir(nodoEliminar);
    }
    else if(nodoEliminar->der)
    {
        remplazar(nodoEliminar,nodoEliminar->der);
        destruir(nodoEliminar);
    }
    else
    {
        remplazar(nodoEliminar,nullptr);
        destruir(nodoEliminar);
    }
}

nodo *abb::minimo(nodo *arbol)
{
    if(arbol==nullptr)
    {
        return nullptr;
    }
    if(arbol->izq)
    {
        return minimo(arbol->izq);
    }
    else
    {
        return arbol;
    }
}

void abb::remplazar(nodo *arbol, nodo *nuevoNodo)
{
    if(arbol->padre)
    {
        if(arbol->dato == arbol->padre->izq->dato)
        {
            arbol->padre->izq = nuevoNodo;
        }
        else if(arbol->dato == arbol->padre->der->dato)
        {
            arbol->padre->der = nuevoNodo;
        }
    }
    if(nuevoNodo)
    {
        nuevoNodo->padre = arbol->padre;
    }
}

void abb::GuardarInformacion(nodo *actual)
{
    ofstream archivo( "file01.txt", ios::app );
    if(!archivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit( EXIT_FAILURE );
    }
    if(actual)
    {
        while (actual)
        {
        GuardarInformacion(actual->izq);
        archivo << actual->num.getNum() << '|' << '*';
        GuardarInformacion(actual->der);
        }

        cout<<"Informacion guardada"<<endl;
    }
    else
    {
        cout<<"\nEl arbol esta vacia"<<endl;
    }
    archivo.close();
}

void abb::CargarInformacion()
{
    Data datoabb;
    int largo;
    string registro,num,buffer;
    ifstream archivo( "file01.txt", ios::in );
    if(!archivo)
    {
        cerr<<"No se pudo abrir el archivo"<<endl;
        exit( EXIT_FAILURE );
    }
    else
    {
        archivo.seekg(0,archivo.end);
        largo=archivo.tellg();
        archivo.seekg(0,archivo.beg);

        char *buffer= new char [largo];
        archivo.read(buffer,largo);
        stringstream ss(buffer);

        while(getline(ss,registro,'*') and ss.eofbit)
        {
            stringstream ss_reg(registro);
            try
            {
                getline(ss_reg, num, '|');

                datoabb.setNum(stoi(num));
            }
            catch(invalid_argument const &e){}
            catch(out_of_range const &e){}
        }
        cout<<"Informacion cargada"<<endl;
    }
    archivo.close();
}
