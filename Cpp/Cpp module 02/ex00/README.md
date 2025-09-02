# 42 C++ Module 02 — ex00: My First Class in Orthodox Canonical Form

Implémentation de la classe `Fixed` en forme canonique orthodoxe avec :
- constructeur par défaut
- constructeur de copie
- opérateur d’affectation par copie
- destructeur
- `getRawBits()` et `setRawBits()`
- champ privé `_rawBits` et `static const int _fractionalBits = 8`

Les méthodes affichent des messages comme exigé dans le sujet pour tracer
les appels (ex : "Default constructor called", "Copy constructor called", etc.).

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
ex00/
├── Makefile
├── include
│   └── Fixed.hpp
└── src
    ├── Fixed.cpp
    └── main.cpp
```
