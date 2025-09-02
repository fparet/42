// ************************************************************************** //
//                                                                            //
//                             randomChump.cpp                                //
//                         42 C++ Module 01 - ex00                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

void randomChump(const std::string &name) {
    Zombie z(name);   // automatic storage
    z.announce();     // announces before going out of scope
}
