// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 03 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "FragTrap.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Construction & Coplien");
    FragTrap f1("Fraggy");
    FragTrap f2(f1);
    FragTrap f3;
    f3 = f1;

    separator("Actions");
    f1.attack("Skag");
    f1.takeDamage(60);
    f1.beRepaired(25);
    f1.highFivesGuys();

    separator("Energy test");
    for (int i = 0; i < 105; ++i) f1.attack("Dummy");

    separator("State");
    std::cout << f1.getName() << " HP=" << f1.getHitPoints()
              << " EP=" << f1.getEnergyPoints()
              << " AD=" << f1.getAttackDamage() << std::endl;

    return 0;
}
