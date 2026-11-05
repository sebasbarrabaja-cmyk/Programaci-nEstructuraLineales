// Autor: Sebastián Mateo
#include "pila.hpp"

#include <cassert>
#include <cstdlib>


Pila::Pila()
    : cima_(nullptr), tamano_(0)
{
}

Pila::Pila(const Pila&)
    : cima_(nullptr), tamano_(0)
{
    assert(false && "sin implementar");
    std::abort();
}

Pila& Pila::operator=(Pila)
{
    assert(false && "sin implementar");
    std::abort();
}

Pila::~Pila()
{
}

void Pila::intercambiar(Pila&)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Pila::vacia() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Pila::tamano() const
{
    assert(false && "sin implementar");
    std::abort();
}

void Pila::apilar(const Paquete&)
{
    assert(false && "sin implementar");
    std::abort();
}

Paquete Pila::desapilar()
{
    assert(false && "sin implementar");
    std::abort();
}

const Paquete& Pila::cima() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool Pila::contiene(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

void Pila::imprimir() const
{
    assert(false && "sin implementar");
    std::abort();
}
