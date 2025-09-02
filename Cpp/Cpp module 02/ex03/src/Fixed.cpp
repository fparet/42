// ************************************************************************** //
//                                                                            //
//                                 Fixed.cpp                                  //
//                         42 C++ Module 02 - ex03                            //
//                                                                            //
// ************************************************************************** //
#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Coplien
Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) _rawBits = other._rawBits;
    return *this;
}
Fixed::~Fixed() {}

// Extras
Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {}
Fixed::Fixed(const float value)
    : _rawBits(static_cast<int>(std::floor(value * (1 << _fractionalBits) + (value >= 0 ? 0.5f : -0.5f)))) {}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / static_cast<float>(1 << _fractionalBits);
}
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// Comparisons
bool Fixed::operator<(const Fixed& rhs) const { return _rawBits < rhs._rawBits; }
bool Fixed::operator>(const Fixed& rhs) const { return _rawBits > rhs._rawBits; }
bool Fixed::operator<=(const Fixed& rhs) const { return _rawBits <= rhs._rawBits; }
bool Fixed::operator>=(const Fixed& rhs) const { return _rawBits >= rhs._rawBits; }
bool Fixed::operator==(const Fixed& rhs) const { return _rawBits == rhs._rawBits; }
bool Fixed::operator!=(const Fixed& rhs) const { return _rawBits != rhs._rawBits; }

// Arithmetic (minimal)
Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed tmp;
    tmp = Fixed(this->toFloat() - rhs.toFloat());
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
