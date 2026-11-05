// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Maria Fernanda | Prueba: Sebastián
#ifndef INTERPRETE_HPP
#define INTERPRETE_HPP

#include <iostream>
#include <string>

#include "centro.hpp"

class Interprete {
public:
    explicit Interprete(Centro& centro);
    bool ejecutarLinea(const std::string& linea);   
    void ejecutar();                                

private:
    Centro& centro_;
};

#endif
