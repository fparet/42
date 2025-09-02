// ************************************************************************** //
//                                                                            //
//                               Character.hpp                                
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
public:
    // Coplien
    Character();
    Character(const Character& other);
    Character& operator=(const Character&);
    virtual ~Character();

    // Custom
    explicit Character(const std::string& name);

    // ICharacter
    const std::string& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

private:
    std::string _name;
    AMateria*   _inv[4];

    // Keep unequipped materias to delete them in dtor (avoid leaks)
    AMateria*   _floor[128];
    void initSlots_();
    void clearSlots_();
};

#endif // CHARACTER_HPP
