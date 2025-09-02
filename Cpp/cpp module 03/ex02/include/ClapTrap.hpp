// ************************************************************************** //
//                                                                            //
//                               ClapTrap.hpp                                 //
//                         42 C++ Module 03 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
    // Coplien form
    ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap&);
    virtual ~ClapTrap();

    // Custom constructor
    explicit ClapTrap(const std::string& name);

    // Actions
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Accessors
    const std::string& getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    void setAttackDamage(unsigned int amount);

protected:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

    bool canAct_() const; // internal helper: alive + energy
};

#endif // CLAPTRAP_HPP
