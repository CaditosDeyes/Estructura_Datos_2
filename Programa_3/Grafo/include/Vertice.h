#ifndef VERTICE_H
#define VERTICE_H
#include"Arista.h"

class Vertice: public Arista
{
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;
};

#endif // VERTICE_H
