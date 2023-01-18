#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include "dato.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class lista{
    private:
        nodo* ancla;
    public:
        lista();
        lista(const lista&);
        ~lista();
        void show();
        bool validPosition(nodo*);
        bool empty();
        void push(nodo*,Dato&);
        void pop(nodo*);
        void popAll();
        nodo* find(Dato);
        nodo* getFirstPosition() const;
        nodo* getLastPosition();
        nodo* getNextPosition(nodo*);
        nodo* getPrevPosition(nodo*);
        void copyAll(const lista&);
        void writeToDisk();
        void readFromDisk();
};

#endif