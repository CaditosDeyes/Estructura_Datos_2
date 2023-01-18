#ifndef ARISTA_H
#define ARISTA_H
#include"Vertice.h"

class Arista
{
    Arista *sig;
    Vertice *ady;
    int peso;
    friend class Grafo;
};

#endif // ARISTA_H
