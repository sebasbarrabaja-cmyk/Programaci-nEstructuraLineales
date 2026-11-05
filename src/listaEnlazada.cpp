// Autor: Sebastián Mateo
#include "listaEnlazada.hpp"

#include <cassert>

ListaEnlazada::ListaEnlazada()
    : primero_(nullptr), ultimo_(nullptr), n_(0)
{
}

ListaEnlazada::ListaEnlazada(const ListaEnlazada& otra)
    : primero_(nullptr), ultimo_(nullptr), n_(0)
{
    for (const Nodo* p = otra.primero_; p != nullptr; p = p->sig) {
        anadirAlFinal(p->dato);
    }
}

ListaEnlazada& ListaEnlazada::operator=(ListaEnlazada otra)
{
    intercambiar(otra);
    return *this;
}

ListaEnlazada::~ListaEnlazada()
{
    vaciar();
}

void ListaEnlazada::intercambiar(ListaEnlazada& otra)
{
    Nodo* p = primero_;
    primero_ = otra.primero_;
    otra.primero_ = p;
    Nodo* u = ultimo_;
    ultimo_ = otra.ultimo_;
    otra.ultimo_ = u;
    int n = n_;
    n_ = otra.n_;
    otra.n_ = n;
}

int ListaEnlazada::tam() const
{
    return n_;
}

bool ListaEnlazada::vacia() const
{
    return n_ == 0;
}

const std::string& ListaEnlazada::at(int i) const
{
    assert(i >= 0 && i < n_);
    const Nodo* p = primero_;
    for (int k = 0; k < i; ++k) {
        p = p->sig;
    }
    return p->dato;
}

void ListaEnlazada::insertar(int i, const std::string& parada)
{
    assert(i >= 0 && i <= n_);
    Nodo* nuevo = new Nodo{parada, nullptr};
    if (i == 0) {
        nuevo->sig = primero_;
        primero_ = nuevo;
        if (ultimo_ == nullptr) {
            ultimo_ = nuevo;
        }
    } else {
        Nodo* previo = ultimo_;  // al final no hace falta recorrer
        if (i < n_) {
            previo = primero_;
            for (int k = 1; k < i; ++k) {
                previo = previo->sig;
            }
        }
        nuevo->sig = previo->sig;
        previo->sig = nuevo;
        if (nuevo->sig == nullptr) {
            ultimo_ = nuevo;
        }
    }
    ++n_;
}

void ListaEnlazada::anadirAlFinal(const std::string& parada)
{
    insertar(n_, parada);
}

void ListaEnlazada::borrar(int i)
{
    assert(i >= 0 && i < n_);
    Nodo* quitar = primero_;
    if (i == 0) {
        primero_ = quitar->sig;
        if (primero_ == nullptr) {
            ultimo_ = nullptr;
        }
    } else {
        Nodo* previo = primero_;
        for (int k = 1; k < i; ++k) {
            previo = previo->sig;
        }
        quitar = previo->sig;
        previo->sig = quitar->sig;
        if (quitar == ultimo_) {
            ultimo_ = previo;
        }
    }
    delete quitar;
    --n_;
}

int ListaEnlazada::buscar(const std::string& parada) const
{
    int i = 0;
    for (const Nodo* p = primero_; p != nullptr; p = p->sig, ++i) {
        if (p->dato == parada) {
            return i;
        }
    }
    return -1;
}

void ListaEnlazada::vaciar()
{
    while (primero_ != nullptr) {
        Nodo* siguiente = primero_->sig;
        delete primero_;
        primero_ = siguiente;
    }
    ultimo_ = nullptr;
    n_ = 0;
}
