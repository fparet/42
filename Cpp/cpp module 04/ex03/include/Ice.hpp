// ************************************************************************** //
//                                                                            //
//                                  Ice.hpp                                   
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
    // Coplien
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice&);
    virtual ~Ice();

    // AMateria
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif // ICE_HPP
