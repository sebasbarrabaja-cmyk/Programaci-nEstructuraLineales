// Autores: Maria Fernanda Ticona y Sebastián Mateo
#include "centro.hpp"

#include <cassert>
#include <cstdlib>

Centro::Centro(TipoRuta tipo)
    : ruta_(tipo), cinta_(), furgoneta_(), reentregas_(),
      dia_(1), cerrado_(false), entregados_(0), fallidos_(0)
{
}

bool Centro::fijarCapacidad(double)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::recibir(const std::string&, const std::string&, double)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::fijarRuta(const Ruta&)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::insertarParada(const std::string&, int)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::anularParada(const std::string&)
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::consultarPosicion(const std::string&) const
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::cargar()
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::entregar()
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::fallo()
{
    assert(false && "sin implementar");
    std::abort();
}

void Centro::estado() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::cerrarDia()
{
    assert(false && "sin implementar");
    std::abort();
}

void Centro::nuevoDia()
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::dia() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::enCinta() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::enFurgoneta() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::enReentregas() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::paradasEnRuta() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::entregadosHoy() const
{
    assert(false && "sin implementar");
    std::abort();
}

int Centro::fallidosHoy() const
{
    assert(false && "sin implementar");
    std::abort();
}
