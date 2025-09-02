// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 03 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "DiamondTrap.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Construction & Coplien");
    DiamondTrap d1("WeirdOne");
    DiamondTrap d2(d1);
    DiamondTrap d3;
    d3 = d1;

    separator("whoAmI");
    d1.whoAmI();

    separator("Stats");
    std::cout << "HP=" << d1.getHitPointsDT()
              << " EP=" << d1.getEnergyPointsDT()
              << " AD=" << d1.getAttackDamageDT() << std::endl;

    separator("Actions");
    d1.attack("Hyperion Bot"); // ScavTrap attack
    d1.takeDamage(40);
    d1.beRepaired(20);
    d1.highFivesGuys(); // from FragTrap
    d1.guardGate();     // from ScavTrap

    return 0;
}
