# Autores: Maria Fernanda Ticona y Sebastián Mateo
#
#   make          construye ./reparto con la línea oficial del enunciado
#   make test     construye y pasa todas las baterías de tests/
#   make san      pruebas con el detector de fugas activado
#   make clean    borra todo lo generado

CXX      := c++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Wshadow -g -fsanitize=address
CPPFLAGS := -Iinclude

MODULOS  := paquete cola pila listaContigua listaEnlazada ruta furgoneta centro interprete
OBJ      := $(MODULOS:%=build/%.o)
CABECERAS := $(wildcard include/*.hpp)

PRUEBAS  := testPaquete testCola testPila testLista testFurgoneta testCentro testInterprete
BIN_PRUEBAS := $(PRUEBAS:%=build/%)

.PHONY: all test san clean

all: reparto

reparto: $(OBJ) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp $(CABECERAS) | build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

build/test%: tests/test%.cpp $(OBJ) | build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< $(OBJ) -o $@

build:
	mkdir -p build

test: $(BIN_PRUEBAS)
	@for t in $(BIN_PRUEBAS); do \
	    echo "== $$t"; \
	    ./$$t || { echo "FALLA: $$t"; exit 1; }; \
	done
	@echo "== Todas las baterías pasan."

san: reparto $(BIN_PRUEBAS)
	@for t in $(BIN_PRUEBAS); do \
	    ASAN_OPTIONS=detect_leaks=1 ./$$t > /dev/null || { echo "FALLA (san): $$t"; exit 1; }; \
	done
	@echo "== Pruebas limpias con el detector de memoria."

clean:
	rm -rf build reparto
