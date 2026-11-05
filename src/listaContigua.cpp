// Autor: Sebastián Mateo
#include "listaContigua.hpp"

#include <cassert>
#include <cstdlib>


ListaContigua::ListaContigua()
    : datos_(nullptr), n_(0), capacidad_(0)
{
}

ListaContigua::ListaContigua(const ListaContigua&)
    : datos_(nullptr), n_(0), capacidad_(0)
{
    assert(false && "sin implementar");
    std::abort();
}

ListaContigua& ListaContigua::operator=(ListaContigua)
{
    assert(false && "sin implementar");
    std::abort();
}

ListaContigua::~ListaContigua()
{
}

void ListaContigua::intercambiar(ListaContigua&)
{
    assert(false && "sin implementar");
    std::abort();
}

int ListaContigua::tam() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool ListaContigua::vacia() const
{
    assert(false && "sin implementar");
    std::abort();
}

const std::string& ListaContigua::at(int) const
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaContigua::insertar(int, const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaContigua::anadirAlFinal(const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaContigua::borrar(int)
{
    assert(false && "sin implementar");
    std::abort();
}

int ListaContigua::buscar(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaContigua::vaciar()
{
    assert(false && "sin implementar");
    std::abort();
}

int ListaContigua::capacidad() const
{
    assert(false && "sin implementar");
    std::abort();
}

void ListaContigua::crecer()
{
    assert(false && "sin implementar");
    std::abort();
}
