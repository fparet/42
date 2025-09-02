// ************************************************************************** //
//                                                                            //
//                               FragTrap.hpp                                 //
//                         42 C++ Module 03 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Coplien form
    FragTrap();
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap&);
    virtual ~FragTrap();

    // Custom constructor
    explicit FragTrap(const std::string& name);

    // Override
    void attack(const std::string& target);

    // Specific ability
    void highFivesGuys();
};

#endif // FRAGTRAP_HPP
