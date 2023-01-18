#include "data.h"

data::data() {}

void data::setAutor(const string &a)
{
    autor = a;
}

string data::getAutor()
{
    return autor;
}

void data::setLibro(const string &l)
{
    libro = l;
}

string data::getLibro()
{
    return libro;
}

void data::setPaginas(const string &p)
{
    paginas = p;
}

string data::getPaginas()
{
    return paginas;
}

void data::setLlave(int l)
{
    llave = l;
}

int data::getLlave()
{
    return llave;
}
