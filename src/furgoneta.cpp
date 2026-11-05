// Autor: Sebastián Mateo
#include "furgoneta.hpp"

#include <cassert>
#include <cstdlib>


Furgoneta::Furgoneta()
    : capacidad_(0), peso_(0), carga_()
{
}

double Furgoneta::capacidad() const
{
    assert(false && "sin implementar");
    std::abort();
}

double Furgoneta::peso() const
{
    assert(false && "sin implementar");
    std::abort();
}

void Furgoneta::fijarCapacidad(double)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Furgoneta::cabe(double) const
{
    assert(false && "sin implementar");
    std::abort();
}

void Furgoneta::cargar(const Paquete&)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Furgoneta::vacia() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Furgoneta::numPaquetes() const
{
    assert(false && "sin implementar");
    std::abort();
}

const Paquete& Furgoneta::siguiente() const
{
    assert(false && "sin implementar");
    std::abort();
}

Paquete Furgoneta::descargar()
{
    assert(false && "sin implementar");
    std::abort();
}

bool Furgoneta::contiene(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

void Furgoneta::imprimir() const
{
    assert(false && "sin implementar");
    std::abort();
}
