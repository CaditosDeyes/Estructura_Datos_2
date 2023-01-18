#ifndef NODE_H
#define NODE_H
#include "dato.h"

class nodo{
    private:
        Dato data;
        nodo* next;
    public:
        nodo();
        nodo(const Dato&);
        ~nodo();

        Dato& getData();
        nodo* getNext();

        void setData(Dato&);
        void setNext(nodo*);
        bool operator!=(Dato&);

};
#endif