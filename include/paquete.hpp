// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Maria Fernanda | Prueba: Sebastián
#ifndef PAQUETE_HPP
#define PAQUETE_HPP

#include <iostream>
#include <string>

class Paquete {
public:
    Paquete(const std::string& id, const std::string& parada, double kilos);
    Paquete(const Paquete& otro);
    Paquete& operator=(const Paquete& otro);
    ~Paquete();

    const std::string& id() const;                            
    const std::string& parada() const;                        
    double kilos() const;                                     
    void imprimir() const;                  
    static int vivos();                     

private:
    std::string id_;
    std::string parada_;
    double kilos_;
    static int vivos_;
};

#endif
