// Autor: Sebastián Mateo
// Mini-arnés de pruebas: cada batería declara un array de Prueba (nombre + función) y
// llama a ejecutarPruebas. Las comprobaciones se hacen con assert: la primera que falla
// aborta el programa y `make test` se detiene en esa batería.
#ifndef PRUEBA_HPP
#define PRUEBA_HPP

#include <cassert>
#include <iostream>

#ifdef NDEBUG
#error "Las pruebas usan assert: no compiles con NDEBUG"
#endif

// Marca un caso nombrado que todavía no tiene cuerpo. Si la batería se activa sin haberlo
// escrito, falla a propósito.
#define PENDIENTE_DE_ESCRIBIR() assert(false && "prueba sin escribir")

struct Prueba {
    const char* nombre;
    void (*funcion)();
};

// Si el módulo aún no está implementado (bandera MODULO_IMPLEMENTADO del fichero a false),
// no ejecuta nada: informa de cuántas pruebas esperan y devuelve 0.
// Si está implementado, las ejecuta en orden e informa de cada una.
template <int N>
int ejecutarPruebas(const char* modulo, bool implementado, const Prueba (&pruebas)[N])
{
    if (!implementado) {
        std::cout << "[PENDIENTE] " << modulo << ": " << N << " pruebas sin activar\n";
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        std::cout << "  " << pruebas[i].nombre << " ... " << std::flush;
        pruebas[i].funcion();
        std::cout << "ok\n";
    }
    std::cout << "[OK] " << modulo << ": " << N << " pruebas pasan\n";
    return 0;
}

#endif
