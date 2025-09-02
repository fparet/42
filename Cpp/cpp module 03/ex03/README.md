# 42 C++ Module 03 — ex03: Now it's weird! (DiamondTrap)

- `DiamondTrap` hérite de **`ScavTrap`** et **`FragTrap`**.
- Forme canonique de Coplien respectée pour toutes les classes.
- Noms: `DiamondTrap` possède son propre `_name`, et **`ClapTrap::_name`** est initialisé à `name + "_clap_name"`.
- `attack()` de `DiamondTrap` délègue à **`ScavTrap::attack`**.
- Stats: **HP=100** (FragTrap), **EP=50** (ScavTrap), **AD=30** (FragTrap).
- Méthode `whoAmI()` affiche le nom propre et le *clap name*.
- Projet autonome: inclut `ClapTrap`, `ScavTrap`, `FragTrap` et `DiamondTrap`.

## Compilation
```bash
make
```

## Exécution
```bash
./diamondtrap
```

## Arborescence
```
ex03/
├── Makefile
├── include
│   ├── ClapTrap.hpp
│   ├── ScavTrap.hpp
│   ├── FragTrap.hpp
│   └── DiamondTrap.hpp
└── src
    ├── ClapTrap.cpp
    ├── ScavTrap.cpp
    ├── FragTrap.cpp
    ├── DiamondTrap.cpp
    └── main.cpp
```
