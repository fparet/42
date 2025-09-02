// ************************************************************************** //
//                                                                            //
//                                 Fixed.cpp                                  //
//                         42 C++ Module 02 - ex01                            //
//                                                                            //
// ************************************************************************** //
#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Coplien
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other._rawBits;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Extra constructors
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

// Accessors
int Fixed::getRawBits(void) const {
    // Keep the log, per subject
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

// Conversions
float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// Non-member
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
