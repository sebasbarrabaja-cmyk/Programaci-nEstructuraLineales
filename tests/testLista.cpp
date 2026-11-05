// Esqueleto creado por Sebastián Mateo; la escribe María Fernanda
// Pruebas de ListaContigua, ListaEnlazada y Ruta (include/listaContigua.hpp,
// include/listaEnlazada.hpp, include/ruta.hpp).
#include "listaContigua.hpp"
#include "listaEnlazada.hpp"
#include "ruta.hpp"
#include "prueba.hpp"

// Pasa a true cuando se fusionen modulo/lista-contigua, modulo/lista-enlazada y
// modulo/ruta y el esqueleto esté escrito.
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

// ---- ListaContigua

void contigua_recienConstruidaVacia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_capacidadEmpiezaEn0YCreceA4YDuplica()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_unSoloElemento()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_insertarAlPrincipioEnMedioYAlFinal()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_borrarAlPrincipioEnMedioYAlFinal()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_atEnLosExtremos()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_buscarPresenteAusenteYRepetida()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_vaciarYReutilizar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_crecerDecrecerYVolverACrecer()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_copiaIndependiente()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_asignacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_autoasignacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void contigua_intercambiar()
{
    PENDIENTE_DE_ESCRIBIR();
}


// ---- ListaEnlazada

void enlazada_recienConstruidaVacia()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_unSoloElemento()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_insertarAlPrincipioEnMedioYAlFinal()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_borrarAlPrincipioEnMedioYAlFinal()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_borrarElUltimoYAnadirDespues()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_atEnLosExtremos()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_buscarPresenteAusenteYRepetida()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_vaciarYReutilizar()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_crecerDecrecerYVolverACrecer()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_copiaIndependiente()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_asignacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_autoasignacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void enlazada_intercambiar()
{
    PENDIENTE_DE_ESCRIBIR();
}


// ---- Ruta

void ruta_guardaElTipoElegido()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ruta_contiguaReenviaCadaOperacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ruta_enlazadaReenviaCadaOperacion()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ruta_ambosTiposDanElMismoResultado()
{
    PENDIENTE_DE_ESCRIBIR();
}

void ruta_copiaIndependiente()
{
    PENDIENTE_DE_ESCRIBIR();
}

const Prueba pruebas[] = {
    {"contigua_recienConstruidaVacia", contigua_recienConstruidaVacia},
    {"contigua_capacidadEmpiezaEn0YCreceA4YDuplica", contigua_capacidadEmpiezaEn0YCreceA4YDuplica},
    {"contigua_unSoloElemento", contigua_unSoloElemento},
    {"contigua_insertarAlPrincipioEnMedioYAlFinal", contigua_insertarAlPrincipioEnMedioYAlFinal},
    {"contigua_borrarAlPrincipioEnMedioYAlFinal", contigua_borrarAlPrincipioEnMedioYAlFinal},
    {"contigua_atEnLosExtremos", contigua_atEnLosExtremos},
    {"contigua_buscarPresenteAusenteYRepetida", contigua_buscarPresenteAusenteYRepetida},
    {"contigua_vaciarYReutilizar", contigua_vaciarYReutilizar},
    {"contigua_crecerDecrecerYVolverACrecer", contigua_crecerDecrecerYVolverACrecer},
    {"contigua_copiaIndependiente", contigua_copiaIndependiente},
    {"contigua_asignacion", contigua_asignacion},
    {"contigua_autoasignacion", contigua_autoasignacion},
    {"contigua_intercambiar", contigua_intercambiar},
    {"enlazada_recienConstruidaVacia", enlazada_recienConstruidaVacia},
    {"enlazada_unSoloElemento", enlazada_unSoloElemento},
    {"enlazada_insertarAlPrincipioEnMedioYAlFinal", enlazada_insertarAlPrincipioEnMedioYAlFinal},
    {"enlazada_borrarAlPrincipioEnMedioYAlFinal", enlazada_borrarAlPrincipioEnMedioYAlFinal},
    {"enlazada_borrarElUltimoYAnadirDespues", enlazada_borrarElUltimoYAnadirDespues},
    {"enlazada_atEnLosExtremos", enlazada_atEnLosExtremos},
    {"enlazada_buscarPresenteAusenteYRepetida", enlazada_buscarPresenteAusenteYRepetida},
    {"enlazada_vaciarYReutilizar", enlazada_vaciarYReutilizar},
    {"enlazada_crecerDecrecerYVolverACrecer", enlazada_crecerDecrecerYVolverACrecer},
    {"enlazada_copiaIndependiente", enlazada_copiaIndependiente},
    {"enlazada_asignacion", enlazada_asignacion},
    {"enlazada_autoasignacion", enlazada_autoasignacion},
    {"enlazada_intercambiar", enlazada_intercambiar},
    {"ruta_guardaElTipoElegido", ruta_guardaElTipoElegido},
    {"ruta_contiguaReenviaCadaOperacion", ruta_contiguaReenviaCadaOperacion},
    {"ruta_enlazadaReenviaCadaOperacion", ruta_enlazadaReenviaCadaOperacion},
    {"ruta_ambosTiposDanElMismoResultado", ruta_ambosTiposDanElMismoResultado},
    {"ruta_copiaIndependiente", ruta_copiaIndependiente},
};

}  // namespace

int main()
{
    return ejecutarPruebas("ListaContigua, ListaEnlazada y Ruta", MODULO_IMPLEMENTADO, pruebas);
}
