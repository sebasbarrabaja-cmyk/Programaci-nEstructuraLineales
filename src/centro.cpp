// Autores: Maria Fernanda Ticona y Sebastián Mateo
#include "centro.hpp"

#include <cassert>
#include <cstdlib>

namespace
{
// Mientras la cima de la furgoneta sea de una parada que ya no está en la ruta (se
// anuló con el paquete a bordo), se devuelve al centro: va a reentregas y cuenta como
// fallido. Así se entrega o falla siempre el siguiente paquete que de verdad toca.
void devolverAnulados(Furgoneta& furgoneta, const Ruta& ruta, Cola& reentregas, int& fallidos)
{
    while (!furgoneta.vacia() && ruta.buscar(furgoneta.siguiente().parada()) == -1) {
        Paquete p = furgoneta.descargar();
        std::cout << "DEVUELTO " << p.id() << " de " << p.parada()
                  << " (parada anulada): a reentregas\n";
        reentregas.encolar(p);
        ++fallidos;
    }
}
}  // namespace

Centro::Centro(TipoRuta tipo)
    : ruta_(tipo), cinta_(), furgoneta_(), reentregas_(),
      dia_(1), cerrado_(false), entregados_(0), fallidos_(0)
{
}

bool Centro::fijarCapacidad(double kilos)
{
    if (kilos <= 0) {
        std::cout << "ERROR el peso debe ser mayor que cero (FURGONETA " << kilos << ")\n";
        return false;
    }
    if (!furgoneta_.vacia()) {
        std::cout << "ERROR la furgoneta todavia lleva paquetes (FURGONETA " << kilos << ")\n";
        return false;
    }
    furgoneta_.fijarCapacidad(kilos);
    std::cout << "OK furgoneta de " << kilos << " kg\n";
    return true;
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
    if (!furgoneta_.vacia()) {
        std::cout << "ERROR la furgoneta todavia lleva paquetes (CARGAR)\n";
        return false;
    }

    // Selección: parada a parada EN ORDEN DE RUTA y, dentro de cada una, por orden
    // de llegada. Cada pasada rota la cinta entera una vez (sale y vuelve a entrar),
    // así lo que no se selecciona conserva su orden relativo.
    Pila seleccionados;
    double pesoSeleccionado = 0;
    int cargados = 0;
    for (int pos = 0; pos < ruta_.tam(); ++pos) {
        const std::string parada = ruta_.at(pos);
        const int n = cinta_.tamano();
        for (int k = 0; k < n; ++k) {
            Paquete p = cinta_.desencolar();
            if (p.parada() == parada
                && pesoSeleccionado + p.kilos() <= furgoneta_.capacidad() + 1e-9) {
                seleccionados.apilar(p);  // el primero seleccionado queda al fondo
                pesoSeleccionado += p.kilos();
            } else {
                cinta_.encolar(p);  // no cabe, otra parada o fuera de ruta: sigue en la cinta
            }
        }
    }

    // Se pasan a la furgoneta de uno en uno: el último seleccionado entra primero y el
    // primero seleccionado (primera parada de la ruta) queda en la puerta.
    while (!seleccionados.vacia()) {
        furgoneta_.cargar(seleccionados.desapilar());
        ++cargados;
    }

    std::cout << "OK cargados " << cargados << ", sin cargar " << cinta_.tamano()
              << " (peso " << furgoneta_.peso() << "/" << furgoneta_.capacidad() << " kg)\n";
    return true;
}

bool Centro::entregar()
{
    devolverAnulados(furgoneta_, ruta_, reentregas_, fallidos_);
    if (furgoneta_.vacia()) {
        std::cout << "ERROR la furgoneta esta vacia (ENTREGAR)\n";
        return false;
    }
    Paquete p = furgoneta_.descargar();
    ++entregados_;
    std::cout << "OK entregado " << p.id() << " en " << p.parada() << "\n";
    return true;
}

bool Centro::fallo()
{
    devolverAnulados(furgoneta_, ruta_, reentregas_, fallidos_);
    if (furgoneta_.vacia()) {
        std::cout << "ERROR la furgoneta esta vacia (FALLO)\n";
        return false;
    }
    Paquete p = furgoneta_.descargar();
    reentregas_.encolar(p);
    ++fallidos_;
    std::cout << "OK fallo " << p.id() << " en " << p.parada() << ": se reparte manana\n";
    return true;
}

void Centro::estado() const
{
    assert(false && "sin implementar");
    std::abort();
}

bool Centro::cerrarDia()
{
    cerrado_ = true;
    std::cout << "OK cierre: entregados " << entregados_ << ", fallidos " << fallidos_
              << ", sin cargar " << cinta_.tamano()
              << ", en furgoneta " << furgoneta_.numPaquetes() << "\n";
    return true;
}

void Centro::nuevoDia()
{
    // La cinta nueva: primero las reentregas (en orden de fallo), luego lo que seguía a
    // bordo (en el orden en que se habría entregado) y luego lo que seguía sin cargar.
    // Lo que llegue después se encola detrás.
    Cola nueva;
    while (!reentregas_.vacia()) {
        nueva.encolar(reentregas_.desencolar());
    }
    while (!furgoneta_.vacia()) {
        nueva.encolar(furgoneta_.descargar());
    }
    while (!cinta_.vacia()) {
        nueva.encolar(cinta_.desencolar());
    }
    cinta_.intercambiar(nueva);

    ruta_.vaciar();      // la ruta se fija cada día
    entregados_ = 0;
    fallidos_ = 0;
    cerrado_ = false;
    ++dia_;
    std::cout << "OK dia nuevo (dia " << dia_ << "): " << cinta_.tamano() << " paquetes en la cinta\n";
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
