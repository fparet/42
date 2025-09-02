# 42 C++ Module 01 — ex00: BraiiiiiiinnnzzzZ

Implémentation d'une classe `Zombie` avec deux fonctions:
- `Zombie* newZombie(const std::string& name)` : alloue sur le tas et renvoie un pointeur.
- `void randomChump(const std::string& name)` : crée un zombie sur la pile et l'annonce immédiatement.

Le zombie annonce sous la forme: `<name>: BraiiiiiiinnnzzzZ...`

## Compilation
```bash
make
```

## Exécution
```bash
./zombie
```

## Arborescence
```
.
├── Makefile
├── include
│   └── Zombie.hpp
└── src
    ├── Zombie.cpp
    ├── main.cpp
    ├── newZombie.cpp
    └── randomChump.cpp
```
