#include "nodo.h"

nodo::nodo() :next(nullptr) {}
nodo::nodo(const Dato& d) {
    data = d;
    next = nullptr;
}

nodo::~nodo() {}

Dato& nodo::getData() {
    return data;
}

nodo* nodo::getNext() {
    return next;
}

void nodo::setData(Dato& d) {
    data = d;
}

void nodo::setNext(nodo* p) {
    next = p;
}
