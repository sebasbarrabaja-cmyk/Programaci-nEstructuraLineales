// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef FURGONETA_HPP
#define FURGONETA_HPP

#include <iostream>
#include <string>

#include "paquete.hpp"
#include "pila.hpp"

class Furgoneta {
public:
    Furgoneta();                               

    double capacidad() const;                  
    double peso() const;                       
    void fijarCapacidad(double kilos);         
    bool cabe(double kilos) const;             
    void cargar(const Paquete& p);             
    bool vacia() const;                        
    int numPaquetes() const;                   
    const Paquete& siguiente() const;          
    Paquete descargar();                       
    bool contiene(const std::string& id) const;     
    void imprimir() const;                          

private:
    double capacidad_;
    double peso_;
    Pila carga_;
};

#endif
