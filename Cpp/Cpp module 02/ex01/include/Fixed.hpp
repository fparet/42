// ************************************************************************** //
//                                                                            //
//                                 Fixed.hpp                                  //
//                         42 C++ Module 02 - ex01                            //
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

    // Accessors
    int  getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;

private:
    int                 _rawBits;
    static const int    _fractionalBits; // 8
};

// Non-member: stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif // FIXED_HPP
