// Autora: Maria Fernanda Ticona
#include <iostream>
#include <string>

#include "centro.hpp"
#include "interprete.hpp"

int main(int argc, char* argv[])
{
    TipoRuta tipo = TipoRuta::Contigua;
    if (argc == 2 && std::string(argv[1]) == "enlazada") {
        tipo = TipoRuta::Enlazada;
    } else if (argc > 2 || (argc == 2 && std::string(argv[1]) != "contigua")) {
        std::cerr << "uso: " << argv[0] << " [contigua|enlazada]\n";
        return 1;
    }

    Centro centro(tipo);
    Interprete interprete(centro);
    interprete.ejecutar();
    return 0;
}
