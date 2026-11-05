// Autor: Sebastián Mateo
// Pruebas de Interprete (include/interprete.hpp). Esqueleto: se escriben cuando el
// módulo de María Fernanda esté fusionado.
#include "interprete.hpp"
#include "centro.hpp"
#include "ruta.hpp"
#include "prueba.hpp"

// Pasa a true cuando María Fernanda fusione Interprete (y Centro esté completo).
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

void lineaVaciaNoHaceNada()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ordenDesconocidaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void recibirConArgumentos()
{
    PENDIENTE_DE_ESCRIBIR();
}

void recibirConArgumentosMalFormadosEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ruta()
{
    PENDIENTE_DE_ESCRIBIR();
}

void insertar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void anular()
{
    PENDIENTE_DE_ESCRIBIR();
}

void posicion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void furgoneta()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cargar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void entregar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void fallo()
{
    PENDIENTE_DE_ESCRIBIR();
}

void estado()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cerrarDia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void nuevoDia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ejecutarLeeHastaElFinDeLaEntrada()
{
    PENDIENTE_DE_ESCRIBIR();
}

const Prueba pruebas[] = {
    {"lineaVaciaNoHaceNada", lineaVaciaNoHaceNada},
    {"ordenDesconocidaEsError", ordenDesconocidaEsError},
    {"recibirConArgumentos", recibirConArgumentos},
    {"recibirConArgumentosMalFormadosEsError", recibirConArgumentosMalFormadosEsError},
    {"ruta", ruta},
    {"insertar", insertar},
    {"anular", anular},
    {"posicion", posicion},
    {"furgoneta", furgoneta},
    {"cargar", cargar},
    {"entregar", entregar},
    {"fallo", fallo},
    {"estado", estado},
    {"cerrarDia", cerrarDia},
    {"nuevoDia", nuevoDia},
    {"ejecutarLeeHastaElFinDeLaEntrada", ejecutarLeeHastaElFinDeLaEntrada},
};

}  // namespace

int main()
{
    return ejecutarPruebas("Interprete", MODULO_IMPLEMENTADO, pruebas);
}
