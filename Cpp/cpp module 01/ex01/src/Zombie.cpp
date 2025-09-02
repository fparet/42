// ************************************************************************** //
//                                                                            //
//                               Zombie.cpp                                   //
//                         42 C++ Module 01 - ex01                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("anonymous") {}
Zombie::Zombie(const std::string &name) : _name(name) {}
Zombie::~Zombie() {}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
    this->_name = name;
}
