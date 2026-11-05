<!-- Autores: Maria Fernanda Ticona y Sebastián Mateo -->
# 02 · Contrato de interfaces

**E1 · 5 de noviembre de 2026** Desde hoy, cambiar algo de `include/` exige una petición de cambio escrita.

El contrato completo de cada módulo (invariante, precondiciones, costes, copia y memoria) está en su cabecera de `include/`

## Módulos y quién usa a quién

```
main → Interprete → Centro ─┬─ Cola (cinta y reentregas) ─┐
                            ├─ Furgoneta → Pila ──────────┼─→ Paquete
                            └─ Ruta ─┬─ ListaContigua
                                     └─ ListaEnlazada
```

## Fichas

| Módulo | Qué representa | Estructura | Implementa | Prueba |
|---|---|---|---|---|
| `Paquete` | Un paquete (id, parada, kilos). Es un valor | — | Maria Fernanda | Sebastián |
| `Cola` | La cinta y las reentregas: salen en el orden en que entraron | Cola enlazada | Maria Fernanda | Sebastián |
| `Pila` | El interior de la furgoneta: solo se coge lo último que entró | Pila enlazada | Sebastián | Maria Fernanda |
| `ListaContigua` | Lista de paradas sobre un bloque que crece | Array dinámico | Sebastián | Maria Fernanda |
| `ListaEnlazada` | Lista de paradas sobre nodos, con la misma interfaz | Lista enlazada | Sebastián | Maria Fernanda |
| `Ruta` | La ruta del día: usa una de las dos listas según el tipo elegido al arrancar | usa las listas | Sebastián | Maria Fernanda |
| `Furgoneta` | Pila + límite de peso | usa Pila | Sebastián | Maria Fernanda |
| `Centro` | Reglas del negocio (una operación por orden) | usa todas | los dos | los dos, cruzado |
| `Interprete` + `main` | Lee órdenes y llama al Centro | — | Maria Fernanda | Sebastián |

**Cómo se elige la lista.** `Ruta` guarda el tipo elegido (`./reparto contigua` o `./reparto enlazada`) y en cada operación llama, con un `if`, a la lista de ese tipo. El Centro solo usa `Ruta`, así que funciona con cualquiera de las dos sin cambiar una línea.

En el Centro, Maria Fernanda implementa `recibir`, `fijarRuta`, `insertarParada`, `anularParada`, `consultarPosicion` y `estado`, que prueba Sebastián. Sebastián implementa `fijarCapacidad`, `cargar`, `entregar`, `fallo`, `cerrarDia` y `nuevoDia`, que prueba Maria Fernanda.

## Costes de la ruta (las dos implementaciones)

| Operación | Contigua | Enlazada |
|---|---|---|
| `at(i)` | O(1) | O(i) |
| `anadirAlFinal` | O(1) amortizado | O(1) |
| `insertar(i)` / `borrar(i)` | O(n − i) | O(i) |
| `buscar` | O(n) | O(n) |

Cola, Pila y Furgoneta: todas sus operaciones son O(1), salvo copiar, `contiene` e `imprimir`, que son O(n).

## Cómo se cumple «coger el paquete sin mover ninguno»

`CARGAR` mete los paquetes en la furgoneta en el **orden inverso de la ruta**: los de la última parada al fondo y los de la primera en la puerta. Así, en cada parada, sus paquetes son los que están en la puerta.
