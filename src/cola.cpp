// Autora: Maria Fernanda Ticona
#include "cola.hpp"

#include <cassert>
#include <cstdlib>


Cola::Cola()
    : primero_(nullptr), ultimo_(nullptr), tamano_(0)
{
}

Cola::Cola(const Cola&)
    : primero_(nullptr), ultimo_(nullptr), tamano_(0)
{
    assert(false && "sin implementar");
    std::abort();
}

Cola& Cola::operator=(Cola)
{
    assert(false && "sin implementar");
    std::abort();
}

Cola::~Cola()
{
}

void Cola::intercambiar(Cola&)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Cola::vacia() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Cola::tamano() const
{
    assert(false && "sin implementar");
    std::abort();
}

void Cola::encolar(const Paquete&)
{
    assert(false && "sin implementar");
    std::abort();
}

Paquete Cola::desencolar()
{
    assert(false && "sin implementar");
    std::abort();
}

const Paquete& Cola::frente() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool Cola::contiene(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

void Cola::imprimir() const
{
    assert(false && "sin implementar");
    std::abort();
}
