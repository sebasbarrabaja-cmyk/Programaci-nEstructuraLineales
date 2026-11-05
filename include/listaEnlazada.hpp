// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef LISTA_ENLAZADA_HPP
#define LISTA_ENLAZADA_HPP

#include <string>

class ListaEnlazada {
public:
    ListaEnlazada();
    ListaEnlazada(const ListaEnlazada& otra);
    ListaEnlazada& operator=(ListaEnlazada otra);
    ~ListaEnlazada();
    void intercambiar(ListaEnlazada& otra);     

    int tam() const;
    bool vacia() const;
    const std::string& at(int i) const;                  
    void insertar(int i, const std::string& parada);     
    void anadirAlFinal(const std::string& parada);
    void borrar(int i);                                  
    int buscar(const std::string& parada) const;         
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
