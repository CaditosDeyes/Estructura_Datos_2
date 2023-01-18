#ifndef ABB_H
#define ABB_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Data.h"
#include "nodo.h"
using namespace std;

class abb: public nodo
{
    private:
        nodo *arbol;
        nodo *h;
    public:
        abb();
        nodo *crearNodo(int,nodo *);
        void Inicializa();
        void insertar(nodo *&,int,nodo *);
        void mostrar(nodo *,int);
        void inOrden(nodo*);
        void preoden(nodo*);
        void eliminar(nodo *,int);
        void eliminarNodo(nodo *);
        nodo *minimo(nodo *);
        nodo* Siguiente(string);
        void remplazar(nodo *,nodo *);
        void destruir(nodo *);
        void GuardarInformacion(nodo *);
        void CargarInformacion();
};

#endif // ABB_H
