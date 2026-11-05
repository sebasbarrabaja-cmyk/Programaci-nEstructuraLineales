// Contrato: Maria Fernanda Ticona y Sebastián Mateo · Implementa: Sebastián · Prueba: Maria Fernanda
#ifndef RUTA_HPP
#define RUTA_HPP

#include <string>

#include "listaContigua.hpp"
#include "listaEnlazada.hpp"

// Implementación de la ruta, elegida al arrancar (./reparto contigua | ./reparto enlazada).
enum class TipoRuta { Contigua, Enlazada };

// Ruta: la ruta del día, una secuencia de paradas que se modifica por el medio. Guarda las
//             paradas en la lista del tipo elegido al construirla y le pasa cada operación con un if.
// Invariante: tipo_ no cambia nunca; solo se usa la lista de tipo_ (la otra está siempre vacía).
// Copia y memoria: no gestiona memoria propia; copia, asignación y destrucción las hacen las
//             listas miembro, que tienen regla de tres. Copia y original son independientes.
// Qué NO hace: no cambia de tipo, no aplica reglas del negocio (duplicados, anulaciones,
//             mensajes OK/ERROR: eso es Centro), no añade comprobaciones: las precondiciones
//             y los costes son los de la lista elegida.
// Costes:        Contigua            Enlazada
//   at(i)        O(1)                O(i)
//   insertar(i)  O(n - i)            O(i)
//   borrar(i)    O(n - i)            O(i)
//   anadirAlFinal O(1) amortizado    O(1)
//   buscar       O(n)                O(n)
class Ruta {
public:
    // Ruta vacía del tipo indicado. O(1).
    explicit Ruta(TipoRuta tipo);
    // El tipo elegido al construir. O(1).
    TipoRuta tipo() const;

    // Número de paradas. O(1).
    int tam() const;
    // ¿tam() == 0? O(1).
    bool vacia() const;
    // Pre: 0 <= i < tam(). La parada en la posición i. Contigua O(1), Enlazada O(i).
    const std::string& at(int i) const;                  
    // Pre: 0 <= i <= tam(). Inserta en la posición i. Contigua O(n - i), Enlazada O(i).
    void insertar(int i, const std::string& parada);     
    // Inserta al final. Contigua O(1) amortizado, Enlazada O(1).
    void anadirAlFinal(const std::string& parada);
    // Pre: 0 <= i < tam(). Quita la posición i. Contigua O(n - i), Enlazada O(i).
    void borrar(int i);                                  
    // Posición de la primera aparición, o -1 si no está. O(n).
    int buscar(const std::string& parada) const;         
    // Deja la ruta sin paradas. O(n).
    void vaciar();

private:
    TipoRuta tipo_;
    ListaContigua contigua_;
    ListaEnlazada enlazada_;
};

#endif
