// ************************************************************************** //
//                                                                            //
//                               Zombie.cpp                                   //
//                         42 C++ Module 01 - ex00                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::~Zombie() {
    // Optional: uncomment to observe destruction
    // std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
