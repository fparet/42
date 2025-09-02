// ************************************************************************** //
//                                                                            //
//                               Weapon.hpp                                   //
//                         42 C++ Module 01 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
    explicit Weapon(const std::string &type);
    const std::string &getType() const;
    void setType(const std::string &type);
private:
    std::string _type;
};

#endif // WEAPON_HPP
