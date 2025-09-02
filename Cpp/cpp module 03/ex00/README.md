# 42 C++ Module 03 — ex00: Aaaaand... OPEN! (ClapTrap)

Implémente la classe **ClapTrap** (C++98) en **forme canonique de Coplien** :
- Constructeur par défaut, constructeur de copie, opérateur d’affectation, destructeur
- Constructeur avec `name`
- Méthodes: `attack(target)`, `takeDamage(amount)`, `beRepaired(amount)`
- Stats par défaut: HP=10, EP=10, AD=0
- Action impossible si HP=0 ou EP=0 (messages explicites)

## Compilation
```bash
make
```

## Exécution
```bash
./claptrap
```

## Arborescence
```
ex00/
├── Makefile
├── include
│   └── ClapTrap.hpp
└── src
    ├── ClapTrap.cpp
    └── main.cpp
```
