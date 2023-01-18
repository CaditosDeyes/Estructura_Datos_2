#ifndef NODO_H
#define NODO_H
#include "Data.h"
using namespace std;

class nodo
{
    public:
        int dato;
        nodo *tmp;
        nodo *izq;
        nodo *der;
        nodo *padre;
        Data num;
        nodo *sig;
        nodo();
};

#endif // NODO_H
