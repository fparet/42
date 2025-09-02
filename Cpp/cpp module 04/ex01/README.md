# 42 C++ Module 04 — ex01: Animals + Brain (deep copy)

- `Animal` (virtuel), `Dog`, `Cat` — **forme canonique de Coplien**.
- `Brain` (100 idées) — **deep copy** dans `Dog` et `Cat` (copy ctor & operator= copient le contenu, dtor delete).
- `main` : tableau d'`Animal*` (polymorphisme), tests de copie profonde sur `Dog` et `Cat`.

## Compilation
```bash
make
```

## Exécution
```bash
./animals_brain
```

## Arborescence
```
ex01/
├── Makefile
├── include
│   ├── Animal.hpp
│   ├── Brain.hpp
│   ├── Cat.hpp
│   └── Dog.hpp
└── src
    ├── Animal.cpp
    ├── Brain.cpp
    ├── Cat.cpp
    ├── Dog.cpp
    └── main.cpp
```
