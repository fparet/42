// ************************************************************************** //
//                                                                            //
//                                   main.cpp                                  //
//                         42 C++ Module 06 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Classes.hpp"
#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) {
        Base* p = generate();
        std::cout << "identify(p*): "; identify(p);
        std::cout << "identify(p&): "; identify(*p);
        delete p;
    }
    return 0;
}
