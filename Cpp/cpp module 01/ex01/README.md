# 42 C++ Module 01 — ex01: Moar brainz! (ZombieHorde)

Implémentation d'une fonction `Zombie* zombieHorde(int N, const std::string& name)`
qui alloue un tableau de `N` zombies initialisés avec `name`.

- Si `N <= 0`, la fonction renvoie `NULL`.
- Chaque `Zombie` a `announce()`, `setName()` et un constructeur par défaut.

## Compilation
```bash
make
```

## Exécution
```bash
./zombiehorde
```

## Arborescence
```
ex01/
├── Makefile
├── include
│   └── Zombie.hpp
└── src
    ├── Zombie.cpp
    ├── main.cpp
    └── zombieHorde.cpp
```
