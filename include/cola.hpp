// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Maria Fernanda | Prueba: Sebastián
#ifndef COLA_HPP
#define COLA_HPP

#include <iostream>
#include <string>

#include "paquete.hpp"

class Cola {
public:
    Cola();                                    
    Cola(const Cola& otra);                    
    Cola& operator=(Cola otra);               
    ~Cola();                                   
    void intercambiar(Cola& otra);              

    bool vacia() const;                        
    int tamano() const;                        
    void encolar(const Paquete& p);            
    Paquete desencolar();                      
    const Paquete& frente() const;             
    bool contiene(const std::string& id) const;     
    void imprimir() const;                          

private:
    struct Nodo {
        Paquete dato;
        Nodo* sig;
    };
    Nodo* primero_;
    Nodo* ultimo_;
    int tamano_;
};

#endif
