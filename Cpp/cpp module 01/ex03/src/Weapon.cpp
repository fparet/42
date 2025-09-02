// ************************************************************************** //
//                                                                            //
//                               Weapon.cpp                                   //
//                         42 C++ Module 01 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

const std::string &Weapon::getType() const {
    return _type;
}

void Weapon::setType(const std::string &type) {
    _type = type;
}
