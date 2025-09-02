// ************************************************************************** //
//                                                                            //
//                            zombieHorde.cpp                                 //
//                         42 C++ Module 01 - ex01                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"

Zombie* zombieHorde(int N, const std::string &name) {
    if (N <= 0)
        return 0;
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name);
    }
    return horde;
}
