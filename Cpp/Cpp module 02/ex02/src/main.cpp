// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 02 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Fixed.hpp"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // Extra quick checks
    Fixed c(2);
    Fixed d(3.5f);
    std::cout << (c + d) << std::endl;
    std::cout << (d - c) << std::endl;
    std::cout << (c * d) << std::endl;
    std::cout << (d / c) << std::endl;
    return 0;
}
