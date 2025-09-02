// ************************************************************************** //
//                                                                            //
//                               ScavTrap.cpp                                 //
//                         42 C++ Module 03 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "ScavTrap.hpp"
#include <iostream>

// Subject-typical ScavTrap stats
static const unsigned int ST_HP = 100;
static const unsigned int ST_EP = 50;
static const unsigned int ST_AD = 20;

// Coplien
ScavTrap::ScavTrap() : ClapTrap("ScavAnon") {
    _hitPoints = ST_HP;
    _energyPoints = ST_EP;
    _attackDamage = ST_AD;
    std::cout << "ScavTrap default-constructed: " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy-constructed from: " << other._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap copy-assigned from: " << other._name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destroyed: " << _name << std::endl;
}

// Custom
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = ST_HP;
    _energyPoints = ST_EP;
    _attackDamage = ST_AD;
    std::cout << "ScavTrap constructed: " << _name << std::endl;
}

// Override
void ScavTrap::attack(const std::string& target) {
    if (!canAct_()) return;
    --_energyPoints;
    std::cout << "ScavTrap " << _name << " slashes " << target
              << ", dealing " << _attackDamage << " damage! "
              << "(EP left: " << _energyPoints << ")" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
