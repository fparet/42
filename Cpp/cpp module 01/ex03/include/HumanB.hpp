// ************************************************************************** //
//                                                                            //
//                               HumanB.hpp                                   //
//                         42 C++ Module 01 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
public:
    explicit HumanB(const std::string &name);
    void setWeapon(Weapon &weapon);
    void attack() const;
private:
    std::string _name;
    Weapon     *_weapon; // pointer: may be null
};

#endif // HUMANB_HPP
