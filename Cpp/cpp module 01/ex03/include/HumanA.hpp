// ************************************************************************** //
//                                                                            //
//                               HumanA.hpp                                   //
//                         42 C++ Module 01 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
public:
    HumanA(const std::string &name, Weapon &weapon);
    void attack() const;
private:
    std::string _name;
    Weapon     &_weapon; // reference: must be initialized and never null
};

#endif // HUMANA_HPP
