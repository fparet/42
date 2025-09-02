// ************************************************************************** //
//                                                                            //
//                                 Fixed.cpp                                  //
//                         42 C++ Module 02 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Fixed.hpp"
#include <cmath>
#include <stdexcept>

const int Fixed::_fractionalBits = 8;

// Coplien
Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_rawBits = other._rawBits;
    }
    return *this;
}
Fixed::~Fixed() {}

// Extra constructors
Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {}
Fixed::Fixed(const float value)
    : _rawBits(static_cast<int>(std::floor(value * (1 << _fractionalBits) + (value >= 0 ? 0.5f : -0.5f)))) {}

// Internal raw constructor
Fixed::Fixed(int raw, bool /*isRawTag*/) : _rawBits(raw) {}

// Accessor (kept private to avoid subject's logging constraints from ex00/ex01)
int Fixed::getRawBits(void) const { return this->_rawBits; }

// Conversions
float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / static_cast<float>(1 << _fractionalBits);
}
int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& rhs) const { return _rawBits > rhs._rawBits; }
bool Fixed::operator<(const Fixed& rhs) const { return _rawBits < rhs._rawBits; }
bool Fixed::operator>=(const Fixed& rhs) const { return _rawBits >= rhs._rawBits; }
bool Fixed::operator<=(const Fixed& rhs) const { return _rawBits <= rhs._rawBits; }
bool Fixed::operator==(const Fixed& rhs) const { return _rawBits == rhs._rawBits; }
bool Fixed::operator!=(const Fixed& rhs) const { return _rawBits != rhs._rawBits; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->_rawBits + rhs._rawBits, true);
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->_rawBits - rhs._rawBits, true);
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    // Use long for intermediate to reduce overflow risk in typical ranges
    long prod = static_cast<long>(this->_rawBits) * static_cast<long>(rhs._rawBits);
    int raw = static_cast<int>(prod >> _fractionalBits);
    return Fixed(raw, true);
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs._rawBits == 0)
        throw std::runtime_error("Division by zero");
    long num = (static_cast<long>(this->_rawBits) << _fractionalBits);
    int raw = static_cast<int>(num / rhs._rawBits);
    return Fixed(raw, true);
}

// Increment/Decrement
Fixed& Fixed::operator++() {
    ++_rawBits; // increase by 1/256
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++_rawBits;
    return tmp;
}
Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --_rawBits;
    return tmp;
}

// Min/Max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Non-member
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
