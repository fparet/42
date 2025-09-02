// ************************************************************************** //
//                                                                            //
//                                   main.cpp                                 
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    // unequip test: do not delete, but keep safe
    me->unequip(0);
    me->use(0, *bob); // nothing
    AMateria* again = src->createMateria("ice");
    me->equip(again);
    me->use(0, *bob);

    // deep copy test
    Character original("orig");
    original.equip(src->createMateria("ice"));
    Character copied = original; // deep
    original.use(0, *bob);
    copied.use(0, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}
