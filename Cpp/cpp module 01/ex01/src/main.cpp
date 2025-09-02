// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 01 - ex01                            //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>

static void test_horde(int n, const std::string& name) {
    std::cout << "\n[Create horde of " << n << " named '" << name << "']" << std::endl;
    Zombie* horde = zombieHorde(n, name);
    if (!horde) {
        std::cout << "No zombies created (N <= 0)" << std::endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        horde[i].announce();
    }
    delete [] horde;
}

int main() {
    test_horde(5, "HordeMember");
    test_horde(1, "Solo");
    test_horde(0, "Nobody");
    test_horde(-3, "Negative");
    return 0;
}
