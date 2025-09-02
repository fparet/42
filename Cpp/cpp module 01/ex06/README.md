# 42 C++ Module 01 — ex06: Harl filter

Filtrer les messages de `Harl` en fonction d'un niveau passé en argument:
- `DEBUG`  → affiche DEBUG, INFO, WARNING, ERROR
- `INFO`   → affiche INFO, WARNING, ERROR
- `WARNING`→ affiche WARNING, ERROR
- `ERROR`  → affiche ERROR
- Autre    → affiche la ligne générique

Le `switch` utilise les *fallthrough* intentionnels pour éviter la duplication.

## Compilation
```bash
make
```

## Exécution
```bash
./harlFilter WARNING
```

## Arborescence
```
ex06/
├── Makefile
├── include
│   └── Harl.hpp
└── src
    ├── Harl.cpp
    └── main.cpp
```
