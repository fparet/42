// ************************************************************************** //
//                                                                            //
//                                AMateria.hpp                                
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter; // fwd

class AMateria {
public:
    // Coplien
    AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria&);
    virtual ~AMateria();

    // Custom
    explicit AMateria(const std::string& type);

    const std::string& getType() const; // returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

protected:
    std::string _type;
};

#endif // AMATERIA_HPP
