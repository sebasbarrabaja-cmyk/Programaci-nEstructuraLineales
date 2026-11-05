// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef LISTA_ENLAZADA_HPP
#define LISTA_ENLAZADA_HPP

#include <string>

// ListaEnlazada: la misma secuencia de paradas y la misma interfaz que ListaContigua, sobre
//             nodos simplemente enlazados con puntero al primero y al último.
// Invariante: n_ es el número de nodos alcanzables desde primero_;
//             n_ == 0 <=> primero_ == nullptr <=> ultimo_ == nullptr;
//             si n_ > 0, ultimo_ es el nodo cuyo sig es nullptr.
// Copia y memoria: posee sus nodos (new/delete). La copia es profunda y conserva el orden; la
//             asignación es por copia e intercambio; el destructor libera todos los nodos.
//             Copia y original son independientes.
// Qué NO hace: no comprueba duplicados, no ordena, no tiene capacidad, no lanza excepciones:
//             un índice fuera de rango es un error de programa (assert).
class ListaEnlazada {
public:
    // Lista vacía. O(1).
    ListaEnlazada();
    // Copia profunda con el mismo orden. O(n).
    ListaEnlazada(const ListaEnlazada& otra);
    // Copia e intercambio. O(n).
    ListaEnlazada& operator=(ListaEnlazada otra);
    // Libera todos los nodos. O(n).
    ~ListaEnlazada();
    // Intercambia el contenido con otra sin copiar elementos. O(1).
    void intercambiar(ListaEnlazada& otra);     

    // Número de paradas. O(1).
    int tam() const;
    // ¿tam() == 0? O(1).
    bool vacia() const;
    // Pre: 0 <= i < tam(). La parada en la posición i. O(i).
    const std::string& at(int i) const;                  
    // Pre: 0 <= i <= tam(). Inserta en la posición i. O(i); O(1) si i == 0 o i == tam().
    void insertar(int i, const std::string& parada);     
    // Inserta al final usando ultimo_. O(1).
    void anadirAlFinal(const std::string& parada);
    // Pre: 0 <= i < tam(). Quita la posición i. O(i).
    void borrar(int i);                                  
    // Posición de la primera aparición, o -1 si no está. O(n).
    int buscar(const std::string& parada) const;         
    // Libera todos los nodos y deja tam() == 0. O(n).
    void vaciar();

private:
    struct Nodo {
        std::string dato;
        Nodo* sig;
    };
    Nodo* primero_;
    Nodo* ultimo_;
    int n_;
};

#endif
