// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef FURGONETA_HPP
#define FURGONETA_HPP

#include <iostream>
#include <string>

#include "paquete.hpp"
#include "pila.hpp"

// Furgoneta: una pila de paquetes con límite de peso. Se carga y se descarga por detrás:
//             el siguiente en salir es el último que se cargó.
// Invariante: 0 <= peso_ <= capacidad_ (con tolerancia de redondeo 1e-9);
//             peso_ es la suma de los kilos de carga_ (exactamente 0 si está vacía);
//             capacidad_ vale 0 hasta fijarCapacidad, así que antes no cabe nada.
// Copia y memoria: no gestiona memoria directamente; la Pila carga_ tiene regla de tres, así
//             que copia, asignación y destructor por defecto dan copias independientes.
// Qué NO hace: no decide el orden de carga (el orden inverso a la ruta lo pone Centro::cargar),
//             no busca por parada, no saca paquetes del medio, no imprime OK/ERROR,
//             no lanza excepciones (precondiciones con assert).
// Costes: O(1) salvo copiar, contiene e imprimir, que son O(n).
class Furgoneta {
public:
    // Vacía y con capacidad 0. O(1).
    Furgoneta();                               

    // Límite de peso en kilos. O(1).
    double capacidad() const;                  
    // Kilos que lleva ahora. O(1).
    double peso() const;                       
    // Pre: kilos > 0 y vacia(). Fija el límite de peso. O(1).
    void fijarCapacidad(double kilos);         
    // ¿peso() + kilos <= capacidad()? O(1).
    bool cabe(double kilos) const;             
    // Pre: cabe(p.kilos()). Mete una copia de p detrás (pasa a ser el siguiente). O(1).
    void cargar(const Paquete& p);             
    // ¿No lleva ningún paquete? O(1).
    bool vacia() const;                        
    // Número de paquetes a bordo. O(1).
    int numPaquetes() const;                   
    // Pre: !vacia(). El paquete que sale a continuación, sin sacarlo. O(1).
    const Paquete& siguiente() const;          
    // Pre: !vacia(). Saca y devuelve el siguiente y descuenta su peso. O(1).
    Paquete descargar();                       
    // ¿Lleva un paquete con ese id? O(n).
    bool contiene(const std::string& id) const;     
    // Peso, capacidad y una línea por paquete, el siguiente arriba. O(n).
    void imprimir() const;                          

private:
    double capacidad_;
    double peso_;
    Pila carga_;
};

#endif
