// Autor: Sebastián Mateo
#include "pila.hpp"

#include <cassert>

Pila::Pila()
    : cima_(nullptr), tamano_(0)
{
}

// Copia profunda conservando el orden: de la cima hacia abajo, enlazando al final.
Pila::Pila(const Pila& otra)
    : cima_(nullptr), tamano_(0)
{
    Nodo* ultimo = nullptr;
    for (const Nodo* n = otra.cima_; n != nullptr; n = n->sig) {
        Nodo* nuevo = new Nodo{n->dato, nullptr};
        if (ultimo == nullptr) {
            cima_ = nuevo;
        } else {
            ultimo->sig = nuevo;
        }
        ultimo = nuevo;
        ++tamano_;
    }
}

// El parámetro por valor YA es la copia: se intercambia y se lleva lo viejo.
Pila& Pila::operator=(Pila otra)
{
    intercambiar(otra);
    return *this;
}

Pila::~Pila()
{
    while (cima_ != nullptr) {
        Nodo* arriba = cima_;
        cima_ = arriba->sig;
        delete arriba;
    }
}

void Pila::intercambiar(Pila& otra)
{
    Nodo* c = cima_;
    cima_ = otra.cima_;
    otra.cima_ = c;
    int t = tamano_;
    tamano_ = otra.tamano_;
    otra.tamano_ = t;
}

bool Pila::vacia() const
{
    return tamano_ == 0;
}

int Pila::tamano() const
{
    return tamano_;
}

void Pila::apilar(const Paquete& p)
{
    cima_ = new Nodo{p, cima_};
    ++tamano_;
}

Paquete Pila::desapilar()
{
    assert(!vacia());
    Nodo* arriba = cima_;
    Paquete p = arriba->dato;
    cima_ = arriba->sig;
    delete arriba;
    --tamano_;
    return p;
}

const Paquete& Pila::cima() const
{
    assert(!vacia());
    return cima_->dato;
}

bool Pila::contiene(const std::string& id) const
{
    for (const Nodo* n = cima_; n != nullptr; n = n->sig) {
        if (n->dato.id() == id) {
            return true;
        }
    }
    return false;
}

// Una línea por paquete, de la cima hacia abajo (el primero en salir, arriba).
void Pila::imprimir() const
{
    for (const Nodo* n = cima_; n != nullptr; n = n->sig) {
        std::cout << "  ";
        n->dato.imprimir();
        std::cout << "\n";
    }
}
