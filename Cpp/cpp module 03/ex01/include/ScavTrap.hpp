// ************************************************************************** //
//                                                                            //
//                               ScavTrap.hpp                                 //
//                         42 C++ Module 03 - ex01                            //
//                                                                            //
// ************************************************************************** //
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Coplien form
    ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap&);
    ~ScavTrap();

    // Custom constructor
    explicit ScavTrap(const std::string& name);

    // Override
    void attack(const std::string& target);

    // Specific ability
    void guardGate();
};

#endif // SCAVTRAP_HPP
