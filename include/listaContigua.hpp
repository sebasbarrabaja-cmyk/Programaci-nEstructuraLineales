// Contrato: Maria Fernanda Ticona y Sebastián Mateo | Implementa: Sebastián | Prueba: Maria Fernanda
#ifndef LISTA_CONTIGUA_HPP
#define LISTA_CONTIGUA_HPP

#include <string>

class ListaContigua {
public:
    ListaContigua();
    ListaContigua(const ListaContigua& otra);
    ListaContigua& operator=(ListaContigua otra);
    ~ListaContigua();
    void intercambiar(ListaContigua& otra);     

    int tam() const;
    bool vacia() const;
    const std::string& at(int i) const;                  
    void insertar(int i, const std::string& parada);     
    void anadirAlFinal(const std::string& parada);
    void borrar(int i);                                  
    int buscar(const std::string& parada) const;         
    void vaciar();
    int capacidad() const;                               

private:
    std::string* datos_;
    int n_;
    int capacidad_;
    void crecer();                                       
};

#endif
