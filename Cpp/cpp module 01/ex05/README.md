# 42 C++ Module 01 — ex05: Harl 2.0

Classe `Harl` avec quatre niveaux de logs: `DEBUG`, `INFO`, `WARNING`, `ERROR`.
La méthode `complain(level)` appelle la méthode correspondante via un tableau
de pointeurs sur fonctions-membres.

- Niveaux pris en charge: `DEBUG`, `INFO`, `WARNING`, `ERROR`.
- Niveau inconnu: affiche une ligne générique.

## Compilation
```bash
make
```

## Exécution
```bash
./harl
```

## Arborescence
```
ex05/
├── Makefile
├── include
│   └── Harl.hpp
└── src
    ├── Harl.cpp
    └── main.cpp
```
