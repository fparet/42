// ************************************************************************** //
//                                                                            //
//                                 Fixed.hpp                                  //
//                         42 C++ Module 02 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    // Coplien form
    Fixed();                         // Default constructor
    Fixed(const Fixed& other);       // Copy constructor
    Fixed& operator=(const Fixed&);  // Copy assignment operator
    ~Fixed();                        // Destructor

    // Extra constructors
    Fixed(const int value);
    Fixed(const float value);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // Increment/Decrement
    Fixed& operator++();   // pre-increment
    Fixed  operator++(int); // post-increment
    Fixed& operator--();   // pre-decrement
    Fixed  operator--(int); // post-decrement

    // Min/Max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int                 _rawBits;
    static const int    _fractionalBits; // 8

    // Internal helper to construct from raw bits
    explicit Fixed(int raw, bool isRawTag);
    int  getRawBits(void) const;
};

// Non-member: stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif // FIXED_HPP
