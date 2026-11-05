// Autor: Sebastián Mateo
// Pruebas de Cola escritas leyendo solo include/cola.hpp.
#include "cola.hpp"
#include "paquete.hpp"
#include "prueba.hpp"

#include <sstream>
#include <string>

// Pasa a true cuando María Fernanda fusione su implementación de Cola (y de Paquete).
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

Paquete paq(const std::string& id)
{
    return Paquete(id, "parada-" + id, 1.0);
}

// Vacía c comprobando que salen exactamente los ids esperados, en ese orden.
template <int N>
void sacarEnOrden(Cola& c, const char* const (&ids)[N])
{
    assert(c.tamano() == N);
    for (int i = 0; i < N; ++i) {
        assert(c.frente().id() == ids[i]);
        Paquete p = c.desencolar();
        assert(p.id() == ids[i]);
        assert(c.tamano() == N - 1 - i);
    }
    assert(c.vacia());
}

void recienConstruidaVacia()
{
    Cola c;
    assert(c.vacia());
    assert(c.tamano() == 0);
    assert(!c.contiene("X"));
}

void unSoloElemento()
{
    Cola c;
    c.encolar(paq("A"));
    assert(!c.vacia());
    assert(c.tamano() == 1);
    assert(c.frente().id() == "A");  // primero y último coinciden
    assert(c.contiene("A"));
    Paquete p = c.desencolar();
    assert(p.id() == "A" && p.parada() == "parada-A" && p.kilos() == 1.0);
    assert(c.vacia() && c.tamano() == 0);
    assert(!c.contiene("A"));
}

void saleEnOrdenDeLlegada()
{
    Cola c;
    c.encolar(paq("A"));
    c.encolar(paq("B"));
    c.encolar(paq("C"));
    const char* const orden[] = {"A", "B", "C"};
    sacarEnOrden(c, orden);
}

void extremos()
{
    Cola c;
    c.encolar(paq("A"));
    c.encolar(paq("B"));
    assert(c.frente().id() == "A");  // encolar por detrás no cambia el frente
    c.encolar(paq("Z"));
    assert(c.frente().id() == "A");
    c.desencolar();
    c.desencolar();
    assert(c.frente().id() == "Z");  // el último llega al frente
    assert(c.tamano() == 1);
}

void crecerDecrecerYVolverACrecer()
{
    Cola c;
    for (int i = 0; i < 100; ++i) {
        c.encolar(paq("P" + std::to_string(i)));
    }
    assert(c.tamano() == 100);
    for (int i = 0; i < 100; ++i) {
        assert(c.desencolar().id() == "P" + std::to_string(i));
    }
    assert(c.vacia());
    // Tras vaciarse del todo, sigue funcionando como recién construida.
    c.encolar(paq("X"));
    c.encolar(paq("Y"));
    const char* const orden[] = {"X", "Y"};
    sacarEnOrden(c, orden);
    // Y mezclando entradas y salidas.
    c.encolar(paq("1"));
    c.encolar(paq("2"));
    c.desencolar();
    c.encolar(paq("3"));
    const char* const resto[] = {"2", "3"};
    sacarEnOrden(c, resto);
}

void copiaIndependiente()
{
    Cola original;
    original.encolar(paq("A"));
    original.encolar(paq("B"));
    Cola copia(original);
    assert(copia.tamano() == 2);

    original.desencolar();
    original.encolar(paq("C"));
    copia.encolar(paq("D"));

    const char* const deOriginal[] = {"B", "C"};
    sacarEnOrden(original, deOriginal);
    const char* const deCopia[] = {"A", "B", "D"};
    sacarEnOrden(copia, deCopia);
}

void copiaDeVacia()
{
    Cola vacia;
    Cola copia(vacia);
    assert(copia.vacia() && copia.tamano() == 0);
    copia.encolar(paq("A"));
    assert(vacia.vacia());
}

void asignacion()
{
    Cola a;
    a.encolar(paq("A"));
    a.encolar(paq("B"));
    Cola b;
    b.encolar(paq("X"));
    b.encolar(paq("Y"));
    b.encolar(paq("Z"));
    b = a;  // b pierde lo que tenía
    assert(b.tamano() == 2);
    a.encolar(paq("C"));  // y es independiente de a
    const char* const deB[] = {"A", "B"};
    sacarEnOrden(b, deB);
    const char* const deA[] = {"A", "B", "C"};
    sacarEnOrden(a, deA);

    Cola vacia;
    a.encolar(paq("Q"));
    a = vacia;  // asignar una vacía la deja vacía
    assert(a.vacia());
}

void autoasignacion()
{
    Cola a;
    a.encolar(paq("A"));
    a.encolar(paq("B"));
    Cola& misma = a;
    a = misma;
    const char* const orden[] = {"A", "B"};
    sacarEnOrden(a, orden);
}

void intercambiar()
{
    Cola a;
    a.encolar(paq("A"));
    Cola b;
    b.encolar(paq("X"));
    b.encolar(paq("Y"));
    a.intercambiar(b);
    const char* const deA[] = {"X", "Y"};
    sacarEnOrden(a, deA);
    const char* const deB[] = {"A"};
    sacarEnOrden(b, deB);
}

void contiene()
{
    Cola c;
    c.encolar(paq("A"));
    c.encolar(paq("B"));
    c.encolar(paq("C"));
    assert(c.contiene("A") && c.contiene("B") && c.contiene("C"));
    assert(!c.contiene("D"));
    assert(!c.contiene(""));
    c.desencolar();
    assert(!c.contiene("A"));
    assert(c.contiene("C"));
}

void imprimirNoCambiaLaCola()
{
    Cola c;
    c.encolar(paq("A"));
    c.encolar(paq("B"));
    std::ostringstream salida;
    std::streambuf* antes = std::cout.rdbuf(salida.rdbuf());
    c.imprimir();
    std::cout.rdbuf(antes);
    const char* const orden[] = {"A", "B"};
    sacarEnOrden(c, orden);
}

void noQuedanObjetosVivos()
{
    const int base = Paquete::vivos();
    {
        Cola a;
        for (int i = 0; i < 10; ++i) {
            a.encolar(paq("P" + std::to_string(i)));
        }
        Cola b(a);
        Cola c;
        c = b;
        c.desencolar();
        a.intercambiar(c);
        // Se destruyen llenas: el destructor debe liberar todos los paquetes.
    }
    assert(Paquete::vivos() == base);
    {
        Cola d;
        d.encolar(paq("A"));
        d.desencolar();
        assert(Paquete::vivos() == base);  // desencolar no deja copias colgando
    }
    assert(Paquete::vivos() == base);
}

const Prueba pruebas[] = {
    {"recienConstruidaVacia", recienConstruidaVacia},
    {"unSoloElemento", unSoloElemento},
    {"saleEnOrdenDeLlegada", saleEnOrdenDeLlegada},
    {"extremos", extremos},
    {"crecerDecrecerYVolverACrecer", crecerDecrecerYVolverACrecer},
    {"copiaIndependiente", copiaIndependiente},
    {"copiaDeVacia", copiaDeVacia},
    {"asignacion", asignacion},
    {"autoasignacion", autoasignacion},
    {"intercambiar", intercambiar},
    {"contiene", contiene},
    {"imprimirNoCambiaLaCola", imprimirNoCambiaLaCola},
    {"noQuedanObjetosVivos", noQuedanObjetosVivos},
};

}  // namespace

int main()
{
    return ejecutarPruebas("Cola", MODULO_IMPLEMENTADO, pruebas);
}
