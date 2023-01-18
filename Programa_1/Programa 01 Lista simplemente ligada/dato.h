#ifndef DATO_H
#define DATO_H
#include<iostream>

using namespace std;

class Dato{
    private:
        int codigo;
        string tipo;
        int fuerza;
    public:
        Dato();
        Dato(Dato&);
        int getCodigo() const;
        string getTipo() const;
        int getFuerza() const;
        void setCodigo(const int&);
        void setTipo(const string&);
        void setFuerza(const int&);
        bool operator!=(const Dato &d) const;
        friend ostream& operator<<(ostream&,const Dato&);
        friend istream& operator>>(istream&,Dato&);
};

#endif