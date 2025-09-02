// ************************************************************************** //
//                                                                            //
//                                   main.cpp                                  //
//                         42 C++ Module 05 - ex00                            //
//                                                                            //
// ************************************************************************** //
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << "Increment Bob (should throw)..." << std::endl;
        b.incrementGrade(); // 149
        std::cout << b << std::endl;

        std::cout << "Decrement Alice (should throw if >150)..." << std::endl;
        a.decrementGrade(); // 2
        std::cout << a << std::endl;

        std::cout << "Construct with bad grade (-1)..." << std::endl;
        Bureaucrat c("Charlie", -1);
        (void)c;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
