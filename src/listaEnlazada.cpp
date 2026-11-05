// Autor: Sebastián Mateo
#include "listaEnlazada.hpp"

#include <cassert>
#include <cstdlib>


ListaEnlazada::ListaEnlazada()
    : primero_(nullptr), ultimo_(nullptr), n_(0)
{
}

ListaEnlazada::ListaEnlazada(const ListaEnlazada&)
    : primero_(nullptr), ultimo_(nullptr), n_(0)
{
    assert(false && "sin implementar");
    std::abort();
}

ListaEnlazada& ListaEnlazada::operator=(ListaEnlazada)
{
    assert(false && "sin implementar");
    std::abort();
}

ListaEnlazada::~ListaEnlazada()
{
}

void ListaEnlazada::intercambiar(ListaEnlazada&)
{
    assert(false && "sin implementar");
    std::abort();
}

int ListaEnlazada::tam() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool ListaEnlazada::vacia() const
{
    assert(false && "sin implementar");
    std::abort();
}

const std::string& ListaEnlazada::at(int) const
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaEnlazada::insertar(int, const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaEnlazada::anadirAlFinal(const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaEnlazada::borrar(int)
{
    assert(false && "sin implementar");
    std::abort();
}

int ListaEnlazada::buscar(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaEnlazada::vaciar()
{
    assert(false && "sin implementar");
    std::abort();
}
