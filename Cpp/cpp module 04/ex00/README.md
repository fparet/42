# 42 C++ Module 04 — ex00: Polymorphism (Animals)

- `Animal` (base) avec **destructeur virtuel**, `makeSound()` virtuel, `getType()`.
- `Dog` et `Cat` dérivent et **redéfinissent** `makeSound()`.
- `WrongAnimal` / `WrongCat` démontrent l'absence de polymorphisme si la méthode n'est **pas virtuelle**.
- **Forme canonique de Coplien** pour toutes les classes.
- `main` compare le comportement correct et incorrect.

## Compilation
```bash
make
```

## Exécution
```bash
./animals
```

## Arborescence
```
ex00/
├── Makefile
├── include
│   ├── Animal.hpp
│   ├── Cat.hpp
│   ├── Dog.hpp
│   ├── WrongAnimal.hpp
│   └── WrongCat.hpp
└── src
    ├── Animal.cpp
    ├── Cat.cpp
    ├── Dog.cpp
    ├── WrongAnimal.cpp
    ├── WrongCat.cpp
    └── main.cpp
```
