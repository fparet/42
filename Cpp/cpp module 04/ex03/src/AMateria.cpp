// ************************************************************************** //
//                                                                            //
//                                AMateria.cpp                                
//                         42 C++ Module 04 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("unknown") {}
AMateria::AMateria(const std::string& type) : _type(type) {}
AMateria::AMateria(const AMateria& other) : _type(other._type) {}
AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) _type = other._type;
    return *this;
}
AMateria::~AMateria() {}

const std::string& AMateria::getType() const { return _type; }
void AMateria::use(ICharacter& /*target*/) {
    // default does nothing
}
