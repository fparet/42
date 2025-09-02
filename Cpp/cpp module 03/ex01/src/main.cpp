// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 03 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "ScavTrap.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Construction & Coplien");
    ScavTrap s1("Serena");
    ScavTrap s2(s1);    // copy
    ScavTrap s3;        // default then assign
    s3 = s1;

    separator("Actions");
    s1.attack("Handsome Jack");
    s1.takeDamage(42);
    s1.beRepaired(15);
    s1.guardGate();

    separator("Energy check");
    for (int i = 0; i < 55; ++i) s1.attack("training-bot");

    separator("State");
    std::cout << s1.getName() << " HP=" << s1.getHitPoints()
              << " EP=" << s1.getEnergyPoints()
              << " AD=" << s1.getAttackDamage() << std::endl;

    return 0;
}
