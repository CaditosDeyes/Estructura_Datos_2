#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <list>
#include <cstring>
#include <fstream>
#include "data.h"

using namespace std;

class Hash
{
    static const int consola = 20;
    list<pair<int, data>> tabla[consola];

public:
    Hash();
    bool vacia() const;
    int hashFuncion(int llave);
    void insertar(int llave, data valor);
    void eliminar(int llave);
    void buscar(int llave);
    void mostrar_tabla();
    void Guardar();
    void Cargar();
};

#endif // HASH_H
