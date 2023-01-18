#include "dato.h"

Dato::Dato(){}
Dato::Dato(Dato& d): codigo(d.codigo), tipo(d.tipo) ,fuerza(d.fuerza) {}

int Dato::getCodigo() const {
    return codigo;
}

string Dato::getTipo() const {
    return tipo;
}

int Dato::getFuerza() const {
    return fuerza;
}

void Dato::setCodigo(const int &c) {
    codigo=c;
}

void Dato::setTipo(const string &t) {
    tipo=t;
}

void Dato::setFuerza(const int &f) {
    fuerza=f;
}

bool Dato::operator!=(const Dato &d) const {
    return codigo!=d.codigo;
}

ostream& operator<<(ostream& os, const Dato& s) {
    os<<s.codigo<<"|";
    os<<s.tipo<<"|";
    os<<s.fuerza<<"*\n";
    return os;
}

istream& operator>>(istream& is, Dato& s) {
    string myStr;
    getline(is, myStr,'|');
    s.codigo = atoi(myStr.c_str());
    getline(is, myStr,'|');
    s.tipo=myStr;
    getline(is, myStr,'*');
    s.fuerza = atoi(myStr.c_str());

    return is;
}