// Esqueleto creado por Sebastián Mateo; la escribe María Fernanda
// Pruebas de Pila (include/pila.hpp).
#include "pila.hpp"
#include "paquete.hpp"
#include "prueba.hpp"

// Pasa a true cuando se fusione modulo/pila y el esqueleto esté escrito.
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

void recienConstruidaVacia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void unSoloElementoCimaYFondoCoinciden()
{
    PENDIENTE_DE_ESCRIBIR();
}

void saleElUltimoQueEntro()
{
    PENDIENTE_DE_ESCRIBIR();
}

void extremosCimaTrasApilarYDesapilar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void crecerDecrecerYVolverACrecer()
{
    PENDIENTE_DE_ESCRIBIR();
}

void copiaIndependienteYMismoOrden()
{
    PENDIENTE_DE_ESCRIBIR();
}

void copiaDeVacia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void asignacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void autoasignacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void intercambiar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contiene()
{
    PENDIENTE_DE_ESCRIBIR();
}

void imprimirNoCambiaLaPila()
{
    PENDIENTE_DE_ESCRIBIR();
}

void noQuedanObjetosVivos()
{
    PENDIENTE_DE_ESCRIBIR();
}

const Prueba pruebas[] = {
    {"recienConstruidaVacia", recienConstruidaVacia},
    {"unSoloElementoCimaYFondoCoinciden", unSoloElementoCimaYFondoCoinciden},
    {"saleElUltimoQueEntro", saleElUltimoQueEntro},
    {"extremosCimaTrasApilarYDesapilar", extremosCimaTrasApilarYDesapilar},
    {"crecerDecrecerYVolverACrecer", crecerDecrecerYVolverACrecer},
    {"copiaIndependienteYMismoOrden", copiaIndependienteYMismoOrden},
    {"copiaDeVacia", copiaDeVacia},
    {"asignacion", asignacion},
    {"autoasignacion", autoasignacion},
    {"intercambiar", intercambiar},
    {"contiene", contiene},
    {"imprimirNoCambiaLaPila", imprimirNoCambiaLaPila},
    {"noQuedanObjetosVivos", noQuedanObjetosVivos},
};

}  // namespace

int main()
{
    return ejecutarPruebas("Pila", MODULO_IMPLEMENTADO, pruebas);
}
