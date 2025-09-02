# 42 C++ Module 01 — ex03: Unnecessary violence

Trois classes :
- `Weapon` : possède un type modifiable via `setType` et consultable via `getType` (retour par référence const).
- `HumanA` : détient une référence vers un `Weapon` (doit être fournie au constructeur).
- `HumanB` : détient un pointeur vers un `Weapon` (optionnel, configurable via `setWeapon`).

Le `main` reproduit le scénario du sujet et montre la différence entre la référence et le pointeur.

## Compilation
```bash
make
```

## Exécution
```bash
./violence
```

## Arborescence
```
ex03/
├── Makefile
├── include
│   ├── HumanA.hpp
│   ├── HumanB.hpp
│   └── Weapon.hpp
└── src
    ├── HumanA.cpp
    ├── HumanB.cpp
    ├── Weapon.cpp
    └── main.cpp
```
