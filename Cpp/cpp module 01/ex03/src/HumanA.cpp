// ************************************************************************** //
//                                                                            //
//                               HumanA.cpp                                   //
//                         42 C++ Module 01 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon)
    : _name(name), _weapon(weapon) {}

void HumanA::attack() const {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
