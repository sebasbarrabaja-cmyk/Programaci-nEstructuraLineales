// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>
#include <string>

#include "paquete.hpp"

class Pila {
public:
    Pila();                                    
    Pila(const Pila& otra);                    
    Pila& operator=(Pila otra);               
    ~Pila();                                   
    void intercambiar(Pila& otra);             

    bool vacia() const;                        
    int tamano() const;                        
    void apilar(const Paquete& p);             
    Paquete desapilar();                       
    const Paquete& cima() const;               
    bool contiene(const std::string& id) const;     
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
