// ************************************************************************** //
//                                                                            //
//                              newZombie.cpp                                 //
//                         42 C++ Module 01 - ex00                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie* newZombie(const std::string &name) {
    return new Zombie(name);
}
