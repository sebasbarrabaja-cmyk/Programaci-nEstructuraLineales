// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef LISTA_CONTIGUA_HPP
#define LISTA_CONTIGUA_HPP

#include <string>

// ListaContigua: secuencia de paradas por posición (0 .. tam()-1) sobre un bloque contiguo que crece.
// Invariante: 0 <= n_ <= capacidad_; datos_ == nullptr <=> capacidad_ == 0;
//             los elementos son datos_[0 .. n_-1], en orden.
// Crecimiento: empieza con capacidad 0; la primera inserción pide un bloque de 4 y, cada vez
//             que se llena, se duplica (4, 8, 16, ...). Nunca encoge: ni borrar ni vaciar
//             devuelven memoria.
// Copia y memoria: posee el bloque (new[]/delete[]). La copia es profunda, con la misma
//             capacidad; la asignación es por copia e intercambio; el destructor libera el bloque.
//             Copia y original son independientes.
// Qué NO hace: no comprueba duplicados, no ordena, no encoge el bloque, no lanza excepciones:
//             un índice fuera de rango es un error de programa (assert).
class ListaContigua {
public:
    // Lista vacía, capacidad 0, sin bloque. O(1).
    ListaContigua();
    // Copia profunda (misma capacidad). O(n).
    ListaContigua(const ListaContigua& otra);
    // Copia e intercambio. O(n).
    ListaContigua& operator=(ListaContigua otra);
    // Libera el bloque. O(n).
    ~ListaContigua();
    // Intercambia el contenido con otra sin copiar elementos. O(1).
    void intercambiar(ListaContigua& otra);     

    // Número de paradas. O(1).
    int tam() const;
    // ¿tam() == 0? O(1).
    bool vacia() const;
    // Pre: 0 <= i < tam(). La parada en la posición i. O(1).
    const std::string& at(int i) const;                  
    // Pre: 0 <= i <= tam(). Inserta en la posición i desplazando [i, tam()) una a la
    // derecha; crece si está lleno. O(n - i) (más O(n) cuando crece).
    void insertar(int i, const std::string& parada);     
    // Inserta al final. O(1) amortizado.
    void anadirAlFinal(const std::string& parada);
    // Pre: 0 <= i < tam(). Quita la posición i desplazando el resto a la izquierda. O(n - i).
    void borrar(int i);                                  
    // Posición de la primera aparición, o -1 si no está. O(n).
    int buscar(const std::string& parada) const;         
    // Deja tam() == 0 y conserva la capacidad. O(n).
    void vaciar();
    // Tamaño del bloque reservado (0, 4, 8, ...). O(1).
    int capacidad() const;                               

private:
    std::string* datos_;
    int n_;
    int capacidad_;
    // Bloque nuevo del doble (4 si era 0), copia y libera el viejo. O(n).
    void crecer();                                       
};

#endif
