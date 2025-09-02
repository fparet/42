// ************************************************************************** //
//                                                                            //
//                                 Fixed.hpp                                  //
//                         42 C++ Module 02 - ex03                            //
//                                                                            //
// ************************************************************************** //
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    // Coplien form
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Extras
    Fixed(const int value);
    Fixed(const float value);

    float toFloat(void) const;
    int   toInt(void) const;

    // Comparisons (useful if needed)
    bool operator<(const Fixed& rhs) const;
    bool operator>(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic (minimal)
    Fixed operator-(const Fixed& rhs) const;

private:
    int                 _rawBits;
    static const int    _fractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif // FIXED_HPP
