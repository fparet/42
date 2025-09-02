// ************************************************************************** //
//                                                                            //
//                               FragTrap.cpp                                 //
//                         42 C++ Module 03 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "FragTrap.hpp"
#include <iostream>

// Subject-typical FragTrap stats
static const unsigned int FT_HP = 100;
static const unsigned int FT_EP = 100;
static const unsigned int FT_AD = 30;

// Coplien
FragTrap::FragTrap() : ClapTrap("FragAnon") {
    _hitPoints = FT_HP;
    _energyPoints = FT_EP;
    _attackDamage = FT_AD;
    std::cout << "FragTrap default-constructed: " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy-constructed from: " << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap copy-assigned from: " << other._name << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destroyed: " << _name << std::endl;
}

// Custom
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = FT_HP;
    _energyPoints = FT_EP;
    _attackDamage = FT_AD;
    std::cout << "FragTrap constructed: " << _name << std::endl;
}

// Override
void FragTrap::attack(const std::string& target) {
    if (!canAct_()) return;
    --_energyPoints;
    std::cout << "FragTrap " << _name << " blasts " << target
              << " for " << _attackDamage << " damage! "
              << "(EP left: " << _energyPoints << ")" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " requests high fives! ✋" << std::endl;
}
