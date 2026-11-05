// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementan y prueban: los dos (ver docs/02)
#ifndef CENTRO_HPP
#define CENTRO_HPP

#include <iostream>
#include <string>

#include "cola.hpp"
#include "furgoneta.hpp"
#include "ruta.hpp"

class Centro {
public:
    explicit Centro(TipoRuta tipo);

    bool fijarCapacidad(double kilos);                                            // FURGONETA
    bool recibir(const std::string& id, const std::string& parada, double kilos); // RECIBIR
    bool fijarRuta(const Ruta& paradas);                                          // RUTA
    bool insertarParada(const std::string& parada, int posicion);                 // INSERTAR 
    bool anularParada(const std::string& parada);                                 // ANULAR
    bool consultarPosicion(const std::string& parada) const;                      // POSICION
    bool cargar();                                                                // CARGAR
    bool entregar();                                                              // ENTREGAR
    bool fallo();                                                                 // FALLO
    void estado() const;                                                          // ESTADO
    bool cerrarDia();                                                             // CERRAR DIA
    void nuevoDia();                                                              // NUEVO DIA

    // Consultas para las pruebas
    int dia() const;
    int enCinta() const;
    int enFurgoneta() const;
    int enReentregas() const;
    int paradasEnRuta() const;
    int entregadosHoy() const;
    int fallidosHoy() const;

private:
    Ruta ruta_;
    Cola cinta_;
    Furgoneta furgoneta_;
    Cola reentregas_;
    int dia_;
    bool cerrado_;
    int entregados_;
    int fallidos_;
};

#endif
