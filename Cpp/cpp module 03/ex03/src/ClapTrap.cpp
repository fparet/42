// ************************************************************************** //
//                                                                            //
//                               ClapTrap.cpp                                 //
//                         42 C++ Module 03 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "ClapTrap.hpp"
#include <iostream>

// Default stats per subject (base ClapTrap)
static const unsigned int CT_DEFAULT_HP = 10;
static const unsigned int CT_DEFAULT_EP = 10;
static const unsigned int CT_DEFAULT_AD = 0;

// Coplien
ClapTrap::ClapTrap()
    : _name("anonymous"), _hitPoints(CT_DEFAULT_HP), _energyPoints(CT_DEFAULT_EP), _attackDamage(CT_DEFAULT_AD) {
    std::cout << "ClapTrap default-constructed: " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy-constructed from: " << other._name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap copy-assigned from: " << other._name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destroyed: " << _name << std::endl;
}

// Custom
ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(CT_DEFAULT_HP), _energyPoints(CT_DEFAULT_EP), _attackDamage(CT_DEFAULT_AD) {
    std::cout << "ClapTrap constructed: " << _name << std::endl;
}

bool ClapTrap::canAct_() const {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot act: no hit points left." << std::endl;
        return false;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " cannot act: no energy left." << std::endl;
        return false;
    }
    return true;
}

void ClapTrap::attack(const std::string& target) {
    if (!canAct_()) return;
    --_energyPoints;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage! "
              << "(EP left: " << _energyPoints << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already at 0 HP." << std::endl;
        return;
    }
    unsigned int prev = _hitPoints;
    _hitPoints = (amount >= _hitPoints) ? 0u : (_hitPoints - amount);
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage ("
              << prev << " -> " << _hitPoints << " HP)." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!canAct_()) return;
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount
              << " HP (now " << _hitPoints << " HP, EP left: " << _energyPoints << ")." << std::endl;
}

// Accessors
const std::string& ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; }
void ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }
