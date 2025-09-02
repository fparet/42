# 42 C++ Module 02 — ex01: Fixed (constructors & conversions)

Extension de `Fixed` :
- Forme canonique de Coplien respectée (par défaut, copie, affectation, destructeur).
- Constructeurs supplémentaires depuis `int` et `float`.
- Méthodes `toFloat()` et `toInt()`.
- Surcharge de `operator<<` comme fonction non-membre affichant `toFloat()`.

## Compilation
```bash
make
```

## Exécution
```bash
./fixed
```

## Arborescence
```
ex01/
├── Makefile
├── include
│   └── Fixed.hpp
└── src
    ├── Fixed.cpp
    └── main.cpp
```
