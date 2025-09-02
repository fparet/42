// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 01 - ex00                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "[Test] randomChump (stack):" << std::endl;
    randomChump("Bob");

    std::cout << "\n[Test] newZombie (heap):" << std::endl;
    Zombie* alice = newZombie("Alice");
    alice->announce();
    delete alice;

    std::cout << "\n[Test] Multiple zombies:" << std::endl;
    Zombie* z1 = newZombie("Rick");
    Zombie* z2 = newZombie("Morty");
    z1->announce();
    z2->announce();
    delete z1;
    delete z2;

    return 0;
}
