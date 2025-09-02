// ************************************************************************** //
//                                                                            //
//                                 Fixed.hpp                                  //
//                         42 C++ Module 02 - ex00                            //
//                                                                            //
// ************************************************************************** //
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();                         // Default constructor
    Fixed(const Fixed& other);       // Copy constructor
    Fixed& operator=(const Fixed&);  // Copy assignment operator
    ~Fixed();                        // Destructor

    int  getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int                 _rawBits;
    static const int    _fractionalBits; // always 8 in the subject
};

#endif // FIXED_HPP
