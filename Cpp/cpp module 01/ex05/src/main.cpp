// ************************************************************************** //
//                                                                            //
//                                 main.cpp                                   //
//                         42 C++ Module 01 - ex05                            //
//                                                                            //
// ************************************************************************** //
#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    // Run through all valid levels
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    // Unknown level
    harl.complain("BOGUS");

    return 0;
}
