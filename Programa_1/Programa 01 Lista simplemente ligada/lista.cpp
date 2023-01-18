#include "lista.h"

lista::lista() :ancla(nullptr) {}
lista::lista(const lista& l)
{
    copyAll(l);
}

lista::~lista()
{
    if(empty())
    {

    }
    else
    {
        return;
    }

}

void lista::show()
{

    nodo* aux(ancla);
    while (aux != nullptr)
    {
        cout<<aux->getData()<<endl;
        aux=aux->getNext();
    }
}

bool lista::validPosition(nodo* p)
{
    nodo* aux(ancla);
    while (aux != nullptr)
    {
        if (aux == p)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

bool lista::empty()
{
    return ancla == nullptr;
}

nodo* lista::find(Dato d)
{
    nodo* aux(ancla);
    while ((aux != nullptr) && (aux->getData() != d))
    {
        aux = aux->getNext();
    }
    return aux;
}

void lista::push(nodo* p,Dato& d)
{
    if ((p != nullptr) && ( !validPosition(p)))
    {
        throw("El elemento no puede ser guardado, posicion invalida");
    }
    nodo* aux(new nodo(d));
    if (aux == nullptr){
        throw ("Memoria no disponible");
    }
    if (p == nullptr)
    {
        aux->setNext(ancla);
        ancla = aux;
    }
    else {
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

void lista::pop(nodo* p)
{
    if (!validPosition(p)) {
        throw ("Posicion invalida, pop");
    }
    if (p == ancla)
    {
        ancla = p->getNext();
    }
    else {
        getPrevPosition(p)->setNext(p->getNext());
    }
    delete p;
}

void lista::popAll()
{
    nodo* aux;
    while (ancla != nullptr)
    {
        aux = ancla;
        ancla = ancla->getNext();
        delete aux;
    }

}

nodo* lista::getFirstPosition() const
{
    return ancla;
}

nodo* lista::getLastPosition()
{
    if (empty())
    {
        return nullptr;
    }
    nodo* aux(ancla);
    while (aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }
    return aux;
}

nodo* lista::getNextPosition(nodo* p)
{
    return p->getNext();
}

nodo* lista::getPrevPosition(nodo* p)
{
    if (p == ancla || !validPosition(p))
    {
        return nullptr;
    }
    nodo* aux(ancla);
    while (aux->getNext() != p)
    {
        aux = aux->getNext();
    }
    return aux;
}

void lista::copyAll(const lista& l)
{
    nodo* aux(l.ancla);
    nodo* last(nullptr);
    nodo* newNodo;
    while (aux != nullptr)
    {
        newNodo = new nodo(aux->getData());
        if (newNodo == nullptr)
        {
            throw("Memoria no disponible, copyAll");
        }

        if (last == nullptr) {
            ancla = newNodo;
        }
        else {
            last->setNext(newNodo);
        }
        last = newNodo;
        aux = aux->getNext();
    }

}

void lista::writeToDisk()
{
    string fileName;
    fileName = "file01.txt";
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open())
    {
        string message;
        message = "Error al abrir el archivo ";
        message += fileName;
        message += " para guardarlo";

        throw(message);
    }
    nodo* aux(ancla);

    while(aux != nullptr)
    {
        myFile << aux->getData();
        aux = aux->getNext();
    }

    myFile.close();

}

void lista::readFromDisk()
{
    string fileName;
    fileName = "file01.txt";
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open())
    {
        string message;
        message = "Error al abrir el archivo";
        message += fileName;
        message += " para cargarlo";

        throw(message);
    }

    popAll();

    Dato myData;
    nodo* last(nullptr);
    nodo* newNodo;

    while(myFile >> myData)
    {
        if ((newNodo = new nodo(myData)) == nullptr)
        {
            myFile.close();

            throw("Memoria no disponible, readFromDisk");
        }

        if(last==nullptr)
        {
            ancla = newNodo;
        }
        else
        {
            last->setNext(newNodo);
        }

        last = newNodo;

    }
    myFile.close();
}