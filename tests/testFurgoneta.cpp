// Esqueleto creado por Sebastián Mateo; la escribe María Fernanda
// Pruebas de Furgoneta (include/furgoneta.hpp).
#include "furgoneta.hpp"
#include "paquete.hpp"
#include "prueba.hpp"

// Pasa a true cuando se fusionen modulo/pila y modulo/furgoneta y el esqueleto esté escrito.
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

void recienConstruidaVaciaYSinCapacidad()
{
    PENDIENTE_DE_ESCRIBIR();
}

void fijarCapacidad()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cabeJustoEnElLimite()
{
    PENDIENTE_DE_ESCRIBIR();
}

void noCabeSiSePasa()
{
    PENDIENTE_DE_ESCRIBIR();
}

void unSoloPaquete()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cargarSumaPesoYDescargarLoResta()
{
    PENDIENTE_DE_ESCRIBIR();
}

void siguienteEsElUltimoCargado()
{
    PENDIENTE_DE_ESCRIBIR();
}

void pesoVuelveACeroAlVaciarse()
{
    PENDIENTE_DE_ESCRIBIR();
}

void crecerDecrecerYVolverACrecer()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contiene()
{
    PENDIENTE_DE_ESCRIBIR();
}

void copiaIndependiente()
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

void imprimirNoCambiaLaFurgoneta()
{
    PENDIENTE_DE_ESCRIBIR();
}

void noQuedanObjetosVivos()
{
    PENDIENTE_DE_ESCRIBIR();
}

const Prueba pruebas[] = {
    {"recienConstruidaVaciaYSinCapacidad", recienConstruidaVaciaYSinCapacidad},
    {"fijarCapacidad", fijarCapacidad},
    {"cabeJustoEnElLimite", cabeJustoEnElLimite},
    {"noCabeSiSePasa", noCabeSiSePasa},
    {"unSoloPaquete", unSoloPaquete},
    {"cargarSumaPesoYDescargarLoResta", cargarSumaPesoYDescargarLoResta},
    {"siguienteEsElUltimoCargado", siguienteEsElUltimoCargado},
    {"pesoVuelveACeroAlVaciarse", pesoVuelveACeroAlVaciarse},
    {"crecerDecrecerYVolverACrecer", crecerDecrecerYVolverACrecer},
    {"contiene", contiene},
    {"copiaIndependiente", copiaIndependiente},
    {"asignacion", asignacion},
    {"autoasignacion", autoasignacion},
    {"imprimirNoCambiaLaFurgoneta", imprimirNoCambiaLaFurgoneta},
    {"noQuedanObjetosVivos", noQuedanObjetosVivos},
};

}  // namespace

int main()
{
    return ejecutarPruebas("Furgoneta", MODULO_IMPLEMENTADO, pruebas);
}
