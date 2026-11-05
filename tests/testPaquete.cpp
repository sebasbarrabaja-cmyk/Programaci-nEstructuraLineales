// Autor: Sebastián Mateo
// Pruebas de Paquete escritas leyendo solo include/paquete.hpp.
#include "paquete.hpp"
#include "prueba.hpp"

#include <sstream>
#include <string>

// Pasa a true cuando María Fernanda fusione su implementación de Paquete.
constexpr bool MODULO_IMPLEMENTADO = false;

namespace {

void construidoGuardaSusDatos()
{
    Paquete p("P1", "Plaza Mayor", 2.5);
    assert(p.id() == "P1");
    assert(p.parada() == "Plaza Mayor");
    assert(p.kilos() == 2.5);
}

void datosEnLosExtremos()
{
    Paquete ligero("L", "A", 0.001);
    assert(ligero.kilos() == 0.001);
    Paquete pesado("H", "B", 1000.0);
    assert(pesado.kilos() == 1000.0);
    const std::string idLargo(200, 'x');
    Paquete largo(idLargo, "Parada con espacios", 1.0);
    assert(largo.id() == idLargo);
    assert(largo.parada() == "Parada con espacios");
}

void copiaIndependiente()
{
    Paquete original("P1", "Norte", 1.0);
    Paquete copia(original);
    assert(copia.id() == "P1" && copia.parada() == "Norte" && copia.kilos() == 1.0);

    Paquete otro("P2", "Sur", 3.0);
    copia = otro;  // cambiar la copia no toca el original
    assert(copia.id() == "P2" && copia.parada() == "Sur" && copia.kilos() == 3.0);
    assert(original.id() == "P1" && original.parada() == "Norte" && original.kilos() == 1.0);
}

void asignacion()
{
    Paquete a("A", "Este", 1.5);
    Paquete b("B", "Oeste", 4.0);
    b = a;
    assert(b.id() == "A" && b.parada() == "Este" && b.kilos() == 1.5);
    assert(a.id() == "A" && a.parada() == "Este" && a.kilos() == 1.5);
}

void autoasignacion()
{
    Paquete a("A", "Este", 1.5);
    Paquete& mismo = a;
    a = mismo;
    assert(a.id() == "A" && a.parada() == "Este" && a.kilos() == 1.5);
}

void imprimirNoCambiaNadaYEscribeAlgo()
{
    Paquete p("P1", "Centro", 2.0);
    std::ostringstream salida;
    std::streambuf* antes = std::cout.rdbuf(salida.rdbuf());
    p.imprimir();
    std::cout.rdbuf(antes);
    assert(!salida.str().empty());
    assert(p.id() == "P1" && p.parada() == "Centro" && p.kilos() == 2.0);
}

void vivosCuentaCadaObjeto()
{
    const int base = Paquete::vivos();
    {
        Paquete a("A", "X", 1.0);
        assert(Paquete::vivos() == base + 1);
        Paquete b(a);
        assert(Paquete::vivos() == base + 2);
        b = a;  // asignar no crea ni destruye paquetes
        assert(Paquete::vivos() == base + 2);
    }
    assert(Paquete::vivos() == base);
}

void noQuedanObjetosVivos()
{
    const int base = Paquete::vivos();
    {
        Paquete a("A", "X", 1.0);
        Paquete b("B", "Y", 2.0);
        Paquete c(a);
        c = b;
        a = c;
    }
    assert(Paquete::vivos() == base);
}

const Prueba pruebas[] = {
    {"construidoGuardaSusDatos", construidoGuardaSusDatos},
    {"datosEnLosExtremos", datosEnLosExtremos},
    {"copiaIndependiente", copiaIndependiente},
    {"asignacion", asignacion},
    {"autoasignacion", autoasignacion},
    {"imprimirNoCambiaNadaYEscribeAlgo", imprimirNoCambiaNadaYEscribeAlgo},
    {"vivosCuentaCadaObjeto", vivosCuentaCadaObjeto},
    {"noQuedanObjetosVivos", noQuedanObjetosVivos},
};

}  // namespace

int main()
{
    return ejecutarPruebas("Paquete", MODULO_IMPLEMENTADO, pruebas);
}
