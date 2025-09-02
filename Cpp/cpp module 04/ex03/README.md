# 42 C++ Module 04 — ex03: Interface & recap (Materia)

Système de Materias inspiré de FF :
- `AMateria` (abstraite) avec `clone()` et `use(ICharacter&)`.
- `Ice` / `Cure` dérivent de `AMateria`.
- `ICharacter` (interface) et implémentation `Character` avec **inventaire 4 slots**.
  - `equip` ajoute la materia (si plein: posée au "floor" pour éviter les leaks).
  - `unequip` **ne supprime pas** la materia (déplacée vers un "floor" interne, détruite au dtor).
  - **Copie profonde** de l'inventaire via `clone()`.
- `IMateriaSource` (interface) / `MateriaSource` : peut **learn** jusqu'à 4 Materias (prend possession du pointeur)
  et **create** par type via `clone()`.

## Compilation
```bash
make
```

## Exécution
```bash
./materia
```

## Arborescence
```
ex03/
├── Makefile
├── include
│   ├── AMateria.hpp
│   ├── Character.hpp
│   ├── Cure.hpp
│   ├── ICharacter.hpp
│   ├── IMateriaSource.hpp
│   ├── Ice.hpp
│   └── MateriaSource.hpp
└── src
    ├── AMateria.cpp
    ├── Character.cpp
    ├── Cure.cpp
    ├── ICharacter.cpp
    ├── IMateriaSource.cpp
    ├── Ice.cpp
    ├── MateriaSource.cpp
    ├── main.cpp
```
