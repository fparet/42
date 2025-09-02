# 42 C++ Module 04 — ex02: Classe abstraite (AAnimal + Brain)

- `AAnimal` est **abstraite** (`makeSound()` **purement virtuelle**). On ne peut pas l'instancier.
- `Dog` et `Cat` dérivent de `AAnimal`, possèdent chacun un `Brain*` et respectent la **copie profonde**.
- **Forme canonique de Coplien** pour toutes les classes, séparation header/source.
- `main` montre l'usage polymorphique via `AAnimal*` et teste la deep copy.

## Compilation
```bash
make
```

## Exécution
```bash
./animals_abstract
```

## Arborescence
```
ex02/
├── Makefile
├── include
│   ├── AAnimal.hpp
│   ├── Brain.hpp
│   ├── Cat.hpp
│   └── Dog.hpp
└── src
    ├── AAnimal.cpp
    ├── Brain.cpp
    ├── Cat.cpp
    ├── Dog.cpp
    └── main.cpp
```
