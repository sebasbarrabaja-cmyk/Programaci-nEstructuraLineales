// Autor: Sebastián Mateo
#include "furgoneta.hpp"

#include <cassert>

Furgoneta::Furgoneta()
    : capacidad_(0), peso_(0), carga_()
{
}

double Furgoneta::capacidad() const
{
    return capacidad_;
}

double Furgoneta::peso() const
{
    return peso_;
}

void Furgoneta::fijarCapacidad(double kilos)
{
    assert(kilos > 0);
    assert(vacia());  // con carga a bordo el peso podría superar la nueva capacidad
    capacidad_ = kilos;
}

bool Furgoneta::cabe(double kilos) const
{
    return peso_ + kilos <= capacidad_ + 1e-9;
}

void Furgoneta::cargar(const Paquete& p)
{
    assert(cabe(p.kilos()));
    carga_.apilar(p);
    peso_ += p.kilos();
}

bool Furgoneta::vacia() const
{
    return carga_.vacia();
}

int Furgoneta::numPaquetes() const
{
    return carga_.tamano();
}

const Paquete& Furgoneta::siguiente() const
{
    assert(!vacia());
    return carga_.cima();
}

Paquete Furgoneta::descargar()
{
    assert(!vacia());
    Paquete p = carga_.desapilar();
    peso_ -= p.kilos();
    if (carga_.vacia()) {
        peso_ = 0;  // el redondeo no se acumula entre cargas
    }
    return p;
}

bool Furgoneta::contiene(const std::string& id) const
{
    return carga_.contiene(id);
}

void Furgoneta::imprimir() const
{
    std::cout << "Furgoneta " << peso_ << "/" << capacidad_ << " kg, "
              << carga_.tamano() << " paquetes (el primero en entregarse, arriba):\n";
    carga_.imprimir();
}
