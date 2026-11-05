// Autor: Sebastián Mateo (recibir, fijarRuta, insertarParada, anularParada, consultarPosicion, estado)
// Esqueleto creado por Sebastián Mateo; la escribe María Fernanda (fijarCapacidad, cargar, entregar,
// fallo, cerrarDia, nuevoDia).
// Pruebas de Centro (include/centro.hpp). Prueba cruzada: cada uno escribe las de los
// métodos que implementa el otro.
#include "centro.hpp"
#include "paquete.hpp"
#include "ruta.hpp"
#include "prueba.hpp"

// Pasa a true cuando estén fusionadas las dos mitades de Centro (y los módulos que usa).
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

// ---- Métodos de María Fernanda (las escribe Sebastián)

void recienConstruidoDia1YTodoVacio()
{
    PENDIENTE_DE_ESCRIBIR();
}

void recibirVaALaCinta()
{
    PENDIENTE_DE_ESCRIBIR();
}

void recibirKilosNoPositivosEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void recibirIdRepetidoEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void recibirConservaElOrdenDeLlegada()
{
    PENDIENTE_DE_ESCRIBIR();
}

void fijarRutaSustituyeLaAnterior()
{
    PENDIENTE_DE_ESCRIBIR();
}

void fijarRutaConParadaRepetidaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void insertarParadaAlPrincipioEnMedioYAlFinal()
{
    PENDIENTE_DE_ESCRIBIR();
}

void insertarParadaFueraDeRangoEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void insertarParadaRepetidaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void anularParadaExistente()
{
    PENDIENTE_DE_ESCRIBIR();
}

void anularParadaInexistenteEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void consultarPosicionExistente()
{
    PENDIENTE_DE_ESCRIBIR();
}

void consultarPosicionInexistenteEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void estadoNoCambiaNada()
{
    PENDIENTE_DE_ESCRIBIR();
}


// ---- Métodos de Sebastián (las escribe María Fernanda)

void fijarCapacidadValida()
{
    PENDIENTE_DE_ESCRIBIR();
}

void fijarCapacidadNoPositivaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void fijarCapacidadConCargaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cargarEnOrdenInversoALaRuta()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cargarRespetaElLimiteDePeso()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cargarDejaEnLaCintaLoNoCargadoEnSuOrden()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cargarConFurgonetaOcupadaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void entregarEnOrdenDeRutaSinMoverOtros()
{
    PENDIENTE_DE_ESCRIBIR();
}

void entregarConFurgonetaVaciaEsError()
{
    PENDIENTE_DE_ESCRIBIR();
}

void falloPasaAReentregas()
{
    PENDIENTE_DE_ESCRIBIR();
}

void paqueteDeParadaAnuladaVuelveAReentregas()
{
    PENDIENTE_DE_ESCRIBIR();
}

void cerrarDiaResume()
{
    PENDIENTE_DE_ESCRIBIR();
}

void nuevoDiaReentregasAntesQueNuevosEnOrdenDeFallo()
{
    PENDIENTE_DE_ESCRIBIR();
}

void nuevoDiaVaciaRutaYContadoresYAvanzaElDia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void noQuedanObjetosVivos()
{
    PENDIENTE_DE_ESCRIBIR();
}

const Prueba pruebas[] = {
    {"recienConstruidoDia1YTodoVacio", recienConstruidoDia1YTodoVacio},
    {"recibirVaALaCinta", recibirVaALaCinta},
    {"recibirKilosNoPositivosEsError", recibirKilosNoPositivosEsError},
    {"recibirIdRepetidoEsError", recibirIdRepetidoEsError},
    {"recibirConservaElOrdenDeLlegada", recibirConservaElOrdenDeLlegada},
    {"fijarRutaSustituyeLaAnterior", fijarRutaSustituyeLaAnterior},
    {"fijarRutaConParadaRepetidaEsError", fijarRutaConParadaRepetidaEsError},
    {"insertarParadaAlPrincipioEnMedioYAlFinal", insertarParadaAlPrincipioEnMedioYAlFinal},
    {"insertarParadaFueraDeRangoEsError", insertarParadaFueraDeRangoEsError},
    {"insertarParadaRepetidaEsError", insertarParadaRepetidaEsError},
    {"anularParadaExistente", anularParadaExistente},
    {"anularParadaInexistenteEsError", anularParadaInexistenteEsError},
    {"consultarPosicionExistente", consultarPosicionExistente},
    {"consultarPosicionInexistenteEsError", consultarPosicionInexistenteEsError},
    {"estadoNoCambiaNada", estadoNoCambiaNada},
    {"fijarCapacidadValida", fijarCapacidadValida},
    {"fijarCapacidadNoPositivaEsError", fijarCapacidadNoPositivaEsError},
    {"fijarCapacidadConCargaEsError", fijarCapacidadConCargaEsError},
    {"cargarEnOrdenInversoALaRuta", cargarEnOrdenInversoALaRuta},
    {"cargarRespetaElLimiteDePeso", cargarRespetaElLimiteDePeso},
    {"cargarDejaEnLaCintaLoNoCargadoEnSuOrden", cargarDejaEnLaCintaLoNoCargadoEnSuOrden},
    {"cargarConFurgonetaOcupadaEsError", cargarConFurgonetaOcupadaEsError},
    {"entregarEnOrdenDeRutaSinMoverOtros", entregarEnOrdenDeRutaSinMoverOtros},
    {"entregarConFurgonetaVaciaEsError", entregarConFurgonetaVaciaEsError},
    {"falloPasaAReentregas", falloPasaAReentregas},
    {"paqueteDeParadaAnuladaVuelveAReentregas", paqueteDeParadaAnuladaVuelveAReentregas},
    {"cerrarDiaResume", cerrarDiaResume},
    {"nuevoDiaReentregasAntesQueNuevosEnOrdenDeFallo", nuevoDiaReentregasAntesQueNuevosEnOrdenDeFallo},
    {"nuevoDiaVaciaRutaYContadoresYAvanzaElDia", nuevoDiaVaciaRutaYContadoresYAvanzaElDia},
    {"noQuedanObjetosVivos", noQuedanObjetosVivos},
};

}  // namespace

int main()
{
    return ejecutarPruebas("Centro", MODULO_IMPLEMENTADO, pruebas);
}
