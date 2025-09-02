# 42 C++ Module 02 — ex03: BSP

Implémente une classe immuable `Point` (coordonnées `Fixed const`) et une fonction:
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```
qui renvoie `true` si `point` est STRICTEMENT à l'intérieur du triangle `abc`
(les points sur les arêtes ou sommets renvoient `false`).

- `Point` respecte la forme canonique de Coplien (l'opérateur d'affectation est un *no-op*
  puisque les membres sont `const`).
- `Fixed` fourni (C++98) avec conversions et comparaisons de base.

## Compilation
```bash
make
```

## Exécution
```bash
./bsp
```

## Arborescence
```
ex03/
├── Makefile
├── include
│   ├── Fixed.hpp
│   └── Point.hpp
└── src
    ├── Fixed.cpp
    ├── Point.cpp
    ├── bsp.cpp
    └── main.cpp
```
