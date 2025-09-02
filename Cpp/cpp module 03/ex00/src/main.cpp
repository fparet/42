// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 03 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "ClapTrap.hpp"
#include <iostream>

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====" << std::endl;
}

int main() {
    separator("Construction & Coplien");
    ClapTrap a("CL4P-TP");
    ClapTrap b(a);           // copy ctor
    ClapTrap c;              // default
    c = a;                   // copy assign

    separator("Basic actions");
    a.setAttackDamage(3);
    a.attack("target-dummy");
    a.takeDamage(5);
    a.beRepaired(2);

    separator("Energy exhaustion");
    ClapTrap e("ZERO-EP");
    e.setAttackDamage(1);
    for (int i = 0; i < 12; ++i) e.attack("training-bot"); // should stop when EP=0

    separator("Death check");
    ClapTrap d("GL4SS");
    d.takeDamage(15); // drops to 0 HP
    d.attack("nobody");
    d.beRepaired(5);

    separator("State");
    std::cout << a.getName() << " HP=" << a.getHitPoints()
              << " EP=" << a.getEnergyPoints()
              << " AD=" << a.getAttackDamage() << std::endl;
    return 0;
}
