// Autor: Sebastián Mateo
#include "ruta.hpp"

// Ruta no guarda nada propio: cada operación se la pasa a la lista del tipo elegido.
// Es el único sitio donde se distingue entre las dos implementaciones.

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
    return tipo_ == TipoRuta::Contigua ? contigua_.tam() : enlazada_.tam();
}

bool Ruta::vacia() const
{
    return tipo_ == TipoRuta::Contigua ? contigua_.vacia() : enlazada_.vacia();
}

const std::string& Ruta::at(int i) const
{
    return tipo_ == TipoRuta::Contigua ? contigua_.at(i) : enlazada_.at(i);
}

void Ruta::insertar(int i, const std::string& parada)
{
    if (tipo_ == TipoRuta::Contigua) {
        contigua_.insertar(i, parada);
    } else {
        enlazada_.insertar(i, parada);
    }
}

void Ruta::anadirAlFinal(const std::string& parada)
{
    if (tipo_ == TipoRuta::Contigua) {
        contigua_.anadirAlFinal(parada);
    } else {
        enlazada_.anadirAlFinal(parada);
    }
}

void Ruta::borrar(int i)
{
    if (tipo_ == TipoRuta::Contigua) {
        contigua_.borrar(i);
    } else {
        enlazada_.borrar(i);
    }
}

int Ruta::buscar(const std::string& parada) const
{
    return tipo_ == TipoRuta::Contigua ? contigua_.buscar(parada) : enlazada_.buscar(parada);
}

void Ruta::vaciar()
{
    if (tipo_ == TipoRuta::Contigua) {
        contigua_.vaciar();
    } else {
        enlazada_.vaciar();
    }
}
