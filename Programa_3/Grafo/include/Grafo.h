#ifndef GRAFO_H
#define GRAFO_H
#include<iostream>
#include<fstream>
using namespace std;

class Arista;

class Vertice
{
    Vertice *sig;
    Arista *ady;
    string nombre;
    void setNombre(string nombre){ nombre=nombre; };
    string getNombre(){return nombre;};
    friend class grafo;
    friend class Arista;
};

class Arista
{
    Arista *sig;
    Vertice *ady;
    int peso;
    void setPeso(int peso){peso=peso;};
    int getPeso(){return peso;};
    friend class grafo;
};

class grafo
{
    Vertice *h;
    public:
        grafo();
        void inicializa();
        bool vacio();
        int tamano();
        Vertice *getVertice(string nombre);
        void insertArista(string, string, int peso);
        void insertVertice(string nombre);
        void listaAdyacencia();
        void eliminarArista(Vertice *origen, Vertice *destino);
        void anular();
        void eliminarVertice(string);
        void guarVer();
        void guarAri();
        void cargVer();
        void cargAri();
};

#endif // GRAFO_H
