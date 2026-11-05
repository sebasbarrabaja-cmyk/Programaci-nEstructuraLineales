// Autor: Sebastián Mateo
#include "listaContigua.hpp"

#include <cassert>

ListaContigua::ListaContigua()
    : datos_(nullptr), n_(0), capacidad_(0)
{
}

ListaContigua::ListaContigua(const ListaContigua& otra)
    : datos_(nullptr), n_(otra.n_), capacidad_(otra.capacidad_)
{
    if (capacidad_ > 0) {
        datos_ = new std::string[capacidad_];
        for (int i = 0; i < n_; ++i) {
            datos_[i] = otra.datos_[i];
        }
    }
}

ListaContigua& ListaContigua::operator=(ListaContigua otra)
{
    intercambiar(otra);
    return *this;
}

ListaContigua::~ListaContigua()
{
    delete[] datos_;
}

void ListaContigua::intercambiar(ListaContigua& otra)
{
    std::string* d = datos_;
    datos_ = otra.datos_;
    otra.datos_ = d;
    int n = n_;
    n_ = otra.n_;
    otra.n_ = n;
    int c = capacidad_;
    capacidad_ = otra.capacidad_;
    otra.capacidad_ = c;
}

int ListaContigua::tam() const
{
    return n_;
}

bool ListaContigua::vacia() const
{
    return n_ == 0;
}

const std::string& ListaContigua::at(int i) const
{
    assert(i >= 0 && i < n_);
    return datos_[i];
}

void ListaContigua::insertar(int i, const std::string& parada)
{
    assert(i >= 0 && i <= n_);
    if (n_ == capacidad_) {
        crecer();
    }
    for (int k = n_; k > i; --k) {
        datos_[k] = datos_[k - 1];
    }
    datos_[i] = parada;
    ++n_;
}

void ListaContigua::anadirAlFinal(const std::string& parada)
{
    insertar(n_, parada);
}

void ListaContigua::borrar(int i)
{
    assert(i >= 0 && i < n_);
    for (int k = i; k + 1 < n_; ++k) {
        datos_[k] = datos_[k + 1];
    }
    --n_;
    datos_[n_].clear();
}

int ListaContigua::buscar(const std::string& parada) const
{
    for (int i = 0; i < n_; ++i) {
        if (datos_[i] == parada) {
            return i;
        }
    }
    return -1;
}

void ListaContigua::vaciar()
{
    for (int i = 0; i < n_; ++i) {
        datos_[i].clear();
    }
    n_ = 0;
}

int ListaContigua::capacidad() const
{
    return capacidad_;
}

// Pide un bloque del doble (4 la primera vez), copia y libera el viejo.
void ListaContigua::crecer()
{
    int nueva = (capacidad_ == 0) ? 4 : capacidad_ * 2;
    std::string* bloque = new std::string[nueva];
    for (int i = 0; i < n_; ++i) {
        bloque[i] = datos_[i];
    }
    delete[] datos_;
    datos_ = bloque;
    capacidad_ = nueva;
}
