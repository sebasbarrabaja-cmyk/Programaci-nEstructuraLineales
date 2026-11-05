// Autora: Maria Fernanda Ticona
#include "interprete.hpp"

#include <cassert>
#include <cstdlib>


Interprete::Interprete(Centro& centro)
    : centro_(centro)
{
}

bool Interprete::ejecutarLinea(const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

void Interprete::ejecutar()
{
    assert(false && "sin implementar");
    std::abort();
}
