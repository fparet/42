// ************************************************************************** //
//                                                                            //
//                             DiamondTrap.cpp                                
//                         42 C++ Module 03 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "DiamondTrap.hpp"
#include <iostream>

// Desired DiamondTrap stats per subject:
// HP from FragTrap (100), EP from ScavTrap (50), AD from FragTrap (30)

// Coplien
DiamondTrap::DiamondTrap()
    : ClapTrap("diamond_clap_name"), ScavTrap(), FragTrap(), _name("diamond") {
    // Initialize to desired stats
    this->ClapTrap::_hitPoints   = 100; // from FragTrap
    this->ClapTrap::_energyPoints= 50;  // from ScavTrap
    this->ClapTrap::_attackDamage= 30;  // from FragTrap
    std::cout << "DiamondTrap default-constructed: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy-constructed from: " << other._name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap copy-assigned from: " << other._name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destroyed: " << _name << std::endl;
}

// Custom
DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    this->ClapTrap::_hitPoints   = 100; // FragTrap
    this->ClapTrap::_energyPoints= 50;  // ScavTrap
    this->ClapTrap::_attackDamage= 30;  // FragTrap
    std::cout << "DiamondTrap constructed: " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    // Use ScavTrap's attack implementation
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name
              << " | ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

unsigned int DiamondTrap::getHitPointsDT() const { return this->ClapTrap::_hitPoints; }
unsigned int DiamondTrap::getEnergyPointsDT() const { return this->ClapTrap::_energyPoints; }
unsigned int DiamondTrap::getAttackDamageDT() const { return this->ClapTrap::_attackDamage; }
