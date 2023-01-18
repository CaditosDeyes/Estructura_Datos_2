#include "grafo.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

grafo::grafo()
{
    //ctor
}

void grafo::inicializa()
{
    h=nullptr;
}

bool grafo::vacio()
{
    if(h==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int grafo::tamano()
{
    int cont=0;
    Vertice *aux;
    aux=h;
    while(aux!=nullptr)
    {
        cont++;
        aux=aux->sig;
    }
    return cont;
}

Vertice *grafo::getVertice(string nombre)
{
    Vertice *aux;
    aux=h;
    while(aux!=nullptr)
    {
        if(aux->nombre==nombre)
        {
            return aux;
        }
        aux=aux->sig;
    }
    return nullptr;
}

void grafo::insertVertice(string nombre)
{
    Vertice *nuevo=new Vertice;
    nuevo->nombre=nombre;
    nuevo->sig=nullptr;
    nuevo->ady=nullptr;
    if(vacio())
    {
        h=nuevo;
    }
    else
    {
        Vertice *aux;
        aux=h;
        while(aux->sig!=nullptr)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
}

void grafo::insertArista(string ori, string des, int peso)
{
    Vertice *origen=getVertice(ori);
    Vertice *destino=getVertice(des);
    Arista *nueva=new Arista;
    nueva->peso =peso;
    nueva->sig=nullptr;
    nueva->ady=nullptr;
    Arista *aux;
    aux=origen->ady;
    if(aux==nullptr)
    {
        origen->ady=nueva;
        nueva->ady=destino;
    }
    else
    {
        while(aux->sig!=nullptr)
        {
            aux=aux->sig;
        }
        aux->sig=nueva;
        nueva->ady=destino;
    }
}

void grafo::listaAdyacencia()
{
    Vertice *verAux;
    Arista *ariAux;

    verAux=h;
    while(verAux!=nullptr)
    {
        cout<<verAux->nombre<<"->";
        ariAux=verAux->ady;
        while(ariAux!=nullptr)
        {
            cout<<ariAux->ady->nombre<<"->";
            ariAux=ariAux->sig;
        }
        verAux=verAux->sig;
        cout<<endl;
    }
}

void grafo::anular()
{
    Vertice *aux;
    while(h!=nullptr)
    {
        aux=h;
        h=h->sig;
        delete aux;
    }
}

void grafo::eliminarArista(Vertice *origen, Vertice *destino)
{
    int band=0;
    Arista *actual,*anterio;
    actual=origen->ady;

    if(actual==nullptr)
    {
        cout<<"\nEl Vertice Origen no tiene aristas\n";
    }
    else if(actual->ady==destino)
    {
        origen->ady=actual->sig;
        delete actual;
    }
    else
    {
        while(actual->ady!=nullptr)
        {
            if(actual->ady==destino)
            {
                band=1;
                anterio->sig=actual->sig;
                delete actual;
                break;
            }
            anterio=actual;
            actual=actual->sig;
        }
        if(band==0)
        {
            cout<<"\nEsos dos vertices no estan conectados\n";
        }
    }
}

void grafo::eliminarVertice(string v)
{
    Vertice *ver=getVertice(v);
    Vertice *actual,*anterior;
    Arista *aux;

    actual=h;

    while(actual!=nullptr)
    {
        aux=actual->ady;
        while(aux!=nullptr)
        {
            if(aux->ady==ver)
            {
                eliminarArista(actual,aux->ady);
                break;
            }
            aux=aux->sig;
        }
        actual=actual->sig;
    }
    actual=h;
    if(h==ver)
    {
      h=h->sig;
      delete actual;
    }
    else
    {
        while(actual!=ver)
        {
            anterior =actual;
            actual=actual->sig;
        }
        anterior->sig=actual->sig;
        delete actual;
    }
}

void grafo::guarVer()
{
    Vertice *auxVer=h;
    ofstream archivo( "file01.txt", ios::out );
    if ( !archivo )
    {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit( EXIT_FAILURE );
    }

    if(auxVer)
    {
        while(auxVer)
        {
            archivo<< auxVer->getNombre()<<"*";
            auxVer=auxVer->sig;
        }
        archivo<<"$";
    }
    guarAri();
    archivo.close();
}

void grafo::guarAri()
{
    Vertice *auxVer=h;
    Arista *auxAri;
    ofstream archivo( "file02.txt", ios::out );
    if ( !archivo )
    {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit( EXIT_FAILURE );
    }
    if(auxVer)
    {
        while(auxVer)
        {
            auxAri=auxVer->ady;
            while(auxAri)
            {
                archivo<<auxVer->getNombre()<<'|'<<auxAri->ady->getNombre()<<'|'<<auxAri->getPeso()<<'*';
                auxAri=auxAri->sig;
            }
            auxVer=auxVer->sig;
        }
        archivo<<"$";
    }
    archivo.close();
}

void grafo::cargVer()
{
    Vertice dat;
    string registro,nombre,peso,buffer;
    ifstream archivo( "file01.txt", ios::in );
    if ( !archivo )
    {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit( EXIT_FAILURE );
    }
    else
    {
        getline(archivo,buffer,'$');
        stringstream ss(buffer);
        while (getline(ss,registro,'*') and ss.eofbit)
        {
            stringstream ss_reg(registro);
            try
            {
                getline(ss_reg, nombre, '*');

                dat.setNombre(nombre);
                insertVertice(nombre);
            }
            catch (invalid_argument const &e){}
            catch (out_of_range const &e){}
        }
        cargAri();
        cout<<"\nInformacion cargada"<<endl;
    }
    archivo.close();
}

void grafo::cargAri()
{
    string registro,origen,costo,destino,buffer;
    ifstream archivo( "file02.txt", ios::in );
    if ( !archivo )
    {
        cerr << "No se pudo abrir el archivo" <<endl;
        exit( EXIT_FAILURE );
    }
    else
    {
        getline(archivo,buffer,'$');
        stringstream ss(buffer);
        while (getline(ss,registro,'*') and ss.eofbit)
        {
            stringstream ss_reg(registro);
            try
            {
                getline(ss_reg, origen, '|');
                getline(ss_reg, destino, '|');
                getline(ss_reg, costo, '|');

                insertArista(origen,destino,stoi(costo));
            }
            catch (invalid_argument const &e){}
            catch (out_of_range const &e){}
        }
    }
    archivo.close();
}
