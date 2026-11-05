// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <string>

#include "paquete.hpp"

// Pila: el interior de la furgoneta. Solo se puede coger el último paquete que entró (LIFO).
// Representación: nodos simplemente enlazados; cima_ apunta al último apilado.
// Invariante: tamano_ es el número de nodos alcanzables desde cima_;
//             vacia() <=> cima_ == nullptr <=> tamano_ == 0.
// Copia y memoria: la pila posee sus nodos (new/delete). La copia es profunda y conserva el
//             orden; la asignación es por copia e intercambio (segura ante autoasignación);
//             el destructor libera todos los nodos. Copia y original son independientes.
// Qué NO hace: no limita peso ni número de paquetes (eso es Furgoneta), no deja ver ni quitar
//             nada que no sea la cima, no ordena, no lanza excepciones (precondiciones con assert).
// Costes: O(1) salvo copiar, destruir, contiene e imprimir, que son O(n).
class Pila {
public:
    // Pila vacía. O(1).
    Pila();                                    
    // Copia profunda con el mismo orden. O(n).
    Pila(const Pila& otra);                    
    // Copia e intercambio; lo anterior se libera al salir. O(n).
    Pila& operator=(Pila otra);               
    // Libera todos los nodos. O(n).
    ~Pila();                                   
    // Intercambia el contenido con otra sin copiar paquetes. O(1).
    void intercambiar(Pila& otra);             

    // ¿No hay ningún paquete? O(1).
    bool vacia() const;                        
    // Número de paquetes. O(1).
    int tamano() const;                        
    // Guarda una copia de p en la cima. O(1).
    void apilar(const Paquete& p);             
    // Pre: !vacia(). Quita la cima y la devuelve. O(1).
    Paquete desapilar();                       
    // Pre: !vacia(). El paquete de la cima, sin quitarlo; la referencia
    // vale hasta la siguiente modificación de la pila. O(1).
    const Paquete& cima() const;               
    // ¿Hay algún paquete con ese id? O(n).
    bool contiene(const std::string& id) const;     
    // Una línea por paquete en std::cout, de la cima hacia abajo. O(n).
    void imprimir() const;                          

private:
    struct Nodo {
        Paquete dato;
        Nodo* sig;
    };
    Nodo* cima_;
    int tamano_;
};

#endif
