// Autora: Maria Fernanda Ticona
#include "paquete.hpp"

#include <cassert>
#include <cstdlib>


int Paquete::vivos_ = 0;

Paquete::Paquete(const std::string& id, const std::string& parada, double kilos)
    : id_(id), parada_(parada), kilos_(kilos)
{
    ++vivos_;
}

Paquete::Paquete(const Paquete& otro)
    : id_(otro.id_), parada_(otro.parada_), kilos_(otro.kilos_)
{
    ++vivos_;
}

Paquete& Paquete::operator=(const Paquete&)
{
    assert(false && "sin implementar");
    std::abort();
}

Paquete::~Paquete()
{
    --vivos_;
}

const std::string& Paquete::id() const
{
    assert(false && "sin implementar");
    std::abort();
}

const std::string& Paquete::parada() const
{
    assert(false && "sin implementar");
    std::abort();
}

double Paquete::kilos() const
{
    assert(false && "sin implementar");
    std::abort();
}

void Paquete::imprimir() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Paquete::vivos()
{
    return vivos_;
}
