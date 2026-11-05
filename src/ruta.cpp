// Autor: Sebastián Mateo
#include "ruta.hpp"

#include <cassert>
#include <cstdlib>


Ruta::Ruta(TipoRuta tipo)
    : tipo_(tipo), contigua_(), enlazada_()
{
}

TipoRuta Ruta::tipo() const
{
    return tipo_;
}



int Ruta::tam() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool Ruta::vacia() const
{
    assert(false && "sin implementar");
    std::abort();
}

const std::string& Ruta::at(int) const
{
    assert(false && "sin implementar");
    std::abort();
}

void Ruta::insertar(int, const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void Ruta::anadirAlFinal(const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void Ruta::borrar(int)
{
    assert(false && "sin implementar");
    std::abort();
}

int Ruta::buscar(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

void Ruta::vaciar()
{
    assert(false && "sin implementar");
    std::abort();
}
