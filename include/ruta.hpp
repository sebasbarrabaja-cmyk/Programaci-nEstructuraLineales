// Contrato: Maria Fernanda Ticona y Sebastián Mateo · Implementa: Sebastián · Prueba: Maria Fernanda
#ifndef RUTA_HPP
#define RUTA_HPP

#include <string>

#include "listaContigua.hpp"
#include "listaEnlazada.hpp"

enum class TipoRuta { Contigua, Enlazada };

class Ruta {
public:
    explicit Ruta(TipoRuta tipo);
    TipoRuta tipo() const;

    int tam() const;
    bool vacia() const;
    const std::string& at(int i) const;                  
    void insertar(int i, const std::string& parada);     
    void anadirAlFinal(const std::string& parada);
    void borrar(int i);                                  
    int buscar(const std::string& parada) const;         
    void vaciar();

private:
    TipoRuta tipo_;
    ListaContigua contigua_;
    ListaEnlazada enlazada_;
};

#endif
