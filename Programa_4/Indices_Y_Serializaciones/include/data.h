#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <iomanip>

using namespace std;

class data
{
    string autor;
    string libro;
    string paginas;
    int llave;

public:
    data();
    void setAutor(const string &a);
    string getAutor();
    void setLibro(const string &l);
    string getLibro();
    void setPaginas(const string &p);
    string getPaginas();
    void setLlave(int l);
    int getLlave();

    friend ostream &operator<<(ostream &out, const data &d)
    {
        out << left;
        out << "|"<<d.autor;
        out << "|\t|" << d.libro;
        out << "\t|" << d.paginas;
        out << endl;
        return out;
    }

    friend istream &operator>>(istream &in, data &d)
    {
        cout << "Ingresa el nombre del Autor: ";
        getline(cin, d.autor);
        cout << "Ingresa el nombre del libro: ";
        getline(cin, d.libro);
        cout << "Ingresa el numero de paginas: ";
        getline(cin, d.paginas);
        cout << endl;
        cout << "Ingrese el codigo: ";
        cin >> d.llave;
        cin.ignore();
        return in;
    }

    bool operator==(const data &d) const
    {
        return llave == d.llave;
    }
};

#endif // DATA_H
