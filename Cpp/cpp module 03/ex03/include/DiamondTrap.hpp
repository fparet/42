// ************************************************************************** //
//                                                                            //
//                             DiamondTrap.hpp                                
//                         42 C++ Module 03 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    // Coplien form
    DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap&);
    ~DiamondTrap();

    // Custom constructor
    explicit DiamondTrap(const std::string& name);

    // Use ScavTrap's attack by default
    void attack(const std::string& target);

    // Specific ability
    void whoAmI();

    // For display
    unsigned int getHitPointsDT() const;
    unsigned int getEnergyPointsDT() const;
    unsigned int getAttackDamageDT() const;

private:
    std::string _name; // own name distinct from ClapTrap::_name
};

#endif // DIAMONDTRAP_HPP
